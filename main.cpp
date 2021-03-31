#include<stdio.h>
#include<stdlib.h>
void MergeStep(int a[], int r[], int s, int m, int n) {       //归并函数
	int i, j, k;
	k = i = s;
	j = m + 1;
	while (i <= m && j <= n) {   //两个表都没结束时循环比较
		if (a[i] <= a[j])        //当较小的元素复制到R中
			r[k++] = a[i++];
		else
			r[k++] = a[j++];
	}
	while (i <= m)            //将未合并的复制到R中
		r[k++] = a[i++];
	while (j <= n)
		r[k++] = a[j++];
}
void MergePass(int a[], int r[], int n, int len) {   //一遍合并
	int s, e;
	s = 0;
	while (s + len < n) {
		e = s + 2 * len - 1;
		MergeStep(a, r, s, s + len - 1, e);
		s = e + 1;
	}
	if (s < n) {
		for (; s < n; s++)
			r[s] = a[s];
	}
}
void MergeSort(int a[], int n) {    
	int* p;
	int len = 1;
	int f = 0;
	if (!(p = (int*)malloc(sizeof(int) * n))) {
		printf("分配临时内存失败！\n");
		exit(0);
	}
	while (len < n) {
		if (f)
			MergePass(p, a, n, len);
		else
			MergePass(a, p, n, len);
		len *= 2;
		f = 1 - f;
	}
	if (f) {
		for (f = 0; f < n; f++) {
			a[f] = p[f];
		}
		free(p);
	}
}
int main(void) {

	system("pause");
}