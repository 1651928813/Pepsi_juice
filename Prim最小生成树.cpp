#include<stdio.h>
int map[100][100]={0};
int parent[100]; 
int end=1;
int n;
int min1,min2,min=1e5; 

void buildmap(){                                   //邻接矩阵存图信息 
	scanf("%d",&n);
	int i,j;
	scanf("%d",&i);
	int x,y,z;
	for(j=0;j<i;j++)
	{
		scanf("%d %d %d",&x,&y,&z);
		map[x][y]=z;
		map[y][x]=z;
	}
	for(int k=0;k<n;k++)
	parent[k]=-2;

} 

void Prim(int point)
{
	parent[point]=-1;
	while(end<n)                                  //while循环当加一个点时end+1 
	{
		int i,j;
		for(i=0;i<n;i++)
		{

			if(parent[i]!=-2)                              //当起点被访问时进行下步操作 
			{
				for(j=0;j<n;j++)
				{
					if(map[i][j]<=min&&map[i][j]>0&&parent[j]==-2)                 //记录最短且终点未被访问的边的信息 
					{ 
						min1=i;
						min2=j;
						min=map[i][j];
					}
				}	
			}
		}			
			parent[min2]=min1;                                          //加入最小生成树 
			end++;
			min=1e5;
	}
} 


int main()
{
	buildmap();

	int k;
	scanf("%d",&k);
	Prim(k);
	int i,j;
	printf("Prim法构造最小生成树：");
	for(i=0;i<n;i++)
	printf("%d-%d ",parent[i],i);                  //-前为父节点 后为子节点   -1代表无父节点 即此节点为根节点 
	printf("\n");

 } 
 /*
5
6
0 1 4
0 2 3
1 2 8
1 3 7
2 4 1
3 4 9
0
*/
