#include <stdio.h>

#if 0
/*
 * fopen
 * FILE *fopen(const char *filename, const char *mode);
 *
 * fclose
 * int *fclose(*steram);
 *
 * fputc
 * int fputc(int, FILE *steram);
 *
 * fgetc
 * int fgetc(FILE *steram);
 *
 * fputs
 * int fputs(const char *str, FILE *stream);
 *
 * fprintf指定格式写入文本
 * int fprintf(FILE *stream, const char * format, ...);
 *
 * printf
 * int printf(const char * format, ...);
 *
 * fseek偏移
 * SEEK_CUR：当前位置
 * SEEK_END：末尾
 * SEEK_SET：开头
 * int fseek(FILE *stream, long int offset, int origin);
 *
 * rewind
 * 让文件指针的位置回到文件的起始位置
 * void rewind(FILE *stream);
 */
int main() {
    //FILE ，古老的称呼：句柄
//    FILE *fp = fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\test.log.txt",
//                     "a");
//    if (NULL == fp) {
//        printf("fopen error!\n");
//        return 1;
//    }
//    for (int i = 'a'; i <= 'z'; ++i) {
////        printf("%c ", i);
////        fputc(i, stdout);
//
//        //abcd\nefg\nxyz
//        int pos = ftell(fp);
//        printf("%d ", pos);
//        fputc(i, fp);
//    }
//
//    char c='x';
//    while (c!=EOF){
//        c = fgetc(fp);
//        printf("%c ", c);
//    }

//    fputs("Hello World\n", fp);
//    fputs("Hello Bit\n", fp);
//    fputs("Hello 73\n", fp);

//    char str[64];
//    fgets(str, 64, fp);
//    printf("%s", str);
//
//    fgets(str, 64, fp);
//    printf("%s", str);
//
//    fgets(str, 64, fp);
//    printf("%s", str);

//    int d=100;
//    char c='a';
//    float f=3.14;
//    fscanf(fp, "Hello %d, hHello %c Hello %s", &d, &c, &f);
//    fprintf("Hello %d, hHello %c Hello %s\n", 100, 'a', 3.14);

//    fseek(fp, 3, SEEK_END);
//    fputc("XYZ", fp);
//    fclose(fp);

//    FILE *pFILE2 = fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\example.txt", "wb");
//    fputs("This is an example.", pFILE2);
//    fseek(pFILE2, 9, SEEK_SET);
//    fputs(" sam", pFILE2);
//    fclose(pFILE2);
//
//    FILE *pFILE3= fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\example.txt", "rb");
//    if (NULL==pFILE3){
//        printf("fopen error\n");
//        return 1;
//    }
//    fputs("This is an example.", pFILE3);
//    printf("begin:%d\n", ftell(pFILE3));
//    fseek(pFILE3, 0, SEEK_END);
//    printf("after:%d\n", ftell(pFILE3));
//    int size=ftell(pFILE3);
//    printf("size:%d\n", size);

    FILE *pFILE4= fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\example.txt", "rb");
    if (NULL==pFILE4){
        printf("fopen error\n");
        return 1;
    }
    int c='x';
    do {
        printf("begin pos: %d\n", ftell(pFILE4));
        c=fgetc(pFILE4);
        printf("end pos: %d\n", ftell(pFILE4));
//        rewind(pFILE4);//让文件指针的位置回到文件的起始位置
        fseek(pFILE4, 0, SEEK_SET);//让文件指针的位置回到文件的起始位置
        printf("%c ", c);

#include <accctrl.h>
        Sleep(100);
    } while (c!=EOF);
    return 0;
}
#endif

#if 0
/*
 * fwrite
 * size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
 *
 * feof
 * int feof(FILE *stream);
 *
 * fread
 * size_t fread(const void *ptr, size_t size, size_t count, FILE *stream);
 */
int main(){
    int a=10000;
    FILE *pf=fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\test.txt", "wb");
//    fprintf(pf, "%d", a);
    //    fwrite(&a, 4, 1, pf);
    fwrite(&a, 4, 1, stdout);
    fclose(pf);
    pf=NULL;
    return 0;
}
#endif

#if 0
#define SIZE 10

int main() {
//    double a[SIZE]={3.14,3.15,3.16,3.17};
//    FILE *fp=fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\data.txt", "w");
//    if (NULL==fp){
//        printf("fopen error\n");
//        return 1;
//    }
//    for (int i = 0; i < SIZE; ++i) {
//        fwrite(a+i, sizeof(double), 1, fp);
//    }
//    fclose(fp);

    FILE *fp2 = fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\data.txt", "w");
    if (NULL == fp2) {
        printf("fopen error\n");
        return 1;
    }
    double b[3] = {0.0};
//    size_t s = fread(b, sizeof(double), 3, fp2);
//    printf("%d\n", s);

//    while ((fread(b, sizeof(double), 3, fp2)) >= 3) {
//        for (int i = 0; i < 3; ++i) {
//            printf("%f ", b[i]);
//        }
//    }

    size_t s=fread(b, sizeof(double), 3, fp2);
    //任何操作
//    if (s<3){
//        break;
//    }
    //任何操作
    if (feof(fp2)){
        printf("read file end...!\n");
    } else{
        printf("read file end fail...!\n");
    }
    fclose(fp2);
    return 0;
}
#endif

#include <accctrl.h>
int main(){
    FILE *fp1=fopen("D:\\Progam\\jetBrains\\Clion\\文件操作\\data.txt", "w");
    if (NULL==fp1){
        printf("fopen error\n");
        return 1;
    }
    char buf[]="吃人的世界abc123";
    fwrite(buf, sizeof(buf), 1, fp1);
    fflush(fp1);//强制刷新
    printf("fflush done\n");
    printf("sleep ing...\n");
    Sleep(5000);
    printf("sleep end...\n");
    fclose(fp1);
    return 0;
}
