#include<stdio.h>
void hanoi(int n,char src,char mid ,char dest);
int main(){
    int n;
    char a,b,c;
    scanf("%d %c %c %c",&n,&a,&b,&c);
    hanoi(n,a,b,c);
    return 0;
}
void hanoi(int n ,char src, char mid , char dest)
{
    if(n==1)
    {
        printf("%d:%c->%c\n",n,src,dest);
        return ;
    }
    hanoi(n-1,src,dest,mid);
    printf("%d:%c->%c\n",n,src,dest);
    hanoi(n-1,mid,src,dest);
    return ;
}
/*
输入
输入为一个整数后面跟三个单字符字符串。
整数为盘子的数目，后三个字符表示三个杆子的编号。
输出
输出每一步移动盘子的记录。一次移动一行。
每次移动的记录为例如3:a->b 的形式，即把编号为3的盘子从a杆移至b杆。
我们约定圆盘从小到大编号为1, 2, ...n。即最上面那个最小的圆盘编号为1，最下面最大的圆盘编号为n。
*/