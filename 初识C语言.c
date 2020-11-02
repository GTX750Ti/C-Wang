#include <stdio.h>

/*
 * 程序运行的时候，都要先加载到内存
 * 定义变量的本质：变量是在内存中被定义的
 * 定义：开辟内存空间
 * char：字符数据类型--1
 * short：短整形--2
 * int：整形--4
 * long：长整形--8
 * long long：更长的整形--8
 * float：但精度浮点数--4
 * double：双精度浮点数--8
 * C语言没有字符串类型，存在变量是为了合理使用内存
 *
 */
//int main() {
//    printf("char=%d\n", sizeof(char));
//    printf("short=%d\n", sizeof(short));
//    printf("int=%d\n", sizeof(int));
//    printf("long=%d\n", sizeof(long));
//    printf("long long=%d\n", sizeof(long long));
//    printf("float=%d\n", sizeof(float));
//    printf("fdouble=%d\n", sizeof(double));
//    return 0;
//}





/*
 *
 * 变量：不变的值
 * 常量：变的值
 */
//int main(){
//    int age = 150;
//    float weight = 45.5f;
//    char ch = 'w';
//    return 0;
//}




/*
 * 变量的分类
 * 局部变量
 * 全局变量
 */
//int global = 2020;//全局变量
//int main(){
//    int local = 2021;//局部变量
//    //下面定义的global会不会有影响？
//    int global = 2021;//局部变量
//    printf("global = %d\n", global);
//    return 0;
//}

//int main(){
//    int num1 = 0;
//    int num2 = 0;
//    printf("请输入两个数据：");
//    scanf("%d %d", &num1, &num2);
//    printf("num1=%d, num2=%d\n", num1, num2);
//    return 0;
//}






/*
 * 变量的作用域和生命周期
 *
 * 变量作用域：限定这个可用性的代码范围就是这个名字的作用域
 * 局部变量的作用域：变量所在的局部范围
 * 全局变量的作用域：整个工程
 *
 * 变量生命周期：变量的创建到变量的销毁之间的一个时间段
 * 局部变量的生命周期：进入这个作用域生命周期开始，出作用域生命周期结束
 * 全局变量的生命周期：整个程序的生命周期
 */
//void show(){
//    int a = 10;
//    printf("show run!\n");
//}
//
//int main(){
//    show();
//    return 0;
//}






/*
 *常量分类：字面常量，const修饰的常变量，#define定义的标示符常量，枚举常量
 */
#define MAX 100
//enum {
//    RED = 100,
//    YELLOW,
//    BLACK,
//    BLUE
//};
//int main(){
////    1;
////    'a';
////    "Hello World";
////    int num = 0;
////    float pi = 3.14;
//
//
//
//
//
////    MAX = 200;//标示符常量不能被赋值
////    int a = 100;
////    printf("MAX:%d\n", MAX);
////    printf("a:%d\n", a);
//
//
//
////    int a = RED;
////    int b = YELLOW;
//////    BLUE = 100;枚举常量不能被修改
////    printf("%d\n", a);
////    printf("%d\n", b);
//
//
//
//
//    //定义变量：分两步1：开辟空间 2：写入对应的数据
//    //初始化：空间开辟好，里边的数据与生俱来是某个值
//    const int a = 100;//初始化
//    //赋值：第二次进行主动赋值
////    a = 200;//赋值
//    //const修饰变量定义，被修饰的变量，不能被直接修改
//    return 0;
//}





/*
 * 字符串+转义字符+注释
 * 字符串"hello bit.\n"
 * 字符串结束标志是\0，
 */
//int main(){
////    char str[16] = {"bit"};
////    char str1[16] = {'b', 'i', 't'};
////    char str2[16] = {'b', 'i', 't', '\0'};
////    printf("str=%s\n", str);
////    printf("str1=%s\n", str1);
////    printf("str2=%s\n", str2);
////    printf("%d\n", sizeof(str));
//
//
//
//
//
//
//
//
//
////    printf("比\\特\n");//由字面含义转为特殊含义，由特殊含义转为字面含义
////    printf("c:\code\test.c\n");
//    return 0;
//}










