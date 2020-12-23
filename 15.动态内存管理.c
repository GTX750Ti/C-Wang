#include <stdio.h>


#if 0
#include <malloc.h>
#include <string.h>
int main() {
    /*
     * 栈空间不担心申请与销毁
     * 对空间人为开辟认为释放
     */
    char *mem = (char *)malloc((sizeof(char))*10);//堆开辟的空间，mem在栈，通过mem指针指向堆
    if (NULL == mem){
        printf("malloc error\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        *(mem+i)=i;
    }
    free(mem);

    int arr[5] = {1,2,3,4};
    memset(arr, 1, 4);//单位是字节
    printf("%d\n", *arr);
    return 0;
}
#endif

#if 0
#include <stdlib.h>
/*
 * void *maclloc(size_t size);ptr指的空间不是动开辟的，free行为是未定义
 *
 * void free(void *ptr);如果ptr指向的是NULL，则函数什么事都不做
 */
int main(){
//    int arr[1000*1000];
    char *p = (char *)malloc(1000*1000*10);
    if (NULL==p){
        printf("malloc error\n");
    }
    for (int i = 0; i < 5; ++i) {
        p[i]=i;
    }
    printf("malloc success\n");
    printf("after:%p\n", p);
    free(p);
    p=NULL;
    printf("after:%p\n", p);
    return 0;
}
#endif

#if 0
/*
 * void *calloc(size_t num, size_t size);
 */
#include <stdlib.h>
int main(){
    char *p= (char *)calloc(5,1);
    free(p);
    p=NULL;
    return 0;
}
#endif

#if 0
/*
 * void *realloc(void *ptr, size_t size);
 * ptr：调整的内存地址
 * size：调整后新大小
 */
#include <stdlib.h>
int main(){
    char *p=(char *)malloc(20);
    if (NULL==p){
        printf("malloc error!\n");
        return 1;
    }
    for (int i = 0; i < 5; ++i) {
        p[i]=i;
    }
    printf("malloc success!: %p\n", p);
    int *ptr = realloc(p, 2199999);
    printf("realloc success!: %p\n", ptr);
    if (NULL!=p){
        p=ptr;
    }
    free(p);
    p=NULL;
    return 0;
}
#endif

#if 0
/*
 * 常见的动态内存错误
 */
#include <stdlib.h>

void test1() {
    int *p = (int *) malloc(INT8_MAX / 4);//vs2013上有INT_MAX
    *p = 20;//如果p的值为NULL，就有问题
    free(p);
}

void test2() {
    int i = 0;
    int *p = (int *) malloc(10 * sizeof(int));
    if (NULL == p) {
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <= 10; i++) {
        *(p + i) = i;//当i是10的时候越界访问
        free(p);
    }
}

void test3(){
    int a=10, *p=&a;
    free(p);//对非动态开辟的内存使用free释放
}

void test4(){
    int *p=(int *)malloc(10*sizeof(int));
    free(p);
    free(p);//重复释放
}

void test5(){
    int *p=(int *)malloc(10*sizeof(int));
    ++p;
    free(p);//只释放了一部分动态内存
}

void test6(){
    int *p=(int *)malloc(10*sizeof(int));
    //对动态内存没有释放（内存泄漏）
}

/*
 * 几个经典的笔试题
 */
void GetMemory(char **p){
    *p=(char *)malloc(32);
}
#include <string.h>
void test7(void){
    char *str=NULL;
    GetMemory(&str);
    strcpy(str, "Hello");
    printf(str);
}

char *GetMemory2(){
    char p[] = "HelloWorld";
    return p;
}
void test8(){
    char *str=NULL;
    str=GetMemory2();
    printf(str);
}
void test9(){
    char *str=(char *)malloc(100);
    strcpy(str, "Hello");
    printf("before: %p\n", str);
    free(str);
    printf("after: %p\n", str);
    if (str!=NULL){
        strcpy(str, "World");
        printf(str);
    }
}
int main() {
    test9();
    return 0;
}
#endif

#if 0
#include <stdlib.h>
int un_g_val;
int g_val=100;
int main(){
    const char *str="HelloWorld";
    printf("code addr: %p\n", main);
    printf("red only addr: %p\n", str);
    printf("init g_val: %p\n", &g_val);
    printf("uninit g_val: %p\n", &un_g_val);
    static int a=10;
    int b=10;
    printf("a static: %p\n", &a);
    printf("b static: %p\n", &b);
    char *m=(char *)malloc(10);
    char *m1=(char *)malloc(10);
    char *m2=(char *)malloc(10);
    char *m3=(char *)malloc(10);
    printf("malloc addr: %p\n", m);
    printf("malloc addr: %p\n", m1);
    printf("malloc addr: %p\n", m2);
    printf("malloc addr: %p\n", m3);
    printf("stack addr: %p\n", &m);
    printf("stack addr: %p\n", &str);
    return 0;
}
#endif

//需求：在结构体中需要一个变长的数组
struct Score1 {
    int num;//几门学科
    int *p;
    int arr1[0];//0->数学，1->c语言，2->OS...
    int arr2[];
};

typedef struct Score2 {
    int num;
    int arr[0];
} s_t;

#include <stdlib.h>

int main() {
    struct Score1 *s = (struct Score1 *) malloc(sizeof(struct Score1));
    s->num = 12;
    if (s == NULL) {
        return 1;
    }
    s->p = (int *) malloc(sizeof(int) * s->num);
    if (s->p == NULL) {
        free(s);
        return 2;
    }


    s_t *s2 = (s_t *) malloc(sizeof(s_t) + 10 * sizeof(int));
    s->num = 10;
    for (int i = 0; i < s->num; ++i) {
        (s2->arr)[i] = i;
    }
    free(s2);
    return 0;
}
