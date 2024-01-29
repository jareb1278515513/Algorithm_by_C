#include<stdio.h>
#include<stdlib.h>
//快速排序
//https://blog.csdn.net/qq_74009838/article/details/128078803
int cmp_int (const void* elem1,const void* elem2)//比较函数
{
    return *(int *)elem1-*(int *)elem2;
}
// 快速排序函数
// qsort(void* base, size_t num, size_t size, int (*comparator)(const void* elem1, const void* elem2));
// qsort（）函数需要四个参数
// 1. void* base:  需排序数组首元素
// 2. size_t num: 数组元素个数
// 3. size_t size: 一个数组元素大小（byte）
// 4. int (*comparator) (const void* elem1 , const void* elem2):  是一个函数指针，其指向的是一个比较函数的地址，该函数有两个void* 的参数，其返回类型为int 。

int judge(int ,int ,int*,int);
//函数功能:判断在某个间隔下，能否放得下所有牛
//参数声明：栅栏数量，牛的数量，栅栏位置数组,间隔大小
//返回值：1->可放下，2->不可放下
int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int stall[n];
    for(int i=0;i<n;i++){
        scanf("%d",&stall[i]);
    }
    qsort(stall,n,sizeof(stall[0]),cmp_int);
    int l=1,r=(stall[n-1]-stall[0]/(c-1));
    int mid,res=1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(judge(n,c,stall,mid)){
            l=mid+1;
            res=mid;   
        }else{
            r=mid-1;
        }
    }
    printf("%d",res);
    return 0;
}
int judge(int n,int c,int stall[],int d){
    int num=1,tmp=stall[0];
    for(int i=1;i<n;i++){
        if(stall[i]-tmp>=d){
            num++;
            tmp=stall[i];
        }
    }
    if(num>=c){
        return 1;
    }else{
        return 0;
    }
}

/*
描述
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
 The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout 
and become aggressive towards each other once put into a stall.
 To prevent the cows from hurting each other, 
 FJ want to assign the cows to the stalls, 
 such that the minimum distance between any two of them is as large as possible.
  What is the largest minimum distance?
输入
* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 contains an integer stall location, xi
输出
* Line 1: One integer: the largest minimum distance
样例输入
5 3
1
2
8
4
9
样例输出
3
提示
OUTPUT DETAILS:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

Huge input data,scanf is recommended.
*/