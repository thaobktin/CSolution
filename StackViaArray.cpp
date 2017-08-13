/* Cai dat ngan xep su dung mang  */

#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

struct Stack
{
	int so[30];
	int top;
};
 
struct DoubleStack {
    int PhanTu[101];
    int n1; //so phan tu cua ngan xep 1
    int n2; //so phan tu cua ngan xep 2
};

void CreateS(Stack & S) {
    S.top = 0;
}

void Push(Stack & S, int n) {
    S.top++;
    S.so[S.top] = n;
}

int Pop(Stack & S) {
    if (S.top > 0) {
        S.top--;
        return S.so[S.top + 1];
    } else return -1;
}

void TaoRong(DoubleStack & S) {
    S.n1 = 0; //bat dau luu tru tai vi tri 1
    S.n2 = 101; //bat dau luu tru tai vi tri 100
}

//them vao dau ngan xep
void Push1(DoubleStack & S, int phantu) {
    if (S.n1 >= 50) {
        cout << "\nNgan xep day";
        return;
    }
    S.PhanTu[++S.n1] = phantu;
}

void Push2(DoubleStack & S, int phantu) {
    if (S.n2 <= 50) {
        cout << "\nNgan xep day";
        return;
    }
    S.PhanTu[--S.n2] = phantu;
}

//lay mot phan tu o dinh ngan xep
int Pop1(DoubleStack & S) {
    if (S.n1 <= 0 || S.n1 >= 50) {
        cout << "\nNgan xep rong hoac day";
        getch();
        return -1;
    }
    return S.PhanTu[S.n1--];
}

int Pop2(DoubleStack & S) {
    if (S.n2 <= 50 || S.n2 >= 101) {
        cout << "\nNgan xep rong hoac day";
        getch();
        return -1;
    }
    return S.PhanTu[S.n2++];
}

//nhap va luu tru ngan xep kep
void Nhap(DoubleStack & S) {
    char str[99];
    cout << "\nNhap vao mot day so nguyen";
    gets(str);
    for (int i = 1; i <= strlen(str); i++) {
        Push1(S, int(str[i - 1]) - 48);
        Push2(S, int(str[i - 1]) - 48);
    }
}

//xuat ngan xep kep
void Xuat1(DoubleStack S) {
    for (int i = S.n1; i >= 1; i--)
        cout << S.PhanTu[i];
    getch();
}

void Xuat2(DoubleStack S) {
    for (int i = S.n2; i <= 100; i++)
        cout << S.PhanTu[i];
    getch();
}

int DinhGiaHauTo(List & L) {
    int tam1, tam2;
    Stack S;
    CreateS(S);
    int n = 0;
    Node * N = L.First - > Right;
    for (int i = 0; i <= L.n; i++) {
        n = int(N - > Info - 48);
        if (n >= 1 && n <= 9)
            Push(S, n);
        else {
            tam1 = Pop(S);
            tam2 = Pop(S);
            switch (N - > Info) {
            case '+':
                tam1 = tam2 + tam1;
                break;
            case '-':
                tam1 = tam2 - tam1;
                break;
            case '*':
                tam1 = tam2 * tam1;
                break;
            case '/':
                tam1 = tam2 / tam1;
                break;
            };
            Push(S, tam1);
        }
        N = N - > Right;
    }
    return Pop(S);
}

int DinhGiaTienTo(List & L) {
    int tam1, tam2;
    Stack S;
    CreateS(S);
    int n = 0;
    Node * N = L.Last - > Left;
    for (int i = 0; i <= L.n - 1; i++) {
        n = int(N - > Info - 48);
        if (n >= 1 && n <= 9)
            Push(S, n);
        else {
            tam1 = Pop(S);
            tam2 = Pop(S);
            switch (N - > Info) {
            case '+':
                tam1 = tam2 + tam1;
                break;
            case '-':
                tam1 = tam2 - tam1;
                break;
            case '*':
                tam1 = tam2 * tam1;
                break;
            case '/':
                tam1 = tam2 / tam1;
                break;
            };
            Push(S, tam1);
        }
        N = N - > Left;
    }
    return Pop(S);
}

void StackViaArray() {
    clrscr();
    DoubleStack A;

    TaoRong(A);
    Nhap(A);
    cout << "\nDoubleStack 1= ";
    Xuat1(A);
    cout << "\nDoubleStack 2= ";
    Xuat2(A);

    getch();
}
