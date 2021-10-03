#include<stdio.h>
#include<string.h>
//this program doesn't need a variable that checks for an idle condition

struct process
{
    char name[10];
    int at,bt,tt,wt,status,rem_bt,q;
};

int p=1,queue_size=1,queue_rn=0;

struct done
{
    char name[20];
    int st,ct;
};


int getprocess(struct process pro[],int proc_size,int at)
{
    int index=-1;
    //int low=-1;
    for(int i=0;pro[i].at<=at;i++)
    {
        if(pro[i].q==queue_rn&&pro[i].status==0)
        {
            index=i;
        }
    }
    if(index==-1)
    {
        for(int i=0;i<proc_size;i++)
        {
            if(pro[i].status==0&&pro[i].q==-1)
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
    int proc_size,d=0,index,count=0,tq;
    struct done gantt[20];
    printf("Enter time quantum:");
    scanf("%d",&tq);
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
        pro[i].rem_bt=pro[i].bt;
        pro[i].q=-1;
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
    pro[0].q=0;
    for(int i=pro[0].at;count<proc_size;)//k is used to traverse through processes
    {
        index=getprocess(pro,proc_size,i);
        if(pro[index].at<=i)//checks if next process in line has arrived or not
        {
            strcpy(gantt[d].name,pro[index].name);//all required calculations
            gantt[d].st=i;
            if(pro[i].rem_bt>tq)
            {
                gantt[d].ct=i+tq;
                pro[index].rem_bt-=tq;
                queue_rn++;
            }
            else
            {
                gantt[d].ct=i+pro[index].rem_bt;
                pro[index].rem_bt=0;
            }
            if(pro[index].rem_bt==0)
            {
                pro[index].tt=gantt[d].ct-pro[index].at;
                pro[index].wt=pro[index].tt-pro[index].bt-pro[index].at;
                pro[index].status=1;
                queue_rn++;
                count++;
            }
            i=gantt[d].ct;//completion time of current process is set as the new scheduler time
            while(pro[p].at<=i&&p<proc_size)
            {
                pro[p].q=queue_size;
                queue_size++;
                p++;
            }
            pro[index].q=queue_size++;
            d++;
            //count++;
        }
        else
        {
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