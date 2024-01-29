#include<stdio.h>
int climb(int );
int main(){
   int n;
   scanf("%d",&n);
   while(n){
        printf("%d\n",climb(n)) ;
        scanf("%d",&n);
   }
    return 0;
}
int climb(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return climb(n-1)+climb(n-2);
}
/*
树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数
例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级
也可以第一次走两级，第二次走一级，一共3种方法。

输入:
输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30,最后输入0结束程序。
输出:
不同的走法数，每一行输入对应一行输出
*/