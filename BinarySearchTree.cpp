#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> // du`ng cho ham tao cay ngau nhien


//=============== 1.Cau truc 1 node ==================
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node NODE;

//================ 2.Khoi tao cay.==================
void INIT(NODE *&T)
{
	T = (NODE*)malloc(sizeof(NODE));
	//T->left = T->right = NULL;
	T = NULL;
}

//================== 3.Them node vao cay. ==================
void Insert(NODE *&T, NODE *p)
{
	// Tru?ng h?p Node c?n th�m v�o l� Node r?ng.
	if(p == NULL)
	{
		return;//K�t thu�c
	}
	
	// Tru?ng h?p c�y r?ng.
	if(T == NULL)
	{
		T = p; // G�n Node p l�m Node g?c c?a c�y.
		return;
	}
	
	// Tru?ng h?p b? tr�ng Node.
	if(T ->data == p ->data)
	{
		return;
	}
	//Xe�t 1 node la` g��c cu?a 1 c�y: node co� gia� tri? nho? hon g��c -> ga�n va`o node b�n tra�i
	//node co� gia� tri? lo�n hon g��c -> ga�n va`o node b�n pha?i -> cu� d�? quy nhu v�?y
	if(T ->data < p ->data)// or d�~ nhi`n: p->Data > T->Data
	{
		Insert(T ->right, p); // �? quy.
	}
	else
	{
		Insert(T ->left, p); // �? quy.
	}
}

//================== 4.H�m t?o 1 Node.==================
NODE* GetNode(int x)
{
	NODE* p = new NODE;
	if(p == NULL)
	{
		printf("\nKhong du bo nho !");
		getch();
		return NULL;
	}
	p ->data = x;
	p ->left = NULL;
	p ->right = NULL;
	return p;
}

/* ====================== Duy?t c�y ====================== */
//================== 5.Duy�?t truo�c : NLR <=> Node Left Right
void NLR(NODE* T)
{
	if(T == NULL)
	{
		return;
	}
	printf("%5d",T->data);
	NLR(T ->left);
	NLR(T ->right);
}
//================== 6.Duy�?t giu~a ==================
void LNR(NODE* T)
{
	if(T == NULL)
	{
		return;
	}
	LNR(T ->left);
	printf("%5d",T->data);
	LNR(T ->right);
}
//================== 7.Duy�?t sau ==================
void LRN(NODE* T)
{
	if(T == NULL)
	{
		return;
	}
	LRN(T ->left);
	LRN(T ->right);
	printf("%5d",T->data);
}

//============== 8.H�m nh?p m?ng c�c s? nguy�n - h? tr? t?o c�y t? m?ng.
void NhapMang(int *a, int n) //hoa?c NhapMang(int a[], int n) cu~ng duo?c
{
	for(int i = 0; i < n; i++)
	{
		printf("\nNhap phan tu thu %d: ", i);
		scanf("%d",(a+i));//hoa?c &a[i] cu~ng duo?c
	}
}

//================== 9.H�m th�m c�c s? nguy�n t? m?ng v�o c�y.
void CreateTreeFromArray(NODE *&T, int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		NODE *p = GetNode(a[i]);
		Insert(T, p);
	}
}

//================== 10.H�m t?o c�y - random.==================
void CreateAutoTree(NODE *&T)
{
	int n;
	int x;
	printf("\nNhap vao so luong Node can tao ngau nhien: ");
	scanf("%d", &n);
	
	srand(time(0));
	
	printf("\nDay so nguyen duoc Random la:\n");
	for(int i = 1; i <= n; i++)
	{
		x = (rand() % 50) - 10;
		printf("%5d",x);
		NODE* p = GetNode(x);
		Insert(T, p);
	}
}

//================== 12.H�m d?m s? Node tr�n c�y.==================
int DemSoNutTrenCay(NODE *T)
{
	if(T == NULL)
	{
		return 0;
	}
	
	int DemLeft = DemSoNutTrenCay(T ->left);
	int DemRight = DemSoNutTrenCay(T ->right);
	return 1 + DemLeft + DemRight;
}

//================== 13.1 D�ng d? quy.==================
bool TimKiemNodeCoGiaTriX_DeQuy(NODE *T, int x)
{
	if(T == NULL)
	{
		return false;
	}
	
	if(T ->data == x)
	{
		return true;
	}
	
	else if(T ->data < x)
	{
		TimKiemNodeCoGiaTriX_DeQuy(T ->right, x);
	}
	
	else
	{
		TimKiemNodeCoGiaTriX_DeQuy(T ->left, x);
	}
}

//================== 13.2 Kh�ng d�ng d? quy.==================
bool TimKiemNodeCoGiaTriX_KhongDeQuy(NODE *T, int x)
{
	NODE* p = T;
	while(p != NULL)
	{
		if(p ->data == x)
		{
			return true;
		}
		else if(p ->data > x)
		{
			p = p ->left;
		}
		else
		{
			p = p ->right;
		}
	}
	return false;
}

