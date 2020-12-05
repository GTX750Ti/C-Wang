#include <stdio.h>

#if 0
int main() {
    char c = 'a';
    char *p = &c;

    const char *str = "Hello World";

    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    char *str3 = "hello bit.";
    char *str4 = "hello bit.";
    if (str1 == str2)//两块不同的内存地址
        printf("1==2\n");
    else{
        printf("1!=2\n");
    }
    if (str3 == str4)//字符串的地址就是同一份
        printf("3==4\n");
    else{
        printf("3!=4\n");
    }
    return 0;
}
#endif

#if 0
int main() {
//    int arr[5] = {0};
//    printf("%p\n", arr);
//    printf("%p\n", &arr);
//    printf("%p\n", arr+1);
//    printf("%p\n", &arr+1);

    int arr[4][5] = {0};
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", arr + 1);
    printf("%p\n", &arr + 1);
    return 0;
}
#endif

/*
 * 指针数组
 * 存放指针的数组
 * int *parr1[10];//存放10个整形指针的数组
 */

/*
 * 数组指针
 * 指向数组的指针，数组指针中存放的是数组的地址
 * int (*parr2)[10];//指向能够存放10个元素的一维整形数组
 */

/*
 * 拓展
 * int (*parr3[10])[10];//数组指针数组
 */
//int main(){
////    int a[6] = {0};
////    int (*p)[5] = a;//不对。数组元素个数也是数组类型之一，个数要和数组指针类的数组个数保持一致
//
//    int a[5] = {0};
//    int(*p)[5] = &a;//把数组a的地址赋值给数组指针变量p
//    return 0;
//}

#if 0
void print_arr1(int arr[][5], int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", arr[i][j]);
        }
    }
}

void print_arr2(int (*arr)[5], int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", arr[i][j]);
        }
    }
}
int main(){
    int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
    print_arr1(arr, 3, 5);
    printf("\n");
    /*
     * 数组名表示首元素地址
     * 但是二维数组的首元素师二维数组第一行
     * 所以这里传递的arr也就是第一行的地址，是一维数组的地址
     * 可以数组指针来接收
     */
    print_arr2(arr, 3, 5);

    return 0;
}
#endif

/*
 * 数组传参
 */
//一维数组传参
#if 0
void test1(int arr[]) {}//本质是一个整形指针 ok
void test1(int arr[10]) {}//本来可以忽略，加上也无所谓，20，30，40都可以写 ok
void test1(int *arr) {}//数组传参会发生降维，降维成指向内部的元素类型的指针 ok
void test2(int *arr[20]) {}//20可以省略 ok
void test2(int **arr) {}// ok

void test(int **b) {}

int main() {
    int arr[10] = {0};
    int *arr2[20] = {0};//指针数组
    test1(arr);
    test2(arr2);

    int *a[5] = {NULL};
    test(a);
    return 0;
}
#endif

#if 0
/*
 * 二维数组传参
 */
void test(int arr[3][5]){}// ok
void test(int arr[][]){}// no
void test(int arr[][5]){}// ok
void test(int *arr){}// no
void test(int *arr[5]){}// no
void test(int (*arr)[5]){}// ok
void test(int **arr){}// no
int main(){
    int arr[3][5] = {0};
    return 0;
}
#endif

#if 0
/*
 * 一级指针传参
 */
void print(int *p, int sz){
    for (int i = 0; i < sz; ++i) {
        printf("%d ", *(p+i));
    }
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int *p = arr;
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(p, sz);
    return 0;
}
#endif

/*
 * 函数指针
 */
void Print() { printf("Hello World\n"); }

void (*pfun1)();//函数指针：pfun1先与*结合，说明pfun1是指针，指向的是一个函数，指向的函数无参数，返回值类型为void
void *pfun2();//函数声明
int Add(int a, int b) { return a + b; }

int main() {
    printf("%p\n", Print);//函数名代表函数的地址，其含义与&地址名等价
    printf("%p\n", &Print);//

    printf("%d\n", Add(10, 20));
    int (*p)(int, int) = Add;
    printf("%d\n", (*p)(100, 200));
    printf("%d\n", p(1000, 2000));

    (*(void (*)()) 0)();//0被强制转换为函数指针void类型，0被当为了指针[地址]。之后被*解引用，找到地址中0部分代表的函数在调用
    void (*signal(int, void (*)()))(int);

    typedef void(*pfun_t)(int);
    pfun_t signal(int, pfun_t);

    //函数指针数组
    void (*parr1[10])(const char*);
    //函数指针数组的指针
    void (*(*parr2[10]))(const char*);
}