//N皇后问题
#include <stdio.h>
#include<math.h>
// int n;
// int queen[9];
void nq(int ,int ,int *);
int main(){
    int n;
    int queen[9];
    scanf("%d",&n);
    nq(0,n,queen);
    return 0;
}
void nq(int k,int n ,int *queen)//在前k-1行皇后已经摆好的情况下，摆第k行及其后的皇后
{
    if(k==n)
    {
        for(int i=0;i<k;i++){
            printf("%d",queen[i]+1);
            if(i==k-1){
                printf("\n");
            }else{
                printf(" ");
            }
        }
    }
    int j;
    for(int i=0;i<n;i++){
        for(j=0;j<k;j++){
            if(queen[j]==i||abs(k-j)==abs(queen[j]-i)){
                break;
            }
        }
            if(j==k){
                queen [k]=i;
                nq(k+1,n,queen);
        }
    }
}