//================== 14.1 H�m ki?m tra t?t c? c�c ph?n t? tr�n c�y c� > x hay kh�ng.
bool KiemTraLonHonX(NODE *T, int x)
{
NODE* p = T;
while(p != NULL)
{
if(p ->data <= x)
{
return false;
}
p = p ->left;
}
return true;
}
//================== 15.Ti`m gia� tri? lo�n nh�t tr�n c�y nhi? ph�n ti`m ki�m
int TimMax_KhongDeQuy(NODE *T)
{
NODE* p = T;
int Max;
while(p != NULL)
{
Max = p ->data;
p = p ->right;
}
return Max;
}
//================== 15.1 Ti`m min
int TimMin_KhongDeQuy(NODE *T)
{
NODE* p = T;
int Min;
while(p != NULL)
{
Min = p ->data;
p = p ->left;
}
return Min;
}
//================== 15.2 ==================
int Max;
void TimMax_DeQuy(NODE *T)
{
if(T == NULL)
{
return;
}

TimMax_DeQuy(T ->left);
Max = T ->data;
TimMax_DeQuy(T ->right);
}
//================== 15.3 ==================
int Min;
void TimMin_DeQuy(NODE* T)
{
if(T == NULL)
{
return;
}

TimMin_DeQuy(T ->right);
Min = T ->data;
TimMin_DeQuy(T ->left);
}
//================== 16.Xo�a c�y ==================
//void XoaCay(NODE *T) vi�t nhu na`y co� le~ ko du�ng !
// {
// NODE *p;
// while(T)
// {
// p = T->left;
// free(p);
// p = T->right;
// free(p);
// }
// }

///////////////////////////////////////////
//void XoaCay(NODE *& n)
//{
//	if (!n) return;
//	if (n->left || n->right)
//	{
//		XoaCay(n->left);
//		XoaCay(n->right);
//	}
//	else
//	{
//		free(n);
//		n = NULL;
//	}
//}

/*Ham XoaCay sau d�y do Cu?ng Ph?m vi�t : cha?y dc ! */
void XoaCay(NODE *& T)
{
	if (!T) return;
	if (T->left || T->right)
	{
		XoaCay(T->left);
		XoaCay(T->right);
	}
	else
	{
		free(T);
		T = NULL;
	}
}
//================== 17.Ham Main ==================
int BinarySearchTree()
{
	NODE *T;
	INIT(T);
	printf("\n\n\t\t========== MENU =================\n\n\t\t");
	printf("\n\n\t\tA. Duyet cay NPTK");
	printf("\n\n\t\tB. Them 1 Node vao cay");
	printf("\n\n\t\tC. Dem so Node tren cay");
	printf("\n\n\t\tD. Tim kiem 1 Node x");
	printf("\n\n\t\tE. Thoat");
	printf("\n\n\t\t===========================\n\n\t\t");
	
	printf("\n\n\t\ta. Tao cay Nhi Phan Tim Kiem: \n\n\t\t");
	printf("\n\n\t\tChon 1.Tao cay tu Mang\n\n\t\t");
	printf("\n\n\t\tChon 2.Tao cay random\n\n\t\t");
	int Choose;
	printf("\nBan chon cach tao cay la 1 hay 2: ");
	scanf("%d",&Choose);
	
	if(Choose == 1)
	{
		printf("\n\n\t\tBan chon tao cay tu mang: \n\n\t\t");
		int n;
		printf("\n\n\t\tNhap vao so luong phan tu cua mang: ");
		scanf("%d", &n);
		int *a = (int*)malloc(n*sizeof(int));
		NhapMang(a, n);
		CreateTreeFromArray(T, a, n);
		free(a);
	}
	else if (Choose == 2)
	{
		printf("\n\n\t\tBan chon tao cay ngau nhien: \n\n\t\t");
		CreateAutoTree(T);
	}
	
	while(true){
		printf("\n\n\t\tMoi ban chon cac thao tac trong MENU: \n\n\t\t");
		char Choose1;
		scanf("%c",&Choose1);
		if(Choose1 == 'a')
		{
			printf("\n\n\t\tBan chon duyet cay: \n\n\t\t");
			/* =============== Duyet cay theo 3 cach =============== */
			printf("\n\n\t\t* Duyet truoc: NLR *\n\n\t\t");
			NLR(T);
			
			printf("\n\n\t\t* Duyet giua: LNR *\n\n\t\t");
			LNR(T);
			
			printf("\n\n\t\t* Duyet sau: LRN *\n\n\t\t");
			LRN(T);
		}
		else if ( Choose1 == 'b')
		{
			printf("\n\n\t\tBan chon THEM NODE vao cay: \n\n\t\t");
			printf("\n\n\t\tNhap gia tri nut can them: ");
			int x;
			printf("\n\n\t\tNhap vao gia tri x can them vao cay: ");
			scanf("%d",&x);
			NODE* p = GetNode(x);
			Insert(T, p);
			
			printf("\n\n\t\tCay sau khi them Node co gia tri %d la: ",x);
			printf("\n\n\t\t* NLR *\n");
			NLR(T);
		}
		else if ( Choose1 == 'c')
		{
			printf("\n\n\t\tBan chon dem so nut hien co tren cay: ");
			printf("\n\n\t\tSo luong Node hien co tren cay la: %d ",DemSoNutTrenCay(T));
		}
		else if ( Choose1 == 'd')
		{
			printf("\n\n\t\tBan chon tim kiem gia tri 1 node co tren cay khong: ");
			int x1;
			printf("\n\n\t\tNhap vao gia tri x can tim kiem: ");
			scanf("%d",&x1);
			if(TimKiemNodeCoGiaTriX_KhongDeQuy(T, x1))
			{
				printf("\n\n\t\tTrong cay co ton tai Node co gia tri la %d",x1);
			}
			else
			{
				printf("\n\n\t\tTrong cay khong ton tai Node co gia tri la %d",x1);
			}
		}
		else if ( Choose1 == 'e')
		{
			break; // Ket thuc chuong trinh
		}
	}
	XoaCay(T);
	
	getch();
	return 0;
}

