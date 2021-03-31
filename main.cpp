#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 32
void MergeStep(int a[], int r[], int low, int mid, int high) {       //归并函数
	int i = low;
	int j = mid + 1;
	int m = mid;
	int n = high;
	int k = 0;
	while (i <= m && j <= n) {   //两个表都没结束时循环比较
		if (a[i] <= a[j])        //当较小的元素复制到R中
			r[k++] = a[i++];
		else
			r[k++] = a[j++];
	}
	while (i <= m)            
		r[k++] = a[i++];
	while (j <= n)
		r[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[low + i] = r[i];
}
void MergeSort(int a[],int r[], int low,int high){    
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(a, r, low,mid);
		MergeSort(a, r, mid+1, high);
		MergeStep(a, r,low, mid, high);
	}
}
int main(void) {
	int A[8] = { 1,5,8,6,2,4,3,7 };
	int* r;
	r = (int*)malloc(sizeof(int) * MAXVALUE);
	MergeSort(A,r,0,7);
	free(r);
	for (int i = 0; i < 8; i++) {
		printf("%d", A[i]);
	}
	system("pause");
}
