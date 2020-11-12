#include <stdio.h>

#if 0
void show(int arr[], int num){
    //降级/降级/退化
//    printf("show:%d\n", sizeof(arr));

    for (int i = 0; i < num; ++i) {
        printf("arr[%d]:%d, %p\n", i, *(arr+i), &arr[i]);
    }
}
int main() {
    int arr[] = {1,2,3,4,4,5,6};
    int num = sizeof(arr)/sizeof(arr[0]);
    show(arr, num);
    return 0;
}
#endif

void show(int arr[], int sz) {
    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }
}

//升序
void BubbleSort(int arr[], int sz) {
    int flag = 0;
    for (int j = 0; j < sz - 1; ++j) {
        for (int i = 0; i < sz - i - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    show(arr, sz);
    BubbleSort(arr, sz);
    printf("\n");
    show(arr, sz);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[0]+1);
    printf("%p\n", &arr +1);
    return 0;
}
