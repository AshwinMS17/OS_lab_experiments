#include<stdio.h>
#include<string.h>

struct process
{
    int max[10],alloc[10],need[10],done;
    char name[10];
};

void main()
{
    int proc_size,res_size,avail[10],count;
    char safe_seq[20]="";
    printf("Enter no:of resources:");
    scanf("%d",&res_size);
    printf("Enter availability of each resource:");
    for(int i=0;i<res_size;i++)
    {
        printf("Resource %d:",i);
        scanf("%d",&avail[i]);
    }
    printf("Enter no:of processes:");
    scanf("%d",&proc_size);
    struct process pro[proc_size];
    for(int i=0;i<proc_size;i++)
    {
        printf("Enter process name:");
        scanf("%s",pro[i].name);
        printf("Enter maximum requirement of each resource:\n");
        for(int j=0;j<res_size;j++)
        {
            printf("Resource %d:",j);
            scanf("%d",&pro[i].max[j]);
        }
        printf("Enter allocation of each resource:\n");
        for(int j=0;j<res_size;j++)
        {
            printf("Resource %d:",j);
            scanf("%d",&pro[i].alloc[j]);
            pro[i].need[j]=pro[i].max[j]-pro[i].alloc[j];
        }
        pro[i].done=0;
    }
    for(int i=0;i<proc_size;i++)
    {
        count=0;
        for(int j=0;j<res_size;j++)
        {
            if(pro[i].need[j]<=avail[j])
            {
                count++;
            }
        }
        if(count==res_size)
        {
            pro[i].done=1;
            for(int j=0;j<res_size;j++)
            {
                avail[j]+=pro[i].alloc[j];
            }
            strcat(safe_seq,pro[i].name);
            strcat(safe_seq,",");
        }
    }
    for(int i=0;i<proc_size;i++)
    {
        if(pro[i].done==0)
        {
            strcat(safe_seq,pro[i].name);
            strcat(safe_seq,",");
        }
    }
    printf("\n%s",safe_seq);
}