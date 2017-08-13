#include <conio.h>
#include <stdio.h>

struct PolyNode{
	int coef;
	int pow;
	struct PolyNode * next;
}

typedef PolyNode Polynom;
Polynom *PolySum(Polynom *Poly1, *Poly2);
Polynom *PolyMult(Polynom *Poly1, *Poly2);

Polynom *PolyMult(Polynom *Poly1, *Poly2)
{
	Polynom *tree1, *tree2, *tree3, *Poly3;
	tree1 =(Polynom*)malloc(sizeof(Polynom)); //thay the cho Poly1
	tree2 =(Polynom*)malloc(sizeof(Polynom)); //thay the cho Poly2
	Poly3 =(Polynom*)malloc(sizeof(Polynom)); //Da thuc luu ket qua sau moi lan cong them
	tree3 =(Polynom*)malloc(sizeof(Polynom)); //luu gia tri tich cua 1 ptu Poly1 voi ca Poly2
	tree4 =(Polynom*)malloc(sizeof(Polynom)); //luu dia chi tree3
	tree1 = Poly1;
	tree4 = tree3;
	while (tree1!= NULL)
	{
		tree2 = Poly2;
		while(tree2!=NULL)
		{
			tree3->coeff=tree1->coeff*tree2->coeff;		//nhan co so
			tree3->pow = tree1->pow + tree2->pow;		//cong so mu
			tree2 = tree2->next;
			tree3 = tree3->next;
		}
		Poly3 = PolySum(Poly3, tree4);
		tree1 = tree1->next;
	}
}
