#include <stdio.h>

/*
 * strlen
 * size_t strle(const char *str);
 * 字符串已经'\0'作为结束标志，strlen函数返回的是字符串中'\0'前面出现的字符个数（不包含'\0'）
 * 参数指向的字符串必须要以'\0'结束
 * 注意函数的返回值是size_t，是无符号的（易错）
 */
#if 0
int my_strlen1(const char*str){
    //计数器方式
    int count = 0;
    while (*str){
        count++;
        str++;
    }
    return count;
}

int my_strlen2(const char*str){
    //不能创建临时变量计数器--递归
    if (*str == '\0'){
        return 0;
    }else{
        return 1+my_strlen2(str+1);
    }
}

int my_strlen3(const char*str){
    char *p = str;
    //结束指针-初指针
    while (*p != '\0'){
        p++;
    }
    return p-str;
}
#include <string.h>
int main() {
    const char *str1 = "abcdef";
    const char *str2 = "bbb";
    if (strlen(str2) - strlen(str1) > 0) {
        printf("str2>str1\n");
    } else {
        printf("srt1>str2\n");
    }
    return 0;
}
#endif


/*
 * strcpy
 * char * str(char *dst, const char * rc);
 * 后者给前者
 * 源字符串必须以'\0'结束
 * 会将源字符串中的'\0'拷贝到目标空间
 * 目标空间必须足够大，以确保能存放源字符串
 * 目标空间必须可变
 *
 * strncpy
 * char *strncpy(char *dst, const char *src, size_t num);
 * 拷贝num个字符从源字符串到目标空间
 * 如果源字符串长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个
 */
#if 0
#include <assert.hh>
void *my_strcpy1(char void* dst, const char void*src){
    assert(dst && src);
    char *ret = dst;
    while((*dst++=*src++)){
        ;
    }
    return ret;
}
#include <string.h>
int main(){
    char dst[20];
    char src[20];
    strcpy(dst, "To be ");
    strcpy(src, "or not to be ");
    strncat(dst, src, 6);
    puts(dst);//stdin stdout stderr
}
#endif

/*
 * strcat
 * char *(char *dst, const char *src);
 * 源字符串必须以'\0'结束
 * 目标空间必须足够大，能容纳下源字符串的内容
 * 目标空间必须可变
 *
 * strncat
 * char *(char *dst, const char *src, size_t num);
 */
#if 0
#include <assert.h>
void *my_strcat1(char void*dst, const char* src){
    assert(dst && src);
    char *dret = dst;
    while(*dst++){
        ;
    }
    while(*dst++==*src++){
        ;
    }
    return ret;
}
#include <string.h>
int main(){
    char *src= "world!";
    char dst[16] = "aaa\0xf";
    strncat(dst, src, strlen(src)+1);
    printf("%s\n", dst);
}
#endif


/*
 * strcmp
 * int strcmp(const char *dst, const char *src);
 * 第一个字符串大于第二个字符串，返回大于0
 * 第一个字符串大等于第二个字符串，返回等于0
 * 第一个字符串小于第二个字符串，返回小于0
 *
 * int strncmp(const char *dst, const char *src, size_t num);
 * 比较另一个字符串不一样或者一个字符串结束或者num个字符全部比较完
 */
#if 0
#include <assert.h>
int my_strcmp(const char *dst, const char *src){
    assert(dst && src);
    int ret=0;
    // (!...) && *src中*src作用可以保证src指针不越界，当dst指针为\0之时，更具判断就可以知道dst不会继续后移【方法很巧妙】
    while (!(    ret=    *(unsigned char *)dst-*(unsigned char *)src    )     && *src){
        ++src,++dst;
    }
    if (ret < 0){
        ret = -1;
    }else if(ret > 0){
        ret = 1;
    }
    return ret;
}
#endif

#if 0
#include <string.h>
int main() {
    char str[][5] = {"R2D2", "C3PO", "R2A6"};
    int n;
    puts("Looking for R2 astromech droids...");
    for (n = 0; n < 3; n++)
        if (strncmp(str[n], "R2xx", 2) == 0) {
            printf("found %s\n", str[n]);
        }
    return 0;
}
#endif

/*
 * strstr
 * char *strstr(const char *, const *src);
 * 字串查找
 */
#if 0
#include <assert.h>
const char *my_strstr1(const char *str, const char *sub_str){
    assert(str && sub_str);
    //确定起始位置
    while (*str){
        //局部比较
        const char*p = str;
        const char*q=sub_str;
        while (*p && *q && *p == *q){//此处一定可以保证sub_str不为0，p不越界
            p++;
            q++;
        }
        if (*q == '\0'){//当越界发生时，无论是sub_str还是p只需要判断sub_str为0，就代表检查完毕可以返回原始的str指针地址
            return str;
        }
        str++;//第一次判断什么都没有，重新确立起始位置
    }
    return NULL;
}
#include <string.h>
int main(){
    char *start=strstr("hello bit, hello world", "bit");
    printf("%s\n", start);

    char str[] = "This is a simple string";
    char *pch = strstr(str, "simple");
    strncpy(pch, "sample", 6);
    puts(str);

    const char *str3 = "abc 123 abcd 1234 adcdef";
    const char *sub_str = "1234";
    printf("%s\n", my_strstr1(str3, sub_str));
    return 0;
}
#endif


