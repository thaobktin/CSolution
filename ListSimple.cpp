//Ca´c ba?n xem la?i dê? hiê?u ro~ hon nhe´ !
//DANH SA´CH NÔ´I ÐON :Ca´ch 1 sau dây se~ du`ng dâ´u châ´m (.) va` tham chiê´u:vd: l.head, l.tail
//(ca´ch 2:se~ du`ng dâ´u * va` -> cu?a con tro? se~ la` ca´ch la`m chi´nh cu?a chu´ng ta)
//Soft:VS2010
#include <conio.h>
#include <stdlib.h>

  //------------------1.Câ´u tru´c 1 node------------------------------------
  struct node {
    int data;
    struct node * next;
  };
typedef struct node node; //co the trung ten
/*Cach 2: de typedef ngay dau struct
typedef struct node
{
int data;
struct node *next;
}node; */

//-----------------------2.Câ´u tru´c danh sa´ch----------------------------
struct list {
  node * head;
  node * tail;
};
typedef struct list list;
/*
Ca´ch 2: dê? typedef ngay dâ`u struct
typedef struct list
{
node *head;
node *tail;
}list; */
//------------------------3.Kho?i ta?o danh sa´ch------------------------------
void init(list & l) {
  l.head = l.tail = NULL;
}

//-------------4.Ta?o 1 node va` ga´n gia´ tri? cho node do´
node * getnode(int x) {
    node * p = (node * ) malloc(sizeof(node));
    if (p == NULL) {
      printf("\nKhong du bo nho !");
      getch();
      return NULL;
    }
    p - > data = x;
    p - > next = NULL;
    return p;
  }
  //---------------------5.Thêm va`o dâ`u danh sa´ch-----------------------
void addhead(list & l, node * p) {
    if (l.head == NULL) // neu danh sach rong
    {
      l.head = l.tail = p;
    } else {
      p - > next = l.head;
      l.head = p;
    }
  }
  //------------------6.Thêm va`o cuô´i danh sa´ch-----------------------------
void addtail(list & l, node * p) {
    if (l.head == NULL) {
      l.head = l.tail = p;
    } else {
      l.tail - > next = p;
      l.tail = p;
      /*hoac l.tail = p;
      p -> next = NULL; cung duoc*/
    }
  }
  //-------------------7.Ha`m nhâ?p danh sa´ch------------------------
void nhapdanhsach(list & l) {
    int sophantu;
    printf("\nNhap so luong phan tu: ");
    scanf("%d", & sophantu);
    init(l);
    for (int i = 1; i <= sophantu; i++) {
      int x; //x la` gia´ tri? se~ dua va`o node,tuo?ng tuo?ng node nhu 1 ca´i toa tâ`u,
      //co`n x la` ha`ng ho´a trong toa do´
      printf("\nGia tri so thu %d: ", i);
      scanf("%d", & x);
      node * p = getnode(x);
      addhead(l, p); // hoac addtail(l,p); cung duoc

    }
  }
  //-----------------------8.In danh sach-------------------------------
void xuatdanhsach(list l) {

    for (node * p = l.head; p != NULL; p = p - > next) {
      printf("%4d", p - > data);
    }
  }
  //----------------------9.Xoa danh sach---------------------------------
void xoadanhsach(list & l) {
    node * p;
    while (l.head != NULL) {
      p = l.head;
      l.head = l.head - > next;
      free(p);
    }
    free(l);
    /* node *p = l.head; //nê´u du`ng ca´ch na`y se~ co´ thông ba´o lô~i
    while(p != NULL)
    {
    p = l.head;
    l.head = p->next;
    free(p);
    } */
  }
  //---------------------10.Kiem tra gia tri x co trong danh sach khong
bool kiemtra(list l, int x) {
    for (node * p = l.head; p != NULL; p = p - > next) {
      if (p - > data == x) {
        return true;
        break;
      }
    }
    return false;
  }
  //---------------------11.Sa´p xê´p danh sa´ch tang / gia?m dâ`n
void hoanvi(int & x, int & y) {
  int temp = x;
  x = y;
  y = temp;
}
void sapxep(list & l) {
    for (node * p = l.head; p != l.tail; p = p - > next) {
      for (node * q = p - > next; q != NULL; q = q - > next) {
        if (p - > data > q - > data) //tang dan
        {
          hoanvi(p - > data, q - > data);
        }
      }
    }
  }
  //-----------------11.Thêm (che`n ) 1 node va`o sau 1 node p trong danh sa´ch
