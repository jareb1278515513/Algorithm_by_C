#include <stdio.h>
int put (int ,int );
int main(){
    int t,m,n;
    scanf("%d",&t);
    while(t--){
        scanf ("%d %d",&m,&n);
        printf("%d\n",put (m,n));
    }
}
int put(int a,int p){
    if(a==0){
        return 1;
    }
    if(p==0){
        return 0;
    }
    if(a<p){
        return put(a,a);
    }
    return put (a,p-1)+put(a-p,p);
}
/*
描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入
第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出
对输入的每组数据M和N，用一行输出相应的K。
*/