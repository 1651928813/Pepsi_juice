#include<stdio.h>

int p[11]={0};
int len;
int m[10][10]={0};
int s[10][10]={0};

int RecurMatrixChain(int p[],int i,int j)  //æÿ’Û¡¥≥À∑®µ›πÈ µœ÷ 
{
	if (i==j)
	{
		s[i][j]=i;
		m[i][j]=0;
		return m[i][j];
	}
	int q;
	m[i][j]=1e5;
	s[i][j]=i;
	int k;
	for(k=i;k<=j-1;k++)
	{
		q=RecurMatrixChain(p,i,k)+RecurMatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];
	
	if(q<m[i][j])
	{
		m[i][j]=q;
		s[i][j]=k;
	}
	}
	return m[i][j];
 } 

int main()
{
	scanf("%d",&len);
	
	for (int i=0;i<=len;i++)
	{
		scanf("%d",&p[i]);
	}
	int end;
	end=RecurMatrixChain(p,1,len);
	printf("%d",end);
 } 
/*
4
5 25 10 20 15
*/
