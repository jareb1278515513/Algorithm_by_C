//选择排序
//时间复杂度： O(n^2)
#include<stdio.h>
void SelectSort(int *arr,int n);
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
	SelectSort(arr,n);
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

//本函数同时选择最小值放在最前面，最大值放在最后面，提升效率 
void SelectSort(int *arr,int n)
{
	int begin=0,end=n-1;
	//保存参与单趟排序的第一个数字和最后一个数字
	while(begin<end){
		//保存最大值下标
		int maxi=begin;
		//保存最小值下标
		int mini=begin;
		//找出最大值和最小值下标
		for(int i=begin;i<=end;i++){
			if(arr[i]<arr[mini]){
				mini=i;
			}
			if(arr[i]>arr[maxi]){
				maxi=i;
			}
		}
		//将最小值放在序列头
		swap(&arr[mini],&arr[begin]);
		//防止最大值在begin位置时被换走
		if(maxi==begin){
			maxi=mini;
		}
		//最大值放结尾
		swap(&arr[end],&arr[maxi]);
		//改变开始和结尾位置
		begin++;
		end--; 
		
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
	每次从待排序列中选出一个最小值，然后放在序列的起始位置，直到全部待排数据排完即可。
	实际上，我们可以一趟选出两个值，一个最大值一个最小值，然后将其放在序列开头和末尾，这样可以使选择排序的效率快一倍。
*/