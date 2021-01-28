#include <stdio.h>

/*
 * FILE *fopen(const char *filename, const char *mode);
 */
int main() {
    //FILE ，古老的称呼：句柄
    FILE *fp = fopen("test.log", "w");
    if (NULL == fp) {
        printf("fopen error!\n");
        return 1;
    }

    for (int i = 'a'; i <= 'z'; ++i) {
//        fputs(i, fp);

        int pos=ftell(fp);
        printf("%d ", pos);
        putc(i, fp);
    }

    //文件的格式化读取与输出
    /*
     * int fprintf(FILE *stream, const char *format, ...);
     */
//    fprintf(fp, "hello %d, hello %c, hello %f\n", 100, 'c', 3.14);
//    int d=0;
//    char c=0;
//    float f=0;
//    fscanf(fp, "hello %d, hello %c, hello %f\n", &d, &c, &f);

    //一行一行读取
//    char str[64];
//    fgets(str, 64, fp);
//    printf("%s\n", str);

    //一个一个读
//    int c = 'x';
//    while (c!=EOF){
//        c=fgetc(fp);
//        printf("%c ", c);
//    }

    //一行一行写
//    fputs("HelloWorld!\n",fp);
//    fputs("HelloBit!\n",fp);
//    fputs("Hello73!\n",fp);

    //一个一个写
//    for (int i = 'a'; i <= 'z'; ++i) {
////        printf("%-2c", i);
////    fputc(i, stdout);
//        fputc(i, fp);//文件中写入
//    }
    fclose(fp);
    return 0;
}
