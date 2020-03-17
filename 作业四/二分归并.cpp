#include<stdio.h>

int arr[8]={5,33,12,123,55,853,113,2333};
int mergearray(int a[], int left, int mid, int right, int temp[])  
{  
    int i = left;
	int j = mid + 1;  
    int m = mid;
	int n = right;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[left + i] = temp[i];  
}  

int mergesort(int a[], int left, int right, int temp[])  
{  
    if (left < right)  
    {  
        int mid = (left + right) / 2;  
        mergesort(a, left, mid, temp);     
        mergesort(a, mid + 1, right, temp); 
        mergearray(a, left, mid, right, temp); 
    }  
}  
 
int main()
{
	int *p=new int[8];
	int left=0;
	int right=7;
	mergesort(arr,0,7,p);
	delete[] p;
	for(int i=0;i<=7;i++)
	printf("%d ",arr[i]);
	
 } 
