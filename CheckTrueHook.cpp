/*
	Kiem tra ngoac dung
*/

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

int ktngoacdung(char A[], int n)
{
    int i=0,j;
    for(j=0;j<n;j++)
    {
        if(A[j]=='(') i++;
        if(A[j]==')') i--;
        if(i<0) return 0;
    }
    
    if(i==0) return 1;
    else return 0;
}

void Inkq(char A[], int n)
{
     int i;
     printf("\n1 loi giai thu duoc: ");
     for(i=0;i<n;i++)
          printf(" %c ", A[i]); 
}

void timbtdung(char A[], int k, int m, int n)
{
     int i;
     
     if(k==m+1)
     {
         if(ktngoacdung(A,n)==1)
              Inkq(A,n);
              
         return;
     }
     
     for(i=0;i<n;i++)
     {
          if(A[i]=='?')
          {
                A[i] = '(';
                timbtdung(A,k+1,m,n);
                A[i] = ')';
                timbtdung(A,k+1,m,n);
                A[i] = '?';
                break;
          }
          
     }   
}

int CheckTrueHook()
{
    char A[]={'?','?','?','?','?','?'};
    int n = 6;
    int m = 6;
    //printf(" gtri tra ve %d\n",ktngoacdung(A,4));   
    timbtdung(A,1,m,n);
 	getch();
	return 1;
}

