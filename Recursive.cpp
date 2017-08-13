#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

/*=====================================================================================*/
/*
	cai dat cong thuc de qui:
       f(0) = 3,               n = 0
       f(n+1) = 2f(n) + 3,     n > 0 
*/
int hamf(int n)
{
	/* in ra */
	printf("Bat dau goi ham voi dau vao la %d\n",n);
	if(n==0) 
	{
		printf("tra ve gia tri 3 khi n=0\n");
		return 3;
	}
	else
	{
		printf("goi de qui ham %d\n",n-1);
		int k = 2*hamf(n-1)+3;
		printf("tra ve gia tri %d khi n=%d\n",k,n);
		return k;
	}
}
/*=====================================================================================*/
/* 
	cai dat ham de qui de tinh n!
       f(n) = 0! = 1, n=0
       f(n) = f(n-1)*n, n>0
*/
int giaithua(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		int k = n * giaithua(n-1);
		printf("Ham voi dau vao %d tra ve %d\n",n,k);
		return k;
	}
}
/*=====================================================================================*/
/* 
	cai dat ham de qui de tinh x^n (n>=0)
       f(n) = 1, n = 0
       f(n) = f(n-1)*x , n > 0
*/
int power(int x, int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		int k = power(x, n-1)*x;
		//printf("Ham voi dau vao %d tra ve %d\n",n,k);
		return k;
	}
}
/*=====================================================================================*/
/* 
	Bai toan thap Hanoi
	Chuyen A sang B lay C lam trung gian 
*/
int HanoiTower(char A, char B, char C, int n)
{
	if (n <= 0) printf("Khong hop le");
	if (n == 1) 
	{
		printf("Chuyen dia tu cot %c sang cot %c.\n", A, B);	
	}
	else{
		HanoiTower(A, C, B, n - 1);			// Chuyen n-1 dia tu A sang C lay B lam trung gian
		HanoiTower(A, B, C, 1);				// Chuyen 1 dia tua A sang B
		HanoiTower(C, B, A, n - 1);			// Chuyen n-1 dia tu C sang B lay A lam trung gian
	}
}
/*=====================================================================================*/
int FindMin(int A[], int n)
{
	if(n == 1) return A[0];
	else
	{
		if(FindMin(A, n-1) < A[n-1]) 
			return FindMin(A, n-1);
		else 
			return A[n-1];
	}
}
/*=====================================================================================*/
/* 
	De quy Fibo khong nho (NOT have memory) 
*/
int Fibo(int n)
{
	printf("Ham fibo voi n=%d\n", n);
	
	if(n < 2) 
		return n;
	else 
		return Fibo(n-1) + Fibo(n-2);
}
/*=====================================================================================*/
/* 
	De quy Fibo co nho (have memory) 
*/
int FibowMem(int A[], int n)
{
	printf("Ham fibo voi n=%d\n",n);
	if(n < 2) 
		return n;
	else 
	{
		if(A[n-1]==-1) A[n-1] = Fibowmem(n-1);
		if(A[n-2]==-1) A[n-2] = Fibowmem(n-2);
		return  A[n-1] + A[n-2];
	}
}
/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/
