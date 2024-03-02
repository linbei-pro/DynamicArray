
#include <stdio.h>
#include <stdlib.h>

// 定义动态数组结构
struct DynamicArray {
    int *array;
    size_t size;
    size_t capacity;
};

// 初始化动态数组
void initDynamicArray(struct DynamicArray *arr, size_t capacity) {
    arr->array = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

// 在动态数组末尾添加元素
void pushBack(struct DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // 如果数组已满，扩展容量
        arr->capacity *= 2;
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
    }

    arr->array[arr->size++] = value;
}

// 释放动态数组内存
void freeDynamicArray(struct DynamicArray *arr) {
    free(arr->array);
}

int main() {
    // 使用动态数组
    struct DynamicArray myArray;
    initDynamicArray(&myArray, 5);

    pushBack(&myArray, 10);
    pushBack(&myArray, 20);
    pushBack(&myArray, 30);

    // 输出数组元素
    for (size_t i = 0; i < myArray.size; ++i) {
        printf("%d ", myArray.array[i]);
    }

    // 释放内存
    freeDynamicArray(&myArray);

    return 0;
}
