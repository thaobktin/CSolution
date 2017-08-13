#
include < stdio.h > #include < stdlib.h > #include < conio.h > #include < malloc.h >

  #define TRUE 1# define FALSE 0

typedef struct tagnode {
  int key;
  struct tagnode * left;
  struct tagnode * right;
}
node;
typedef node * tree;
typedef char bool;

node * search(tree t, int x);
bool insert(tree * t, int x);
bool find(tree t, int x);
bool delleft(tree * t, tree q, int x);
bool delright(tree * t, tree q, int x);
int height(tree t);
int max(int a, int b);
int sonutLa(tree t);
int sonut1con(tree t);
int sonut2con(tree t);
void NLR(tree t);
void printtree(tree t, int indent);

/************************************/
/* Tim kiem nut co key x */
/************************************/
bool find(tree t, int x) {
  if (t != NULL) {
    if (x == t - > key) {
      printf("Da tim thay %d", t - > key);
      return TRUE;
    } else if (x < t - > key)
      find(t - > left, x);
    else
      find(t - > right, x);
  } else {
    printf("Khong tim thay ");
    return FALSE;
  }
}

/************************************/
/* So Nut co 1 con */
/************************************/
int sonut1con(tree t) {
  if (t == NULL)
    return 0;
  if ((t - > left == NULL) && (t - > right == NULL))
    return 0;
  if (t - > left == NULL)
    return 1 + sonut1con(t - > right);
  if (t - > right == NULL)
    return 1 + sonut1con(t - > left);
  else
    return sonut1con(t - > left) + sonut1con(t - > right);
}

/************************************/
/* So Nut co 2 con */
/************************************/
int sonut2con(tree t) {
  if (t == NULL)
    return 0;
  if ((t - > left == NULL) && (t - > right == NULL))
    return 0;
  if (t - > left == NULL)
    return sonut2con(t - > right);
  if (t - > right == NULL)
    return +sonut2con(t - > left);
  else
    return 1 + sonut2con(t - > left) + sonut2con(t - > right);
}

/************************************/
/* So La cua cay */
/************************************/
int sonutLa(tree t) {
  if (t == NULL)
    return 0;
  if ((t - > left == NULL) && (t - > right == NULL))
    return 1;
  return sonutLa(t - > left) + sonutLa(t - > right);
}

/************************/
/* Ham max */
/************************/
int max(int a, int b) {
  if (a >= b) return (a);
  else return (b);
}

/*************************/
/* Dem chieu cao cua cay */
/*************************/
int height(tree t) {
  if (t == NULL)
    return (0);
  else
    return (1 + max(height(t - > left), height(t - > right)));
}

/**************************************/
/* In hinh cay */
/**************************************/
void printtree(tree t, int dichphai) {
  int i;
  tree temp = t;
  if (temp != NULL) {
    printtree(temp - > right, dichphai + 4);
    for (i = 1; i <= dichphai; i++) printf(" ");
    printf(" %d \n", temp - > key);
    printtree(temp - > left, dichphai + 4);
  }
}

/*******************************************/
/* Duyet cay de in */
/*******************************************/
void NLR(tree t) {
  if (t == NULL) return;
  printf("%3d", t - > key);
  if (t - > left) NLR(t - > left);
  if (t - > right) NLR(t - > right);
}

/*******************************************/
/* Tim phan tu tren cay */
/*******************************************/
node * search(tree t, int x) {
  if (t != NULL) return NULL;
  if (x == t - > key) {
    printf("Da tim thay %d", t - > key);
    getch();
    return t;
  }
  if (x < t - > key) * search(t - > left, x);
  if (x > t - > key) * search(t - > right, x);
}

/*******************************************/
/* Them phan tu vao cay */
/*******************************************/
bool insert(tree * t, int x) {
  tree t1, tnew, p;
  if ( * t == NULL) {
    p = (node * ) malloc(sizeof(node));
    p - > key = x;
    p - > left = p - > right = NULL; * t = p;
  } else {
    t1 = * t;
    if (t1 - > key == x) return FALSE;
    if (t1 - > key > x) {
      if (t1 - > left)
        return insert( & (t1 - > left), x);
      else {
        tnew = (node * ) malloc(sizeof(node));
        tnew - > key = x;
        tnew - > left = tnew - > right = NULL;
        t1 - > left = tnew;
      }
    } /*key>x*/
    else {
      if (t1 - > right)
        return insert( & (t1 - > right), x);
      else {
        tnew = (node * ) malloc(sizeof(node));
        tnew - > key = x;
        tnew - > left = tnew - > right = NULL;
        t1 - > right = tnew;
      }
    }
  }
  return TRUE;
}