//笔试题：程序输出什么
//#include <string.h>
//int main(){
//    printf("strlen(abcdef)=%d\n", strlen("abcdef"));//6
//    printf("sizeof(abcdef)=%d\n", sizeof("abcdef"));//7
//    printf("strlen(c:\\test\\328\\test.c)=%d\n", strlen("c:\test\328\test.c"));//14
//    printf("\c");
//    printf("sizeof(\"\c\")=%d\n", sizeof("\c"));
//    printf("sizeof(\'\c\')=%d\n", sizeof('\c'));
//    return 0;
//}










//选择语句
//int main(){
//    int select = 0;
//    printf("你有没有好好学习呢?<0:yes, 1:no>#");
//    scanf("%d", &select);
//    if (select == 0){
//        printf("恭喜，你能达到好的offer🎉\n");
//    }else{
//        printf("抱歉。。。！\n");
//    }
//    //C中，0为假，非0为真
//    //C中也没有bool true/false类型数据
//    printf("%d\b", 1==1);
//    printf("%d\b", 1==2);
//    return 0;
//}










//while循环
//int main(){
//    int i = 1;
//    while (i <= 10){
//        printf("i:%d\n", i);
//        i++;
//    }
//    return 0;
//}





//#define MAX 60000
//int main(){
//    printf("加入比特");
//    int line = 0;
//    while (line <= MAX){
//        printf("coding...\n");
//        line++;
//    }
//    if (line > MAX){
//        printf("走向人生巅峰");
//    }
//    return 0;
//}






//for循环
//int main(){
////    int i = 0;
////    for (; i < 10; ++i) {
////        printf("i:%d\n", i);
////    }
//
//
//
//
//    for(;;){
//        printf("死循环\n");
//    }
//    return 0;
//}








//do...while...
//int main(){
//    int i = 0;
//    do{
//        printf("i:%d\n", i);
//        i++;
//    }while (i < 10);
//    return 0;
//}










//函数
//int sum(int x, int y) {
//    int result = x + y;
//    return result;
//}
//
//int sub(int x, int y) {
//    int result = x - y;
//    return result;
//}
//
//int mub(int x, int y) {
//    int result = x * y;
//    return result;
//}
//
//int div(int x, int y) {
//    int result = x / y;
//    return result;
//}
//
//int main() {
//    printf("please enter two numbers:");
//    int x = 0;
//    int y = 0;
//    scanf("%d %d ", &x, &y);
//    char op = 'x';
////    fflush(stdout);
//    while (1) {
//        printf("\nplease enter your choice<+-*/>");
//        scanf(" %c", &op);
//        if (op == '+') {
//            printf("\n%d+%d=%d\n", x, y, sum(x, y));
//        } else if (op == '-') {
//            printf("\n%d-%d=%d\n", x, y, sub(x, y));
//        } else if (op == '*') {
//            printf("\n%d*%d=%d\n", x, y, mub(x, y));
//        } else if (op == '/') {
//            if (y != 0) {
//                printf("\n%d/%d=%d\n", x, y, div(x, y));
//            } else {
//                printf("\ndiv zero! error!\n");
//            }
//        } else {
//            printf("\nenter error!\n");
//            break;
//        }
//    }
//    return 0;
//}




//int sum(int _a, int _b){
//    printf("after:_a:%d, _b:%d\n", _a, _b);
//    printf("after:_a:%p, _b:%p\n", &_a, &_b);
//    int _ret = _a + _b;
//    return _ret;
//}
//
//int main(){
//    int a = 10;
//    int b = 20;
//    printf("before:a:%d, b:%d\n", a, b);
//    printf("before:a:%p, b:%p\n", &a, &b);
//    int ret = sum(a, b);
//    printf("result=%d\n", ret);
//    return 0;
//}











/*
 * 数组：具有相同类型的数据集合
 */
//#define SIZE 5
//
//int main() {
//    //定义数组时[]内应该是常量，不可以用常变量，变量来表示，默认初始化为0
////    const int n = 10;
////    int arr[n];
//
//    int arr[SIZE] = {11, 22, 33};
//    printf("%d\n", sizeof(arr));//数组总大小
//    printf("%d\n", sizeof(arr[0]));//数组一个元素大小
//
//    //动态求出数组的元素个数
//    int num = sizeof(arr)/sizeof(arr[0]);
//    printf("num=%d\n", num);
////    for (int i = 0; i < SIZE; ++i) {
////        printf("%d ", arr[i]);
////    }
//
////    char arr[] = "Hello World";
//    return 0;
//}









