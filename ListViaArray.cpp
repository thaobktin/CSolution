/*
	Cai dat danh sach dung mang
*/

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

# define maxlength 1000

typedef int elementtype; /* elements are integers */ 

typedef struct list_tag 
{
	elementtype elements[maxlength];
	int last;
} list_type;
/*=====================================================================================*/
elementtype end (list_type *lp)
{
    return (lp->last +1);
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Empty(list_type &list)
{
	list.n = 0;
}

//nhap va luu tru theo thu tu
void Nhap(list_type *lp) {
    char str[99];
    cout << "\nNhap vao mot day so nguyen";
    gets(str);
    for (int i = 1; i <= strlen(str); i++)
        InsertToLast(lp, int(str[i - 1]) - 48);
}

//them vao dau sanh sach
void InsertToFirst(list_type *lp, elementtype element) {
    for (int i = lp.n; i >= 1; i--)
        lp.elements[i + 1] = lp.elements[i];
    lp.elements[1] = element;
    lp.n++;
}

//them vao cuoi danh sach
void InsertToLast(list_type *lp, elementtype element) {
    lp.n++;
    lp.elements[lp.n] = element;
}

//nhap va luu tru nguoc voi thu tu nhap
void NhapNguoc(list_type *lp) {
    char str[99];
    cout << "\nNhap vao mot day so nguyen";
    gets(str);
    for (int i = 1; i <= strlen(str); i++)
        InsertToFirst(lp, int(str[i - 1]) - 48);
}

void Insert(elementtype x , int p , list_type *lp)
{   
	int v;		//running position
	
    if (lp->last >= maxlength - 1)
    {    
		printf("\n%s ","list is full");
         return;
    }
    if ((p < 0) || (p > lp->last + 1))
    {    
		printf("\n%s ","position does not exist"); 
         return;
    }     
    else 
	{
    	for (int q = lp->last; q >= p; q--) 
        	lp->elements[q+1] = lp->elements[q];
    	lp->last = lp->last +1 ;
    	lp->elements[p] = x;
    } 
}

void DeleteL(int p , list_type *lp) 
{ 
   int q; /* running position */
   if ((p > lp-> last) || (p < 0))
   {     
         printf("\n%s ","position does not exist"); 
         return;
   }
   else /* shift elements */ {
      lp -> last --;     
      for (int q = p; q <= lp ->last; q++)
         lp -> elements [q] = lp -> elements [q+1]; 
   } 
}

//xoa nhung phan tu trung nhau trong danh sach
void DeleteDuplicate(list_type * lp) {
    for (int i = 1; i <= lp.n - 1; i++) {
        if (lp.elements[i] == lp.elements[i + 1]) {
            DeleteL(lp, i + 1);
            i--;
        }
    }
}

//them vao vi tri k trong sanh sach
void InsertToK(list_type & DS, int phantu, int k) {
    int i, n = DS.n, j = DS.n - k + 1;
    for (i = 1; i <= j; i++) //dich chuyen cac phan tu sau vi tri k lui 1
    {
        DS.elements[n + 1] = DS.elements[n];
        n--;
    }
    //them vao vi tri k
    DS.elements[k] = phantu;
    DS.n++;
}

//tim vi tri thich hop va them vao sanh sach
void Them(list_type & DS, int phantu) {
    if (DS.n == 0) InsertToFirst(DS, phantu);
    else if (phantu < DS.elements[1]) InsertToFirst(DS, phantu);
    else if (phantu > DS.elements[DS.n]) InsertToLast(DS, phantu);
    else
        for (int i = 1; i <= DS.n - 1; i++)
            if (DS.elements[i] < phantu && DS.elements[i + 1] > phantu) {
                InsertToK(DS, phantu, i + 1);
                i = DS.n; //ket thuc vong lap(chi them 1 lan)
            }
}

void TronDS(list_type & A, list_type & B, list_type & C) {
    int i;
    for (i = 1; i <= A.n; i++)
        Them(C, A.elements[i]);
    for (i = 1; i <= B.n; i++)
        Them(C, B.elements[i]);
}

void Tach(list_type & A, list_type & B, list_type & C) {
    for (int i = 1; i <= A.n; i++)
        if (A.elements[i] % 2 == 0)
            Them(B, A.elements[i]);
        else Them(C, A.elements[i]);
}

void SapXepTang(list_type *lp) {
    int tam;
    for (int i = 1; i < lp.n; i++)
        for (int j = i + 1; j <= lp.n; j++)
            if (lp.elements[i] > lp.elements[j]) {
                Swap(lp.elements[i], lp.elements[j]);
            }
}

void PrintList(list_type * lp)
{
     int i;
     printf("\nCac ptu in ra:\n");
     for(i=0;i<lp->last;i++)
        printf("%d\n",lp->elements[i]);
}

int ListViaArray()
{
    list_type *danhsach1;
    danhsach1 = (list_type*)malloc(sizeof(list_type));
    
    insert(100, 0, danhsach1);
    insert(-20, 1, danhsach1);
    insert(-30, 1, danhsach1);
    insert(-40, 1, danhsach1);
    deleteL(2, danhsach1);
    PrintList(danhsach1);
    
    
	getch();
	return 1;
}

