//DANH SA´CH NÔ´I ÐON: VS2010
//Ca´ch 2: du`ng con tro?: dâ´u châ´m thay ba`ng dâ´u ->

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//1-----------------------------------------------------------------------------------

  typedef struct node {
    int data;
    struct node * next;
  }
node;

//2-----------------------------------------------------------------------------------

typedef struct list {
  node * first;
  node * last;
}
list;

//3-----------------------------------------------------------------------------------

void init(list * & l) {
  l = (list * ) malloc(sizeof(list));
  l - > first = l - > last = NULL;
}

//4-----------------------------------------------------------------------------------

node * getnode(int value) {
  node * p = (node * ) malloc(sizeof(node));
  if (p == NULL) {
    printf("\nKhong du bo nho !");
    getch();
    return NULL;
  }
  p - > data = value;
  p - > next = NULL;
  return p;
}

//5-----------------------------------------------------------------------------------

void addfirst(list * & l, node * p) {
  if (l - > first == NULL) {
    l - > first = l - > last = p;
    p - > next = NULL;
  } else {
    p - > next = l - > first;
    l - > first = p;
  }
}

//6-----------------------------------------------------------------------------------

void addlast(list * & l, node * p) {
  if (l - > first == NULL) {
    l - > first = l - > last = p;
    p - > next = NULL;
  } else {
    l - > last - > next = p;
    l - > last = p;
  }
}

//7-----------------------------------------------------------------------------------

void nhapdanhsach(list * & l) {
  int soluong;
  printf("\nNhap so luong so nguyen: ");
  scanf("%d", & soluong);
  init(l);
  for (int i = 1; i <= soluong; i++) {
    int x;
    printf("\nNhap gia tri thu %d: ", i);
    scanf("%d", & x);
    node * p = getnode(x);
    addfirst(l, p);
  }
}

//8-----------------------------------------------------------------------------------

void indanhsach(list * l) {
  for (node * p = l - > first; p != NULL; p = p - > next) {
    printf("%5d", p - > data);
  }
}

//9-----------------------------------------------------------------------------------

void xoadanhsach(list * & l) {
  node * p;
  while (l - > first != NULL) {
    p = l - > first;
    l - > first = l - > first - > next;
    free(p);

  }
}

//10-----------------------------------------------------------------------------------

void chensau(list * & l, node * q, node * p) //che`n node p sau node q
  {
    for (node * k = l - > first; k != NULL; k = k - > next) {
      if (k - > data == q - > data) {
        p - > next = k - > next;
        k - > next = p;
      }
    }
    //l -> count++;
  }

//11-----------------------------------------------------------------------------------

int xoadau(list * & l) {
  node * p = l - > first;
  if (l - > first == NULL) {
    return NULL;
  } else if (p - > next == NULL) {
    l - > last = NULL;
    l - > first = l - > last;
    int value = p - > data;
    free(p);
    return value;
  } else {
    l - > first = p - > next; //or l->first = l->first->next;
    int value = p - > data;
    free(p);
    return value;
  }
}

//12-----------------------------------------------------------------------------------

int xoacuoi(list * & l) {
  node * p = l - > first;
  if (l - > first == NULL) {
    return NULL;
  } else if (p - > next == NULL) {
    l - > last = NULL;
    l - > first = l - > last;
    int value = p - > data;
    free(p);
    return value;
  } else {
    while (p - > next != NULL) {
      if (p - > next == l - > last) {
        node * g = l - > last;
        int value = l - > last - > data;
        l - > last = p;
        p - > next = NULL;
        //int value = l->last->data; neu de day thi se in ra gtri ngay trc gtri cuoi
        free(g);
        return value;

        /*Cach 2: p->next = NULL;
        int value = l->last->data;
        free(l->last);
        return value;*/
      }
      p = p - > next;
    }
  }
}

//13-----------------------------------------------------------------------------------

int xoasaumotnode(list * & l, node * p) {
  for (node * k = l - > first; k != NULL; k = k - > next) {
    if (k - > data == p - > data) {
      if (k - > next != NULL) {
        node * g = k - > next;
        k - > next = g - > next;
        free(g);
        int value = g - > data;
        return value;
      }
    }
  }
}

//14-----------------------------------------------------------------------------------

int main() {

  list * l;
  nhapdanhsach(l);
  printf("\n\n\t\tDanh sach vua nhap la: \n\n\t\t");
  indanhsach(l);

  //1 Goi ham xoa dau
  printf("\n\nPhan tu o dau bi xoa co gtri la: %d", xoadau(l));
  printf("\n\n\t\tDS sau khi xoa dau la: \n\n\t\t");
  indanhsach(l);

  //2 Goi ham xoa cuoi
  printf("\n\nPhan tu o cuoi bi xoa co gtri la: %d", xoacuoi(l));
  printf("\n\n\t\tDS sau khi xoa cuoi la: \n\n\t\t");
  indanhsach(l);

  //3 Goi ham chen sau
  int giatrip;
  printf("\nNhap gia tri node p(gtri can nhap): ");
  scanf("%d", & giatrip);
  node * p = getnode(giatrip);
  int giatriq;
  printf("\nNhap gia tri node q(gtri da nhap): ");
  scanf("%d", & giatriq);
  node * q = getnode(giatriq);
  chensau(l, q, p);
  printf("\n\n\t\tDS sau khi chen %d sau %d la: \n\n\t\t", giatrip, giatriq);
  indanhsach(l);

  xoadanhsach(l);
  getch();
  return 0;
}
