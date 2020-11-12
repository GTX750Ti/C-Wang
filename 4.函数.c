//
// Created by iTurning on 2020/11/5.
//
#include <stdio.h>

/*
 * 将src拷贝到dst中
 */
//#include <string.h>
//int main(){
//    char src[] = "hello world";
//    char dst[64];
//    strcpy(dst, src);
//    printf("%s\n", src);
//    return 0;
//}

/*
 * memset：只关注内存，不关注类型；设置时以字节为单位
 */
//#include <memory.h>

//void swap(int *x, int *y){
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//
//int main(){
////    void *xp = NULL;
////    int a = 10;
////    double d = 3.14;
////    char c = 'c';
////    xp = &a;
////    xp = &d;
////    xp = &c;
//
//    char a[10];
//    int b[10];
//    double c[10];
//
//    memset(a, 0, sizeof(a));
//    memset(b,0, sizeof(b));
//    memset(c,0, sizeof(c));
//
//    int a1 = 10;
//    int b1 = 20;
//    swap(&a1, &b1);
//    printf("a=%d, b=%d\n", a1, b1);
//    return 0;
//}





//#include <math.h>
//
//int is_PrimeNumber(int n) {
////    for (int i = 2; i <= n / 2; ++i) {
//
//    int top = (int)sqrt(n);
//    for (int i = 2; i <= top; ++i) {
//        if (n % i == 0) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    for (int i = 2; i <= 100; ++i) {
//        int ret = is_PrimeNumber(i);
//        if (ret == 1) {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}






//int is_LeapYear(int year){
//    return ((year %4 == 0 && year % 100 != 0) || (year %400 == 0));
//}
//int main(){
//    for (int i = 1; i <= 2020; ++i) {
//        int ret = is_LeapYear(i);
//        if (ret == 1){
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}







//int BinSearch(int arr[], int num, int x) {
//    int left = 0;
//    int right = num - 1;
//    int mid = 0;
//    while (left <= right) {
//        mid = (left + right) / 2;
//        if (arr[mid] > x){
//            right = mid - 1;
//        }else if (arr[mid] < x){
//            left = mid + 1;
//        }else{
//            printf("找到了，下标是：%d\n", mid);
//            return 0;
//        }
//    }
//}
//
//int main() {
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    BinSearch(arr, sizeof(arr)/sizeof(arr[0]), 5);
//    return 0;
//}








//int main(){
//    int num = printf("aa:%d\n", 123);
//    printf("%d\n", num);
//    printf("%d", printf("%d", printf("%d", 43)));
//    return 0;
//}





//#include <string.h>
//int main(){
//    char str[64] = "Hello";
//    //链式访问
//    int ret = strlen(strcat(str, "bit"));
//    printf("%d\n", ret);
//    //把world拷贝到字符串去Hello后边
//    char *s = strcat(str, "World");
//    printf("%s\n", s);
//    return 0;
//}






//int MyStrlen(char *str){
////    int len = 0;
////    while (*str){
////        len++;
////        str++;
////    }
//
//    if (*str == '\0'){
//        return 0;
//    }
//    return 1+MyStrlen(str+1);
//}
//int main(){
//    char *str = "abc123";
//    printf("len=%d\n", MyStrlen(str));
//    return 0;
//}





//void PrintInt(int n){
//    if (n > 10){
//        PrintInt(n / 10);
//    }
//    printf("%d ", n%10);
//}
//
//int main(){
////    接受一个整型值（无符号），按照顺序输出他的每一位
//    int n1 = 1234;
//    while (n1){
//        printf("%d ", n1%10);
//        n1 /= 10;
//    }
//
//    int n2 = 1234;
//    PrintInt(n2);
//    return 0;
//}




//int fact(int n){
//    if (n <= 2){
//        return n;
//    }
//    return n*fact(n-1);
//}
//
//int main(){
//    int ret = fact(5);
//    printf("ret=%d\n", ret);
//    return 0;
//}




//int count = 0;
//int fib(int n){
//    if (n <= 2){
//        return 1;
//    }
//    if (n == 3){
//        count++;
//    }
//    return fib(n-1)+fib(n-2);
//}

//int fib(int n){
//    int first = 1;
//    int second = 1;
//    int third = 1;
//    while (n > 2){
//        third = first + second;
//        first = second;
//        second = third;
//        n--;
//    }
//    return third;
//}
////斐波那契数列1 1 2 3 5 8 13 21 34...
//int main(){
//    int n = 40;
//    printf("%d\n", fib(n));
//    printf("%d\n", count);
//    return 0;
//}






/*
 * 汉诺塔
 * 青蛙跳台阶
 */
