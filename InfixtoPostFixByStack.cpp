#include <conio.h>
#include <stdio.h>
//#include <iostream.h>
#include <string.h>

#define maxx 255

struct anode{
	char ope; 
	int val;
};
struct node{
    char ope; 
	int val;
    node *l,*r;
};
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
char ope[4]={'+' , '-' , '*' , '/'};

#define maxx 255

struct anode{
	char ope; 
	int val;
};
struct node{
    char ope; 
	int val;
    node *l,*r;
};
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
char ope[4]={'+' , '-' , '*' , '/'};
