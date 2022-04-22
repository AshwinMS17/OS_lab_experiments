#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    char opcode[10], mnemonic[3], operand[10], label[10], code[10];
    int locctr, start = 0, length;
    FILE *fp1, *fp2, *fp3, *fp4;
    FILE *fp5; //here
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("sym.txt", "w");
    fp3 = fopen("intermediate.txt", "w");
    fp4 = fopen("optab.txt", "r");
    fp5 = fopen("pgm_length.txt", "w");//here
    fscanf(fp1, "%s%s%s", label, opcode, operand);
    if(strcmp(opcode, "START")==0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp3, "%d\t%s\t%s\t%s\n",locctr, label, opcode, operand);
        fscanf(fp1, "%s%s%s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }

    while(strcmp(opcode, "END") != 0 )
    {
        fprintf(fp3, "%d\t", locctr);
        if(strcmp(label, "**") != 0)
        {
            fprintf(fp2, "%s\t%d\n", label, locctr);
        }
        fscanf(fp4, "%s%s", code, mnemonic);
        while(strcmp(code,"END")!=0)
        {
            if(strcmp(opcode,code)==0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp4, "%s%s", code, mnemonic);
        }
        if(strcmp(opcode, "WORD")==0)
        {
            locctr += 3;
        }
        else if(strcmp(opcode, "RESW")==0)
        {
            locctr += (3*(atoi(operand)));
        }
        else if(strcmp(opcode, "RESB")==0)
        {
            locctr += atoi(operand);
        }
        else if(strcmp(opcode, "BYTE")==0)
        {
            if(operand[0]=='X')
            {
                locctr += 1;
            }
            else if(operand[0]=='C')
            {
                locctr += strlen(operand) - 3;
            }
        }
        fprintf(fp3, "%s\t%s\t%s\t\n", label, opcode, operand);
        fscanf(fp1, "%s%s%s", label, opcode, operand);
    }
    fprintf(fp3, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    length = locctr - start;
    printf("The length of the program is %d. ", length);
    fprintf(fp5,"%d\n",length);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}