void themvaosau(list & l, node * p) {
    int x; // gia tri node can them
    printf("\nNhap gia tri node can them: ");
    scanf("%d", & x);
    node * q = getnode(x);
    for (node * k = l.head; k != NULL; k = k - > next) {
      if (k - > data == p - > data) {
        q - > next = k - > next;
        k - > next = q;
      }
    }
  }
  //--------------------12.Xo´a phâ`n tu? dâ`u danh sa´ch

void xoadau(list & l) {
    node * p = l.head;
    if (l.head == NULL) {
      return; // ket thuc
    } else if (p - > next == NULL) //truong hop ds chi co 1 phan tu
    {
      l.tail = NULL;
      l.head = l.tail;
      free(p);
      return;
    } else {
      l.head = l.head - > next;
      free(p);
    }

  }
  //-------------------------13.Xoa phan tu cuoi danh sach
void xoacuoi(list & l) {
    node * p = l.head;
    if (l.head == NULL) {
      return;
    } else if (p - > next == NULL) //truong hop ds chi co 1 phan tu
    {
      l.tail = NULL;
      l.head = l.tail;
      free(p);
      return;
    } else {
      for (p = l.head; p != NULL; p = p - > next) {
        if (p - > next == l.tail) {
          p - > next = NULL;
          free(l.tail);
          return;
        }
      }
      /*Cach 2: while(p->next != NULL)
      {
      if(p->next == l.tail)
      {
      p->next = NULL;
      free(l.tail);
      return;
      }
      p = p -> next;
      }*/
    }
  }
  //--------------------------14.Xo´a node na`m sau node p
void xoasau(list & l, node * p) {
    for (node * k = l.head; k != NULL; k = k - > next) {
      if (k - > data == p - > data) {
        if (k - > next != NULL) // Dieu kien la node nam sau k(den cho nay la p)phai khac rong
        {
          node * t = k - > next;
          k - > next = t - > next;
          free(t);
          return;
        }
      }
    }
  }
  //-----------------15.Xo´a 1 node co´ kho´a (gia´ tri? data) bâ´t ky`
void xoabatky(list & l) {
    int x;
    printf("\nNhap vao gia tri cua node can xoa: ");
    scanf("%d", & x);
    node * g; // g la node nam truoc node k
    for (node * k = l.head; k != NULL; k = k - > next) {
      if (k - > data == x) {
        if (k == l.head) {
          xoadau(l);
          return;
        } else if (k == l.tail) {
          xoacuoi(l);
          return;
        } else if (k != l.head && k != l.tail) {
          xoasau(l, g);
          return;
        }
      }
      g = k;
    }
  }
  //------------------------Main------------------------------------------
int main() {
  list l;
  nhapdanhsach(l);
  printf("\n\n\t\tDanh sach vua nhap vao la: \n\n\t\t");
  xuatdanhsach(l);

  ////1.Goi ham kiem tra gia tri co trong danh sach hay khong
  int a;
  printf("\nNhap gia tri can kiem tra: ");
  scanf("%d", & a);
  if (kiemtra(l, a)) {
    printf("\nGia tri %d co trong danh sach.", a);
  } else {
    printf("\nGia tri %d khong co trong ds.", a);
  }

  ////2.Goi ham sap xep danh sach
  sapxep(l);
  printf("\n\n\t\tDanh sach sau khi sap xep la: \n\n\t\t");
  xuatdanhsach(l);

  //3.Goi ham them vao sau node p
  int b;
  printf("\nNhap gia tri node p(gia su la co): ");
  scanf("%d", & b);
  node * p = getnode(b);
  themvaosau(l, p);
  printf("\n\n\t\tDanh sach sau khi them 1 node la: \n\n\t\t");
  xuatdanhsach(l);

  //4.Goi ham xoa dau
  xoadau(l);
  printf("\n\n\t\tDanh sach sau khi xoa node dau la: \n\n\t\t");
  xuatdanhsach(l);

  //5.Goi ham xoa cuoi
  xoacuoi(l);
  printf("\n\n\t\tDanh sach sau khi xoa node cuoi la: \n\n\t\t");
  xuatdanhsach(l);

  //6.Goi ham xoa sau 1 node
  int c;
  printf("\nNhap gia tri cho node p: ");
  scanf("%d", & c);
  node * p = getnode(c);
  xoasau(l, p);
  printf("\n\n\t\tDanh sach sau khi xoa 1 node la: \n\n\t\t");
  xuatdanhsach(l);

  //7.Goi ham xoa bat ky
  xoabatky(l);
  printf("\n\n\t\tDanh sach sau khi xoa 1 node bat ky la: \n\n\t\t");
  xuatdanhsach(l);

  //Goi ham xoa (giai phong) danh sach
  xoadanhsach(l);
  getch();
  return 0;
}
