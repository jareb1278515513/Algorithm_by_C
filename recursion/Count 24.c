#include<stdio.h>
#include<math.h>
#define EPS 1e-6
int isZero(double);
int count24(double a[],int n);
int main()
{
    double a[5];
    scanf("%lf %lf %lf %lf",&a[0],&a[1],&a[2],&a[3]);
    while(a[0]!=0)
    {
        if(count24(a,4)==1)
        {
            printf("YES\n");
        }else
        {
            printf("NO\n");
        }
        scanf("%lf %lf %lf %lf",&a[0],&a[1],&a[2],&a[3]);
    }
    return 0;
}
int isZero(double x)
{
    if(fabs(x)<=EPS)
    {
        return 1;
    }else
    {
        return 0;
    }
}
int count24(double a[],int n)//从所给的数组a中的n个数字，计算24
{
    if(n==1)
    {
        if(isZero(a[0]-24))
        {
            return 1;
        }else
        {
            return 0;
        }
    }
    double b[5];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)//枚举两个数的组合
        {
            int m=0;//还剩下m个数，m=n-2
            for(int k=0;k<n;k++)
            {
                if(k!=i&&k!=j)
                {
                    b[m++]=a[k];//把其余数字都放进数组b
                }
            }

            b[m]=a[i]+a[j];
            if(count24(b,m+1))
            {
                return 1;
            }

            b[m]=a[i]-a[j];
            if(count24(b,m+1))
            {
                return 1;
            }

            b[m]=a[j]-a[i];
            if(count24(b,m+1))
            {
                return 1;
            }

            b[m]=a[i]*a[j];
            if(count24(b,m+1))
            {
                return 1;
            }

            if(!isZero(a[j]))
            {
                b[m]=a[i]/a[j];
                if(count24(b,m+1))
                {
                    return 1;
                }
            }

            if(!isZero(a[i]))
            {
                b[m]=a[j]/a[i];
                if(count24(b,m+1))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
/*
描述
给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。

这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。

比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
输入
输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
输出
对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
样例输入
5 5 5 1
1 1 4 2
0 0 0 0
样例输出
YES
NO
*/