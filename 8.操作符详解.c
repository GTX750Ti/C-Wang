#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#if 0
int main() { 
	int num = -1;
	/*
	* 00000000 00000000 00000000 00000001--1����
	* 00000000 00000000 00000000 00000000--1����
	* 11111111 11111111 11111111 11111111--�õ�-1
	* 
	* 00000000 00000000 00000000 00000010--2����
	* 00000000 00000000 00000000 00000001--2����
	* 11111111 11111111 11111111 11111110�õ�-2�Ĳ���
	*/
	printf("%d\n", num << 1);
	return 0;
}
#endif

#if 0
int main() {
	//int a = 11;
	//int count = 1;
	//while (a) {
	//	if(a%2 == 1){
	//		count++;
	//	}
	//	a /= 2;
	//}
	//printf("%d\n", count);

	//int num = -1;
	//int count = 0;
	//for (int i=0; i<32; ++i){
	//	if ( ((num >> i)&1) == 1 ) {
	//		count++;
	//	}
	//}
	//printf("%d\n", count);


	/*
	* 1000 0000 0000 0000 1111 1110 1111 1110
	* 1111 1111 1111 1111 0000 0001 0000 0001
	* 1111 1111 1111 1111 0000 0001 0000 0010
	*/
	//int x = 0xFEFE;
	//int count = 0;
	//while (x) {
	//	x &= (x - 1);
	//	count++;
	//}
	//printf("%d\n", count);


	//int a = 10;
	//printf("%d\n", sizeof(a));
	//printf("%d\n", sizeof a);

	//unsigned int a = 0;
	//int b = -1;
	//printf("%u\n", ~a);
	//printf("%d\n", ~b);

	//int a = 10;
	//int b = a++;
	//printf("a=%d, b=%d\n", a, b);

	//char a = 'a';
	//printf("%d\n", a);

	//int i = 0, a = 0, b = 2, c = 3, d = 4;
	//i = a++ && ++b && d++;
	///*i = a++ || ++b || d++;*/
	//printf("a=%d\n b=%d\n c=%d\n d=%d\n", a,b,c,d);

	//int a = 1;
	//int b = a == 10 ? 20 : 30;
	//printf("%d\n", b);


	/*int a = 1;
	int b = 2;
	int c = (a>b, a=b+10, a, b=a+1);
	printf("%d\n", c);*/


	//int a[5] = { 0 };
	//&a[0];
	//++a[0];
	//a[0]++;
	return 0;
}
#endif


#if 0
void show() {
	printf("show\n");
}
int main() {
	show();
	return 0;
}
#endif

int main() {
	/*char c = 'a';
	int x = c;
	printf("%d\n", c);*/

	//C������������������������ȱʡ�������͵ľ��������㡾�з�������������λ���޷�������0��
	//int a = 10;
	//int b = 20;
	//int c = 30;
	//a = b + c;
	//printf("%d\n", a);

	//��������������
	//signed char c = -1;
	//unsigned char d = -1;
	//printf("%u\n", c);//1111 1111 1111 1111 1111 1111 1111 1111
	//printf("%u\n", d);//0000 0000 0000 0000 0000 0000 1111 1111

	/*
	00000000 00000000 00000000 00000000
	   00	    00		 00		  00
	4��������λ==1��ʮ������λ
	*/
	/*char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6)
		printf("a");
	if (b == 0xb600)
		printf("b");
	if (c == 0xb6000000)
		printf("c");*/

	//char c = 1;
	//printf("%u\n", sizeof(c));//1
	//printf("%u\n", sizeof(+c));//4
	//printf("%u\n", sizeof(!c));//1
	return 0;
}