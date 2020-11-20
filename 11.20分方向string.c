#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <assert.h>

#if 0
int main()
{
	//int c = toupper('a');
	int c = tolower('A');
	printf("%c\n", c);
	system("pause");
	return 0;
}
#endif

#if 0
/*
* void * memcpy(void *destination, const void *source, size_t num);
* ��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ��
* �ڴ濽���������Ļ�����Ԫ���ֽڣ��������޹�
*/
#include <string.h>
struct Stu {
	char name[32];
	int age;
};
int main()
{
	//memcpy vs memmove����
	/*struct Stu src = { "Tom", 20 };
	struct Stu dst;
	memcpy(&dst, &src, sizeof(src));*/

	/*const char* src = "a/*bcd1234";
	char dst[16];
	memcpy(dst, src, strlen(src)+1);*/

	int a[] = { 0 };
	memset(a, 1, sizeof(a));//ע��mem*������λ���ֽ�
	return 0;
}
#endif


#if 0
//ģ��ʵ��strcpy
char* my_strcpy(char *dest, const char *src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
//ģ��ʵ��strcat
char* my_strcat(char *src, const char *dest)
{
	assert(dest && src);
	char* start = src;
	while (*start)
	{
		start++;
	}
	while (*start = *dest)
	{
		start++, src++;
	}
	return src;
}
//ģ��ʵ��strstr
const char* my_strstr(const char* str, const* sub_str){
	assert(str && sub_str);
	while (*str) {//ȷ����ʼλ��
		const char* p = str;
		const char* q = sub_str;
		while (*p && *q && *p == *q) {//�ֲ��Ƚ�
			p++;
			q++;
		}
		if (*q == '\0') {
			return str;
		}
		str++;
	}
	return 0;
}
int main(){
	const char* str = "abc 123 abcd 1234 abcdef";
	const char* sub_str = "1234";
	const char* s = my_strstr(str, sub_str);
	puts(my_strstr(str, sub_str));
	return 0;
}
#endif


void *my_memcpy(void *dst, const void *src, int num){
	assert(dst && src);
	char* _dst = (char *)dst;
	const char* _src = (const char*)src;
	while (num) {
		*_dst = *_src;
		_dst++;
		_src++;
		num--;
	}
	return dst;
}

void* my_memmove(void* dst, const void* src, int num) {
	assert(dst && src);
	char* _dst = (char*)dst;
	const char* _src = (const char*)src;
	if (_dst > _src && _dst < _src+num) {
		//right->left
		_dst += num-1;
		_src += num-1;
		while (num) {
			*_dst = *_src;
			_dst--;
			_src--;
			num--;
		}
	}
	else {
		//left->right
		while (num) {
			*_dst = *_src;
			_dst++;
			_src++;
			num--;
		}
	}
	return dst;
}
int main() {
	int a[10] = { 1,2,3,4,5 };
	int b[10] = { 0 };
	char buf[16] = "abcd1234";
	//my_memcpy(buf, buf+1, sizeof(buf)+1);
	my_memmove(buf+1, buf, strlen(buf)+1);
	printf("%s\n", buf);
}