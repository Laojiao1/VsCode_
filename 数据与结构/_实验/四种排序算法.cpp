#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//产生随机数组
void gen_array(int arr[],int n)
{
    int i;
    unsigned sr = time(NULL);  //用当前时间做随机数种子
    srand(sr);          //初始化随机数
    for(i=0;i<n;i++)
        arr[i]=1+rand()%100;
}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%6d",a[i]);
    printf("\n");
}

//冒泡排序
void BubleSort(int a[],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)   
    {
        for(j=1;j<n-i;j++) 
        {
            if(a[j-1]>a[j]) 
            {
                x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
            }
        }
    }
}

//快速排序
void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int i = left, j = right, x = a[left];
        while (i < j)
        {
            while(i < j && a[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                a[i++] = a[j];

            while(i < j && a[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                a[j--] = a[i];
        }
        a[i] = x;
        QuickSort(a, left, i - 1); // 递归调用 
        QuickSort(a, i + 1, right);
    }
}

//插入排序
void InsertSort(int arr[], int n)
{
    int i,j,temp;
    for (i = 1; i < n; i++)    
    {   
        temp=arr[i];
        j=i;
        while(j>0 && arr[j-1]>temp)
            {
                arr[j] = arr[j-1];
                j--;
            }
        arr[j]=temp;
    }   

}

//选择排序
void SelectSort(int arr[],int n)
{
    int i,j,k,temp;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[k]) k = j;
        }
        if(k>i)
        {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

int main()
{
    int array[10];
    int len = sizeof(array)/sizeof(int);
    int ch;
    while(1)
    {
        gen_array(array,len);
        printf("Original array:\n");
        print(array,len);
        printf("Please select sort method:\n");//显示菜单
        printf("\t0 exit\n\t1 Buble sort\n\t2 Quick Sort\n\t3 Insertion Sort\n\t4 Selection Sort\nYour choice is>>");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            return 0;
        case 1:
            BubleSort(array,len);
            printf("Buble sorted array:\n");
            print(array,len);
            break;
        case 2:
            QuickSort(array,0,len-1);
            printf("Quick sorted array:\n");
            print(array,len);
            break;
        case 3:
            InsertSort(array,len);
            printf("Insertion sorted array:\n");
            print(array,len);
        case 4:
            SelectSort(array,len);
            printf("Selection sorted array:\n");
            print(array,len);
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}