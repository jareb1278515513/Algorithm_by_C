//归并排序
//时间复杂度： O(n*log(n))
#include<stdio.h>
void merge(int *,int ,int ,int *);
//函数功能：将无序数组分为前后两部分，分别排序，再将其合并
//参数声明：目标数组，起始位置，结束位置，过渡数组 

void sort(int *,int ,int ,int ,int *);
//函数功能：有序合并两部分有序数组
//参数声明：目标数组，起始位置，中间位置，结束位置，过渡数组

int main(){
    int a[10]={17,16,3,31,47,10,2,9,20,4,};
    int tmp[10];
    int size=sizeof(a)/sizeof(a[0]);
    merge(a,0,size-1,tmp);
    for(int i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void merge(int *a,int s,int e,int *tmp){
    if(s<e){
        int m=s+(e-s)/2;
        //将数组分为前后两个部分
        merge(a,s,m,tmp);
        merge(a,m+1,e,tmp);
        
        //合并
        sort(a,s,m,e,tmp);

    }
}
void sort(int *a,int s,int m,int e,int *tmp){
    int pb=0;
    int p1=s,p2=m+1;
    while(p1<=m&&p2<=e){
        if(a[p1]>a[p2]){
            tmp[pb++]=a[p2++];
        }else{
            tmp[pb++]=a[p1++];
        }
    }
    
    //处理剩下未合并的元素
    while(p1<=m){
        tmp[pb++]=a[p1++];
    }
    while(p2<=e){
        tmp[pb++]=a[p2++];
    }

    for(int i=0;i<e-s+1;i++){
        a[s+i]=tmp[i];//注意这里的角标
    }
}

/*
思路：
1）把前一半排序
2）把后一半排序
3）把两半归并到一个新的有序数组，然后再拷贝回原数组，完成排序
*/