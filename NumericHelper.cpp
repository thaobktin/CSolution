#include <stdio.h>
#include <conio.h>

#define PI 3.1415
#define N 5

/*=====================================================================================*/
unsigned int TongBacBa(int n){
	int i = 0;
	unsigned int sum = 0;
	
	while (i <= n) {
		sum += i*i*i;
		i++;
	};
	
	return sum;
}
/*=====================================================================================*/
void InUocSo(int n){
	int i = 1;
	while(i <= n){
		if(n % i == 0){
			printf("%d ", i);
		}
		i++;
	}
}
/*=====================================================================================*/
int SumNumeral(int n){
	int s = 0;
	
	while(n!=0){
		s = s + n % 10;
		n = n / 10;
	}
	return s;
}
/*=====================================================================================*/
void InverseNum(long n) {
	if (n == 0) return;
	else {
		cout << n % 10;
		InverseNum(n / 10);
	}
}

float HaiMuN(int n) {
    if (n < 0) return 1 / HaiMuN(-n);
    if (n == 0) return 1;
    else return 2 * HaiMuN(n - 1);
}

float XmuY(int x, int y) {
    if (y < 0) return 1 / XmuY(x, -y);
    if (x == 0) return 0;
    else if (y == 0) return 1;
    else return x * XmuY(x, y - 1);
}
/*=====================================================================================*/
void DecimalToBinary(int n){
	if(n == 0) return;
	DecimalToBinary(n / 2);
	if(n % 2 == 0) 
		printf("0");
	else 
		printf("1");
}
/*=====================================================================================*/
void DecimalToHexadecimal(int n){
	if(n == 0) return;
	DecimalToHexadecimal(n / 16);
	if(n % 16 == 0) 
		printf("0");
	else if(n % 16 == 1)
		printf("1");
	else if(n % 16 == 2)
		printf("2");
	else if(n % 16 == 3)
		printf("3");
	else if(n % 16 == 4)
		printf("4");
	else if(n % 16 == 5)
		printf("5");
	else if(n % 16 == 6)
		printf("6");
	else if(n % 16 == 7)
		printf("7");
	else if(n % 16 == 8)
		printf("8");
	else if(n % 16 == 9)
		printf("9");
	else if(n % 16 == 10)
		printf("A");
	else if(n % 16 == 11)
		printf("B");
	else if(n % 16 == 12)
		printf("C");
	else if(n % 16 == 13)
		printf("D");
	else if(n % 16 == 14)
		printf("E");
	else if(n % 16 == 15)
		printf("F");
}
/*=====================================================================================*/
int UCLN(int a, int b){
	int r = 0;
	
	while(b!=0){
		r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}
unsigned long USCLN(unsigned long a, unsigned long b)
{
    while((a!=0)&&(b!=0))
    {
        if(a>=b)
            a-=b;
        else
            b-=a;                 
    }
    if(a==0)
        return b;
    else
        return a;
}

unsigned long BSCNN(unsigned long a, unsigned long b)
{
    return (a*b)/USCLN(a,b);
}
/*=====================================================================================*/
/*Tai sao phai xet tu 2 den can bac hai cua a.
  De dang chung minh neu a la hop so, thi se co it nhat 1 uoc # 1 <= sqrt(a)
  Boi neu tat ca ca uoc deu > sqrt(a) thi uoc1 * uoc2 > a. */
int IsPrime(int n)
{
	int ret, sqn, i;
	
    if (n < 2) return 0;
	sqn = (int)floor(sqrt((float)n));
	
	i = 0;
	while((i <= sqn) && (n % i == 0)){
		i++;
		return 0;
	}
    
    return 1;
}
/*=====================================================================================*/
int Inverse(int n)
{
    int numeral;
    while(n>0)
    {
        numeral=n%10;
        n=n/10;
        if(IsPrime(numeral)) return 1;
		
        return 0;
    }
}
/*=====================================================================================*/
void Swap1(int a, int b){
	a^=^b=^a=b;
}
void Swap2(int a, int b){
a-=b=(a+=b)-b;
}
void Swap3(int a, int b){
	a/=b=(a*=b)/b;
}
/*=====================================================================================*/
int calFactorial(int n){
	int mul = 1;
	for (int i = 1; i <= n; i++) mul *= i;
	return mul;
}
/*=====================================================================================*/
/* m(m-1)...(m-n+1) / n! */
int calCombination(int m, int n){
	int Cmn=1;
	int A=1, B=1;
	
	for(int i=m; i>(m-n+1); i--) A *= i;
	for(int i=n; i>0; i--) B *= i;
	Cmn = A/B;
	
	return Cmn;
}
/*=====================================================================================*/
/* calculate C(m,n) - C(p,q) */
int DiffCmnCpq(int m, int n, int p, int q){
	int diff = 0;
	
	diff = calCombination(m, n) - calCombination(p, q);
	return diff;
}
/*=====================================================================================*/
