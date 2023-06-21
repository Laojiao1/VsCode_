#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int a[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
void insert_sort(int arr[], int len) {
	for(int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && key < arr[j]) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
void bubble_sort(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}
int b[N];
void msort(int l, int r) {
	if(l == r) return;
	int mid = (l+r) >> 1;
	int i = l, j = mid+1, k = l;
	msort(l, mid);
	msort(mid+1, r);
	while(i <= mid && j <= r) {
		if(a[i] <= a[j]) {
			b[k++] = a[i++];
		} else {
			b[k++] = a[j++];
		}
	}
	while(i <= mid) b[k++] = a[i++];
	while(j <= r) b[k++] = a[j++];
	for(int i = l; i <= r; i++) {
		a[i] = b[i];
	}
}
void qsort(int l, int r) { 
	int mid = a[(l+r) >> 1];
	int i = l, j = r;
	do {
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		} 
	} while(i <= j);
	if(l < j) qsort(l, j);
	if(r > i) qsort(i, r);
}

int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    //bubble_sort(arr, len);
    //for (int i = 0; i < len; i++)
    //    printf("%d ", arr[i]);
    //msort(0, len-1);
    qsort(0, len-1);
    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    return 0;
}

