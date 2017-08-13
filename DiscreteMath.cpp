#include <stdio.h>
#include <conio.h>

/*=====================================================================================*/
/* Tinh so mat thu tu Dn */
int D(int n)
{
	int Dres;
	
	if (n <= 0) Dres = 0;
	else if (n == 1) Dres = 0;
	else if (n == 2) Dres = 1;
	else Dres = (n - 1) * (D(n - 1) + D(n - 2));
	
	return Dres;	
}
/*=====================================================================================*/
/* So phan mat phang duoc chia boi n duong thang */
int S(int n)
{
	int ret;
	
	if (n <= 0) ret = 0;
	if (n == 1) ret = 2;
	else ret = S(n - 1) + n;
	
	return ret;
}
/*=====================================================================================*/
/* So Fibonaci thu n */
int Fibonaci(int n)
{
	if (n < 0) return 0;
	if (n == 0 || n == 1) return 1;
	else{
		return Fibonaci(n - 1) + Fibonaci(n - 2);
	}
}
/*=====================================================================================*/
/* Check n is Fibonaci */
int IsFibonacci(int n){
	int a = 1, b = 1;
	int c;
	
	if (n==a || n==b) return 1;
	
	c = a + b;
	while (c <= n){
		if (c==n) return 1;
		a = b;
		b = c;
		c = a + b;
	}
	return 0;
}
/*=====================================================================================*/
/* Count Fibonaci in space from n to m */
int CountFibonacci(int n, int m){
	int count = 0;
	if (n > m) return -1;
	
	for (int i = n; i <= m; i++)
	{
		if (IsFibonacci(i) == 1) {
			printf("%d\n", i);
			count++;	
		}
	}
	return count;
}
/*=====================================================================================*/
/* 
	Vi du don gian backtrack.
	Cho 2 mang so.
	Tim cap so co tong bang 10. 
	Moi so duoc chon tu 1 trong 2 mang da cho.
*/
int UCV(int D[], int i, int k, int kq[])
{
	if(k == 1) 
		return 1;
	if(k == 2)
	{
		if((D[i] + kq[0]) == 10) 
			return 1;
		else 
			return 0;
	}
	
	return 0;
}

void backtrack_vidu1(int k)
{
	int i;
	for(i=0; i<4; i++)
	{
		if(UCV(D, i, k, kq) == 1)
		{
			if(k==1) kq[0] = C[i];
			if(k==2) kq[1] = D[i];
			
			if(k == 2) 
				printf("\n mot loi giai %d %d \n", kq[0], kq[1]);
		    else 
				backtrack_vidu1(k+1);
		}
	}
}
/*=====================================================================================*/
int UCV(int ai, int kq[], int k)
{
    int i;
    for(i=0; i<k-1; i++)
    {
    	if(kq[i] == ai) return 0;
    }
    
    return 1;
}
void HienThiHv(int A[], int kq[], int k, int n)
{
     int i;
     for(i=0; i<n; i++)
     {
          if(UCV(A[i], kq, k) == 1)
          {
              kq[k-1] = A[i];
              if(k==n) 
			  	for(i=0; i<n; i++)
			    	printf(" %d", kq[i]);
			 	printf(" \n");
              else 
			  	HienThiHv(A, kq, k+1, n);
          }
     }
}
/*=====================================================================================*/
void Inkq()
{
	int i;
    printf(" kq:");
    for(i=0; i<n; i++)
    	printf(" %d", kq[i]);
    printf(" \n");
}

int UCV(int ai, int kq[], int k)
{
    for(int i=0; i<k-1; i++)
    {
        if(kq[i] == ai) 
			return 0;
        if(abs(kq[i]-ai) == abs(k-i-1)) 
			return 0;
    }
    
    return 1;
}

void DatHau(int kq[], int k, int n)
{
     int i;
     for(i=0;i<n;i++)
     {
		if(UCV(i+1, kq, k)==1) 
		{
			kq[k-1] = i+1;
			if(k == n) 
				Inkq();
			else 
				DatHau(kq, k+1, n);
		}
     }
}
/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

