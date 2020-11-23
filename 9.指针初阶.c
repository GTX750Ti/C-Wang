#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#if 0
int main() { 
	//int a = 10;
	//int* p = &a;
	//p = 100;
	//*p = 100;
	//int** pp = &p;

	/*int arr[10] = { 0 };
	int* pi = (int*)arr;
	short* ps = (short*)arr;
	char* pc = (char*)arr;

	char** pcc = &pc;
	printf("############\n");
	printf("%p\n", arr);
	printf("%p\n", pi);
	printf("%p\n", ps);
	printf("%p\n", pc);
	printf("############\n");
	printf("%p\n", ++pi);
	printf("%p\n", ++ps);
	printf("%p\n", ++pc);*/

	/*int a = 0x11223344;
	char* p = (char*) & a;
	int* q = &a;
	*p = 0x55;
	*q = 0;*/

	int* p=0x1234;//野指针
	*p = 1234;

#define N_VALUES 5
	float values[N_VALUES];
	float* vp;
	for (vp = &values[0]; vp < &values[N_VALUES];) {
		*vp++ = 0;
	}
	//这种写法不规范：标准规定允许指向数组元素的指针与指向数组最后一个元素的
	for (vp = &values[N_VALUES]; vp>values[0]) {
		*--vp = 0;
	}
	return 0;
}
#endif

#if 0
int Strlen(const char* str)
{
	if (str == NULL) {
		return 0;
	}
	char* end = str;
	while (*end) {
		end++;
	}
	return end - str;
}
int main() 
{
	const char* str = "abcd1234";
	int len = Strlen(str);
	printf("%d\n", len);
	return 0;
}
#endif

#if 0
int main()
{
	int a[10] = {0};
	int* p = a;
	int* q = &a[9];
	//指针相加减得到的是中间元素个数
	printf("%d\n", q-p);
	return 0;
}
#endif

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; ++i) {
		//printf("%d ", arr[i]);
		//printf("%d ", p[i]);
		//printf("%d ", *(p+i));
		printf("%d ", *(arr+i));
	}
	return 0;
}
