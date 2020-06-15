#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
 
const int N=4;
double minlen=10000,x[N],r[N];//分别为最小圆排列长度，每个圆心横坐标，每个圆半径
double minr[N];//最小圆排列的半径顺序
 

void compute()
{
	double low=0,high=0;
	for(int i=1;i<N;i++)
	{
		if(x[i]-r[i]<low)
			low=x[i]-r[i];
		if(x[i]+r[i]>high)
			high=x[i]+r[i];
	}
	if(high-low<minlen)
	{
		minlen=high-low;
		for(int i=1;i<N;++i)
			minr[i]=r[i];
	}
}
double get_location(int t)//求圆心坐标
{
	double tmp=0;
	for(int j=1;j<t;++j)
	{
		double xvalue=x[j]+2.0*sqrt(r[t]*r[j]);
		if(xvalue>tmp)
			tmp=xvalue;
	}
	return tmp;
}
void backtrack(int t)
{
	if(t==N)
	{
		compute();
	}
	else
	{
		for(int j=t;j<N;j++)
		{
			swap(r[t],r[j]);
			double get_locationx=get_location(t);
			if(get_locationx+r[t]+r[1]<minlen)
			{
				x[t]=get_locationx;
				backtrack(t+1);
			}
			swap(r[t],r[j]);
		}
	}
}
int main()
{
	r[1]=2,r[2]=5,r[3]=4;
	
	for(int i=1;i<N;++i)
		cout<<"r"<<i<<"="<<r[i]<<' ';
	cout<<endl;
	backtrack(1);
	cout<<"矩阵长度："<<minlen<<endl;
	cout<<"圆排列的顺序对应的半径分别为：";
	for(int i=1;i<N;++i)
		cout<<minr[i]<<' ';
	cout<<endl;
	return 0;
}
