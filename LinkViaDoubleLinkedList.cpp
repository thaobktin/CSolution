#include <stdio.h> 
#include <iostream.h> 
#include <conio.h> 
#include <math.h> 
#include <string.h>

struct Node {
    int Info;
    Node * Left;
    Node * Right;
};

struct List {
    Node * First;
    Node * Last;
    int n;
};

void Create(List & L) {
    L.First = new Node;
    L.Last = new Node;
    L.First - > Left = NULL;
    L.First - > Right = L.Last;
    L.Last - > Left = L.First;
    L.Last - > Right = NULL;
    L.n = 0;
}

int Emty(List & L) {
    return (L.First - > Right == L.Last);
}

//hien thi danh sach
void Display(List & L) {
    cout << "\n\n";
    Node * N = new Node;
    N = L.First - > Right;
    for (int i = 1; i <= L.n; i++) {
        cout << N - > Info;
        N = N - > Right;
    }
}

//vao sau ra truoc (them vao dau danh sach)
void Add_LIFO(List & L, int phantu) {
    Node * N = new Node;
    N - > Info = phantu;
    N - > Left = L.First;
    N - > Right = L.First - > Right;
    L.First - > Right - > Left = N;
    L.First - > Right = N;
    L.n++;
}

//vao truoc ra sau (them vao cuoi danh sach)
void Add_FILO(List & L, int phantu) {
    Node * N = new Node;
    N - > Info = phantu;
    N - > Right = L.Last;
    N - > Left = L.Last - > Left;
    L.Last - > Left - > Right = N;
    L.Last - > Left = N;
    L.n++;
}

