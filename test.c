
#include <stdio.h>
#include <stdlib.h>

// ���嶯̬����ṹ
struct DynamicArray {
    int *array;
    size_t size;
    size_t capacity;
};

// ��ʼ����̬����
void initDynamicArray(struct DynamicArray *arr, size_t capacity) {
    arr->array = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

// �ڶ�̬����ĩβ���Ԫ��
void pushBack(struct DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // ���������������չ����
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
    }

    arr->array[arr->size++] = value;
}

// �ͷŶ�̬�����ڴ�
void freeDynamicArray(struct DynamicArray *arr) {
    free(arr->array);
}

int main() {
    // ʹ�ö�̬����
    struct DynamicArray myArray;
    initDynamicArray(&myArray, 5);

    pushBack(&myArray, 10);
    pushBack(&myArray, 20);
    pushBack(&myArray, 30);

    // �������Ԫ��
    for (size_t i = 0; i < myArray.size; ++i) {
        printf("%d ", myArray.array[i]);
    }

    // �ͷ��ڴ�
    freeDynamicArray(&myArray);

    return 0;
}
