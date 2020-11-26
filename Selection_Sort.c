#include <stdio.h>
#include <stdlib.h>

void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *arr,int length){
    for(int j = 0; j < length-1; j++){  //�]���j��j+1�}�l j�u�n�]��length-1���e��index�N�n
        for(int i = j+1; i < length; i++){
            int minIndex = j;
            if(arr[minIndex] > arr[i]){
                minIndex = i;
            }
            swap(&arr[minIndex],&arr[j]);
        }
    }
}


int main()
{
    printf("---Selection_Sort---\n");
    int arr[] = {9,8,7,1,2,3,55,4,128};
    int length = sizeof(arr)/sizeof(arr[0]);

    selectionsort(arr,length);

    for(int i = 0; i < length; i++){
        printf("%4d",arr[i]);
    }
    printf("\n");
    return 0;
}
