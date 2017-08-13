#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//---------------------------1.Khai bao cau truc 1 node-------------------------
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

//--------------------------------2.Khai bao cau truc 1 stack-------------------
struct stack
{
	node *top;
};
typedef struct stack stack;

//--------------------------------3.Khoi tao -----------------------------------
void init(stack *&s)
{
	s = (stack*)malloc(sizeof(stack));
	s->top = NULL;
}

//---------------4.Tao 1 node va gan gia tri (data ) vao node do
node *getnode(int x)
{
	node *p = (node*)malloc(sizeof(node));
	if(p==NULL)
	{
		printf("\nKhong du bo nho !");
		getch();
		return NULL;
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}

//---------------------------5.Kiem tra xem stack co rong khong----------------------
bool isempty(stack *s)
{
	if(s->top == NULL) //neu stack rong tra ve sai
	{
		return false;
	}
	return true;// stack day
}

//-----------------------------6.Ham them vao stack------------------------------------
void push(stack *&s,node *p)
{
	if(!isempty(s))
	{
		s->top = p;
	}
	else
	{
		p->next = s->top;
		s->top = p;
	}
}

//----------------------------7.Ham lay phan tu ra khoi stack------------------------
//Neu khong co dau & thi o ham instack se bao loi la x khong duoc khoi tao
bool pop(stack *&s, int &value)
{
	if(!isempty(s))
	{
		printf("\nstack rong!");
		return false;
	}
	node *p = s->top;
	s->top = s->top->next; //s->top = p->next;
	value = p->data;
	free(p);
	return true;
	//return value;
}
//---------------------------8.Ham nhap du lieu vao stack---------------------------
void nhapstack(stack *&s)
{
	int soluong;
	printf("\nNhap so luong phan tu: ");
	scanf("%d", &soluong);
	
	init(s); // Neu quen lenh nay se bao loi, bao gio cung phai co ham khoi tao truoc khi nhap
	
	for(int i = 1; i <= soluong;i++)
	{
		int x;
		printf("\nNhap so thu %d: ", i);
		scanf("%d",&x);
		node *p = getnode(x);
		push(s,p);
	}
}
//-----------------------------9.Xuat du lieu trong stack------------------------
void instack(stack *s)
{
	//int x;
	//for(node *p = s->top; p != NULL; p = p->next)
	while(isempty(s))
	{
		int x;
		pop(s,x);
		printf("%5d",x);
	}
}
//-----------------------------10.Xoa (giai phong bo nho)----------------------
void xoastack(stack *&s)
{
	node *p;
	while(s->top != NULL)
	{
		p = s->top;
		s->top = s->top->next;
		free(p);
	}
	free(s);
}

//---------------------------------10.Ham chuyen he----------------------------------
void chuyenhe(stack *&s, int socandoi, int cosocandoi)
{
	init(s);
	while(socandoi != 0)
	{
		int phandu = socandoi % cosocandoi;
		//socandoi /= cosocandoi;
		node *p = getnode(phandu);
		push(s,p);
		socandoi /= cosocandoi;
	}
}

//-------------------------11.Ham in ra he sau khi doi----------------------------------
void inhe(stack *s, int socandoi, int cosocandoi)
{
	//node *p;
	while(isempty(s))
	{
		int t;
		pop(s, t);
		if( t>= 0 && t < 10)
		{
			printf("%d",t);
		}
		else if (t == 10)
		{
			printf("A");
		}
		else if (t == 11)
		{
			printf("B");
		}
		else if (t == 12)
		{
			printf("C");
		}
		else if (t == 13)
		{
			printf("D");
		}
		else if (t == 14)
		{
			printf("E");
		}
		else if (t == 15)
		{
			printf("F");
		}
	}
}

int ChangeNumberBase()
{
	stack *s;
	//nhapstack(s);
	//instack(s);
	
	//Neu test tu day tro xuong thi khong can nhapstack(s); instack(s); nua => dong lai
	int socandoi, cosocandoi;
	printf("\nNhap so can doi: ");
	scanf("%d", &socandoi);
	printf("\nNhap he so can doi: ");
	scanf("%d", &cosocandoi);
	chuyenhe(s,socandoi,cosocandoi);
	printf("\nSo %d chuyen sang he %d la: ", socandoi, cosocandoi);
	inhe(s, socandoi, cosocandoi);
	xoastack(s);

	getch();
	return 0;
}

