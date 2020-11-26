#include <stdio.h>
#include <stdlib.h>
void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *arr,int length){
    for(int i = 0; i < length-1 ; i++){ //總共跑幾趟
            int swaped = 0;              //若一趟之中都沒有swap 則為0跳出迴圈
        for(int j = 0; j < length-1-i; j++){ //每趟比較次數
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swaped = 1;
            }
        }
        if(swaped == 0){
            break;
        }
    }
}
int main()
{
    printf("---Bubble_sort---\n");
    int arr[] = {9,8,7,1,2,3,55,4,128};
    int length = sizeof(arr)/sizeof(arr[0]);

    bubblesort(arr,length);

    for(int i = 0; i < length; i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
}
