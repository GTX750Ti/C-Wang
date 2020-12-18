#include <stdio.h>

#if 0
/*
 * 回调函数
 * 通过函数指针调用的函数，如果把函数的指针（地址）作品为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时
 */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

int main() {
    int x, y;
    int input = 1;
    int (*p[5])(int x, int y) = {0, add, sub, mul, div};
    while (input){
        printf("###################\n");
        printf("##1.add#####2.sub##\n");
        printf("##3.mul#####4.div##\n");
        printf("###################\n");
        printf("请选择：");
        scanf("%d", &input);
        if (input > 4 && input < 1){
            printf("输入有误\n");
        }else{
            printf("请输入计算的数字：");
            scanf("%d %d", &x, &y);
            printf("结果：%d\n", (*p[input])(x, y));//函数指针数组传参不熟练
        }
    }
    return 0;
}
#endif

#if 0
int CompInt(const void *_xp, const void *_yp){
    int *xp = (int*)_xp;
    int *yp = (int*)_yp;
    if (*xp > *yp){
        return 1;
    }else if (*xp < *yp){
        return -1;
    }else{//浮点数不能进行两个元素相等的比较
        return 0;
    }
}

#include <string.h>
int CompStr(const void *_xp, const void *_yp){//对于指针数组，传入的是字符串地址，因此传入的是二级指针
    char *s1 = *(char **)_xp;//需要强转，二级地址解引用就是字符串本身
    char *s2 = *(char **)_yp;
    return strcmp(s1, s2);
}

void Print(int arr[], int num){
    for (int i = 0; i < num; ++i) {
        printf("%d ", arr[i]);
    }
}
/*
 * qsort      任意类型        比较的内存中元素个数    比较的元素占用空间大小     函数指针
 * void qsort(void *base,   size_t num,          size_t size,           int (*compare)(const void*, const void*))
 */
#include <stdlib.h>
int main(){
//    int arr[] = {1,3,5,7,9,2,4,6,8,10};
//    int num = sizeof(arr)/sizeof(arr[0]);
//    qsort(arr, num, sizeof(int), CompInt);
//    Print(arr, num);

    char *arr[] = {"b1234", "a1234", "4321", "abcdef"};//存储的字符常量区
    int num = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, num, sizeof(char *), CompStr);
}
#endif

#if 0
/*
 * 模拟实现qsort
 */
int CompInt(const void *_xp, const void *_yp){
    int *xp = (int*)_xp;
    int *yp = (int*)_yp;
    if (*xp > *yp){
        return 1;
    }else if (*xp < *yp){
        return -1;
    }else{//浮点数不能进行两个元素相等的比较
        return 0;
    }
}

#include <string.h>
int CompStr(const void *_xp, const void *_yp){
    char *s1 = *(char **)_xp;
    char *s2 = *(char **)_yp;
    return strcmp(s1, s2);
}