/*
 * strtok
 * char *strtok(char *str, const char *sep);
 * sep参数是一个字符串，定义了用作分隔符的字符合集
 * 第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
 * strtok函数找到str中的下一个标记，并将其用\0结尾，返回一个指向这个标记的指针（注：strtok函数会改变被操作的字符串，所以使用strtok函数切分的字符串一般都是林hi拷贝的内容并且可修改）
 * strtok函数的第一个参数为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置
 * strtok函数第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记
 * 如果字符串中不存在更多的标记，则返回一个NULL指针
 */
#if 0
#include <string.h>

int main() {
    char str[] = "This is#a_mple.string";
    char *p = strtok(str, " #_.");
    while (p != NULL) {
        printf("%s\n", p);
        p = strtok(NULL, " #_.");
    }
    return 0;
}
#endif

/*
 * strerror
 * 返回错误码，所对应的错误信息
 * char *strerror(int errnum);
 */
#if 0
#include <string.h>
int main() {
    printf("before：%d\n", erron);
    FILE *fp = fopen("test.log", "r");
    if (fp == NULL) {
        printf("after：%d\n", erron);
        printf("after：%s\n", strerror(erron));
    }

    for (int i = 0; i < 50; ++i) {
        printf("%d->%s\n", i, strerror(i));
    }
    return 0;
}
#endif

/*
 * 字符分类函数
 */
#if 0
#include <ctype.h>
int main(){
    char c1 = toupper('c');
    char c2 = tolower('C');
    if (isspace(c1)){
        printf("是空格\n");
    }else if(islower(c1)){
        printf("是小写字母\n");
    }else if(isupper(c1)){
        printf("是大写字母\n");
    }else if(isdigit(c1)){
        printf("是数字\n");
    } else{
        printf("其它字符\n");
    }
    return 0;
}
#endif

/*
 * C语言中与mem
 * 相关的内存拷贝，拷贝的基本单位是字节，与类型无关
 *
 *
 * memcpy
 * void *memcpy(void *destination, const char *source, size_t num);
 * 函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
 * 这个含糊遇到'\0'时候不会停下
 * 如果source和destination有任何重叠，复制的结果都是未定义的
 */
#if 0
#include <assert.h>

void *my_memcpy(void *dst, const void *src, int num) {
    assert(dst && src);
    char *_dst = (char *) dst;
    const char *_src = (const char *) src;

    while (num) {
        *_dst = *_src;
        _dst++, _src++, num--;
    }
    return dst;
}


void *my_memmove(void *dst, const void *src, int num) {
    assert(dst && src);
    char *_dst = (char *) dst;
    const char *_src = (const char *) src;

    if (_dst > _src && _dst < _src + num) {
        //right -> left
        _dst = _dst + num - 1;
        _src - _src + num - 1;
        while (num) {
            *_dst++ = *_src++;
            num--;
        }
    } else {
        //left->right
        while (num) {
            *_dst++ = *_src++;
            num--;
        }
    }
    return dst;
}

struct Stu {
    char name[32];
    int age;
};

#include <string.h>

int main() {
//    const char src = "abcd1234";
//    char dst[16];
//    memcpy(dst, src, strlen(src) + 1);
//
//    struct Stu src2 = {"tom", 18};
//    struct Stu dst2;
//    memcpy(&dst2, &src2, sizeof(src2));

    char buf[16] = "abcd1234";
    my_memcpy(buf+1, buf, strlen(buf) + 1);
    printf("%s\n", buf);

    //解决内存重叠问题
//    my_memmove(buf + 1, buf, strlen(buf) + 1);
//    printf("%s\n", buf);
    return 0;
}
#endif



/*
 * memmove
 * void *memmove(void *destination, const char *void source, size_t num);
 * 和memcpy的差别就是memmove函数处理的原内存和目标内存块可以是重叠的
 * 如果源空间和目标空间出现重叠，就得使用memmove函数处理
 */
#if 0
#include <string.h>

int main() {
    const char src = "abcd1234";
    char dst[16];
    memmove(dst, src, strlen(src) + 1);
    return 0;
}
#endif

/*
 * memcmp
 * int memcmp(const void*ptr1, const void*ptr2, size_t num);
 * 与strncmp判断方式一致
 */
#if 0
#include <assert.h>
void *my_momcmp(void *dst, const void *src, size_t count){
    assert(dst && src);
    void *ret=dst;
    while(count--){
        *(char *)dst=*(char *)src;
        dst=(char *)dst+1;
        src=(char *)src+1;
    }
    return ret;
}
#include <string.h>

int main() {
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;
    n = memcmp(buffer1, buffer2, sizeof(buffer1));
    if (n > 0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
    else if (n < 0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
    else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
    return 0;
}
#endif

/*
 * 三子棋，扫雷时候用的memset
 * memset
 * 操作单位是字节
 */
#if 0
#include <string.h>
int main(){
    int a[5]={0};
    memset(a, 1, sizeof(a));
    return 0;
}
#endif
