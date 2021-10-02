#include<stdio.h>
#include<string.h>

//this program doesn't need a variable that checks for an idle condition


struct process
{
    char name[10];
    int at,bt,tt,wt;
};

struct done
{
    char name[20];
    int st,ct;
};

void main()
{
    int proc_size,d=0,idle=0,k=0;
    struct done gantt[20];
    printf("Enter no:of processes:");
    scanf("%d",&proc_size);
    struct process pro[proc_size];
    printf("Enter process data:\n");
    for(int i=0;i<proc_size;i++)
    {
        printf("Enter process name:");
        scanf("%s",pro[i].name);
        printf("Enter arrival time:");
        scanf("%d",&pro[i].at);
        printf("Enter burst time:");
        scanf("%d",&pro[i].bt);
    }
    for(int i=pro[0].at;k<proc_size;)//k is used to traverse through processes
    {
        if(pro[k].at<=i)//checks if next process in line has arrived or not
        {
            /*if(idle==1)
            {
                idle=0;
                d++;
            }*/
            strcpy(gantt[d].name,pro[k].name);//all required calculations
            gantt[d].st=i;
            gantt[d].ct=i+pro[k].bt;
            pro[k].tt=gantt[d].ct-pro[k].at;
            pro[k].wt=pro[k].tt-pro[k].bt;
            k++;
            i=gantt[d].ct;//completion time of current process is set as the new scheduler time
            d++;
            //idle=0;
        }
        else//if next process in line has not arrived yet
        {
            //idle=1;
            gantt[d].st=i;
            gantt[d].ct=pro[k].at;
            strcpy(gantt[d].name,"idle");
            i=pro[k].at;//skips the scheduler time to the arrival time of the next process in line
            d++;
        }
    }

    //i haven't displayed the gantt chart because i was lazy but this for loop with show the values you need
    for(int i=0;i<d;i++)
    {
        printf("%s----%d-----%d\n",gantt[i].name,gantt[i].st,gantt[i].ct);
    }

}