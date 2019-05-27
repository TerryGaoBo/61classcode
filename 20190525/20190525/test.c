#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
    
//这里修改了                   








int main()
{
	char c = 1;
	printf("%u\n",sizeof(c));
	printf("%u\n",sizeof(+c));
	printf("%u\n",sizeof(!c));
	return 0;
}

#if 0 
/*
数组  结构体  聚合类型
如果对整体进行初始化，只有一次机会
那就是定义的同时进行初始化

*/
/**
调试：
打断点：F9   -->
启动调试：F5
逐过程：F10  
逐语句：F11-->进入函数内部

窗口：监视   内存  寄存器

int  a = 10;
00000000000000000000000000001010

00000000000000000000000000000101
00000000000000000000000000000001
0
*/
//123
void print1(int num)
{
	if(num > 9)
	{
		print1(num/10);
	}
	printf("%d\n",num%10);
}
//123%10 3     123/10=12 12%10 2  12/10=1  1%10=1  1/10=0;
void print(int num)
{
	int tmp = 0;
	if(num < 0)
	{
		num = -num;
		printf("-");
	}
	
	while(num != 0)
	{
		tmp = num%10;
		printf("%d ",tmp);
		num = num/10;
	}
	printf("\n");
}
//0111
//0110
//0001
int DiffBit(int m,int n)
{
	int tmp = m ^ n;
	int count = 0;
	while(tmp != 0)
	{
		count++;
		tmp = tmp&(tmp-1);
	}
	return count;
}
//arr:  {1,3,2,5,5,3,2,7,1,9}
//
//0011
//0000
//0001

void Function(int *arr,int len,int *px,int *py)
{
	int i = 0;
	int pos = 0;
	int sum = 0;
	for(i = 0;i < len;i++)
	{
		sum = sum ^ arr[i];
	}
	//7 ^ 9  -==> 1110
	//找到从右往左数的第pos位为1的位
	for(i=0;i < 32;i++)
	{
		if(((sum>>i)&1) == 1)
		{
			pos = i;
			break;
		}
	}
	//分割数组
	for(i = 0;i < len;i++)
	{
		if(((arr[i]>>pos)&1) == 1)
		{
			*px = *px^arr[i];
		}
		else
		{
			*py = *py^arr[i];
		}
	}
}
int main()
{
	int arr[] = {1,3,2,5,5,3,2,7,1,91};
	int len = sizeof(arr)/sizeof(arr[0]);
	int x = 0;
	int y = 0;
	Function(arr,len,&x,&y);
	printf("%d,%d\n",x,y);
	return 0;
}

int main()
{
	int arr[] = {1,3,2,5,5,3,2,7,1,91};
	int len = sizeof(arr)/sizeof(arr[0]);
	int x = 0;
	int y = 0;
	//全部异或
	int i = 0;
	int pos = 0;
	int sum = 0;
	for(i = 0;i < len;i++)
	{
		sum = sum ^ arr[i];
	}
	//7 ^ 9  -==> 1110
	//找到从右往左数的第pos位为1的位
	for(i=0;i < 32;i++)
	{
		if(((sum>>i)&1) == 1)
		{
			pos = i;
			break;
		}
	}
	//分割数组
	for(i = 0;i < len;i++)
	{
		if(((arr[i]>>pos)&1) == 1)
		{
			x = x^arr[i];
		}
		else
		{
			y = y^arr[i];
		}
	}
	printf("%d,%d\n",x,y);
	/*int n = DiffBit(1999,2299);
	printf("%d\n",n);*/
	return 0;
}

int main()
{
	int n = 3;
	int i = 0;
	for(i = 31;i >= 1; i -= 2)
	{
		printf("%d ",(n>>i)&1);
	}
	printf("\n");
	for(i = 30;i >= 0;i -= 2)
	{
		printf("%d ",(n>>i)&1);
	}
	printf("\n");
	return 0;
}



void test3()
{
	printf("test3");
}
void test2()
{
	test3();
}
void test()
{
	test2();
}
int main()
{
	test();
	//char i = 0;//-128-127  //'0'  '\0'  0  NULL
	//for(i = 0;i < 130;i++)
	//{
	//	printf("%d ",i);
	//}
	//printf("\n");
	return 0;
}

