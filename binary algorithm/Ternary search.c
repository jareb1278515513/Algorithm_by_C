#include <stdio.h>
int search(int *num,int l,int r,int target);
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
	int x=search(a,0,size-1,target);
	if(x==-1){
		printf("不存在这个数字\n");
	}else{
		printf("他是第%d个数字\n",x+1);
	}
	return 0;
}
int search( int *num,int l,int r,int target){
	if(r>=l){
        int midl=l+(r-l)/3;
        int midr=midl+(r-l)/3;
        if (num[midl] == target) return midl;
		if (num[midr] == target) return midr;
		if (num[midl] > target)
			return search(num, l, midl - 1, target);
		if (num[midr] < target)
			return search(num, midr + 1, r,target);
		return search(num, midl + 1, midr - 1, target);
    }
    return -1;
}
