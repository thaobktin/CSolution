struct Node {
    int Info;
    Node * Left;
    Node * Right;
};

struct Stack {
    Node * First;
    Node * Last;
    int n;
};

void Create(Stack & S) {
    S.First = new Node;
    S.Last = new Node;
    S.First - > Left = NULL;
    S.First - > Right = S.Last;
    S.Last - > Left = S.First;
    S.Last - > Right = NULL;
    S.n = 0;
}

int Emty(Stack & S) {
    return (S.First - > Right == S.Last);
}

//hien thi ngan xep
void Display(Stack & S) {
    cout << "\n\n";
    Node * N = new Node;
    N = S.First - > Right;
    for (int i = 1; i <= S.n; i++) {
        cout << N - > Info;
        N = N - > Right;
    }
}

//vao sau ra truoc (them vao dau danh sach)
void Push(Stack & S, int phantu) {
    Node * N = new Node;
    N - > Info = phantu;
    N - > Left = S.First;
    N - > Right = S.First - > Right;
    S.First - > Right - > Left = N;
    S.First - > Right = N;
    S.n++;
}

//lay mot phan tu o dinh ngan xep
int Pop(Stack & S) {
    if (S.n <= 0) {
        cout << "Ngan xep rong";
        getch();
        return 0;
    }
    int n = S.First - > Right - > Info;
    Node * N = S.First - > Right;
    S.First - > Right - > Right - > Left = S.First;
    S.First - > Right = S.First - > Right - > Right;
    delete N;
    S.n--;
    return n;
}

//doi 1 so thap phan sang nhi phan
void Thap2NhiPhan(Stack & S, long n) {
    //int check=0;
    if (n < 0) n = n * -1; //check=1;}
    while (n != 0) {
        Push(S, n % 2);
        n = n / 2;
    }
}

//nhap vao chuoi hau to
void Add_And_Insert(Stack & S) {
    char ch = '1';
    cout << "\nNhap vao chuoi hau to dung (vd: 12+ ): ";
    while (int(ch) != 13) {
        ch = getch();
        cout << ch;
        if ((int(ch) >= 48 && int(ch) <= 57) || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            Push(S, ch);
    }
}

//nhap vao cac pha ntu cua ngan xep
void Add(Stack & S) {
    char ch = '1';
    cout << "\nNhap vao cac phan tu cua ngan xep, nhan ENTER de ket thuc:\n\t ";
    while (int(ch) != 13) {
        ch = getch();
        cout << ch;
        if (int(ch) != 13) {
            Push1(S, ch);
            Push2(S, ch);
        }
    }
}

//doi 1 so thap phan sang nhi phan
//kiem tra chuoi dau ngoac
void Check(Stack & S, Stack & K) {
    char c;
    int i;
    while (!Emty(S)) //chuyen bieu thuc ve dang 1,0
    { //toan hang(=1, )=0
        c = Pop(S);
        if (c == '(')
            Push(K, '1');
        else Push(K, '0');
    }
    cout << "\n\nBieu thuc duoc chuyen ve dang 0,1";
    cout << "\n  ( =1,  )=0";
    Display(K);
    //kiem tra Node N,N+1 co dang 10 hay ko?
    //neu co thi xoa N va N+1
    i = K.n;
    Node * N;
    while (!Emty(K) && i > 0) {
        N = K.First;
        while (N - > Right - > Right != NULL) {
            if (N - > Right - > Info == '1' && N - > Right - > Right - > Info == '0') {
                //xoa 2 Node sau N
                Node * t1 = N - > Right, * t2 = N - > Right - > Right;
                N - > Right - > Right - > Right - > Left = N;
                N - > Right = N - > Right - > Right - > Right;
                delete t1, t2;
                K.n -= 2;
            }
            N = N - > Right;
        }
        i--;
    }

    if (K.First - > Right == K.Last)
        cout << "\nBieu thuc nhap vao co chuoi ngoac dung";
    else cout << "\nBieu thuc nhap vao co chuoi ngoac sai";
    getch();
}

//dao nguoc mot stack
void DaoNguoc(Stack & S) {
    Stack S1, S2;
    char c;
    Create(S1);
    Create(S2);
    while (!Emty(S)) {
        c = Pop(S);
        Push(S1, c);
    }
    while (!Emty(S1)) {
        c = Pop(S1);
        Push(S2, c);
    }
    while (!Emty(S2)) {
        c = Pop(S2);
        Push(S, c);
    }
}

int Count(Stack & S) {
    Stack K;
    Create(K);
    char c;
    int check = 0;
    while (!Emty(S)) //dem so phan tu cua ngan xep
    {
        c = Pop(S);
        check++;
        Push(K, c);
    }
    while (!Emty(K)) //Tra lai ngan xep nhu ban dau
    {
        c = Pop(K);
        Push(S, c);
    }
    return check;
}

void XemPTn(Stack & S, int n) {
    if (n <= 0 || n > S.n) {
        cout << "\nn<0 hoac n lon hon so phan tu cua ngan xep";
        getch();
        return;
    }
    //lay noi dung cua phan tu thu n
    Stack K;
    Create(K);
    int kt = n;
    char c;
    while (kt != 0) {
        c = Pop(S);
        Push(K, c);
        kt--;
    }
    cout << "Phan tu thu " << n << "= " << c;
    getch();

    //tra lai ngan xep ban dau
    while (!Emty(K)) {
        c = Pop(K);
        Push(S, c);
    }
}

void XoaPTn(Stack & S, int n) {
    if (n <= 0 || n > S.n) {
        cout << "\nn<0 hoac n lon hon so phan tu cua ngan xep";
        getch();
        return;
    }

    //lay noi dung cua phan tu thu n
    Stack K;
    Create(K);
    int kt = n;
    char c, tmp;
    while (kt != 0) {
        c = Pop(S);
        Push(K, c);
        kt--;
    }
    cout << "\nPhan tu thu " << n << "= " << c;
    cout << "\nban co muon xoa phan tu nay khong (y,n):";
    tmp = getch();

    if (tmp == 'y') {
        c = Pop(K); //bo di phan tu thu n
        //tra lai ngan xep sau khi xoa
        while (!Emty(K)) {
            c = Pop(K);
            Push(S, c);
        }
    } else {
        //tra lai ngan xep nhu ban dau
        while (!Emty(K)) {
            c = Pop(K);
            Push(S, c);
        }
    }
}

void StackViaLinkedList() {
    clrscr();

    cout << "\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
    Stack B;
    Create(B);
    cout << "\nNgap xep sau khi nhap:";
    Display(B);
    getch();

}
