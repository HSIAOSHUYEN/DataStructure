#include <stdio.h>
#include <stdlib.h>
void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *arr,int length){
    for(int i = 0; i < length-1 ; i++){ //�`�@�]�X��
            int swaped = 0;              //�Y�@�뤧�����S��swap �h��0���X�j��
        for(int j = 0; j < length-1-i; j++){ //�C��������
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
