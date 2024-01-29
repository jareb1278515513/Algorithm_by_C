//插入排序（升序） 
//时间复杂度：O(n^2)
#include<stdio.h>
void InsertSort(int a[],int n);
//函数功能：插入排序
//参数说明：数组，数组中已有元素个数 
int main()
{
	int n;
	printf("请输入数组大小：");
	scanf("%d",&n);
	printf("请输入数组数据，用空格隔开\n");
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	InsertSort(arr,n);
	printf("排序已完成\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

void InsertSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int end=i;//end表示有序序列的最后元素下标 
		int tem=a[end+1];//tem为待插入元素 
		
		//单趟排列 
		while(end>=0){
			if(tem<a[end]){//比插入的数字大就向后移动 
				a[end+1]=a[end];
				end--;
			}else{//比插入的数字小，不变化 
				break;
			}
		}
		a[end+1]=tem;//将tem放在比其小的数字之前 
		
		//测试：输出每次排序后的情况
		// for(int i=0;i<n;i++){
		// 	printf("%d",a[i]); 
		// 	if(i==n-1){
		// 		printf("\n");
		// 	}else{
		// 		printf(" ");
		// 	}
		// } 
	}
}
/*
思路：
	在待排序的元素中，假设前n-1个元素已有序，现将第n个元素插入到前面已经排好的序列中，使得前n个元素有序。按照此法对所有元素进行插入，直到整个序列有序。
	但我们并不能确定待排元素中究竟哪一部分是有序的，所以我们一开始只能认为第一个元素是有序的，依次将其后面的元素插入到这个有序序列中来，直到整个序列有序为止。
*/
