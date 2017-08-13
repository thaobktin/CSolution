/* 
	Cai dat ngan xep su dung ds noi don 
*/

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

struct StackNode {
    int item;
    StackNode *next;
};

struct Stack {
    StackNode *top;
};

Stack *StackConstruct() {
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
		return NULL;  // No memory
    }
    s->top = NULL;
    return s;
}

/*** Kiem tra Stack rong   ***/
int StackEmpty(const Stack *s) {
    return (s->top == NULL);
}

/*** Thông báo Stack tràn ***/
int StackFull() {
   printf("\n NO MEMORY! STACK IS FULL");  
    getch();
    return 1;
}

int StackPush(Stack *s, int item) {
    StackNode *node;
    node = (StackNode *)malloc(sizeof(StackNode)); //(1)
    if (node == NULL) {
	StackFull(); return 1;  // Tràn Stack: het bo nho
    }
    node->item = item;       //(1)
    node->next = s->top;     //(2)
    s->top = node;           //(3)
    return 0;
  }

int StackPop(Stack *s) {
    int item;
    StackNode *node;
    if (StackEmpty(s)) {        //(1)
	// Empty Stack, can't pop
	return 0;
    }
    node = s->top;             //(2)
    item = node->item;         //(3)
    s->top = node->next;       //(4)
    free(node);                //(5)
    return item;               //(6)
}

/* bai toan ngoac dung */
int ktngmo(char in)
{
    if((in=='{')||(in=='[')||(in=='('))
         return 1;
    else return 0;
}

int ktracungkieu(char a, char b)
{
    if(a=='{')
        if(b=='}') return 1;
        else return 0;
        
    if(a=='[')
        if(b==']') return 1;
        else return 0;
        
    if(a=='(')
        if(b==')') return 1;
        else return 0;
    
}

int kiemtrangoacdung(Stack *s, char in[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
         if(ktngmo(in[i])==1)
         {
             // dua vao stack
             StackPush(s, in[i]);
         }
         else{//ngoac dong
              if(StackEmpty(s)!=0) return 0;
              else
              {
                  char tempchar = StackPop(s);
                  if(ktracungkieu(tempchar,in[i])==0)
                  return 0;
              }
         }
    }
    
    if(StackEmpty(s)!=0) return 1;
    else return 0;
}

int StackViaList()
{
    Stack *s = StackConstruct();
    int i;
    for(i=0;i<100;i++)
        StackPush(s, i);
    for(i=0;i<100;i++)
        printf("\n%d",StackPop(s));
    
    char A[]={'{','[',']',']','(',')'};
    int i = kiemtrangoacdung(s, A, 6);
    printf(" ket qua la %d\n",i);
    
	getch();
	return 1;
}

