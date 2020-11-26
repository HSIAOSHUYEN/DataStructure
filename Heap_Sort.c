#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void max_heapify(int arr[], int start, int end) {
    // �إߤ��`�I���ЩM�l�`�I����
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // �Y�l�`�I���Цb�d�򤺤~�����
        if (son + 1 <= end && arr[son] < arr[son + 1]) // �Ĥ@��condtion�ˬd���S���k�S�� , �A�����Ӥl�`�I�j�p�A��̤ܳj��
            son++;
        if (arr[dad] > arr[son]) //�p�G���`�I�j��l�`�I�N��վ㧹���A�������X���
            return;
        else { // �_�h�洫���l���e�A�~��l�`�I�M�]�`�I��?
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    int i;
    // ��l�ơAi�q�̫�@�Ӥ��`�I�}�l�վ� �o�Obottom up
    for (i = len / 2 - 1; i >= 0; i--){
        max_heapify(arr, i, len - 1);
    }
    // ���N�Ĥ@�Ӥ����M�w�Ʀn�����e�@�찵�洫�A�A���s�վ�A����Ƨǧ���
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = {9,8,7,6,5,4,3};
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
//�L�X�}�C
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
