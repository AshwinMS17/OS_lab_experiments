#include<stdio.h>
#include<string.h>
//this program doesn't need a variable that checks for an idle condition

struct process
{
    char name[10];
    int at,bt,tt,wt,status,priority;
};
int p=0;
struct done
{
    char name[20];
    int st,ct;
};

int getprocess(struct process pro[],int proc_size,int at)
{
    int index;
    int low=-1;
    //index=p;
    for(int i=0;pro[i].at<=at;i++)
    {
        if(pro[i].status==0)
        {
            low=pro[i].priority;
            index=i;
            break;
        }
    }
    for(int i=0;pro[i].at<=at;i++)
    {
        if(pro[i].status==0&&low>pro[i].priority)
        {
            low=pro[i].priority;
            index=i;
        }
    }
    if(low==-1)
    {
        for(int i=0;i<proc_size;i++)
        {
            if(pro[i].status==0)
            {
                index=i;
                break;
            }
        }
    }
    printf("\nindex found %d\n",index);
    return index;
}

void main()
{
    int proc_size,d=0,idle=0,index,count=0;
    struct done gantt[20];
    printf("Enter no:of processes:");
    scanf("%d",&proc_size);
    struct process pro[proc_size],temp;
    printf("Enter process data:\n");
    for(int i=0;i<proc_size;i++)
    {
        printf("Enter process name:");
        scanf("%s",pro[i].name);
        printf("Enter arrival time:");
        scanf("%d",&pro[i].at);
        printf("Enter burst time:");
        scanf("%d",&pro[i].bt);
        printf("Enter priority:");
        scanf("%d",&pro[i].priority);
        pro[i].status=0;
    }
    for(int i=0;i<proc_size-1;i++)
    {
        for(int j=0;j<proc_size-i-1;j++)
        {
            if(pro[j].at>pro[j+1].at)
            {
                temp=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp;
            }
        }
    }
    for(int i=pro[0].at;count<proc_size;)//k is used to traverse through processes
    {
        index=getprocess(pro,proc_size,i);
        if(pro[index].at<=i)//checks if next process in line has arrived or not
        {
            strcpy(gantt[d].name,pro[index].name);//all required calculations
            gantt[d].st=i;
            gantt[d].ct=i+pro[index].bt;
            pro[index].tt=gantt[d].ct-pro[index].at;
            pro[index].wt=pro[index].tt-pro[index].bt;
            pro[index].status=1;
            i=gantt[d].ct;//completion time of current process is set as the new scheduler time
            d++;
            count++;
        }
        else
        {
            //idle=1;
            gantt[d].st=i;
            gantt[d].ct=pro[index].at;
            strcpy(gantt[d].name,"idle");
            i=pro[index].at;//skips the scheduler time to the arrival time of the next process in line
            d++;
        }
    }
    for(int i=0;i<d;i++)
    {
        printf("%s----%d-----%d\n",gantt[i].name,gantt[i].st,gantt[i].ct);
    }
}