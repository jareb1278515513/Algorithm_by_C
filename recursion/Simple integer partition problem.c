#include<stdio.h>
int partition(int ,int );
int main(){
    int n;
    int t=50;
    while(t--){
        scanf("%d",&n);
        printf("%d\n",partition(n,n));
    }
    return 0;
}
int partition(int n,int m){
    if(n<m){
        return partition(n,n);
    }
    if(n==0){
        return 1;
    }
    if(m==0){
        return 0;
    }
    return partition(n-m,m)+partition(n,m-1);
}
/*
简单的整数划分问题

描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。

输入
标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
输出
对于每组测试数据，输出N的划分数。
样例输入
5
样例输出
7
提示
5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
*/