typedef struct Student
{
	char name[20];
	int age;
}Student;

typedef struct Person
{
	char name[20];
	int age;
}Person;

void PrintStruct1(Student stu[],int len)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		printf("%s,%d\n",stu[i].name,stu[i].age);
	}
}
void PrintStruct(Student *pstu,int len)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		printf("%s,%d\n",pstu[i].name,
			pstu[i].age);
	}
}

void Show1(Person per)
{
	printf("%s,%d\n",per.name,per.age);
}

void Show(Person *per)
{
	printf("%s,%d\n",(*per).name,(*per).age);
}
struct 
{
	char name[20];
	int age;
}animal;

int main()
{
	Person per = {"han",99};

	/*Student stu[2] = {{"caocao",88},
	{"libei",99}};
	int len = sizeof(stu)/sizeof(stu[0]);
	PrintStruct(stu,len);*/
	/*int i = 0;
	for(i = 0;i < 2;i++)
	{
		printf("%s,%d\n",stu[i].name,stu[i].age);
	}*/

	return 0;
}


typedef struct Student
{
	char name[20];//
	int age;
	//char id[20];
	int id;
	char sex[10];
}Stu;

typedef struct Node
{
	int data;
	struct Node *next;
	//struct Node node;//结构体的自引用
}Node,*pNode;

int main()
{
	int arr[10] ={1,2,3,45,7};
	//arr = {1,2,3,4,5};
	//struct Student stu1;
	Stu student = {"caocao",18,110,"man"};
	student.age = 99;
	strcpy(student.name,"sunquan");
	//student.name = "sunquan";
	//student = {"liubei",19,119,"man"};
	return 0;
}



//由变量提升为对应的类型
typedef int ARR[10];
typedef int (*PARR)[4];
typedef int * PARR2[4];
typedef int (*pFun)(int,int);
//const 
//define
//typedef
#define INT_PTR int* 
typedef int* INT_PTRR;
int main()
{
	int a = 10;
	int b = 20;
	//const INT_PTR p1 = &a;
	//p1 = &b;
	//*p1 = 99;error

	const INT_PTRR p1 = &a;
	//p1 = &b;error
	*p1 = 99;/**/

	/*ARR arr= {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	for(i = 0;i < 10;i++)
	{
		printf("%d ",arr[i]);
	}
	int a = 10;
	int b = 20;
	INT_PTRR p1,p2;
	p1 = &a;
	p2 = &b;*/
	


	//INT_PTR p1,p2;
	//p1 = &a;//int *
	////p2 = &b;
	//p2 = 99;//整型


	/* const int * p = &a;
	int const *p1 = &a;
	int *const p2 = &a;*/
	/*p = &b;
	*p = 99;*/
	return 0;
}





//数组指针 :指向数组的指针
//指针数组 int* arr[3]
int main()
{
	int arr[4] = {1,2,3,4};
	int (*p) [4] = &arr;//

	//int arr1[4] = {1,2,3,4};
	//int arr2[4] = {5,6,7,8};
	//int arr3[4] = {9,10,11,12};
	//int* arr[3] = {arr1,arr2,arr3};
	//int len = sizeof(arr)/sizeof(arr[0]);
	//printf("%d\n",len);
	/*int i = 0;
	int j = 0;
	for(i = 0;i < 3;i++ )
	{
		for(j = 0;j < 4;j++)
		{
			printf("%d ",*(*(arr+i)+j));
		}
		printf("\n");
	}*/
	return 0;
}


int main()
{
	char* str[3] = {"hello","da","boge"};
	int i = 0;
	for(i = 0; i < 3;i++)
	{
		//str+i
		printf("%s\n",*(str+i));
	}
	return 0;
}


