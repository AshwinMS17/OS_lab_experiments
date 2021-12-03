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

int compare(int fr[],int frames,int pages[],int index,int fr1,int fr2)
{
    int ifr1=-1,ifr2=-1;
    for(int i=index-1;i>=0;i--)
    {
        if(ifr1==-1&&fr[fr1]==pages[i])
        {
            ifr1=i;
        }
        if(ifr2==-1&&fr[fr2]==pages[i])
        {
            ifr2=i;
        }
    }
    if(ifr1<ifr2)
    {
        return ifr1;
    }
    return ifr2;
}

int framefinder(int fr[],int frames,int pages[],int index)
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
            find_frame=compare(fr,frames,pages,index,i,find_frame);//lr used of the two
        }	
	}
	//printf("\nfound at %d\n",find);
	return find_frame;
}

void main()
{
	int pages[20];
	int size,frames,empty=0,miss=0,hit=0,fr[10],find;
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
		if(search(fr,frames,pages[i])==0)
		{
			if(empty<frames)
			{
				fr[empty]=pages[i];
				empty++;
			}
			else
			{
				find=framefinder(fr,frames,pages,i);
				fr[find]=pages[i];
			}
			miss++;	
		}
		else
		{
			hit++;
		}
		//printf("%d-- ",i);
		for(int j=0;j<frames;j++)
		{
			if(fr[j]==-1)
			{
				printf("--  ");
			}
			else
			{
				printf("%d  ",fr[j]);
			}
		}
		printf("\n");
	}
	printf("\nMiss=%d\n",miss);
	printf("Hit=%d\n",hit);
	
}
