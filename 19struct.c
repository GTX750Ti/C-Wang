#include <stdio.h>

#if 0
//结构体内存对齐
//修改默认最大对齐数
#pragma pack(1)//设置默认
#pragma pack()//恢复默认
struct S1{
    char c1;
    char c2;
    int i;
};
struct S3{
    double d;//8
    char c;//1
    int i;//3+4
};

struct S4{
    char c1;//1
    struct S3 s3;//7+16
    char *arr[3];//4xxx 12
    short *s;//4
    double d;//8
};
int main() {
    printf("%d\n",sizeof(struct S1));
    printf("%d\n",sizeof(struct S3));
    printf("%d\n",sizeof(struct S4));
    return 0;
}
#endif

#if 0
struct S3{
    double d;//8
    char c;//1
    int i;//3+4
};//16
struct S4{
    char c1;//1
    struct S3 s3;//7+16
    char *arr[3];//4xxx 12
    short *s;//4
    double d;//8
};//48
struct S5{
    char c;//1
    struct S3 s;//7+16
    char *d;//4
    char e[3];//3
    float *fp;//1+4
    float f;//4
    double d1[3];//24
    struct S4 ss[2];//96
    char c2;//1
};
int main(){
    printf("%d\n",sizeof(struct S5));
    return 0;
}
#endif

#if 0
/*
 * 位段
 * 位段的声明和结构体类似但有俩不同
 * 1.位段成员必须是：int, signed int, unsigned int
 * 2.位段的成员后边有一个冒号和一个数字
 *
 * 可移植性差
 */
//A就是一个位段
struct A {
    int _a: 2;
    int _b: 5;
    int _c: 10;
    int _d: 30;
};

struct S {
    char a: 3;
    char b: 4;
    char c: 5;
    char d: 4;
};

int main() {
    printf("%d\n", sizeof(struct A));

    struct S s={0};
    printf("%d\n", sizeof(struct S));
    s.a = 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;
    return 0;
}
#endif

#if 0
/*
 * 正价代码的可读性和维护性
 * 和#define定义的标示符比较枚举有类型检查，更加严谨
 * 防止命名污染（封装）
 * 便与调试
 * 使用方便，一次定义多个常量
 */
enum Color{
    //不赋值的情况下由前一个值确定下一个值
    red = -5,
    yel,
    blu,
    gre,
};
int main(){
    printf("%d\n", yel);
    enum Color c = gre;
    printf("%d\n", c);
    return 0;
}
#endif

int main(){
    return 0;
}