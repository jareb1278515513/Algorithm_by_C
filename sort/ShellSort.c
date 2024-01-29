//希尔排序 
//时间复杂度： O(n^2)
#include<stdio.h>
void ShellSort(int *arr,int n);
//函数功能：希尔排序
//参数说明：数组，数组中已有元素个数
int main(){
	int n;
	printf("请输入数组大小：");
	scanf("%d",&n);
	printf("请输入数组数据，用空格隔开\n");
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	ShellSort(arr,n);
	printf("排序已完成\n");
	return 0;
}
void ShellSort(int *arr,int n){
	int gap=n;
	while(gap>1){
		gap/=2;//每次对gap对折 
		for(int i=0;i<n-gap;i++){//单趟排序 
			int end=i;
			int tem=arr[end+gap];
			while(end>=0){
				if(tem<arr[end]){
					arr[end+gap]=arr[end];
					end-=gap;
				}else{
					break;
				}
			}
			arr[end+gap]=tem;
		}
		// //测试：输出每次排序后的情况
		// for(int i=0;i<n;i++){
		// 	printf("%d",arr[i]);
		// 	if(i!=n-1){
		// 		printf(" ");
		// 	}else{
		// 		printf("\n");
		// 	}
		// }
	}
}
/*
思路： 
希尔排序，先将待排序列进行预排序，使待排序列接近有序，然后再对该序列进行一次插入排序
*/
