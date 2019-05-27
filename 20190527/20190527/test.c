#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//1!+2!+3!+.....+n!
//1*1 +  1*2+ 1*2*3 = 9;

int main()
{
	int i = 0;
	int n = 0;
	int j = 0;
	int sum = 0;
	int ret = 1;
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
	{
		ret = ret*i;
		/*ret = 1;
		for(j = 1;j <= i;j++)
		{
			ret = ret*j;
		}*/
		sum = sum+ret;
	}
	printf("%d\n",sum);
	return 0;
}

#if 0
int main()
{
	int i = 0;
	//百度：数组在什么时候确定大小的？编译
	//数组在什么时候分配内存的？运行
	//数组最大开辟多大内存？栈--》1M-2M
	int arr[10] = {0};
	printf("%p\n",&i);
	printf("%p\n",arr);
	//arr[10] = 1;
	//printf("%d\n",&i);
	//printf("%d\n",&arr[0]);
	//printf("%d\n",&arr[9]);
	
	for(i = 0;i <= 12;i++)
	{
		arr[i] = 0;//10  11  12
		printf("hehe\n");
	}/**/
	return 0;
}


#define SIZE 10
#define  INTPTR int*
 typedef int* INT_PTR;

 struct Student
 {
	 char name[20];
	 int age;
	 //struct Student stu;
	  struct Student *pstu;
 };

int main()
{
	int *p = NULL;
	//断言失败 下面程序将不会被执行
	assert(p != NULL);// DEBUG
	if(p == NULL) 
	{
		printf("p == NULL\n");
		return;
	}
	//int arr[10] = {1,2,3,4,5};
	//arr = {5,6,7,8,9};
	/*int a = 10;
	int b = 20;
	INT_PTR p1,p2;
	p1 = &a;
	p2 = &b;*/

	/*int arr[3] = {0};
	const  int *p = arr;
	 int *const p2 = arr;*/


	//int (*p)[3] = &arr;
	return 0;
}
#endif