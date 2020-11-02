//全局变量一般可以跨文件使用！
//static修饰全局变量，该变量只能在本文件使用
//static int g_val = 1234;
//int g_val = 1234;
#include <stdio.h>

//函数也可以跨文件访问
static void show(){
    printf("Hello World!\n");
}