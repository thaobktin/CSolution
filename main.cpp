#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

/*=====================================================================================*/
/*
	This solution develop on Dev-C++ 5.7.1
*/
/*=====================================================================================*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int ret = IsPrime(13);
	printf("%d", ret);
	
	getch();
	return 0;
}

void NoSemicolon()
{
    if (printf("\x3B")) {}
    if (printf("\x3B")) {}
    if (printf("\x3B")) {}
    if (printf("\x3B")) {}
    switch (printf("\x3B")) { case 1:{} }
    switch (printf("\x3B")) { case 2:{} }
    switch (printf("\x3B")) { case 3:{} }
    while (!printf("\x3B")) {}
    while (!printf("\x3B")) {}
    while (!printf("\x3B\n-- Satisfied ?!?! --\n")){}
}
