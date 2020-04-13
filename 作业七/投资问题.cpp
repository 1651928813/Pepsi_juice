#include<stdio.h>
int m,n;
int x[10][10]={0};
int f(int x,int y)
{
	if(y==1)
	{	
	if(x>0)
	return x+10;
	else
	return 0;
    }
    else if(y==2)
    {
	if(x>1)
	return 5*x-5;
	else
	return 0;    	
	}
	else if (y==3)
	{
	if (x==1)
	return 2;
	else if(x==2)
	return 10;
	else if (x==3)
	return 30;
	else if(x==4)
	return 32;
	else if(x==5)
	return 40;
	else
	return 0;		
	}
	else if(y==4)
	{
	if(x>0)
	return x+19;
	else
	return 0;		
	}
}

int F(int m,int n){
	int i,j,k;
	int max=0,maxx=0;	
	if(m==0)
	{
		x[n][0]=0;
		return 0;
	}	
	else if (n==1)
	{
		x[1][m]=m;
		return f(m,1);
	}
	else
	{
		for (i=0;i<=m;i++)
		{
			if(f(i,n)+F(m-i,n-1)>max)
			{
				max=f(i,n)+F(m-i,n-1);
				maxx=i;
			}
		}
		x[n][m]=maxx;
		return max;
	}
	
	/*for (i=1;i<=n;i++)//第i项目 
	{
		for (j=0;j<=m;j++)//K个项目共 j元 
		{
			for(k=0;k<=j;k++)//第K个项目k元
			{
				if()
			} 
		}
	}*/
}
int main()
{
	scanf("%d %d",&m,&n);
	printf("总效益：%d\n",F(m,n));
	 int s;
	 int ss=m;
	 for(s=n;s>0;s--)
	 {
	 	printf("x%d = %d\n",s,x[s][ss]);
	 	ss=ss-x[s][ss];
	 }
}
