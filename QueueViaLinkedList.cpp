#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct Node {
    char Info;
    Node * Left;
    Node * Right;
};

struct Queue {
    Node * First;
    Node * Last;
    int n;
};

void Create(Queue & Q) {
    Q.First = new Node;
    Q.Last = new Node;
    Q.First - > Left = NULL;
    Q.First - > Right = Q.Last;
    Q.Last - > Left = Q.First;
    Q.Last - > Right = NULL;
    Q.n = 0;
}

int Emty(Queue & Q) {
    return (Q.First - > Right == Q.Last);
}

//hien thi ngan xep
void Display(Queue & Q) {
    cout << "\n\n";
    Node * N;
    N = Q.First - > Right;
    for (int i = 1; i <= Q.n; i++) {
        cout << N - > Info;
        N = N - > Right;
    }
}

//vao sau ra truoc (them vao dau danh sach)
void Push(Queue & Q, char phantu) {
    Node * N = new Node;
    N - > Info = phantu;
    N - > Right = Q.Last;
    N - > Left = Q.Last - > Left;
    Q.Last - > Left - > Right = N;
    Q.Last - > Left = N;
    Q.n++;
}

//lay mot phan tu o dinh hang doi
char Pop(Queue & Q) {
    if (Q.n <= 0) {
        cout << "Hang doi rong";
        getch();
        return 0;
    }
    char n = Q.First - > Right - > Info;
    Node * N = Q.First - > Right;
    Q.First - > Right - > Right - > Left = Q.First;
    Q.First - > Right = Q.First - > Right - > Right;
    delete N;
    Q.n--;
    return n;
}

//nhap vao cac phan tu cua ngan xep
void Add(Queue & Q) {
    char ch = '1';
    cout << "\nNhap vao cac phan tu cua hang doi, nhan ENTER de ket thuc\n\t: ";
    while (int(ch) != 13) {
        ch = getch();
        cout << ch;
        if (int(ch) != 13) Push(Q, ch);
    }
}

void DaoNguoc(Queue & Q) {
    Queue A, B;
    int i, j, q, a, n = Q.n;
    char c;
    Create(A);
    Create(B);
    for (i = 1; i <= n; i++) {
        if (!Emty(Q)) {
            q = Q.n - 1;
            for (j = 1; j <= q; j++) {
                c = Pop(Q);
                Push(A, c);
            }
            c = Pop(Q);
            Push(B, c);
        } else {
            a = A.n - 1;
            for (j = 1; j <= a; j++) {
                c = Pop(A);
                Push(Q, c);
            }
            c = Pop(A);
            Push(B, c);
        }
    }
    //tra lai hang doi sau khi dao nguoc
    while (!Emty(B)) {
        c = Pop(B);
        Push(Q, c);
    }
}

//-------- Kiem tra doi xung (dung Queue va Stack) ----------
void KiemTra(Queue & Q) {
    //chuyen nua chuoi ky tu tu Queue sang Stack
    Stack S;
    CreateS(S);
    int n = Q.n / 2;
    char c;
    for (int i = 1; i <= n; i++) {
        c = PopQ(Q);
        PushS(S, c);
    }

    cout << "\n\nQ= ";
    DisplayQ(Q);
    cout << "\n\nS= ";
    DisplayS(S);
    if (Q.n > S.n) cout << "\nKy tu giua: " << PopQ(Q);
    //kiem tra
    n = Q.n;
    int check = 1;
    for (i = 1; i <= n; i++) {
        if (PopQ(Q) != PopS(S)) check = 0;
    }

    if (check) cout << "\nChuoi vua moi nhap doi xung";
    else cout << "\nChuoi vua moi nhap khong doi xung";
    getch();
}

void QueueViaLinkedList() {
    clrscr();
    cout << "\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
    Queue B;
    Create(B);
    Add(B);
    cout << "\nHang Doi sau khi nhap:";
    Display(B);

    DaoNguoc(B);
    cout << "\nHang Doi sau khi dao nguoc:";
    Display(B);

    getch();

}
