#include<stdio.h>
int map[100][100]={0};
int parent[100]; 
int end=1;
int n;
int min1,min2,min=1e5; 

void buildmap(){                                   //�ڽӾ����ͼ��Ϣ 
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
	while(end<n)                                  //whileѭ������һ����ʱend+1 
	{
		int i,j;
		for(i=0;i<n;i++)
		{

			if(parent[i]!=-2)                              //����㱻����ʱ�����²����� 
			{
				for(j=0;j<n;j++)
				{
					if(map[i][j]<=min&&map[i][j]>0&&parent[j]==-2)                 //��¼������յ�δ�����ʵıߵ���Ϣ 
					{ 
						min1=i;
						min2=j;
						min=map[i][j];
					}
				}	
			}
		}			
			parent[min2]=min1;                                          //������С������ 
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
	printf("Prim��������С��������");
	for(i=0;i<n;i++)
	printf("%d-%d ",parent[i],i);                  //-ǰΪ���ڵ� ��Ϊ�ӽڵ�   -1�����޸��ڵ� ���˽ڵ�Ϊ���ڵ� 
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
