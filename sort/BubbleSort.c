//冒泡排序 
//时间复杂度：O(n^2)
#include<stdio.h>
void BubbleSort(int *arr,int n);
//函数功能：选择排序
//参数说明：数组，数组中已有元素个数
void swap(int *a,int*b);
//函数功能：交换两个变量的值
//参数说明：两个变量的地址
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
	BubbleSort(arr,n);
	printf("排序已完成\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
void swap(int *a,int *b)//交换两个变量（位置）的值 
{
	int tem=*a;
	*a=*b;
	*b=tem;
}
void BubbleSort(int *arr,int n){
	for(int i=0;i<n-1;i++){//需要找n-1次最大值 
		for(int j=0;j<n-i-1;j++){//需要做n-j-1次比较 
			if(arr[j]>arr[j+1]){//将较大值后移 
				swap(&arr[j],&arr[j+1]);
			} 
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
	不断将前面的最大的数字移动到无序序列的最后一位
	若左边大于右边则交换，一趟排下来最大的在右边
*/