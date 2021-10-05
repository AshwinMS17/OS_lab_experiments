#include<stdio.h>
#include<string.h>

int search(int ar[],int size,int s)
{
	int n=0;
	for(int i=0;i<size;i++)
	{
		if(ar[i]==s)
		{
			n=1;
		}
	}
	return n;
}

void main()
{
	int pages[20];
	int size,frames,empty=0,first=-1,miss=0,hit=0,fr[10],disp=0;
	printf("Enter no:of pages:");
	scanf("%d",&size);
	printf("Enter page string:");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&pages[i]);
	}
	printf("\n");
	printf("Enter no:of frames:");
	scanf("%d",&frames);
	for(int i=0;i<frames;i++)
	{
		fr[i]=-1;
	}
	for(int i=0;i<size;i++)
	{
		disp=0;
		if(search(fr,frames,pages[i])==0)
		{
			if(empty<frames)
			{
				if(empty==0)
				{
					first++;
				}
				fr[empty]=pages[i];
				empty++;
			}
			else
			{
				fr[first]=pages[i];
				first=(first+1)%frames;
			}
			miss++;	
			disp=1;
		}
		else
		{
			hit++;
		}
		for(int j=0;j<frames;j++)
		{
			if(fr[j]==-1)
			{
				printf("-  ");
			}
			else
			{
				printf("%d  ",fr[j]);
			}
		}
		if(disp==1)
		{
			printf("   Page Fault %d.\n",miss);
		}
		else
		{
			printf("\n");
		}
	}
	printf("\nMiss=%d\n",miss);
	printf("Hit=%d\n",hit);
	
}


//output
/*
Enter no:of pages:13
Enter page string:8
4
6
4
3
5
8
4
3
2
3
5
8

Enter no:of frames:4
8  empty  empty  empty  
8  4  empty  empty  
8  4  6  empty  
8  4  6  empty  
8  4  6  3  
5  4  6  3  
5  8  6  3  
5  8  4  3  
5  8  4  3  
5  8  4  2  
3  8  4  2  
3  5  4  2  
3  5  8  2  */















	

