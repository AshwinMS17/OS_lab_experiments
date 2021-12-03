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

int compare(int frames,int fr1,int fr2,int count[])
{
	if(count[fr1]<count[fr2])
	{
		return fr1;
	}
	return fr2;
}

int framefinder(int fr[],int frames,int pages[],int index,int count[])
{
	int find_frame=frames,find_page=index;
	//printf("\nfind is %d\n",find);
	for(int i=0;i<frames;i++)
	{
		int c=0;
        	for(int j=index-1;j>=0;j--)
		{
			if(fr[i]==pages[j])//removing find >j from if condition
			{
				c++;
			}
		}
        	if(c<find_page)
        	{
            		find_page=c;
            		find_frame=i;
        	}
        	else if(c==find_page)
        	{
            		find_frame=compare(frames,i,find_frame,count);//lr used of the two
        	}	
	}
	//printf("\nfound at %d\n",find);
	return find_frame;
}

void main()
{
	int pages[20];
	int size,frames,empty=0,miss=0,hit=0,fr[10],find,count[10],c=0,disp=0;
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
		count[i]=-1;
	}
	printf("\nFrames will be as follows:\n\n");
	for(int i=0;i<size;i++)
	{
		disp=0;
		if(search(fr,frames,pages[i])==0)
		{
			if(empty<frames)
			{
				fr[empty]=pages[i];
				count[empty]=c++;
				empty++;
				
			}
			else
			{
				find=framefinder(fr,frames,pages,i,count);
				fr[find]=pages[i];
				count[find]=c++;
				
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
			printf("Page Fault %d.",miss);
		}
		printf("\n");
	}
	printf("\nMiss=%d\n",miss);
	printf("Hit=%d\n",hit);
	
}