void swap(char *src, char *dst, int size){
    char tmp = *src;
    for (int i = 0; i < size; ++i) {
        *src = *dst;
        *dst = tmp;
        ++src;
        ++dst;
    }
}
#include <assert.h>
void my_qsort(void *arr, int num, int size, int (*comp)(const void *, const void *)){
    assert(arr);
    assert(comp);
    char *e = (char *)arr;
    for (int i = 0; i < num-1; ++i) {
        int flag = 0;
        for (int j = 0; j < num-i-1; ++j) {
            if (comp(e+j*size, e+(j+1)*size) > 0){
                //swap
                swap(e+j*size, e+(j+1)*size, size);
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}
int main(){
    char *arr[] = {"b1234", "a1234", "4321", "abcdef"};
    int num = sizeof(arr)/sizeof(arr[0]);
    my_qsort(arr, num, sizeof(char *), CompStr);
}
#endif

#if 0
int main() {
    //一维数组
//    int a[] = {1, 2, 3, 4};
//    printf("%d\n", sizeof(a));//16
//    printf("%d\n", sizeof(a + 0));//8
//    printf("%d\n", sizeof(*a));//4
//    printf("%d\n", sizeof(a + 1));//8
//    printf("%d\n", sizeof(a[1]));//4
//    printf("%d\n", sizeof(&a));//16xx8
//    printf("%d\n", sizeof(*&a));//8xx16
//    printf("%d\n", sizeof(&a + 1));//8
//    printf("%d\n", sizeof(&a[0]));//4x8
//    printf("%d\n", sizeof(&a[0] + 1));//4x8

    //字符数组
#include <string.h>
//    char arr[] = {'a','b','c','d','e','f'};
//    printf("%d\n", sizeof(arr));//6+
//    printf("%d\n", sizeof(arr+0));//8
//    printf("%d\n", sizeof(*arr));//1
//    printf("%d\n", sizeof(arr[1]));//1
//    printf("%d\n", sizeof(&arr));//6xx8
//    printf("%d\n", sizeof(&arr+1));//8
//    printf("%d\n", sizeof(&arr[0]+1));//8
//    // size_t strlen(cont char *str)
//    printf("%d\n", strlen(arr));//6xx6+
//    printf("%d\n", strlen(arr+0));//6xx6+
////    printf("%d\n", strlen(*arr));//1xx报错
////    printf("%d\n", strlen(arr[1]));//1xx报错
//    printf("%d\n", strlen(&arr));//6+
//    printf("%d\n", strlen(&arr+1));//随机
//    printf("%d\n", strlen(&arr[0]+1));//5+

//    char arr[] = "abcdef";
//    printf("%d\n", sizeof(arr));//7
//    printf("%d\n", sizeof(arr+0));//8
//    printf("%d\n", sizeof(*arr));//1
//    printf("%d\n", sizeof(arr[1]));//1
//    printf("%d\n", sizeof(&arr));//8
//    printf("%d\n", sizeof(&arr+1));//随机
//    printf("%d\n", sizeof(&arr[0]+1));//8
//    printf("%d\n", strlen(arr));//6
//    printf("%d\n", strlen(arr+0));//6
////    printf("%d\n", strlen(*arr));//报错
////    printf("%d\n", strlen(arr[1]));//报错
//    printf("%d\n", strlen(&arr));//warning数组地址，数值上和元素一样；但是类型不一样-->6
//    printf("%d\n", strlen(&arr+1));//warning，随机
//    printf("%d\n", strlen(&arr[0]+1));//5


//    char *p = "abcdef";
//    printf("%d\n", sizeof(p));//8
//    printf("%d\n", sizeof(p+1));//8
//    printf("%d\n", sizeof(*p));//1
//    printf("%d\n", sizeof(p[0]));//1
//    printf("%d\n", sizeof(&p));//8
//    printf("%d\n", sizeof(&p+1));//8
//    printf("%d\n", sizeof(&p[0]+1));//8
//    printf("%d\n", strlen(p));//6
//    printf("%d\n", strlen(p+1));//5
////    printf("%d\n", strlen(*p));//error
////    printf("%d\n", strlen(p[0]));//error
//重要，p是指针，和数组没有关系
//    printf("%d\n", strlen(&p));//xxx warning，随机
//    printf("%d\n", strlen(&p+1));//随机
//    printf("%d\n", strlen(&p[0]+1));//5


//    int a[3][4] = {0};
//    printf("%d\n", sizeof(a));//8xx48
//    printf("%d\n",sizeof(a[0][0]));//4
//    printf("%d\n",sizeof(a[0]));//8xx16
//    printf("%d\n",sizeof(a[0]+1));//8
//    printf("%d\n",sizeof(*(a[0]+1)));//16xx4
//    printf("%d\n",sizeof(a+1));//8
//    printf("%d\n",sizeof(*(a+1)));//16
//    printf("%d\n",sizeof(&a[0]+1));//8
//    printf("%d\n",sizeof(*(&a[0]+1)));//16
//    printf("%d\n",sizeof(*a));//16
//    printf("%d\n",sizeof(a[3]));//报错xxx
    return 0;
}
#endif

void solution1() {
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *) (&a + 1);
    printf("%d %d\n", *(a + 1), *(ptr - 1));
}

void solution2() {
    struct Test {
        int Num;
        char *pcName;
        short sDate;
        char cha[2];
        short sBa[4];
    } *p;
    //由于还没学习结构体，这里告知结构体的大小是20个字节
    printf("%p\n", p);
    printf("%p\n", p + 0x1);//+20
    printf("%p\n", (unsigned long) p + 0x1);//+1
    printf("%p\n", (unsigned int *) p + 0x1);//+4
}

void solution3() {
    int a[4] = {1, 2, 3, 4};
    int *ptr1 = (int *) (&a + 1);//指向4后边
    /*
     * a被转换为int，+1就是跳过一个字节
     * 在被强转为int *
     * 小端存储：小小小
     * 低权值在低地址
     * 01 00 00 00   02 00 00 00 ...
     * 00 00 00 02
     * 20 00 00 00
     */
    int *ptr2 = (int *) ((int) a + 1);
    printf("%x,%x", ptr1[-1], *ptr2);
}

void solution4(){
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
    int *p=a[0];
    printf( "%d", p[0]);

}

void solution5(){
    int a[5][5];
    int(*p)[4];
    p = a;
    printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
}

void solution6(){
    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *ptr1 = (int *)(&aa + 1);
    int *ptr2 = (int *)(*(aa + 1));
    printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));
}

void solution7(){
    char *a[] = {"work","at","alibaba"};
    char**pa = a;
    pa++;
    printf("%s\n", *pa);
}

void solution8(){
    char *c[] = {"ENTER","NEW","POINT","FIRST"};
    char**cp[] = {c+3,c+2,c+1,c};
    char***cpp = cp;
    printf("%s\n", **++cpp);//p
    printf("%s\n", *--*++cpp+3);//er
    printf("%s\n", *cpp[-2]+3);//
    printf("%s\n", cpp[-1][-1]+1);//f
}
int main() {
//    solution1();
//    solution2();
//    solution3();
//    solution4();
//    solution5();
//    solution6();
//    solution7();
    solution8();
    return 0;
}