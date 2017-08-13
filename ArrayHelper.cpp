#include <stdio.h>
#include <conio.h>

#define MAX 10

/*=====================================================================================*/
void ArrayInput(int arr[MAX]){
	printf("Nhap vao mang so nguyen: \n");
	for(int i = 0; i < MAX; i++)
	{
		printf("A[%d]= ", i);
		scanf("%d", &arr[i]);
	}
}

/* input array 2 dimension */
void InputArray(int a[][N], int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

/* output array 2 dimension */
void OutputArray(int a[][N], int m, int n){
	printf("Mang hai chieu M:\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			printf("%d	", a[i][j]);
		}
		printf("\n");
	}
}
/*=====================================================================================*/
int FindMinInArray(int arr[MAX]){
	int min = arr[0];
	for(int i = 1; i < MAX; i ++){
		if (min > arr[i])
			min = arr[i];
	}
	
	return min;
}
/*=====================================================================================*/
int FindMaxInArray(int arr[MAX]){
	int max = arr[0];
	for(int i = 1; i < MAX; i ++){
		if (max < arr[i])
			max = arr[i];
	}
	
	return max;
}
/*=====================================================================================*/
/*
	Tim day con lon nhat (tong trong luong)
*/
void DayConMax(int arr[], int n)
{
	int maxSum = 0;
	for (int i=0; i<n; i++) {
   		for (int j=i; j<n; j++) {
   			/* in ra cac ptu trong day tu ai toi aj va tinh tong*/
   			printf("\n");
   			int sum = 0;
   			for (int k=i; k<=j; k++)
   			{
   				printf(" %d ",arr[k]);
   				/* ket thuc in ra */
          		sum += arr[k];
   			}
   			
          	/* in ra tong tuong ung tim thay */
          	printf(" co tong la %d ", sum);
          	
          	/* tinh tong chuoi con lon nhat*/
      		if (sum > maxSum )
          		maxSum = sum;
		}
	}
}
/*=====================================================================================*/

/*=====================================================================================*/

/*=====================================================================================*/
