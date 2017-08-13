#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int key,ht;
	struct TreeNode* left, *right;
} node;

node* insert(node*, int);
node* Delete(node*, int);
void preorder(node*);
void inorder(node*);
int height( node*);
node* rotateright(node*);
node* rotateleft(node*);
node* RR(node*);
node* LL(node*);
node* LR(node*);
node* RL(node*);
node* search(node*,int);
node* findmax(node*);
node* findmin(node*);
int bal(node*);
node* makeBalance(node*);
void DelTree(node*);

int AVLTree()
{
	node* root;
	int x, n, i, op;
	do
	{
		printf("\n0)Thoat");
		printf("\n1)Khoi tao");
		printf("\n2)Chen");
		printf("\n3)Xoa");
		printf("\n4)In thu tu giua");
		printf("\n5)Tim max, min");
		printf("\n6)Tim kiem");
		printf("\nNhap yeu cau: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1: 
			printf("\nSo nut cua cay ban dau: ");
			scanf("%d",&n);
			printf("\nNhap du lieu: ");
			root = NULL;
			for (i = 0; i < n; i++)
			{
				printf("\nKhoa thu %d: ", i + 1);
				scanf("%d", &x);
				root = insert(root, x);
			}
			break;
			
			case 2: 
			printf("\nNhap khoa can chen: ");
			scanf("%d", &x);
			root = insert(root, x);
			break;
			
			case 3:
			printf("\nNhap khoa can xoa: ");
			scanf("%d", &x);
			root = Delete(root, x);
			break;
			
			case 4: 
			printf("\nCay theo thu tu giua: \n");
			inorder(root);
			break;
			
			case 5: 
			printf("\nKhoa lon nhat la: %d", findmax(root)->key);
			printf("\nKhoa nho nhat la: %d", findmin(root)->key);
			break;
			
			case 6:
			printf("\nNhap khoa can tim kiem: ");
			scanf("%d", &x);
			int suc, pre;
			if (!search(root, x)) printf("\nKhong tim thay");
			else printf("\nTim thay");
		}
	} while(op);
	DelTree(root);
	return 0;
}

//Ham tinh He so can bang Balance Factor
int bal(node* T)
{
	if (!T) return 0;
	int lh = 0, rh = 0;
	if (T->left) lh = 1 + T->left->ht;
	if (T->right) rh = 1 + T->right->ht;
	return(lh - rh);
}

void inorder(node* T)
{
	if (T)
	{
		inorder(T->left);
		printf(" %d(bal = %d)", T->key, bal(T));
		inorder(T->right);
	}
}

node* insert(node* T, int x)
{
	if (!T)
	{
		T = (node*)malloc(sizeof(node));
		T->key = x;
		T->left = NULL;
		T->right = NULL;
	}
	else if (x > T->key) T->right = insert(T->right, x);
	else if(x < T->key) T->left = insert(T->left, x);
	T->ht = height(T);
	T = makeBalance(T);
	return T;
}

node* Delete(node* T, int x)
{
	if (!T) return NULL;
	node* p;
	if (x > T->key) T->right = Delete(T->right, x);
	else if (x < T->key) T->left = Delete(T->left, x);
	else
	{
		// find out
		// case 4
		if (T->left && T->right)
		{
			p = findmin(T->right);
			T->key = p->key;
			T->right = Delete(T->right, p->key);
		}
		// case 1, 2, 3
		else 
		{
			node* tmp = T;
			if (!T->left) T = T->right;
			else if (!T->right) T = T->left;
			else T = NULL;
			free(tmp);
		}
	}
	T->ht = height(T);
	T = makeBalance(T);
	return T;
}

node* makeBalance(node* T)
{
	int b = bal(T);
	// if abs(bal(T)) != 2 
	if ((b & 3) != 2) return T;
	if (b > 0) 
	{
		if (bal(T->left) >= 0) return LL(T);
		return LR(T);
	}
	else
	{
		if (bal(T->right) >= 0) return RL(T);
		return RR(T);
	}
}

int height(node* T)
{
	int lh = 0, rh = 0;
	if (!T) return 0;
	if (T->left) lh = 1 + T->left->ht;
	if (T->right) rh = 1 + T->right->ht;
	return rh > lh ? rh : lh;
}
// only use for Root
node* rotateright(node* x)
{
	node* y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}
// only use for Root
node* rotateleft(node* x)
{
	node* y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);
	return y;
}
// only use for Root
node* RR(node* T)
{
	T = rotateleft(T);
	return T;
}
// only use for Root
node* LL(node* T)
{
	T = rotateright(T);
	return T;
}
// only use for Root
node* LR(node* T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return T;
}
// only use for Root
node* RL(node* T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return T;
}

node* findmin(node* T)
{
	while (T->left) T = T->left;
	return T;
}

node* findmax(node* T)
{
	while (T->right) T = T->right;
	return T;
}

node* search(node* T, int x)
{
	if (T)
	{
		if (x < T->key) T = search(T->left, x);
		else if (x > T->key) T = search(T->right, x);
	}
	return T;
}

void DelTree(node* T)
{
	if (!T) return;
	DelTree(T->left);
	DelTree(T->right);
	free(T);
}
