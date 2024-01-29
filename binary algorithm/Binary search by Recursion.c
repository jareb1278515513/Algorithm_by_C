/*
运用递归实现二分查找 
*/
#include<stdio.h>
int RecurBinarySearch( int a[] , int key , int left , int right ); 
int main(){
	int size,target;
	printf("请输入被查找数组大小："); 
	scanf("%d",&size);
	int a[size];
	printf("被数组为：\n"); 
	for(int i=0,j=1;i<size;i++,j++){
		a[i]=j;
		printf("%d ",a[i]);
	} 
	printf("\n请输入您要搜寻的数字：");
	scanf("%d",&target); 
	int x=RecurBinarySearch(a,target,0,size-1);
	if(x==-1){
		printf("不存在这个数字\n");
	}else{
		printf("他是第%d个数字\n",x+1);
	}
	return 0;
}
int RecurBinarySearch( int a[] , int key , int left , int right ) {
	if(left<=right){
		int mid=left+((right-left)/2);
		if(a[mid]>key){
			RecurBinarySearch(a,key,left,mid-1);
		}else if(a[mid]<key){
			RecurBinarySearch(a,key,mid+1,right);
		}else{
			return mid;
		}
	}else{
		return -1;
	}	
}
