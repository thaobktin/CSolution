/* 
	Virus prototype
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

typedef long (_stdcall * FUNC3)(long num,long tmp,long a,long b);

long _stdcall Func2(long a, long b)
{
    return (a + b);
}

void _stdcall Func1(long num) // h�m n�y do m�nh goi �, c�c ban ko d�ng cung duoc
{
	// code v�o d�y
	long p = ((long)&num) - 4;
    long *p2 = (long *)p;

    p2[2] = p2[0];
    p2[0] = (long)Func2; // Lay dia chi h�m Func2 g�n v�o bien cho ko c� goi d�u nha
}

int main(int argc, char* argv[])
{
    long a = 20;
    long b = 30;

	// code v�o d�y
	FUNC3 Func3 = (FUNC3)Func1; 
    long tong = Func3(0,0,a,b);
    printf("Tong:%d",tong);
    getch();
    return 0;
}

