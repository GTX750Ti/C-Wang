#include <stdio.h>

#if 0
/*
 * 1. 预处理 选项 gcc -E test.c -o test.i 预处理完成之后就停下来，预处理之后产生的结果都放在test.i文件中
 * 2. 编译 选项 gcc -S test.c 编译完成之后就停下来，结果保存在test.s中。
 * 3. 汇编 gcc -c test.c 汇编完成之后就停下来，结果保存在test.o中。
 */
#define ADD(x,y) (x+y)
#define M 10
#define PRINT(F, V) printf("The "   #V  " is: "  F "\n", V)
#define MAKE(n,v) sum##n+=v
int main() {
//    printf("%d\n", 10*ADD(10,20));//宏定义需要注意优先级
//    printf("HelloM\n");//宏定义出现在字符常量不会被扫描
//    int  aM=10;
//    printf("%d\n", aM);
//    printf("Hello""World""Hello""Bit");//相邻字符串自动连接

//    PRINT("%f", 3.14+1.0);

//    int sum2 = 10;
//    printf("sum2=%d\n", sum2);
//
//    MAKE(2,20);
//    printf("sum2=%d\n", sum2);

    int arr[1]={1};
//    printf("ret1=%d\n", ++arr[0]);
    printf("ret2=%d\n", arr[0]++);
    return 0;
}
#endif

#define N
#define F 1

int main() {
//    int i=0;
//    //gcc main.c -o mytest -D M=10
//    for (; i < M; ++i) {
//        printf("%d ", i);
//    }

//    int sum=0;
//    int i=1;
//    for (; i <= 100; ++i) {
//        sum+=i;
//        //条件编译：gcc main.c -DDEBUG
//#ifdef DEBUG
//        printf("debug:%d\n", sum);
//#endif
//    }
//    printf("%d\n", sum);

//条件编译
#ifndef M
#define M 10
    printf("%d\n", M);
#endif
    /*
     * #ifndef _TEST_H
     * #define _TEST_H
     *
     * #endif
     * //仅让头文件被引用一次【pragma pack()】
     */

#if F == 3
    printf("F==1\n");
#elif F == 2
    printf("F==2\n");
#else
    printf("Else\n");
#endif
}
