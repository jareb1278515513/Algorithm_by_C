//二分插入排序（升序） 
//时间复杂度：O(n^2)
#include<stdio.h>
void BinaryInsertSort(int a[],int n);
//函数功能：二分插入排序
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
	BinaryInsertSort(arr,n);
	printf("排序已完成\n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
void BinaryInsertSort(int a[],int n)
{
    int low,high,mid,temp;
    for(int i=0;i<n;i++)
    {
        low=0;
        high=i-1;
        mid=(low+high)/2;
        temp=a[i];
        while(high>=low)//high>=low继续寻找
        {
            if(temp>a[mid])//改变low和mid
            {
                low=mid+1;
                mid=(low+high)/2;
            }
            else//改变high和mid
            {
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        for(int j=i;j>low;j--)//把temp放到找到的位       
        {
            a[j]=a[j-1];
        }
        a[low]=temp;
    }
    return ;
}


/*
思路：	思想和插入排序是一样的，只是在寻找插入位置时不一样。普通插入排序在寻找插入位置时从已有序的序列从尾到头遍历寻找插入位置。这样的遍历就会浪费大量的时间去比较。
这里我们其实应该很容易就能想到这种优化思想。因为待插入的是有序序列。我们为何不用更快的方法来寻找插入位置呢。在查找中我们学习了二分查找。正是要在序列有序的情况下使用。所以我们也采用这种思想去寻找插入位置，可以大量减少比较时间。
*/