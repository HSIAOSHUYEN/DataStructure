#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);
int partition1(int arr[],int front, int rear);
void quicksort(int arr[],int front,int rear);
int main()
{

    //quick sort  worst case => T(n) = T(n-1)+O(n)  , Best case T(n) = 2T(n/2) +O(n)
    printf("---Quick_Sort---\n");

    int arr[] = {2,8,7,1,3,5,6,4};
    int length = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < length; i++){
        printf("%4d ", arr[i]);
    }
    printf("\n");

    quicksort(arr,0,length-1);


    for(int i = 0; i < length; i++){
        printf("%4d ", arr[i]);
    }

    printf("\n");

    return 0;
}




int partition1(int arr[],int front, int rear){
    int j = front; //j去記錄比pivot大的index位置
    int i = j-1; //i紀錄比pivot小的index位址
    for(;j < rear; j++){
        if(arr[j] <= arr[rear]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[rear]);
    return (i+1);
}

void quicksort(int arr[],int front,int rear){
    if(front < rear){
        int pivot;

        pivot = partition1(arr,front,rear);

        quicksort(arr,front,pivot-1);
        quicksort(arr,pivot+1,rear);
    }
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
