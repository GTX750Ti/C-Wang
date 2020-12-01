#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#if 0
int main()
{
    int i = 0;
    int arr[10] = { 0 };
    for (i = 0; i <= 12; ++i)
    {
        arr[i] = 0;
        printf("hehe\n");
    }
    return 0;
}
#endif

#if 0
int main()
{
    int sum = 0;
    for (int i = 1; i <= 3; ++i)
    {

        int ret = 1;
        for (int j = 1; j <= i; j++)
        {
            ret *= j;
        }
        sum += ret;
    }
    printf("%d\n", sum);
    return 0;
}
#endif

#if 0
//模拟实现strcpy函数
#include <assert.h>

char *strcpy(char *dst, const char *src) {
    assert(dst && src);
    while (*dst++ = *src++);
    return dst;
}

//static,const,volatile
int main() {
    //int const a = 10;//const int a = 10;
    //a = 20;

    //int const a = 10;
    //int* p = (int*)&a;
    //printf("a=%d\n", a);
    //*p = 20;//用户自己的栈区
    //printf("a=%d\n", a);

    //const char* p = "abcd";//操作系统保护
    //*p = 'A';

    //int a = 10;
    //int* const p1 = &a;//const修饰的p1不能被修改
    //p1 = 100;
    //const int* p2 = &a;//const修饰的*，指针所指向的目标不能被修改
    //p2 = 100;
    //*p2 = 100;

    //int a[1];
    //a[0] = 1;
    //int i = 1;
    //printf("a=%d\n", (++a[0])+(++a[0]));
    //printf("i=%d\n", (++i)+(++i));

//    int a = 10;
//    const int* p = &a;
//    const int** q = &p;
//
//    *p = 100;
//    p = 100;
//    **q = 100;
//    *q = 100;
//    q = 100;

    const int a = 10;
    int *const p = &a;
    *p = 20;
    p = 20;
    return 0;
}
#endif

#include <assert.h>

#if 0
int MyStrlen(const char *s) {    assert(s);
    char *e = s;
    while (*e){
        e++;
    }
    return e-s;
}

int main() {
    const char *str = "abcd1234";
    int len = MyStrlen(str);
    printf("%d\n", len);
    printf("请输入：");
    scanf("%d", &len);
}
#endif

int main() {
    char x = 10;
    char y = -10;
    /*
     * 0000 1010--10【源码】
     *
     * 1000 1010--【-10源码】
     * 1111 0101--【-10反码】
     * 1111 0110--【-10补码】
    */
    char c = -128;
    /*
     * 1 1000 0000--[-128源码]
     * 1 0111 1111--[-128反码]
     * 1 1000 0000--[-128补码]
     * 1000 0000--[-128补码]
     */
    char a = 128;

    printf("x=%d\n", x);
    printf("y=%d\n", y);
    printf("c=%d\n", c);
    printf("a=%d\n", a);
}
