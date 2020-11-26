#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main()
{
    printf("Hello world!\n");
    int arr[] = {9,8,7,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
//----------------selection sort------------------
    for(int i = 0; i < n-1; i++){
        //int min = arr[i];
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
                //min = arr[j];
            }
        }
        swap(&arr[i],&arr[minIndex]);

    }

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
//----------------insertion sort

//    int arr2[] = {69  ,81  ,30  ,38   ,9   ,2  ,47  ,61  ,32  ,79};
//    int arr2Length = sizeof(arr2)/sizeof(arr2[0]);
//    for(int i = 1; i < arr2Length; i++){
//        for(int j = i; j > 0;j--){
//            if(arr2[j-1] <= arr2[j]){
//                break;
//            }
//            swap(&arr2[j-1],&arr2[j]);
//        }
//
//    }
//    for(int i = 0; i < arr2Length; i++){
//        printf("%d ",arr2[i]);
//    }

//----------------Bubble Sort
    int arr3[] = {69  ,81  ,30  ,38   ,9   ,2  ,47  ,61  ,32  ,79};
    int arr3Length = sizeof(arr3)/sizeof(arr3[0]);
    for(int i = 0; i < arr3Length; i++){
            int cond = 0;
        for(int j = 0; j <= arr3Length-1-i; j++){
            if(arr3[j] > arr3[j+1]){
                swap(&arr3[j],&arr3[j+1]);
                cond = 1;
            }
        }
        if(cond == 0){
            break;
        }
    }

    for(int i = 0; i < arr3Length; i++){
        printf("%d ",arr3[i]);
    }
//---------------quick sort



    return 0;

}

void swap(int *a, int*b){
    int  temp  = *a;
    *a = *b;
    *b = temp;
}
