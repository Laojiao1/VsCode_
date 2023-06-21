#include<iostream>
#include<assert.h>
using namespace std;

int bin_search(int* arr, int n, int x) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (x < arr[mid]) {
            right = mid;
        } else if (x > arr[mid]) {
            left = mid;
        } else
            return mid;
    }
    return -1;
}
int main() {
    int arr[100];
    printf("请输入数组元素个数：\n");
    int len = 0;
    scanf("%d", &len);
    printf("请输入数组元素：\n");
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    printf("请输入要查询的元素：\n");
    int num = -1;
    scanf("%d", &num);
    int pos = bin_search(arr, len, num);
    printf("该元素在数组中的位置为: %d", pos);
    return 0;
}