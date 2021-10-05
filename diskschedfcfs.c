#include<stdio.h>
#include<stdlib.h>
void main()
{
	int cyl[100],size,cyl_init,curr,seek_time=0,temp;
	printf("Enter initial cylinder:");
	scanf("%d",&cyl_init);
	curr=cyl_init;
	printf("Enter no:of cylinders needed:");
	scanf("%d",&size);
	printf("Enter cylinders:");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&cyl[i]);
	}
	printf("Seeking sequence is as follows:\n%d-->",curr);
	for(int i=0;i<size;i++)
	{
		seek_time+=abs(cyl[i]-curr);
		curr=cyl[i];
		printf("%d-->",cyl[i]);
	}
	printf("\nSeek time = %d\n",seek_time);
}
