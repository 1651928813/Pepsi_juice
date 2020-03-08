#include<stdio.h>

int a[10][10],p[10][10];    //a邻接矩阵存两点距离   p存两点之间最短路径上经过的第一个点 
int n;                      //点数量

int init()                        //初始化邻接矩阵 
{
	int m;
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	    	a[i][j]=1000;
	    	p[i][j]=-1;
	    	if(i==j)
			{
				a[i][j]=0;
				p[i][j]=i;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		a[x][y]=z;
		p[x][y]=y;
	}
} 

int min(int x,int y)
{
	if(x<y)
	return x;
	else 
	return y;
}
int floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][k]+a[k][j]==min(a[i][j],a[i][k]+a[k][j]))
				{
					a[i][j]=a[i][k]+a[k][j];
					p[i][j]=k;
				}	
			}
		}
	}
	
 } 


int main()
{
	init();
	floyd();
	int x,y;
	for(x=1;x<=4;x++)
	{
		for(y=1;y<=4;y++)
		{
			printf("%d ",a[x][y]);
		}
		printf("\n");
	 } 
} 
/*
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
