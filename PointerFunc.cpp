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

void _stdcall Func1(long num) // hàm này do mình goi ý, các ban ko dùng cung duoc
{
	// code vào dây
	long p = ((long)&num) - 4;
    long *p2 = (long *)p;

    p2[2] = p2[0];
    p2[0] = (long)Func2; // Lay dia chi hàm Func2 gán vào bien cho ko có goi dâu nha
}

int main(int argc, char* argv[])
{
    long a = 20;
    long b = 30;

	// code vào dây
	FUNC3 Func3 = (FUNC3)Func1; 
    long tong = Func3(0,0,a,b);
    printf("Tong:%d",tong);
    getch();
    return 0;
}

