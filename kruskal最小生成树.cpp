#include<stdio.h>

int v[100];                     
int pn,en;                      //pointnumber:����  edgenumber :���� 
typedef struct                  //�ṹ���ߵ���Ϣ 
{
	int point1;
	int point2;
	int edge;
}map;
map m[100];


int create()                          //create������Ϣ���ڽṹ�������� 
{
	scanf("%d",&pn);
	int i;
	scanf("%d",&en);
	for(i=0;i<en;i++)
	{
		scanf("%d %d %d",&m[i].point1,&m[i].point2,&m[i].edge);
	}
	int j;
	for(i=0;i<en;i++)                  //�Աߴ�С�������� 
	{
		for(j=0;j<en-1-i;j++)
		{
			if(m[j].edge>m[j+1].edge)
			{
				map mm;
				mm=m[j];
				m[j]=m[j+1];
				m[j+1]=mm;
			}
		}
	}
}

int getroot(int x)
{
	if(v[x]==x)
	{
		return x;
	}
	return v[x]=getroot(v[x]);
}

int  kruskal()
{
	int i;
	for(i=0;i<pn;i++)
	{
		v[i]=i;
	}
	int num=pn;
	for(i=0;i<en&&num>1;i++)
	{
		int p1=getroot(m[i].point1);
		int p2=getroot(m[i].point2);
		if(p1!=p2)
		{
			v[p1]=p2;
			num--;
		}
	}
	for(i=0;i<en;i++)
	{
		if(v[m[i].point1]!=m[i].point1)
		printf("%d-%d\n",m[i].point1,m[i].point2);
	}
}


int main()
{
	create();
	kruskal();
} 