//nhap va luu tru theo thu tu nhap vao hoac nguoc lai
void Add_And_Insert(List & L) {
    char ch = '1';
    int sx = 0;
    cout << "Ban muon sap xep day so theo thu tu nao ?";
    cout << "\n  Nhan phim '1' neu theo thu tu nhap\n  Nhan phim bat ky neu nguoc lai";
    cin >> sx;
    cout << "Nhap vao mot day so nguyen: ";
    while (int(ch) >= 48 && int(ch) <= 57) {
        ch = getch();
        cout << ch;
        if (int(ch) >= 48 && int(ch) <= 57)
            if (sx == 1) Add_FILO(L, int(ch) - 48);
            else Add_LIFO(L, int(ch) - 48);
    }
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SapXepTang(List & L) {
    Node * tam1 = new Node;
    Node * tam2 = new Node;
    tam1 = L.First;
    while (tam1 -> Right -> Right != L.Last) //chay tu Node dau tien cho den Node ke cuoi
    {
        tam1 = tam1 -> Right;
        while (tam2 -> Right != L.Last) //chay tu Node tam den Node cuoi
        {
            tam2 = tam1 -> Right;
            if (tam1 -> Info > tam2 -> Info)
                Swap(tam1, tam2);
        }
    }
}

void XoaPhanTu(List & L, int pt) {
    Node * tam = new Node;
    tam = L.First;
    while (tam - > Right != L.Last && tam - > PhanTu < pt) //chay tu Node dau tien cho den Node cuoi
    { //Dieu kien dung la pt lon hon PhanTu tai Node tam
        tam = tam - > Right;
        //tim vi tri thich hop
        if (tam - > PhanTu == pt) {
            //xoa phan tu tai vi tri vua tim duoc
            delete tam - > Left - > Right;
            tam - > Right - > Left = tam - > Left;
            tam - > Left - > Right = tam - > Right;
            delete tam;
        }
    }
}

//them vao vi tri thich hop trong danh sach
void Add(List & L, int phantu) {
    if (Emty(L)) Add_LIFO(L, phantu);
    else if (phantu <= L.First - > Right - > Info) Add_LIFO(L, phantu); //them dau
    else if (phantu >= L.Last - > Left - > Info) Add_FILO(L, phantu); //them cuoi
    else {
        Node * N;
        Node * M;
        N = L.First;
        M = L.First - > Right;
        for (int i = 1; i <= L.n - 1; i++) {
            N = N - > Right;
            M = M - > Right;
            if (N - > Info <= phantu && M - > Info > phantu) {
                Node * K = new Node;
                K - > Info = phantu;
                K - > Left = N;
                K - > Right = M;
                N - > Right = K;
                M - > Left = K;
                L.n++;
                return; //dung vong lap, chi them 1 Node
            }
        }
        delete N, M;
    }
}

void Change(List & L) {
    Node * N = L.First - > Right - > Right; //bat dau tu phan tu so 2
    int tam;
    while (N - > Right != NULL) {
        Node * tmp = N;
        tam = N - > Info;
        //xoa Node
        N - > Left - > Right = N - > Right;
        N - > Right - > Left = N - > Left;
        N = N - > Right;
        delete tmp;
        L.n--;
        //them Node vua xoa vao dau danh sach
        Add_LIFO(L, tam);
    }
}

void Tach(List & P, List & Q, List & R) {
    Node * N = P.First - > Right;
    while (N - > Right != NULL) {
        if (N - > Info % 2 == 0)
            Add(Q, N - > Info);
        else Add(R, N - > Info);
        N = N - > Right;
    }
}

void Add_HauTo(List & L) {
    char ch = '1';
    cout << "\nNhap vao chuoi hau to dung (vd: 12+ ): ";
    while (int(ch) != 13) {
        ch = getch();
        cout << ch;
        if ((int(ch) >= 48 && int(ch) <= 57) || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            Add_FILO(L, ch);
    }
}

void Add_TienTo(List & L) {
    char ch = '1';
    cout << "\nNhap vao chuoi tien to dung (vd: +12 ): ";
    while (int(ch) != 13) {
        ch = getch();
        cout << ch;
        if ((int(ch) >= 48 && int(ch) <= 57) || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            Add_FILO(L, ch);
    }
}

void CongDaThuc(List & A, List & B, List & C) {
    int i;
    Node * N = A.First - > Right;
    //da thuc c=a
    while (N - > Right != NULL) {
        Add_FILO(C, N - > HeSo, N - > SoMu);
        N = N - > Right;
    }
    N = B.First - > Right;
    //cong da thuc c=c+b
    while (N - > Right != NULL) {
        Add(C, N - > HeSo, N - > SoMu);
        N = N - > Right;
    }
}

void DaoHam(List & A) {
    Node * N = A.First - > Right;
    //keiem tra cac truong hop dac biet
    if (N - > SoMu == 0 || A.n == 0) {
        cout << "Dao ham cua da thuc = 0";
        return;
    }

    while (N - > Right != NULL) {
        N - > HeSo *= N - > SoMu;
        N - > SoMu--;
        N = N - > Right;
    }
    A.n--;
}

//nhap da thuc
void AddDT(List & L) {
    int ch, i, n;
    cout << "\nNhap vao bac cua da thuc: ";
    cin >> ch;
    DisplayEx(ch);
    cout << "\n";
    for (i = ch; i >= 0; i--) {
        cout << "a" << i << "= ";
        cin >> n;
        if (n != 0) Add_FILO(L, n, i);
    }
}

//cong hai so nguyen lon
void Cong(List & A, List & B, List & C) {
    Node * N, * M;
    if (A.n >= B.n) {
        C = A;
        Display(C);
        getch();
        N = B.Last - > Left;
        M = C.Last - > Left;
        while (N - > Left != NULL) {
            if (M - > Info + N - > Info > 1000) M - > Left - > Info += 1;
            M - > Info = (M - > Info + N - > Info) % 1000;
            N = N - > Left;
            M = M - > Left;
        }
    } else {
        C = B;
        C.First - > Info = 0;
        N = A.Last - > Left;
        M = C.Last - > Left;
        while (N - > Left != NULL) {
            if (M - > Info + N - > Info > 1000) M - > Left - > Info += 1;
            M - > Info = (M - > Info + N - > Info) % 1000;
            N = N - > Left;
            M = M - > Left;
        }
    }
    if (C.First - > Info == 1)
        Add_LIFO(C, 1);
}

void DoubleLinkedList() {
    clrscr();
    cout << "\n\n";
    List B;
    Create(B);
    Add_And_Insert(B);
    Display(B);
    
    getch();
}
