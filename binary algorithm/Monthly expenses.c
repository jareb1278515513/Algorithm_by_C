//月度开销
#include<stdio.h>
int search(int *,int ,int );
//函数功能：寻找最大开销的最小值
//变量声明：开销数组，天数，月数
//返回值：最大开销的最小值
int check(int *,int ,int );
//函数功能：检查某一最大开销下，最少可以分为多少组
//变量声明：开销数组，天数，最大开销
//返回值：分为组数的最小值
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int pay[n];
    for(int i=0;i<n;i++){
        scanf("%d",&pay[i]);
    }
    int expenses=search(pay,n,m);
    printf("%d",expenses);
}
int check(int *pay,int n,int mid){
    int sum=0,cnt=1;
    for(int i=0;i<n;i++){
        if(sum+pay[i]>mid){
            cnt++;
            sum=0;
        }
        sum+=pay[i];
    }
    return cnt;
}
int search(int pay[],int n,int m){
    int min=pay[0],max=0;
    for(int i=0;i<n;i++){
        max+=pay[i];
        if(pay[i]>min){
            min=pay[i];
        }
    }
    int l=min,r=max,mid,money;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(pay,n,mid)<=m){
            r=mid-1;
            money=mid;
        }else{
            l=mid+1;
        }
    }
    return money;
}
/*
描述
农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。
他计算出并记录下了接下来 N (1 ≤ N ≤ 100,000) 天里每天需要的开销。
约翰打算为连续的M (1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。
每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。
约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。

输入
第一行包含两个整数N,M，用单个空格隔开。
接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
输出
一个整数，即最大月度开销的最小值。
样例输入
7 5
100
400
300
100
500
101
400
样例输出
500
提示
若约翰将前两天作为一个月，第三、四两天作为一个月，最后三天每天作为一个月，则最大月度开销为500。
其他任何分配方案都会比这个值更大。
*/