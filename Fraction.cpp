#include "conio.h"
#include "stdio.h"
#include "iostream.h"
#include "math.h"

//------------------- Dinh nghia kieu phan so -------------------------------
struct PhanSo {
    int TuSo; //Numerator
    int MauSo; //Denominator
};

//-------------------------- Khai bao Ham -----------------------------------
PhanSo operator + (PhanSo a, PhanSo b);
PhanSo operator - (PhanSo a, PhanSo b);
PhanSo operator * (PhanSo a, PhanSo b);
PhanSo operator / (PhanSo a, PhanSo b);
int operator > (PhanSo a, PhanSo b);
int operator >= (PhanSo a, PhanSo b);
int operator < (PhanSo a, PhanSo b);
int operator <= (PhanSo a, PhanSo b);
int operator == (PhanSo a, PhanSo b);
int operator != (PhanSo a, PhanSo b);
PhanSo RutGonPS(PhanSo a);

//----------------------- Chuong Trinh Chinh --------------------------------
void main() {
    clrscr();
    cout << "\nThuc Hanh Mon C++ \tBai 2\n";
    PhanSo a;
    PhanSo b;
    PhanSo c; //=new PhanSo;
    cout << "Tu So a=";
    cin >> a.TuSo;
    cout << "MauSo a=";
    cin >> a.MauSo;
    cout << "Tu So b=";
    cin >> b.TuSo;
    cout << "MauSo b=";
    cin >> b.MauSo;
    cout << "\na=" << a.TuSo << "/" << a.MauSo;
    cout << "\nb=" << b.TuSo << "/" << b.MauSo;

    //------- Kiem Tra Cac Truong Hop -------

    c = a + b;
    c = RutGonPS(c);
    cout << "\na+b=" << c.TuSo << "/" << c.MauSo;

    c = a - b;
    c = RutGonPS(c);
    cout << "\na-b=" << c.TuSo << "/" << c.MauSo;

    c = a * b;
    c = RutGonPS(c);
    cout << "\na*b=" << c.TuSo << "/" << c.MauSo;

    c = a / b;
    c = RutGonPS(c);
    cout << "\na/b=" << c.TuSo << "/" << c.MauSo;

    if (a == b)
        cout << "\nPS a bang PS b";
    else cout << "\nPS b khac PS a";
    if (a != b)
        cout << "\nPS a khac PS b";
    else cout << "\nPS b bang PS a";

    if (a > b)
        cout << "\nPS a lon hon PS b";
    else if (b > a)
        cout << "\nPS b lon hon PS a";
    else cout << "\na=b";

    if (a >= b)
        cout << "\nPS a lon hon hoac bang PS b";
    else cout << "\nPS b lon hon hoac bang PS a";

    if (a < b)
        cout << "\nPS a be hon PS b";
    else if (b < a)
        cout << "\nPS b be hon PS a";
    else cout << "\nb=a";

    if (a <= b)
        cout << "\nPS a be hon hoac bang PS b";
    else cout << "\nPS b be hon hoac bang PS a";

    getch();
}

//----------------------- Dinh Nghia Cac Ham  ------------------------------

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo c;
    c.TuSo = a.TuSo * b.MauSo + a.MauSo * b.TuSo;
    c.MauSo = a.MauSo * b.MauSo;
    return c;
}

PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo c;
    c.TuSo = a.TuSo * b.MauSo - a.MauSo * b.TuSo;
    c.MauSo = a.MauSo * b.MauSo;
    return c;
}

PhanSo operator * (PhanSo a, PhanSo b) {
    PhanSo c;
    c.TuSo = a.TuSo * b.TuSo;
    c.MauSo = a.MauSo * b.MauSo;
    return c;
}

PhanSo operator / (PhanSo a, PhanSo b) {
    PhanSo c;
    c.TuSo = a.TuSo * b.MauSo;
    c.MauSo = a.MauSo * b.TuSo;
    return c;
}

int operator > (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo > b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

int operator >= (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo >= b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

int operator < (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo < b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

int operator <= (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo <= b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

int operator == (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo == b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

int operator != (PhanSo a, PhanSo b) {
    if (a.TuSo * b.MauSo != b.TuSo * a.MauSo)
        return 1;
    else return 0;
}

PhanSo RutGonPS(PhanSo a) {
    int UCLN;
    int n = abs(a.TuSo), m = abs(a.MauSo);
    while (n != 0 && m != 0)
        if (n > m)
            n -= m;
        else
            m -= n;
    if (n != 0)
        UCLN = n;
    else
        UCLN = m;
    a.TuSo = a.TuSo / UCLN;
    a.MauSo = a.MauSo / UCLN;
    return a;
}
