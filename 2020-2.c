#include <stdio.h>

#if 0
#include <unistd.h>
int main() {
    for (int i = 1; i <= 100; ++i) {
        if (0 == i % 3){
            printf("%d ", i);
        }
    }
    return 0;
}
#endif

#if 0
int main() {
    int max, mid, min;
    scanf("%d,%d,%d", &max, &mid, &min);
    if (max < mid) {
        int temp = max;
        max = mid;
        mid = temp;
    }
    if (mid < min) {
        int temp = mid;
        mid = min;
        min = temp;
    }
    printf("max=%d, mid=%d, min=%d\n", max, mid, min);
    return 0;
}
#endif

#if 0
int main() {
    int j;
    for (int i = 100; i <= 200; ++i) {
        for (j = 2; j <= i; ++j) {
            if (i%j==0) break;
        }
        if (i == j){
            printf("%d ", i);
        }
    }
    return 0;
}
#endif


#if 0
/*
 * 求两个数的最大公约数
 * 除数 % 被除数 = 商...余数
 * 除数【上一个的被除数】 % 被除数【余数】 = 商...余数
 * 除数 % 被除数 = 商...0
 */
int main() {
    int a = 24;//除数
    int b = 18;//被除数
    int c;//余数
    while (c = a % b) {
        a = b;
        b = c;
    }
    printf("%d\n", b);
    return 0;
}
#endif

//1.[]
void binsearch1(int arr[], int sz, int k){
    int left = 0;
    int right = sz-1;
    while (left <= right){
        int mid = (left+right)/2;
        if (arr[mid] > k){
            right = mid - 1;
        }else if (arr[mid] < k){
            left = mid + 1;
        }else{
            printf("arr下标是：%d\n", mid);
            break;
        }
    }
}

//2.[)
void binsearch2(int arr[], int sz, int k){
    int left = 0;
    int right = sz;
    while (left < right){
        int mid = (left+right)/2;
        if (arr[mid] > k){
            right = mid;
        }else if (arr[mid] < k){
            left = mid + 1;
        }else{
            printf("arr下标是：%d\n", mid);
            break;
        }
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    binsearch2(arr, sizeof(arr)/sizeof(arr[0]), 10);
    return 0;
}
