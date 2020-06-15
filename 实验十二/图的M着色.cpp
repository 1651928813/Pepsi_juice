#include<stdio.h>
#define n 5    //图有多少个点
#define m 4     //色数m
int count=0;    //方案数量 
int color[n]={0};          //第i个点里面放的是哪一种颜色 
int a[n][n]={0,1,1,1,0,      //a数组代表无向图的邻接矩阵 
             1,0,1,1,1,
             1,1,0,1,0,
             1,1,1,0,1,
             0,1,0,1,0};

bool OK(int t){
    for(int j=0;j<n;j++){
        if(a[t][j]==1){
            if(color[t]==color[j])
                return false;
        } 
    } 
    return true;
} 
        
void traceback(int t){
int oldvalue=0;
    if(t==n){    //n个点都已经走完
        count++; 
        return;
    }
    for(int i=1;i<=m;i++){   //i代表颜色 
        oldvalue=color[t];
        color[t]=i;
        if(OK(t)){
            traceback(t+1);
        } 
        color[t]=oldvalue;
    } 
} 
             
int main(){
    traceback(0);   //t代表无向图的顶点 
    printf("%d\n",count); 
    return 0;
}

