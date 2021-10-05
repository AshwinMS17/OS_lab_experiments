#include<stdio.h>

struct memoryblock
{
	int size,rem_size;
	int proc[10],pr_size;
};

/*void sort(struct memoryblock mem_block[],int mem_size)
{
		
}*/

void main()
{
	int process[10],proc_size,mem_size;
	struct memoryblock mem_block[10],temp;
	printf("Enter no:of processes:");
	scanf("%d",&proc_size);
	printf("Enter process sizes:");
	for(int i=0;i<proc_size;i++)
	{
		scanf("%d",&process[i]);
	}
	printf("Enter no:of memory blocks:");
	scanf("%d",&mem_size);
	printf("Enter memory blocks:");
	for(int i=0;i<mem_size;i++)
	{
		scanf("%d",&mem_block[i].size);
		mem_block[i].rem_size=mem_block[i].size;
		mem_block[i].pr_size=0;
	}
	for(int i=0;i<mem_size-1;i++)
	{
		for(int j=0;j<mem_size-i-1;j++)
		{
			if(mem_block[j].size<mem_block[j+1].size)
			{
				temp=mem_block[j];
				mem_block[j]=mem_block[j+1];
				mem_block[j+1]=temp;
			}
		}
	}
	for(int i=0;i<proc_size;i++)
	{
		for(int j=0;j<mem_size;j++)
		{
			if(process[i]<mem_block[j].rem_size)
			{
				mem_block[j].proc[mem_block[j].pr_size]=process[i];
				mem_block[j].pr_size++;
				mem_block[j].rem_size-=process[i];
				break;
			}
		}
	}
	for(int i=0;i<mem_size;i++)
	{
		printf("Block size: %d\n",mem_block[i].size);
		printf("Remaining size: %d\n",mem_block[i].rem_size);
		printf("Processes inside:");
		for(int j=0;j<mem_block[i].pr_size;j++)
		{
			printf("%d  ",mem_block[i].proc[j]);
		}
		printf("\n\n");
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
