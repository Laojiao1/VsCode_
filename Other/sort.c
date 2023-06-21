#include<stdio.h>
void sort(int array[],int n);
int main() { 
  	int a[100], n, i;
  	scanf("%d", &n);
  	for(i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }
  	sort(a, n);
  	for(i = 0; i < n; i++) {
    	printf("%d", a[i]);
	}
  	return 0;
}
void sort(int a[], int n) { 
	int i, j, k;
	int temp;
  	for(i = 0; i < n; i++) { 
	  	//k = i;
    	for(j = i+1; j < n; j++) {
      		if(a[i] < a[j]) {
        	//k = j;
    		temp = a[i];
    		a[i] = a[j];
    		a[j] = temp;
    		}
		}
    }
}