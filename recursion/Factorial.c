//求小于等于给定数字的阶乘的和
#include <stdio.h> 
int factorial(int n);
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=factorial(i);
    }
    printf("%d",sum);
    return 0;
}
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}