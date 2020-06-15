#include<stdio.h>
#define n 5    //ͼ�ж��ٸ���
#define m 4     //ɫ��m
int count=0;    //�������� 
int color[n]={0};          //��i��������ŵ�����һ����ɫ 
int a[n][n]={0,1,1,1,0,      //a�����������ͼ���ڽӾ��� 
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
    if(t==n){    //n���㶼�Ѿ�����
        count++; 
        return;
    }
    for(int i=1;i<=m;i++){   //i������ɫ 
        oldvalue=color[t];
        color[t]=i;
        if(OK(t)){
            traceback(t+1);
        } 
        color[t]=oldvalue;
    } 
} 
             
int main(){
    traceback(0);   //t��������ͼ�Ķ��� 
    printf("%d\n",count); 
    return 0;
}

