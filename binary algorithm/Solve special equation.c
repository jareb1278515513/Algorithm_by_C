//求下面方程的根：f(x) = x3- 5x2+ 10x - 80 = 0。保留9位有效数字。
//已知函数f(x)在[0,100]区间上单调递增，且有唯一实根
#include <stdio.h>
#include <math.h>
#define EPS 1e-6
double f(double x){return x*x*x-5*x*x+10*x-80;}
int main(){
    double root,l=0,r=100,y;
    root=l+(r-l)/2;
    y=f(root);
    while(fabs(y)>EPS){
        if(y>0){
            r=root;
        }else{
            l=root;
        }
        root=l+(r-l)/2;
        y=f(root);
    }
    printf("%.8lf\n",root);
}