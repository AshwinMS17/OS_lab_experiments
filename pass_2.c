#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

FILE *fp1,*fp2,*fp3,*fp4,*fp5;

char label[10],opcode[10],operand[10],str[10],symbol[20],value[10];
int address,start=0,length=0,i;

void search_optab()
{
    fp3=fopen("optab.txt","r");
    while(!feof(fp3))
    {
        fscanf(fp3,"%s\t%s\n",symbol,value);
        if(strcmp(symbol,opcode)==0);
        {
            fprintf(fp2,"^%s",value);
            break;
        }
    }
    fclose(fp3);
}

void searc()
{
    fp4=fopen("sym.txt","r");
    while(!feof(fp4))
    {
        fscanf(fp4,"%s\t%s\n",symbol,value);
        if(strcmp(symbol,operand)==0)
        {
            fprintf(fp2,"%s",value);
            break;
        }
    }
    fclose(fp4);
    
}
void main()
{
    fp1=fopen("intermediate.txt","r");
    fp2=fopen("object_code.txt","w");
    fp5=fopen("pgm_length.txt","r");
    fscanf(fp5,"%d",&length);
    while(!feof(fp1))
    {
        fscanf(fp1,"%d\t%s\t%s\t%s\n",&address,label,opcode,operand);
        if(strcmp(opcode,"START")==0)
        {
            start=atoi(operand);
            fprintf(fp2,"H^%s^00%d00%d\n",label,start,length);
            fprintf(fp2,"T^00%d^00%d",start,length);
        }
        else
        {
            if((strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0))
                continue;
            if(strcmp(opcode,"WORD")==0)
            {
                fprintf(fp2,"^00000%s^",operand);
                continue;
            }
            else if(strcmp(opcode,"BYTE")==0)
            {
                if(operand[0]=='X')
                    for(i=2;i<(strlen(operand)-1);i++)
                    {
                        fprintf(fp2,"%c",operand[i]);
                    }
                else
                    for(i=2;i<(strlen(operand)-1);i++)
                    {
                        fprintf(fp2,"%X",operand[i]);
                    }
                continue;

            }
            else
            {
                search_optab();
                searc();
            }
        }
    }
    fprintf(fp2,"\nE^00%d",start);
}