/**************************************************************/
/* xoa phan tu tren cay theo huong phai nhat cua cay con trai */
/**************************************************************/
bool delleft(tree * t, tree q, int x) {
  tree p, p1;
  if (( * t) - > key == NULL) return FALSE;
  if (( * t) - > key < x)
    delleft( & (( * t) - > right), ( * t), x);
  if (( * t) - > key > x)
    delleft( & (( * t) - > left), ( * t), x);
  if (( * t) - > key == x) {
    p1 = ( * t) - > left;
    p = * t;
    if (p1 == NULL)
      if (!q) {
        p = * t; * t = ( * t) - > right;
      } else
    if (x < q - > key) q - > left = p - > right;
    else q - > right = p - > right;
    else /* q1<>NULL */ {
      q = p;
      while (p1 - > right) {
        q = p1;
        p1 = p1 - > right;
      }
      p - > key = p1 - > key;
      if (p == q)
        p - > left = p1 - > left;
      else
        q - > right = p1 - > left;
      p = p1;
    }
    free(p);
  }
  return TRUE;
}

/**************************************************************/
/* xoa phan tu tren cay theo huong trai nhat cua cay con phai */
/**************************************************************/
bool delright(tree * t, tree q, int x) {
  tree p, p1;
  p = * t;
  if (p - > key == NULL) return FALSE;
  if (p - > key < x)
    delright( & (p - > right), p, x);
  if (p - > key > x)
    delright( & (p - > left), p, x);
  if (p - > key == x) {
    p1 = p - > right;
    if (p1 == NULL) {
      if (!q) {
        p = * t; * t = p - > left;
      } else {
        if (x < q - > key) q - > left = p - > left;
        else q - > right = p - > left;
      }
    } else /*q1<>NULL*/ {
      q = p;
      while (p1 - > left) {
        q = p1;
        p1 = p1 - > left;
      }
      p - > key = p1 - > key;
      if (p == q)
        p - > right = p1 - > right;
      else
        q - > left = p1 - > right;
      p = p1;
    }
    free(p);
  }
  return TRUE;
}

/*******************************************/
/* MAIN */
/*******************************************/
void BinaryTree() {
  tree t, q;
  int k, x, so;

  k = x = 0;

  while (1) {
    clrscr();
    printf("\n Bai lam tren Borland C++ 2.0");
    printf("\n SV Truong Van Thai");
    printf("\n *******************************");
    printf("\n 1. Tao moi mot cay nhi phan ");
    printf("\n 2. Them phan tu vao cay ");
    printf("\n 3. Tim phan tu co khoa x ");
    printf("\n 4. Xoa phan tu trong cay ");
    printf("\n 5. In phan tu trong cay ");
    printf("\n 6. Thoat ");
    printf("\n *******************************");
    printf("\n Chon : ");
    scanf("\n%d", & k);
    switch (k) {
    case 1:
      {
        t = q = NULL;
        while (1) {
          printf("Tao cay , Nhap mot so (neu = -1 -> thoat : ");
          scanf("%d", & x);
          if (x == -1) break;
          insert( & t, x);
        }
        break;
      }

    case 2:
      {
        printf("Nhap so can chen x=");scanf("%d", & x);
        insert( & t, x);
        break;
      }

    case 3:
      {
        printf("Nhap so can tim x=");scanf("%d", & x);
        find(t, x);
        getch();
        break;
      }

    case 4:
      {
        printf("Nhap so can xoa x=");scanf("%d", & x);
        if (delleft( & t, q, x))
          printf("Da xoa xong ");
        else {
          if (delright( & t, q, x))
            printf("Da xoa xong ");
          else
            printf("Khong thay !! ");
        }
        getch();
        break;
      }
    case 5:
      {
        clrscr();
        NLR(t);
        printf("\n\n\n\n\n");
        printtree(t, 2);
        printf("\n Chieu cao cay : %d \n ", height(t));
        printf("\n So nut la : %d \n ", sonutLa(t));
        printf("\n So nut co 1 con : %d \n ", sonut1con(t));
        printf("\n So nut co 2 con : %d \n ", sonut2con(t));
        getch();
        break;
      }
    }
    if (k > 5) break;
  }

  getch();
}
