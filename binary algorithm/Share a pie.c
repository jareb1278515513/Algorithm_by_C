#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
#define EPS 1e-6
int judge(int ,int ,double ,int *);
//函数功能：判断是否能够分派
//参数声明：分派的人数，每人分得的派的大小，派的数量，所有派大小的数组
//返回值：1->可分，2->不可分
double share(int *,int ,int);
//函数功能：利用二分法分派
//参数声明：所有派大小的数组，派的数量，分派的人数

int main(){
    int n,f;
    scanf("%d %d",&n,&f);
    f++;
    int pie[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        pie[i]=x*x;
    }
    double res=share(pie,n,f);
    printf("%.3lf",res);
}
int judge(int n,int f,double mid,int *pie){
    int count =0,i=0;
    for(int i=0;i<n;i++){
        count+=(int)pie[i]*PI/mid;
    }
    if(count>=f){
        return 1;
    }else{
        return 0;
    }
}
double share(int *pie,int n,int f){
    double sum=0;
    for(int i=0;i<n;i++){
        sum+=pie[i]*PI;
    }
    double res,l=0,r=sum/f,mid;
    mid=l+(r-l)/2;
    res=mid;
    while(1){
        if(r-l<EPS){
            return res;
        }
        mid=l+(r-l)/2;
        if(judge(n,f,mid,pie)==1){
            l=mid;
            res=mid;
        }else {
            r=mid;
        }
    }
    
}

/*
描述
我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。
有F个朋友会来参加我的派对，每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。
我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。
因此所有人拿到的派是同样大小的（但不需要是同样形状的），虽然这样有些派会被浪费，但总比搞砸整个派对好。
当然，我也要给自己留一块，而这一块也要和其他人的同样大小。
请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。

输入
第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
第二行包含N个1到10000之间的整数，表示每个派的半径。
输出
输出每个人能得到的最大的派的体积，精确到小数点后三位。
样例输入
3 3
4 3 3
样例输出
25.133
*/