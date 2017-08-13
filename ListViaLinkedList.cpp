/*
	Cai dat danh sach lien ket
*/

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

typedef  int ElementType;
struct NodeType{
	ElementType Inf;
	NodeType *Next; 
};
typedef struct NodeType LIST;

void duyet(LIST *lp)
{
     LIST *tg;
     tg = lp;
     printf(" \n Ds dang duyet: ");
     while(tg != NULL)
     {
          printf(" %d ", tg->Inf);
          tg = tg->Next;
     }
}
 
void InsertToLast(LIST *lp, ElementType X)
{
    if(lp==NULL) return;
    
    LIST *nutx;
    nutx = (LIST*)malloc(sizeof(LIST));
    nutx->Inf = X;
    nutx->Next = NULL;
    
    LIST *tg;
    tg = lp;
    
    while(tg->Next != NULL) tg = tg->Next;
    
    tg->Next = nutx;
}

LIST *InsertToHead(LIST *lp, ElementType X)
{
    LIST *nutx;
    nutx = (LIST*)malloc(sizeof(LIST));
    nutx->Inf = X;
    nutx->Next = lp;
    
    lp = nutx;
    
    return lp;
}

LIST *Insert_Middle(NodeType *Pred, ElementType X)
{	
    LIST *TempNode;
	TempNode = (NodeType *) malloc(sizeof(NodeType));  //(1)
	TempNode->Inf=X;                                   //(1)   
	TempNode->Next=Pred->Next;                         //(2)
	Pred->Next=TempNode;                               //(3)  
	return TempNode;
}


LIST *DeleteAtHead(LIST *lp)
{
    LIST *tempprt;
    if(lp==NULL) return NULL;
    tempprt = lp->Next;
    free(lp);
    //lp = tempprt;
    //return lp;
    return tempprt;
}

void DeleteAtLast(LIST *lp)
{
    LIST *tg, *tg_old;
    if((lp==NULL)||(lp->Next==NULL)) return;
    
    tg = lp;
    tg_old;
    
    while(tg->Next != NULL) 
    {
         tg_old = tg;
         tg = tg->Next;
    }
    
    free(tg);
    tg_old->Next=NULL;
}

LIST* ghepds(LIST* h1, LIST* h2, int n, int m)
{
      LIST* t1 = h1;
      LIST* t2 = h2;
      LIST* h3 = NULL;
      
      int i=0, temp;
      for(i=0;i<n+m;i++)
      {
          if(t1==NULL)
          {
              temp = t2->Inf;
              t2=t2->Next;
          }
          else if(t2==NULL)
          {
              temp = t1->Inf;
              t1=t1->Next;
          }
          else if(t1->Inf<t2->Inf)
          {
              temp = t1->Inf;
              t1=t1->Next;
          }
          else
          {
              temp = t2->Inf;
              t2=t2->Next;
          }
          
          if(h3==NULL) h3 = InsertToHead(h3, temp);
          else InsertToLast(h3, temp);
      }
      
      return h3;
}

int ListViaLinkedList()
{
    LIST* head1=NULL;
    LIST* head2=NULL;
    LIST* head3=NULL;
    head1 = InsertToHead(head1, 1);
    InsertToLast(head1, 5);
    InsertToLast(head1, 6);
    printf(" Danh sach 1: ");
    duyet(head1);
    
    head2 = InsertToHead(head2, 2);
    InsertToLast(head2, 4);
    InsertToLast(head2, 6);
    InsertToLast(head2, 7);
    
    printf(" Danh sach 2: ");
    duyet(head2);
    
    head3 = ghepds(head1, head2, 3, 4);
    
    printf(" Danh sach 3: ");
    duyet(head3);
    
	getch();
	return 1;
}