/*
 * 操作符
 */
//int main() {
//    /*
//     * 1010
//     * >>1:0101
//     * <<1:10100
//     */
////    int a = 10;
////    printf("%d\n", a >> 1);
////    printf("%d\n", a << 1);
////    //10
////    a << 1 == a * 2;
////    a >> 1 == a / 2;
//
//
//
//
//    /*
//     * & ^ |
//     * &：按位与【都为1，则为1】
//     * ^：按位异或【相同为假，相异为真】
//     * |：按位或【有1则1】
//     *
//     * 1010 -- 10
//     * 1100 -- 12
//     * 1000 -- 按位与得8
//     * 1110 -- 按位或得14
//     * 0110 -- 按位异或得6
//     */
//
////    printf("%d\n", 10 & 12);
////    printf("%d\n", 10 | 12);
////    printf("%d\n", 10 ^ 12);
//
//
//
//
//
////    int a = -10;
////    int b = -a;
////    printf("%d\n", b);
//
//
//
//
//
//    int a = 0;
//    printf("%u\n", ~a);
//    return 0;
//}










/*
 * 关键字：32个
 * 数据类型关键字：12
 * 控制语句关键字：12
 * 存储类型关键字：4
 * 类型限定符关键字：2
 * 其他：2
 */

//typedef unsigned long long u_ll;
//int main(){
//    unsigned long long x = 100;
//    u_ll y = 100;
//    printf("%lu\n", x);
//    printf("%lu\n", y);
//    return 0;
//}




/*
 * static：
 */

//void show(){
//    //static在修饰局部变量的时候，有如下两个作用
//    //1.作用域：在本代码块内有效，用static修饰，这个作用不变
//    //2.生命周期：临时性，static修饰，则该变量生命周期变成全局性
//    //3.注意事项：int i = 0;初始化，任何一个变量只会初始化一次
//    static int i = 0;//临时变量具有临时性
//    ++i;
//    printf("i:%d\n", i);
//}
//int main(){
//    for (int i = 0; i < 10; ++i) {
//        show();
//    }
//    return 0;
//}




//static l_val = 4321;
//
//static void show1(){
//    printf("Hello World!\n");
//}
//int main() {
////    extern int g_val;
////    printf("global=%d\n", g_val);
////    printf("local=%d\n", l_val);
//
//    show1();
//    extern void show();
//    show();
//    return 0;
//}










/*
 * #define宏定义
 */
//#define MAX 100
//#define sum(x, y) ((x)+(y))
//int main(){
//    int i = MAX;
//    printf("i:%d\n", i);
//    printf("sum=%d\n", 10*sum(10, 20));//10*10+20
//    return 0;
//}










/*
 * 指针
 */
//int main() {
//    int a = 10;
//    int *p = &a;//指针变量，要开辟内存空间，有变量名，有变量内容
//    *p = 20;
//    printf("%d\n", p);
//    printf("%d\n", a);
//    printf("%p\n", p);
//    return 0;
//}








/*
 * 结构体：可描述复杂数据类型，具有相同或不同数据类型
 */
//struct stu：定义了一个自定义类型【相对于内置类型】
//#define SIZE 64
//struct stu{
//    char name[SIZE];
//    int age;
//    char sex[SIZE/8];
//    char telephone[SIZE/4];
//    //籍贯，成绩
//};
//int main(){
//    struct stu Tom = {"Tom", 19, "男", "110"};
//    struct stu *p = &Tom;
//    printf("%s, %s\n", Tom.name, Tom.telephone);
//    printf("%s, %s\n", p->name, p->telephone);
//    printf("%s, %s\n", (*p).name, (*p).telephone);
//    return 0;
//}





//int i;
//int main(){
//    i--;
//    printf("%d\n", i);
//    if (i>sizeof(i)){
//        printf(">\n");
//    }else{
//        printf("<\n");
//    }
//    return 0;
//}