//快速排序
//时间复杂度： O(n*log(n))
#include<stdio.h>
void quicksort(int *,int ,int );
//函数功能：快速排序
//变量说明：目标数组，起始位置，结尾位置

void swap(int *,int *);
//函数功能：交换两个变量的值
//参数说明：两个变量的地址

int main(){
    int n;
	printf("请输入数组大小：");
	scanf("%d",&n);
	printf("请输入数组数据，用空格隔开\n");
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("排序已完成\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

void quicksort(int *a,int s,int e){
    if(s>=e){
        return ;
    }
    int k=a[s];
    int i=s,j=e;
    while(i!=j){
        while(i<j && a[j]>=k){//此时 k=a[i]
            j--;
        }
        swap(&a[i],&a[j]);
        while(i<j && a[i]<=k){//此时 k=a[j]
            i++;
        }
        swap(&a[i],&a[j]);
    }//处理完后，k=a[i]=a[j]
    quicksort(a,s,i-1);
    quicksort(a,i+1,e);
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
/*
1）设k=a[0], 将k挪到适当位置，
   使得比k小的元素都在k左边,
   比k大的元素都在k右边，
   和k相等的，不关心在k左右出现均可 
   （O（n)时间完成）
2) 把k左边的部分快速排序
3) 把k右边的部分快速排序
*/