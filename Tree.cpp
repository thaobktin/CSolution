#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

struct Tnode
{
	char word;                 // Du lieu cat giu o node
	struct Tnode *left;
	struct Tnode *right;
};
typedef struct Tnode treeNode;
treeNode *root;

treeNode *makeTreeNode(char X)
{
     treeNode *t;
     t = (treeNode*)malloc(sizeof(treeNode));
     if(t == NULL) 
     {
          printf("Ko the cap phat bo nho");
          return NULL;
     }
     t->word = X;
     t->left = NULL;
     t->right = NULL;
     return t;
}

void preorder(treeNode *root)
{
     if(root == NULL) return;
     printf(" %c ",root->word);
     preorder(root->left);
     preorder(root->right);
}

void inorder(treeNode *root)
{
     if(root == NULL) return;
     inorder(root->left);
     printf(" %c ",root->word);
     inorder(root->right);
}

void postorder(treeNode *root)
{
     if(root==NULL) return;
     postorder(root->left);
     postorder(root->right);
     printf(" %c ",root->word);
}

int countnode(treeNode *root)
{
    if(root==NULL) return 0;
    
    int l = countnode(root->left);
    int r = countnode(root->right);
    
    return l+r+1;
}

int depth(treeNode *root)
{
    if(root==NULL) return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    
    if(l>r) 
		return l+1;
    else 
		return r+1;
}

treeNode *delete(treeNode *T, float x){
	treeNode tmp;
	if(T == NULL) 
		printf("not found");
	else if(x< T->key) 
		T->leftPtr = delete(T->leftPtr,x);
	else if(x> T->key) 
		T->rightPtr = delete(T->rightPtr,x);
	else /*Tìm duoc phan tu can xóa */
	if(T->leftPtr && T->rightPtr){/* Tình huong 4 */
		tmp = findmin(T->right);
		T->key = tmp-> key;
		T->rightPtr = delete(T->key,T->rightPtr);
	}else{/* có mot con hoac không có con*/
		tmp = T;
		if(T->leftPtr==NULL)/* chi có con phai */
			T = T->rightPtr;
		else /* chi có con trái */
			T = T->leftPtr;
		free(tmp);
	}
	return(T);
}

int Tree()
{
    treeNode *root1;
    treeNode *nutA = makeTreeNode('A');
    root1 = nutA;
    
    treeNode *nutB = makeTreeNode('B');
    treeNode *nutC = makeTreeNode('C');
    
    nutA->left = nutB;
    nutA->right = nutC;
    
    treeNode *nutD = makeTreeNode('D');
    treeNode *nutE = makeTreeNode('E');
    treeNode *nutF = makeTreeNode('F');
    treeNode *nutG = makeTreeNode('G');
    
    nutB->left = nutD;
    nutB->right = nutE;
    
    nutC->left = nutF;
    nutC->right = nutG;
    
    treeNode *nutH = makeTreeNode('H');
    nutF->left = nutH;
    
    printf(" duyet truoc: \n");
    preorder(root1);
    printf("\n duyet sau: \n");
    postorder(root1);
    printf("\n duyet giua: \n");
    inorder(root1);
    
    printf("\n so nut tren cay: \n");
    int n = countnode(root1);
    printf("%d",n);
    
    printf("\n cay co do sau: \n");
    int level = depth(root1);
    printf("%d",level);
    
    getch();
	return 1;
}

