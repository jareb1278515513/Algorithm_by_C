/*
二分查找有两种基本写法
	1、[左闭，右闭]  
		在while循环条件要使用while(left <= right)，
		因为当(left == right)这种情况发生的时候，得到的结果是有意义的
				if(nums[middle] > target) ， right 要赋值为 middle - 1，
		因为当前的 nums[middle] 一定不是 target ，需要把这个 middle 位置上面的数字丢弃，
		那么接下来需要查找范围就是[left, middle - 1]
	
	2、[左闭右开)
	循环条件使用while (left < right)
	
	if (nums[middle] > target)， right = middle，
	因为当前的 nums[middle] 是大于 target 的，不符合条件,不能取到 middle，
	并且区间的定义是 [left, right)，刚好区间上的定义就取不到 right, 所以 right 赋值为 middle。
*/
#include<stdio.h>
int search(int *num,int size,int target);
int main(){
	int size,target;
	printf("请输入被查找数组大小："); 
	scanf("%d",&size);
	int a[size];
	printf("目标数组为：\n"); 
	for(int i=0,j=1;i<size;i++,j++){
		a[i]=j;
		printf("%d\t",a[i]);
	} 
	printf("\n请输入您要搜寻的数字：");
	scanf("%d",&target); 
	int x=search(a,size,target);
	if(x==-1){
		printf("不存在这个数字\n");
	}else{
		printf("他是第%d个数字\n",x+1);
	}
	return 0;
}
int search( int *num , int size , int target ){//nums是数组，size是数组的大小，target是需要查找的值
	int left = 0; 
	int right = size - 1;// 定义了target在左闭右闭的区间内，[left, right]
	while( left <= right ){//当left == right时，区间[left, right]仍然有效
		int middle = left + (( right - left ) /2 );//等同于 (left + right) / 2，防止溢出！！！！
		if( num[middle] > target ){
			right = middle -1;//target在左区间，所以[left, middle - 1]
		}else if( num[middle] < target ){
			left = middle + 1;//target在右区间，所以[middle + 1, right]
		}else{
			return middle;//既不在左边，也不在右边，那就是找到答案了
		}
	}
	//没找到 
	return -1;
}