void Show(int *p,int len)
{
	int i = 0;
	for(i = 0;i < len;i++)
	{
		//printf("%d ",p[i]);//[]  自带解引用
		printf("%d ",*(p+i));
	}
	printf("\n");
}
int main()
{
	/*int b = 20;
	int *pa = &b;
	int **ppa = &pa;*/
	//*ppa = &b;
	//int arr[10] = {1,2,3,4,5,6,7,8,9};
	//int *p = arr+1;
	//int *q = arr+3;
	////指针减指针  一定要指向同一块内存
	//printf("%d\n",q-p);
	//int a = 10;
	//int b = 20;
	//int *p = &a;
	//int *q = &b;
	//printf("%d\n",&a);
	//printf("%d\n",&b);
	/*int arr[10] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("arr==%d\n",arr);
	printf("&arr == %d\n",&arr);
	printf("%d\n",&arr+1);*/

	//Show(arr,len);
	//int *p = arr;

	//printf("%p\n",arr);//数组首元素的地址
	//printf("%p\n",&arr[0]);
	return 0;
}


int main()
{
	int n = 0x11223344;
	char *pc = (char*)&n;
	int *pi = &n;
	*pi = 0;
	*pc = 0x99;
	return 0;
}

int main()
{
	int n = 0x12345678;
	char *pc = (char*)&n;//int*
	if(*pc == 0x78)
	{
		printf("is little\n");
	}
	else
	{
		printf("is not little\n");
	}
	//printf("%x\n",*pc);
	//int *pi = &n;

	/*int a = 10;
	int *p = &a;
	printf("%p,%p",p,p+1);
	char a = 'g';
	char *p = &a;
	printf("%p,%p",p,p-1);*/

	return 0;
}


int main()
{

	int a =10;
	int* p = &a;
	//*p = 100;
	void *pp = &a;  //无类型的指针，不能进行解引用
	//*pp = 99;
	printf("%d\n",sizeof(pp));
	//int *pp = NULL;
	/*double d = 12.5;
	double* pd = &d;
	printf("%lf\n",*pd);//第一节浮点数的存储
*/
	//printf("%d\n",sizeof(pd));
	return 0;
}

int fun()
{
	static int count = 1;
	return ++count;
}
int main()
{
	int answer;
	answer = fun() - fun() * fun();
	printf( "%d\n", answer);//输出多少？
	return 0;
}


int main()
{
	int c = 2;
	printf("%d\n",c + --c);
	//double d = 12.5;
	//unsigned int a = 10;
	//int c = a+d;

	/*char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(!c));*/

	/*char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	if(a==0xb6)
	printf("a");
	if(b==0xb600)
	printf("b");
	if(c==0xb6000000)
	printf("c");*/
	return 0;
}

int main()
{
	char ch = 0xff;
	//1111 1111 1111 1111 1111 1111 1111 1111
	//111 1111 1111 1111 1111 1111 11111 1110
	ch = (ch>>1)<<1;
	//ch = ch>>1;//0xff
	printf("%x\n",ch);
	//char ch = -1;
	////11111111111111111111111111111111
	////11111111111111111111111111111111
	//printf("%d\n",ch);
	//char ch2 = 1;
	////00000000000000000000000000000001
	////00000000000000000000000000000001
	//printf("%d\n",ch2);
	//unsigned char a = 200;
	//unsigned char b = 60;
	//unsigned char c = 0;
	//c = a+b;//260
	//printf("%d,%d\n",a+b,c);
	return 0;
}


//表达式1,表达式2,dddd,,,,
int Max(int a,int b)
{
	return a > b?a:b;
}
struct Student
{
	char name[20];
	int age;
};
struct A
{
	int a;
	int b;
};
struct B
{
	struct A* pa;
	struct A Aa;
	int c;
};
int main()
{
	struct B ba;
	ba.pa->a;
	ba.pa->b;
	ba.Aa.a;
	ba.c;


	 //struct Student stu1;
	 //struct Student *pstu = &stu1;
	 //(*pstu).age = 10;
	 ////*pstu.age = 10;
	 //(*pstu).name;
	 //pstu->age = 18;
	 //pstu->name;

	 //stu1.age = 18;
	 //stu1.name = "caocao";
	 //strcpy(stu1.name,"cocao");

	//Max(10,20);
	//int a = (2+3)*5;
	//int arr[10] = {1};
	//arr[9] = 0;
	////int[10] arr;
	//int a = 10;
	return 0;
}
#endif