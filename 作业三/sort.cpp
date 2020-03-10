#include<stdio.h>

int t[]={1,2,3,4,5,6,7,8,11,231,233};

int sort1(int x)
{
	int n=sizeof(t)/sizeof(int);
	int i;
	for(i=0;i<n;i++)
	{
		if(x==t[i])
		{
			printf("sort1:%d\n",i+1);
			break;
		}
		if(i==n-1)
		printf("sort1:0\n");
	}
 } 
 int sort2(int x)
 {
 	int n=sizeof(t)/sizeof(int);
 	int i,j;
 	i=0;
	j=n-1;
	while(i<=j)
	{
		if(x>t[(i+j)/2])
		{
			i=(i+j)/2+1;
		}
		else if(x<t[(i+j)/2])
		{
			j=(i+j)/2-1;
		}
		else
		{
			return (i+j)/2+1;
			break;
		}
    }
    return 0;
}
 int main()
 {
 	int k;
 	scanf("%d",&k);
 	sort1(k);
 	printf("sort2:%d",sort2(k));
 }
