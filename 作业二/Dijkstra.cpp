#include<stdio.h>

int map[10][10];                 //�ڽӾ�������Ϣ 
int n;                           //������ 
int dis[10];                  //��A����ĵ�ľ�����ڸ������� 
int min,minp;
int visit[10]={0};

int init()                     //��ʼ���ڽӾ��� 
{
	int m;
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	    	map[i][j]=1000;
	    	if(i==j)
			{
				map[i][j]=0;
			}
		}
		if(i!=1)
		dis[i]=1000;
		else 
		dis[i]=0;
		
	}
	for(i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		map[x][y]=z;
		if(x==1)
		dis[y]=z;
	}
} 

int Dijkstra()                                   
{
	int i,j;
	int k=1;
	for(i=1;i<=n;i++)
	{
		min=1000;
		for(j=1;j<=n;j++)
		{
			if(visit[j]==0&&dis[j]<min)
			{
				min=dis[j];
				minp=j;
			}
		}
		visit[minp]=1;
		int k;
		for(k=1;k<=n;k++)
		{
			if(visit[k]==0&&dis[k]>dis[minp]+map[minp][k]&&map[minp][k]<1000)
			{
				dis[k]=dis[minp]+map[minp][k];
			}
		}
	} 
	
}

int main()
{
    init();	
    Dijkstra();
    printf("a->h:%d\n",dis[8]);
 } 
 
 /*
8
11
1 2 1
2 4 2
4 3 1
3 1 2
5 4 2
6 5 2
4 6 8
5 7 2
7 6 3
8 6 2
7 8 3
*/
