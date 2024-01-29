//输出前k大的数
//思路：把前k大的数字放在数组最右边，然后将他们排序
#include<stdio.h>
void swap(int *,int *);
void quicksort(int *,int ,int );
void arrangeRight(int *,int,int,int);
//参数说明：数组，起点，终点，k
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    scanf("%d",&k);
    arrangeRight(a,0,n-1,k);
    quicksort(a,n-k,n-1);
    for(int i=n-1;i>=n-k;i--){
        printf("%d\n",a[i]);
    }
    return 0;
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void quicksort(int *a,int s,int e){
    if(s>=e){
        return ;
    }
    int k=a[s],i=s,j=e;
    while(i!=j){
        while(i<j && a[j]>=k){
            j--;
        }
        swap(&a[j],&a[i]);
        while(i<j && a[i]<=k){
            i++;
        }
        swap(&a[j],&a[i]);
    }
    quicksort(a,s,i-1);
    quicksort(a,i+1,e);
}
void arrangeRight(int *a,int s,int e,int k){
    if(s>=e){
        return ;
    }
    int key=a[s];
    int i=s,j=e;
    while(i!=j){
        while(i<j && a[j]>=key){
            j--;
        }
        swap(&a[j],&a[i]);
        while(i<j && a[i]<=key){
            i++;
        }
        swap(&a[j],&a[i]);
    }
    int num=e-i+1;
    if(num==k){
        return ;
    }else if(num>k){
        arrangeRight(a,i+1,e,k);
    }else{
        arrangeRight(a,s,i-1,k-num);
    }
}

/*
描述
给定一个数组，统计前k大的数并且把这k个数从大到小输出。

输入
第一行包含一个整数n，表示数组的大小。n < 100000。
第二行包含n个整数，表示数组的元素，整数之间以一个空格分开。每个整数的绝对值不超过100000000。
第三行包含一个整数k。k < n。
输出
从大到小输出前k大的数，每个数一行。
样例输入
10
4 5 6 9 8 7 1 2 3 0
5
样例输出
9
8
7
6
5
*/