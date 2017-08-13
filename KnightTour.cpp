#include <stdio.h>
#include <conio.h>

#define N 8
#define false 0
#define true !false

/* Ham kiem tra xem vi tri x,y co hop le khong */
int isSafe(int x, int y, int sol[N][N])
{
	if ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
	return 1;
	return 0;
}

/* Ham in ket qua */
void printSolution(int sol[N][N])
{
	int x;
	
	for (x=0;x<N;x++)
	{
		int y;
		for (y=0;y<N;y++)
		printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

/* Ham de qui quay lui giai bai toan ma tuan */
int BacktrackKT(int x, int y, int k, int sol[N][N], int xMove[N], int yMove[N])
{
	int i, next_x, next_y;
	if (k == N*N)
		return true;

	/* Thu tat ca 8 UCV tu vi tri hien tai x, y */
	for (i = 0; i < 8; i++)
	{
		next_x = x + xMove[i];
		next_y = y + yMove[i];
		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = k;
			if (BacktrackKT(next_x, next_y, k+1, sol, xMove, yMove) == true)
				return true;
			else
				sol[next_x][next_y] = -1;// Quay lui
		}
	}

	return false;
}

/* Ham chinh giai bai toan ma tuan */
int solveKT(int sx,int sy)
{
	int sol[N][N],x,y;

	/* Khoi tao ma tran loi giai */
	for (x=0;x<N;x++)
		for (y=0;y<N;y++)
			sol[x][y] = -1;

	/* Co 8 buoc chuyen cua quan ma xung quanh vi tri hien tai
	xMove[] cho gia tri hang buoc chuyen tiep
	yMove[] cho gia tri cot buoc chuyen tiep */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Khoi tao gia tri cho vi tri ban dau
	sol[sx][sy] = 0;

	/* Bat dau tu toa do sx,sy */
	if(BacktrackKT(sx,sy,1,sol,xMove,yMove) == false)
	{
		printf("Khong ton tai loi giai");
		return false;
	}
	else
		printSolution(sol);

	return true;
}

int main()
{
	int sx,sy;
	printf("Cho biet vi tri khoi dau : \n");
	printf("Hang = "); scanf("%d",&sx);
	printf("Cot = "); scanf("%d",&sy);
	
	solveKT(sx,sy);
	
	getch();
	return 0;
}

