#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*=====================================================================================*/
/* Hoan vi*/
void Permute(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*=====================================================================================*/
void SelectionSort(int a[], int n)
{
	int b[], k;
	int i, j, min;

	for(i = 0; i < n - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n; j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		Permute(&a[i], &a[min]);
	}
}
/*=====================================================================================*/
void BubbleSort(int a[], int n)
{
	for(int i=n; i>1; i--)
	{
		for(int j=1; j<i; j++)
		{
			if(a[j-1] > a[j])
			{
				Permute(&a[j-1], &a[j]);
			}
		}
	}
}
/*=====================================================================================*/
#define MAX_SIZE 1000

typedef int DataType;

void merge(DataType A[], int first, int mid, int last){   
   DataType tempA[MAX_SIZE];    // mang pha
     
   int first1 = first; int last1 = mid;    
   int first2 = mid + 1; int last2 = last; int index = first1;     
   for (; (first1 <= last1) && (first2 <= last2); ++index){             
       if (A[first1] < A[first2])      {  
         tempA[index] = A[first1]; ++first1;}      
       else
       {tempA[index] = A[first2]; ++first2;}
   }
   for (; first1 <= last1; ++first1, ++index)      
      tempA[index] = A[first1]; // sao not dãy con 1
    for (; first2 <= last2; ++first2, ++index)
      tempA[index] = A[first2]; // sao not dãy con 2
    for (index = first; index <= last; ++index)
      A[index] = tempA[index]; // sao tra mang ket qua
}  // end merge

void mergesort(DataType A[], int first, int last)
{   
   if (first < last)   
   {  // chia thành hai dãy con      
      int mid = (first + last)/2;    // chia se diem giua
      // sap xep dãy con trái A[first..mid]      
      mergesort(A, first, mid);
      // sap xep dãy con phai A[mid+1..last]
      mergesort(A, mid+1, last);
      // Tron hai dãy con      
      merge(A, first, mid, last);   
  }  // end if 
}  // end mergesort
/*=====================================================================================*/
void quick_sort(int *a,int l,int r)
{
  if(r>l)
     {  int k;
	k= part(a,l,r);
	quick_sort(a,l,k-1);
	quick_sort(a,k+1,r);
     }
}
int part(int *a,int l,int r)
{
	  int ls,t,k;
	  k=(l+ r)/2;
	  swap(&a[l],&a[k]);
	  ls=l;
	  while((a[ls+1]<=a[l])&&(ls<r))
	  {
		  ls++;
	  }
	  t=ls+1;
	  while((a[l]<a[t])&&(t<r))
	  {
		  t++;
	  }
	  while(t<=r)
	  {
		  if(a[t]<a[l])
		  {
			  swap(&a[ls+1],&a[t]);
			  ls++;
		  }
		  t++;
	  }
	  swap(&a[l],&a[ls]);
	  k=ls;
	return k;
}

void swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/
