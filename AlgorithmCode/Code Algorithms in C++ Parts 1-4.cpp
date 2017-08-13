/*Code - Robert Sedgewick - Algorithm in C++ Parts 1-2 - Fundamentals, Data*/
/*
	This file contains the code from "Algorithms in C++, Third Edition,
	Parts 1-4," by Robert Sedgewick, and is covered under the copyright
	and warranty notices in that book. Permission is granted for this
	code to be used for educational purposes in association with the text,
	and for other uses not covered by copyright laws, provided that
	the following notice is included with the code:

		"This code is from "Algorithms in C++, Third Edition,"
		by Robert Sedgewick, Addison-Wesley, 1999."

	Commercial uses of this code require the explicit written
	permission of the publisher. Send your request for permission,
	stating clearly what code you would like to use, and in what
	specific way, to: aw.cse@aw.com
*/

----------
CHAPTER 1. Introduction
-----
#include <iostream.h>
static const int N = 10000;
int main()
  { int i, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;
    while (cin >> p >> q)
      { int t = id[p];
        if (t == id[q]) continue;
        for (i = 0; i < N; i++)
          if (id[i] == t) id[i] = id[q];
        cout << " " << p << " " << q << endl;
      }
 }
-----
    for (i = p; i != id[i]; i = id[i]) ;
    for (j = q; j != id[j]; j = id[j]) ;
    if (i == j) continue;
    id[i] = j;
    cout << " " << p << " " << q << endl;
    -----
#include <iostream.h>
static const int N = 10000;
int main()
  { int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) 
      { id[i] = i; sz[i] = 1; }
    while (cin >> p >> q)
      { 
        for (i = p; i != id[i]; i = id[i]) ;
        for (j = q; j != id[j]; j = id[j]) ;
        if (i == j) continue;
        if (sz[i] < sz[j])
             { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        cout << " " << p << " " << q << endl;
      }
 }
-----
    for (i = p; i != id[i]; i = id[i]) 
      id[i] = id[id[i]]; 
    for (j = q; j != id[j]; j = id[j]) 
      id[j] = id[id[j]]; 
    
----------
CHAPTER 2. Principles of Algorithm Analysis
-----
int search(int a[], int v, int l, int r)
  { 
    for (int i = l; i <= r; i++)
      if (v == a[i]) return i;
    return -1;
  }
-----
int search(int a[], int v, int l, int r)
  { 
    while (r >= l)
      { int m = (l+r)/2;
        if (v == a[m]) return m;
        if (v < a[m]) r = m-1; else l = m+1;
      }
    return -1;
  }

----------
CHAPTER 3. Elementary Data Structures
-----
#include <iostream.h>
int lg(int);
int main()
  { 
    for (int N = 1000; N <= 1000000000; N *= 10)
      cout << lg(N) << " " << N << endl; 
  }
int lg(int N)
  {
    for (int i = 0; N > 0; i++, N /= 2) ;
    return i;    
  }
-----
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
typedef int Number;
Number randNum()
  { return rand(); }
int main(int argc, char *argv[])
  { int N = atoi(argv[1]);
    float m1 = 0.0, m2 = 0.0;
    for (int i = 0; i < N; i++)
      {
        Number x = randNum();
        m1 += ((float) x)/N; 
        m2 += ((float) x*x)/N;
      }
    cout << "     Avg.: " << m1 << endl;
    cout << "Std. dev.: " << sqrt(m2-m1*m1) << endl;
  }
-----
struct point { float x; float y; };
float distance(point, point);
-----
#include <math.h>
#include "Point.h"
float distance(point a, point b)
  { float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
  }
-----
#include <iostream.h>
static const int N = 1000;
int main()
  { int i, a[N];
    for (i = 2; i < N; i++) a[i] = 1;
    for (i = 2; i < N; i++)
      if (a[i])
        for (int j = i; j*i < N; j++) a[i*j] = 0;
    for (i = 2; i < N; i++)
      if (a[i]) cout << " " << i;
    cout << endl;
  }
-----
int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]);
    int *a = new int[N];
    if (a == 0) 
      { cout << "out of memory" << endl; return 0; }
    ...
-----
#include <iostream.h>
#include <stdlib.h>
int heads()
  { return rand() < RAND_MAX/2; }
int main(int argc, char *argv[])
  { int i, j, cnt;
    int N = atoi(argv[1]), M = atoi(argv[2]);
    int *f = new int[N+1];
    for (j = 0; j <= N; j++) f[j] = 0;
    for (i = 0; i < M; i++, f[cnt]++)
      for (cnt = 0, j = 0; j <= N; j++) 
        if (heads()) cnt++;
    for (j = 0; j <= N; j++) 
      {
        if (f[j] == 0) cout << ".";
        for (i = 0; i < f[j]; i+=10) cout << "*";
        cout << endl;
      }
 }
-----
#include <math.h>
#include <iostream.h>
#include <stdlib.h>
#include "Point.h"
float randFloat()
  { return 1.0*rand()/RAND_MAX; }
int main(int argc, char *argv[])
 { float d = atof(argv[2]); 
   int i, cnt = 0, N = atoi(argv[1]);
   point *a = new point[N];
   for (i = 0; i < N; i++)
     { a[i].x = randFloat(); a[i].y = randFloat(); }
   for (i = 0; i < N; i++)
     for (int j = i+1; j < N; j++)
       if (distance(a[i], a[j]) < d) cnt++; 
   cout << cnt << " pairs within " << d << endl;
 }
-----
#include <iostream.h>
#include <stdlib.h>
struct node 
  { int item; node* next; 
    node(int x, node* t) 
      { item = x; next = t; } 
  };
typedef node *link;
int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), M = atoi(argv[2]); 
    link t = new node(1, 0); t->next = t;
    link x = t;
    for (i = 2; i <= N; i++)
      x = (x->next = new node(i, t));
    while (x != x->next)
      {
        for (i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; 
      }
    cout << x->item << endl;
  }
-----
link reverse(link x)
  { link t, y = x, r = 0;
    while (y != 0)
      { t = y->next; y->next = r; r = y; y = t; }    
    return r;
  }
-----
    node heada(0, 0); link a = &heada, t = a; 
    for (int i = 0; i < N; i++)
      t = (t->next = new node(rand() % 1000, 0)); 
    node headb(0, 0); link u, x, b = &headb;
    for (t = a->next; t != 0; t = u)
      {
        u = t->next;
        for (x = b; x->next != 0; x = x->next)
          if (x->next->item > t->item) break;
        t->next = x->next; x->next = t; 
      }
-----
typedef int Item;
struct node { Item item; node *next; };
typedef node *link;
typedef link Node;

void construct(int);
Node newNode(int);
void deleteNode(Node);
void insert(Node, Node);
Node remove(Node);
Node next(Node);
Item item(Node);
-----
#include <iostream.h>
#include <stdlib.h>
#include "list.h"
int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), M = atoi(argv[2]); 
    Node t, x;
    construct(N); 
    for (i = 2, x = newNode(1); i <= N; i++)
      { t = newNode(i); insert(x, t); x = t; }
    while (x != next(x))
      {
        for (i = 1; i < M; i++) x = next(x);
        deleteNode(remove(x)); 
      }
    cout << item(x) << endl;
    return 0;
  }
-----
#include <stdlib.h>
#include "list.h"
link freelist;
void construct(int N)
  { 
    freelist = new node[N+1];
    for (int i = 0; i < N; i++)
      freelist[i].next = &freelist[i+1];
    freelist[N].next = 0;
  }    
link newNode(int i)
  { link x = remove(freelist); 
    x->item = i; x->next = x;
    return x;
  }
void deleteNode(link x)
  { insert(freelist, x); }
void insert(link x, link t)
  { t->next = x->next; x->next = t; }
link remove(link x)
  { link t = x->next; x->next = t->next; return t; }
link next(link x)
  { return x->next; }
Item item(link x)
  { return x->item; }
-----
#include <iostream.h>
#include <string.h>
static const int N = 10000;
int main(int argc, char *argv[])
  { int i; char t; 
    char a[N], *p = argv[1];
    for (i = 0; i < N-1; a[i] = t, i++)
      if (!cin.get(t)) break;
    a[i] = 0;
    for (i = 0; a[i] != 0; i++)
      { int j;
        for (j = 0; p[j] != 0; j++)
          if (a[i+j] != p[j]) break;
        if (p[j] == 0) cout << i << " ";
      }        
    cout << endl;
  }
-----
int **malloc2d(int r, int c)
  { int **t = new int*[r];
    for (int i = 0; i < r; i++)
      t[i] = new int[c];
    return t;
  }
-----
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *i, const void *j)
  { return strcmp(*(char **)i, *(char **)j); }
int main()
  { const int Nmax = 1000;
    const int Mmax = 10000;
    char* a[Nmax]; int N;
    char buf[Mmax]; int M = 0;
    for (N = 0; N < Nmax; N++)
      {
        a[N] = &buf[M];
        if (!(cin >> a[N])) break;
        M += strlen(a[N])+1;
      }
    qsort(a, N, sizeof(char*), compare);
    for (int i = 0; i < N; i++) 
      cout << a[i] << endl;
  }
-----
#include <iostream.h>
int main()
  { int i, j, adj[V][V];
    for (i = 0; i < V; i++)
      for (j = 0; j < V; j++) 
        adj[i][j] = 0;
    for (i = 0; i < V; i++) adj[i][i] = 1;
    while (cin >> i >> j)
      { adj[i][j] = 1; adj[j][i] = 1; }
  }
-----
#include <iostream.h>
struct node 
  { int v; node* next; 
    node(int x, node* t) 
      { v = x; next = t; } 
  };
typedef node *link;
int main()
  { int i, j; link adj[V];
    for (i = 0; i < V; i++) adj[i] = 0;
    while (cin >> i >> j)
      { 
        adj[j] = new node(i, adj[j]);
        adj[i] = new node(j, adj[i]);
      }
  }
-----
#include <math.h>
#include <iostream.h>
#include <stdlib.h>
#include "Point.h"
struct node 
  { point p; node *next; 
    node(point pt, node* t) { p = pt; next = t; } };
typedef node *link;
static link **grid; 
static int G, cnt = 0; static float d;
void gridinsert(float x, float y)
  { int X = x*G+1; int Y = y*G+1;
    point p; p.x = x; p.y = y;
    link s, t = new node(p, grid[X][Y]);
    for (int i = X-1; i <= X+1; i++)
      for (int j = Y-1; j <= Y+1; j++)
        for (s = grid[i][j]; s != 0; s = s->next)
          if (distance(s->p, t->p) < d) cnt++; 
    grid[X][Y] = t;
  }
int main(int argc, char *argv[])
 { int i, N = atoi(argv[1]);
   d = atof(argv[2]); G = 1/d;
   grid = malloc2d(G+2, G+2);
   for (i = 0; i < G+2; i++)
     for (int j = 0; j < G+2; j++)
       grid[i][j] = 0;
   for (i = 0; i < N; i++)
     gridinsert(randFloat(), randFloat());
   cout << cnt << " pairs within " << d << endl;
 }
-----

----------
CHAPTER 4. Abstract Data Types
-----
#include <math.h>
class POINT
  {
    private:
      float x, y;
    public:
      POINT()
        { x = 1.0*rand()/RAND_MAX;
          y = 1.0*rand()/RAND_MAX; }
      float distance(POINT a)
        { float dx = x-a.x, dy = y-a.y;
          return sqrt(dx*dx + dy*dy); }
  };
-----
#include <iostream.h>
#include <stdlib.h>
#include "POINT.cxx"
int main(int argc, char *argv[])
 { float d = atof(argv[2]); 
   int i, cnt = 0, N = atoi(argv[1]);
   POINT *a = new POINT[N];
   for (i = 0; i < N; i++)
     for (int j = i+1; j < N; j++)
       if (a[i].distance(a[j]) < d) cnt++; 
   cout << cnt << " pairs within " << d << endl;
 }
-----
class POINT
  {
    private:
      // Implementation-dependent code
    public:
      POINT();
      float distance(POINT) const;
  };
-----
template <class Item>
class STACK 
  {
    private:
      // Implementation-dependent code
    public:
      STACK(int);
      int empty() const;
      void push(Item item);
      Item pop();
  };
-----
#include <iostream.h>
#include <string.h>
#include "STACK.cxx"
int main(int argc, char *argv[])
  { char *a = argv[1]; int N = strlen(a);
    STACK<int> save(N);
    for (int i = 0; i < N; i++)
      {
        if (a[i] == '+') 
          save.push(save.pop() + save.pop());
        if (a[i] == '*') 
          save.push(save.pop() * save.pop());
        if ((a[i] >= '0') && (a[i] <= '9')) 
          save.push(0);
        while ((a[i] >= '0') && (a[i] <= '9')) 
          save.push(10*save.pop() + (a[i++]-'0')); 
      }
    cout << save.pop() << endl;
  }       
-----
#include <iostream.h>
#include <string.h>
#include "STACK.cxx"
int main(int argc, char *argv[])
  { char *a = argv[1]; int N = strlen(a);
    STACK<char> ops(N);
    for (int i = 0; i < N; i++)
      {
        if (a[i] == ')')
          cout << ops.pop() << " ";
        if ((a[i] == '+') || (a[i] == '*')) 
          ops.push(a[i]);
        if ((a[i] >= '0') && (a[i] <= '9')) 
          cout << a[i] << " ";
      }
    cout << endl;
  }       
-----
template <class Item>
class STACK 
  {
    private:
      Item *s; int N;
    public:
      STACK(int maxN)
        { s = new Item[maxN]; N = 0; }
      int empty() const
        { return N == 0; }
      void push(Item item)
        { s[N++] = item; }
      Item pop()
        { return s[--N]; }
  };
-----
template <class Item>
class STACK 
  {
    private:
      struct node 
        { Item item; node* next; 
          node(Item x, node* t) 
            { item = x; next = t; } 
        };
      typedef node *link;
      link head;
    public:
      STACK(int)
        { head = 0; }
      int empty() const
        { return head == 0; }
      void push(Item x)
        { head = new node(x, head); }
      Item pop()
        { Item v = head->item; link t = head->next;
          delete head; head = t; return v; }
  };
-----
class UF 
  {
    private:
      // Implementation-dependent code
    public:
      UF(int);
      int find(int, int);
      void unite(int, int);
  };
-----
#include <iostream.h>
#include <stdlib.h>
#include "UF.cxx"
int main(int argc, char *argv[])
  { int p, q, N = atoi(argv[1]);
    UF info(N);
    while (cin >> p >> q)
      if (!info.find(p, q)) 
        { 
          info.unite(p, q);
          cout << " " << p << " " << q << endl; 
        }
  }
-----
class UF 
  {
    private:
      int *id, *sz;
      int find(int x)
        { while (x != id[x]) x = id[x]; return x; }
    public:
      UF(int N)
        { 
          id = new int[N]; sz = new int[N];
          for (int i = 0; i < N; i++) 
            { id[i] = i; sz[i] = 1; } 
        }
      int find(int p, int q)
        { return (find(p) == find(q)); }
      void unite(int p, int q)
        { int i = find(p), j = find(q);
          if (i == j) return;
          if (sz[i] < sz[j])
               { id[i] = j; sz[j] += sz[i]; }
          else { id[j] = i; sz[i] += sz[j]; }
        }
  };
-----
class uf 
  {
    public:
      virtual uf(int) = 0;
      virtual int find(int, int) = 0;
      virtual void unite(int, int) = 0;
  };
-----
template <class Item>
class QUEUE
  {
    private:
      // Implementation-dependent code
    public:
      QUEUE(int);
      int empty();
      void put(Item);
      Item get();
  };
-----
template <class Item>
class QUEUE 
  {
    private:
      struct node 
        { Item item; node* next; 
          node(Item x) 
            { item = x; next = 0; } 
        };
      typedef node *link;
      link head, tail;
    public:
      QUEUE(int)
        { head = 0; }
      int empty() const
        { return head == 0; }
      void put(Item x)
        { link t = tail; 
          tail = new node(x);
          if (head == 0) 
               head = tail;
          else t->next = tail;
        }
      Item get()
        { Item v = head->item; link t = head->next;
          delete head; head = t; return v; }
  };
-----
template <class Item>
class QUEUE
  {
    private:
      Item *q; int N, head, tail;
    public:
      QUEUE(int maxN)
        { q = new Item[maxN+1]; 
          N = maxN+1; head = N; tail = 0; }
      int empty() const
        { return head % N == tail; }
      void put(Item item)
        { q[tail++] = item; tail = tail % N; }
      Item get()
        { head = head % N; return q[head++]; }
  };
-----
template <class Item>
class STACK 
  {
    private:
      Item *s, *t; int N;
    public:
      STACK(int maxN)
        { 
          s = new Item[maxN]; N = 0; 
          t = new Item[maxN];
          for (int i = 0; i < maxN; i++) t[i] = 0; 
        }
      int empty() const
        { return N == 0; }
      void push(Item item)
        { 
          if (t[item] == 1) return;
          s[N++] = item; t[item] = 1; 
        }
      Item pop()
        { t[s[--N]] = 0; return s[N]; }
  };
-----
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include "COMPLEX.cxx"
int main(int argc, char *argv[])
  { int N = atoi(argv[1]);
    cout << N << " complex roots of unity" << endl;
    for (int k = 0; k < N; k++)
      { float theta = 2.0*3.14159*k/N;
        Complex t(cos(theta), sin(theta)), x = t;
        cout << k << ": " << t << "  ";
        for (int j = 0; j < N-1; j++) x *= t;
        cout << x << endl;
      }
 }
-----
class Complex 
  {
    private:
      // Implementation-dependent code
    public:
      Complex(float, float);
      float Re() const;
      float Im() const;
      Complex& operator*=(Complex&);
  };
-----
#include <iostream.h>
class Complex 
  {
    private:
      float re, im;
    public:
      Complex(float x, float y)
        { re = x; im = y; }
      float Re() const
        { return re; }
      float Im() const
        { return im; }
      Complex& operator*=(const Complex& rhs)
        { float t = Re();
          re = Re()*rhs.Re() - Im()*rhs.Im();
          im = t*rhs.Im() + Im()*rhs.Re();
          return *this; 
        }
  };
ostream& operator<<(ostream& t, const Complex& c)
  { t << c.Re() << " " << c.Im(); return t; }
-----
#include <iostream.h>
#include <stdlib.h>
#include "QUEUE.cxx"
static const int M = 4;
int main(int argc, char *argv[])
  { int N = atoi(argv[1]); 
    QUEUE<int> queues[M];
    for (int i = 0; i < N; i++, cout << endl)
      { int in = rand() % M, out = rand() % M;
        queues[in].put(i);
        cout << i << " in ";
        if (!queues[out].empty())
          cout << queues[out].get() << " out";
        cout << endl;
        for (int k = 0; k < M; k++, cout << endl)
          { QUEUE<int> q = queues[k];
            cout << k << ": ";
            while (!q.empty())
              cout << q.get() << " ";
          }            
      }
  }
-----
template <class Item>
class QUEUE 
  {
    private:
      // Implementation-dependent code
    public:
      QUEUE(int);
      QUEUE(const QUEUE&);
      QUEUE& operator=(const QUEUE&);
      ~QUEUE();
      int empty() const;
      void put(Item);
      Item get();
  };
-----
    private:
      void deletelist()
        { 
          for (link t = head; t != 0; head = t)
            { t = head->next; delete head; }
        }
    public:
      QUEUE(const QUEUE& rhs)
        { head = 0; *this = rhs; }                  
      QUEUE& operator=(const QUEUE& rhs)
        { 
          if (this == &rhs) return *this;
          deletelist();
          link t = rhs.head;
          while (t != 0)
            { put(t->item); t = t->next; }
          return *this;
        }
      ~QUEUE()
        { deletelist(); }
-----
#include <iostream.h>
#include <stdlib.h>
#include "POLY.cxx"
int main(int argc, char *argv[])
  { int N = atoi(argv[1]); float p = atof(argv[2]);
    cout << "Binomial coefficients" << endl;
    POLY<int> x(1,1), one(1,0), t = x + one, y = t;
    for (int i = 0; i < N; i++)
      { y = y*t; cout << y << endl; }
    cout << y.eval(p) << endl;
 }
-----
template <class Number>
class POLY
  {
    private:
      // Implementation-dependent code
    public:
      POLY<Number>(Number, int);
      float eval(float) const;
      friend POLY operator+(POLY &, POLY &);
      friend POLY operator*(POLY &, POLY &);
  };
-----
template <class Number>
class POLY
  {
    private:
      int n; Number *a;
    public:
      POLY<Number>(Number c, int N)
        { a = new Number[N+1]; n = N+1; a[N] = c;
          for (int i = 0; i < N; i++) a[i] = 0; 
        }
      float eval(float x) const
        { double t = 0.0;
          for (int i = n-1; i >= 0; i--)
            t = t*x + a[i];
          return t;
        }
      friend POLY operator+(POLY &p, POLY &q)
        { POLY t(0, p.n>q.n ? p.n-1 : q.n-1);
          for (int i = 0; i < p.n; i++) 
            t.a[i] += p.a[i];
          for (int j = 0; j < q.n; j++) 
            t.a[j] += q.a[j];
          return t;
         }
      friend POLY operator*(POLY &p, POLY &q)
        { POLY t(0, (p.n-1)+(q.n-1));
          for (int i = 0; i < p.n; i++)
            for (int j = 0; j < q.n; j++)
              t.a[i+j] += p.a[i]*q.a[j];
          return t;
        }
  };

----------
CHAPTER 5. Recursion and Trees
-----
int factorial(int N)
  {
    if (N == 0) return 1;
    return N*factorial(N-1);
  }  
-----
int puzzle(int N)
  {
    if (N == 1) return 1;
    if (N % 2 == 0)
         return puzzle(N/2);
    else return puzzle(3*N+1);
  }  
-----
int gcd(int m, int n)
  {
    if (n == 0) return m;
    return gcd(n, m % n);
  }  
-----
char *a; int i;
int eval()
  { int x = 0;
    while (a[i] == ' ') i++;
    if (a[i] == '+')
      { i++; return eval() + eval(); }
    if (a[i] == '*')
      { i++; return eval() * eval(); }
    while ((a[i] >= '0') && (a[i] <= '9')) 
      x = 10*x + (a[i++]-'0'); 
    return x;
  }
-----
int count(link x)
  { 
    if (x == 0) return 0;
    return 1 + count(x->next); 
  }
void traverse(link h, void visit(link))
  { 
    if (h == 0) return;
    visit(h); 
    traverse(h->next, visit);
  }
void traverseR(link h, void visit(link))
  { 
    if (h == 0) return;
    traverseR(h->next, visit);
    visit(h); 
  }
void remove(link& x, Item v)
  { 
    while (x != 0 && x->item == v) 
      { link t = x; x = x->next; delete t; }
    if (x != 0) remove(x->next, v); 
  }
-----
Item max(Item a[], int l, int r)
  {
    if (l == r) return a[l];
    int m = (l+r)/2; 
    Item u = max(a, l, m);
    Item v = max(a, m+1, r);
    if (u > v) return u; else return v;
  }
-----
void hanoi(int N, int d)
  {
    if (N == 0) return;
    hanoi(N-1, -d);
    shift(N, d);    
    hanoi(N-1, -d);
  }  
-----
void rule(int l, int r, int h)
  { int m = (l+r)/2;
    if (h > 0)
      { 
        rule(l, m, h-1);
        mark(m, h);
        rule(m, r, h-1);
      }
  }
-----
void rule(int l, int r, int h)
  { 
    for (int t = 1, j = 1; t <= h; j += j, t++)
      for (int i = 0; l+j+i <= r; i += j+j)
        mark(l+j+i, t);
  }
-----
int F(int i)
  { 
    if (i < 1) return 0;
    if (i == 1) return 1;
    return F(i-1) + F(i-2);
  }
-----
int F(int i)
{ static int knownF[maxN];
  if (knownF[i] != 0) return knownF[i];
  int t = i;
  if (i < 0) return 0;
  if (i > 1) t = F(i-1) + F(i-2);
  return knownF[i] = t;
}
-----
int knap(int cap)
  { int i, space, max, t;
    for (i = 0, max = 0; i < N; i++)
      if ((space = cap-items[i].size) >= 0)
        if ((t = knap(space) + items[i].val) > max) 
          max = t;
    return max;     
  }
-----
int knap(int M)
  { int i, space, max, maxi = 0, t;
    if (maxKnown[M] != unknown) return maxKnown[M];
    for (i = 0, max = 0; i < N; i++)
      if ((space = M-items[i].size) >= 0)
        if ((t = knap(space) + items[i].val) > max)
          { max = t; maxi = i; }
    maxKnown[M] = max; itemKnown[M] = items[maxi];
    return max;     
  }
-----
void traverse(link h, void visit(link))
  { 
    if (h == 0) return;
    visit(h); 
    traverse(h->l, visit);
    traverse(h->r, visit);
  }
-----
void traverse(link h, void visit(link))
  { STACK<link> s(max);
    s.push(h);
    while (!s.empty())
      {
        visit(h = s.pop());
        if (h->r != 0) s.push(h->r); 
        if (h->l != 0) s.push(h->l); 
      }
  }
-----
void traverse(link h, void visit(link))
  { QUEUE<link> q(max);
    q.put(h);
    while (!q.empty())
      {
        visit(h = q.get());
        if (h->l != 0) q.put(h->l); 
        if (h->r != 0) q.put(h->r); 
      }
  }
-----
int count(link h)
  { 
    if (h == 0) return 0;
    return count(h->l) + count(h->r) + 1;
  }
int height(link h)
  { 
    if (h == 0) return -1;
    int u = height(h->l), v = height(h->r);
    if (u > v) return u+1; else return v+1;
  }
-----
void printnode(Item x, int h)
  { for (int i = 0; i < h; i++) cout << "  ";
    cout << x << endl;
  }
void show(link t, int h)
  { 
    if (t == 0) { printnode('*', h); return; }
    show(t->r, h+1);    
    printnode(t->item, h);
    show(t->l, h+1);    
  }
-----
struct node 
  { Item item; node *l, *r;
    node(Item x)
      { item = x; l = 0; r = 0; } 
  }; 
typedef node* link;
link max(Item a[], int l, int r)
  { int m = (l+r)/2;
    link x = new node(a[m]);
    if (l == r) return x;
    x->l = max(a, l, m);
    x->r = max(a, m+1, r);
    Item u = x->l->item, v = x->r->item;
    if (u > v) 
      x->item = u; else x->item = v;
    return x;
  }
-----
char *a; int i;
struct node 
  { Item item; node *l, *r; 
    node(Item x)
      { item = x; l = 0; r = 0; }
  };
typedef node* link;
link parse()
  { char t = a[i++]; link x = new node(t);
    if ((t == '+') || (t == '*'))
      { x->l = parse(); x->r = parse(); }
    return x;
  }
-----
void traverse(int k, void visit(int))
  { visit(k); visited[k] = 1;
    for (link t = adj[k]; t != 0; t = t->next)
      if (!visited[t->v]) traverse(t->v, visit);
  }
-----
void traverse(int k, void visit(int))
  {
    QUEUE<int> q(V*V);
    q.put(k);
    while (!q.empty())
      if (visited[k = q.get()] == 0)
        {
          visit(k); visited[k] = 1;
          for (link t = adj[k]; t != 0; t = t->next)
            if (visited[t->v] == 0) q.put(t->v);
        }
  }
-----

----------
CHAPTER 6. Elementary Sorting Methods
-----
#include <iostream.h>
#include <stdlib.h>
template <class Item> 
  void exch(Item &A, Item &B) 
    { Item t = A; A = B; B = t; } 
template <class Item> 
  void compexch(Item &A, Item &B) 
    { if (B < A) exch(A, B); }
template <class Item> 
  void sort(Item a[], int l, int r)
    { for (int i = l+1; i <= r; i++)
        for (int j = i; j > l; j--) 
          compexch(a[j-1], a[j]);
    }
int main(int argc, char *argv[])
  { int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = new int[N];
    if (sw) 
      for (i = 0; i < N; i++) 
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    else 
      { N = 0; while (cin >> a[N]) N++; }
    sort(a, 0, N-1);
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
  }
-----
template <class Item>
void selection(Item a[], int l, int r)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++) 
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]);
      } 
  }
-----
template <class Item>
void insertion(Item a[], int l, int r)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; Item v = a[i]; 
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v; 
      } 
  }
-----
template <class Item>
void bubble(Item a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }
-----
template <class Item>
void shellsort(Item a[], int l, int r)
  { int h; 
    for (h = 1; h <= (r-l)/9; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
      for (int i = l+h; i <= r; i++)
        { int j = i; Item v = a[i]; 
          while (j >= l+h && v < a[j-h])
            { a[j] = a[j-h]; j -= h; }
          a[j] = v; 
        } 
  }
-----
#include <stdlib.h>
#include "Item.h"
#include "exch.h"
#include "Array.h"
main(int argc, char *argv[])
  { int N = atoi(argv[1]), sw = atoi(argv[2]);
    Item *a = new Item[N];
    if (sw) rand(a, N); else scan(a, N); 
    sort(a, 0, N-1);
    show(a, 0, N-1);
  }
-----
template <class Item>
  void rand(Item a[], int N);
template <class Item>
  void scan(Item a[], int &N);
template <class Item>
  void show(Item a[], int l, int r);
template <class Item>
  void sort(Item a[], int l, int r);
-----
#include <iostream.h>                   
#include <stdlib.h>                   
#include "Array.h"
template <class Item>
  void rand(Item a[], int N)
    { for (int i = 0; i < N; i++) rand(a[i]); }
template <class Item>
  void scan(Item a[], int &N)
    { for (int i = 0; i < N; i++) 
        if (!scan(a[i])) break;
      N = i;
    }
template <class Item>
  void show(Item a[], int l, int r)
    { for (int i = l; i <=r; i++)
          show(a[i]);
      cout << endl;
    }  
-----
typedef struct record { int key; float info; } Item;
 int operator<(const Item&, const Item&);
 int scan(Item&);
void rand(Item&);
void show(const Item&);
-----
#include <iostream.h>
#include <stdlib.h>
#include "Item.h"
int operator<(const Item& A, const Item& B)
  { return A.key < B.key; }
int scan(Item& x)
  { return (cin >> x.key >> x.info) != 0; }
void rand(Item& x) 
  { x.key =  1000*(1.0*rand()/RAND_MAX); 
    x.info = 1.0*rand()/RAND_MAX; }  
void show(const Item& x)
  { cout << x.key << " " << x.info << endl; }
-----
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
static char buf[100000];
static int cnt = 0;
int operator<(const Item& a, const Item& b)
  { return strcmp(a.str, b.str) < 0; }
void show(const Item& x)
  { cout << x.str << " "; }
int scan(Item& x)
  { int flag = (cin >> (x.str = &buf[cnt])) != 0; 
    cnt += strlen(x.str)+1;
    return flag; 
  }
-----
struct record { char name[30]; int num; };
typedef struct { record *r; } Item;
int operator<(const Item&, const Item&);
void rand(Item&);
void show(const Item&);
int scan(Item&);
-----
static record data[maxN];
static int cnt = 0;
void show(const Item& x)
  { cout << x.r->name << " " << x.r->num << endl; }
int scan(Item& x)
  {  
    x.r = &data[cnt++]; 
    return (cin >> x.r->name >> x.r->num) != 0; 
  }
-----
template <class Item>
void insitu(Item data[], Index a[], int N)
  { for (int i = 0; i < N; i++) 
      { Item v = data[i]; 
        int j, k;
        for (k = i; a[k] != i; k = a[j], a[j] = j)
          { j = k; data[k] = data[a[k]]; }
        data[k] = v; a[k] = k;
      } 
  }  
-----
struct node 
  { Item item; node* next; 
    node(Item x) 
      { item = x; next = 0; } 
  };
typedef node *link;
link randlist(int);
link scanlist(int&);
void showlist(link);
link sortlist(link);
-----
link listselection(link h)
  { node dummy(0); link head = &dummy, out = 0;
    head->next = h;
    while (head->next != 0)
      { link max = findmax(head), t = max->next;
        max->next = t->next;
        t->next = out; out = t;
      } 
    return out;
  }
-----
void distcount(int a[], int l, int r)
  { int i, j, cnt[M]; 
    static int b[maxN];
    for (j = 0; j <  M; j++) cnt[j] = 0;
    for (i = l; i <= r; i++) cnt[a[i]+1]++;
    for (j = 1; j <  M; j++) cnt[j] += cnt[j-1];
    for (i = l; i <= r; i++) b[cnt[a[i]]++] = a[i];
    for (i = l; i <= r; i++) a[i] = b[i-l];
  } 

----------
CHAPTER 7. Quicksort
-----
template <class Item>
void quicksort(Item a[], int l, int r)
  {
    if (r <= l) return;
    int i = partition(a, l, r);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
  }
-----
template <class Item>
int partition(Item a[], int l, int r)
  { int i = l-1, j = r; Item v = a[r];
    for (;;)
      { 
        while (a[++i] < v) ;
        while (v < a[--j]) if (j == l) break;
        if (i >= j) break;
        exch(a[i], a[j]);
      }
    exch(a[i], a[r]);
    return i;
  }
-----
#include "STACK.cxx"
inline void push2(STACK<int> &s, int A, int B)
  { s.push(B); s.push(A); }
template <class Item>
void quicksort(Item a[], int l, int r)
  { STACK<int> s(50); 
    push2(s, l, r);
    while (!s.empty())
      {
        l = s.pop(); r = s.pop(); 
        if (r <= l) continue;
        int i = partition(a, l, r);
        if (i-l > r-i)
          { push2(s, l, i-1); push2(s, i+1, r); }
        else
          { push2(s, i+1, r); push2(s, l, i-1); }
      }
  }
-----
static const int M = 10;
template <class Item>
void quicksort(Item a[], int l, int r)
  {
    if (r-l <= M) return;
    exch(a[(l+r)/2], a[r-1]);
    compexch(a[l], a[r-1]); 
      compexch(a[l], a[r]); 
        compexch(a[r-1], a[r]);
    int i = partition(a, l+1, r-1);
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
  } 
template <class Item>
void hybridsort(Item a[], int l, int r)
  { quicksort(a, l, r); insertion(a, l, r); }
-----
template <class Item>
int operator==(const Item &A, const Item &B)
  { return !less(A, B) && !less(B, A); }
template <class Item>
void quicksort(Item a[], int l, int r)
  { int k; Item v = a[r];
    if (r <= l) return;
    int i = l-1, j = r, p = l-1, q = r;
    for (;;)
      { 
        while (a[++i] < v) ;
        while (v < a[--j]) if (j == l) break;
        if (i >= j) break;
        exch(a[i],a[j]);
        if (a[i] == v) { p++; exch(a[p],a[i]); }
        if (v == a[j]) { q--; exch(a[q],a[j]); }
      }
    exch(a[i], a[r]); j = i-1; i = i+1;
    for (k = l  ; k <= p; k++, j--) exch(a[k],a[j]);
    for (k = r-1; k >= q; k--, i++) exch(a[k],a[i]);
    quicksort(a, l, j);
    quicksort(a, i, r); 
  }
-----
template <class Item>
void select(Item a[], int l, int r, int k)
  {
    if (r <= l) return;
    int i = partition(a, l, r);
    if (i > k) select(a, l, i-1, k);
    if (i < k) select(a, i+1, r, k);
  }
-----
template <class Item>
void select(Item a[], int l, int r, int k)
  { 
    while (r > l)
      { int i = partition(a, l, r);
        if (i >= k) r = i-1;
        if (i <= k) l = i+1;
      } 
  }

----------
CHAPTER 8. Mergesort
-----
template <class Item>
void mergeAB(Item c[], Item a[], int N, 
                       Item b[], int M )
  {
    for (int i = 0, j = 0, k = 0; k < N+M; k++)
      {
        if (i == N) { c[k] = b[j++]; continue; }
        if (j == M) { c[k] = a[i++]; continue; }
        c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
      }
  }
-----
template <class Item>
void merge(Item a[], int l, int m, int r)
  { int i, j;
    static Item aux[maxN];
    for (i = m+1; i > l; i--) aux[i-1] = a[i-1];
    for (j = m; j < r; j++) aux[r+m-j] = a[j+1];
    for (int k = l; k <= r; k++)
       if (aux[j] < aux[i]) 
          a[k] = aux[j--]; else a[k] = aux[i++];
  }
-----
template <class Item>
void mergesort(Item a[], int l, int r)
  { if (r <= l) return;
    int m = (r+l)/2;
    mergesort(a, l, m);  
    mergesort(a, m+1, r);
    merge(a, l, m, r);
  }
-----
template <class Item>
void mergesortABr(Item a[], Item b[], int l, int r)
  { if (r-l <= 10) { insertion(a, l, r); return; }
    int m = (l+r)/2;
    mergesortABr(b, a, l, m);  
    mergesortABr(b, a, m+1, r);
    mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
  }
template <class Item>
void mergesortAB(Item a[], int l, int r)
  { static Item aux[maxN];
    for (int i = l; i <= r; i++) aux[i] = a[i];
    mergesortABr(a, aux, l, r);
  }
-----
inline int min(int A, int B) 
  { return (A < B) ? A : B; }
template <class Item>
void mergesortBU(Item a[], int l, int r)
  {
    for (int m = 1; m <= r-l; m = m+m)
      for (int i = l; i <= r-m; i += m+m)
        merge(a, i, i+m-1, min(i+m+m-1, r));
  }
-----
link merge(link a, link b)
  { node dummy(0); link head = &dummy, c = head;
    while ((a != 0) && (b != 0))
      if (a->item < b->item)
        { c->next = a; c = a; a = a->next; }
      else
        { c->next = b; c = b; b = b->next; }
    c->next = (a == 0) ? b : a;
    return head->next;
  }
-----
link mergesort(link c)
  { 
    if (c == 0 || c->next == 0) return c;
    link a = c, b = c->next;
    while ((b != 0) && (b->next != 0))
      { c = c->next; b = b->next->next; }
    b = c->next; c->next = 0;
    return merge(mergesort(a), mergesort(b));
  }
-----
link mergesort(link t)
  { QUEUE<link> Q(max);
    if (t == 0 || t->next == 0) return t;
    for (link u = 0; t != 0; t = u) 
      { u = t->next; t->next = 0; Q.put(t); }
    t = Q.get();     
    while (!Q.empty())
      { Q.put(t); t = merge(Q.get(), Q.get()); }
    return t;
  }

----------
CHAPTER 9. Priority Queues and Heapsort
-----
template <class Item>
class PQ 
  {
    private:
      // Implementation-dependent code
    public:
      PQ(int);
      int empty() const;
      void insert(Item);
      Item getmax();
  };
-----
template <class Item>
class PQ 
  {
    private:
      Item *pq; 
      int N;
    public:
      PQ(int maxN)
        { pq = new Item[maxN]; N = 0; }
      int empty() const
        { return N == 0; }
      void insert(Item item)
        { pq[N++] = item; }
      Item getmax()
        { int max = 0;
          for (int j = 1; j < N; j++)
            if (pq[max] < pq[j]) max = j;
          exch(pq[max], pq[N-1]);  
          return pq[--N];
        }
  };
-----
template <class Item>
void fixUp(Item a[], int k)
  {
    while (k > 1 && a[k/2] < a[k])
      { exch(a[k], a[k/2]); k = k/2; }
  }
-----
template <class Item>
void fixDown(Item a[], int k, int N)
  {
    while (2*k <= N)
      { int j = 2*k;
        if (j < N && a[j] < a[j+1]) j++;
        if (!(a[k] < a[j])) break;
        exch(a[k], a[j]); k = j;
      }
  }
-----
template <class Item>
class PQ 
  {
    private:
      Item *pq; 
      int N;
    public:
      PQ(int maxN)
        { pq = new Item[maxN+1]; N = 0; }
      int empty() const
        { return N == 0; }
      void insert(Item item)
        { pq[++N] = item;  fixUp(pq, N); }
      Item getmax()
        { 
          exch(pq[1], pq[N]); 
          fixDown(pq, 1, N-1); 
          return pq[N--]; 
        }
  };
-----
#include "PQ.cxx"
template <class Item>
void PQsort(Item a[], int l, int r)
  { int k;
    PQ<Item> pq(r-l+1);
    for (k = l; k <= r; k++) pq.insert(a[k]);
    for (k = r; k >= l; k--) a[k] = pq.getmax();
  }
-----
template <class Item>
void heapsort(Item a[], int l, int r)
  { int k, N = r-l+1;
    Item *pq = a+l-1;
    for (k = N/2; k >= 1; k--) 
      fixDown(pq, k, N);
    while (N > 1) 
      { exch(pq[1], pq[N]); 
        fixDown(pq, 1, --N); }
  }
-----
template <class Item>
class PQ 
  {
    private:
      // Implementation-dependent code
    public:
      // Implementation-dependent handle definition
      PQ(int);
      int empty() const;
      handle insert(Item);
      Item getmax();
      void change(handle, Item);
      void remove(handle);
      void join(PQ<Item>&);
  };
-----
template <class Item>
class PQ 
  {
    private:
      struct node 
        { Item item; node *prev, *next; 
          node(Item v) 
            { item = v; prev = 0; next = 0; } 
        }; 
      typedef node *link;
      link head, tail;
    public:
      typedef node* handle;
      PQ(int = 0)
        { 
          head = new node(0); tail = new node(0); 
          head->prev = tail; head->next = tail;
          tail->prev = head; tail->next = head; 
        }
      int empty() const
        { return head->next->next == head; }
      handle insert(Item v)
        { handle t = new node(v);
          t->next = head->next; t->next->prev = t;
          t->prev = head; head->next = t;
          return t;
         }
      Item getmax();
      void change(handle, Item);
      void remove(handle);
      void join(PQ<Item>&);
  };
-----
  Item getmax()
    { Item max; link x = head->next;
      for (link t = x; t->next != head; t = t->next)
        if (x->item < t->item) x = t;
      max = x->item; 
      remove(x); 
      return max;
    }
  void change(handle x, Item v)
    { x->key = v; }  
  void remove(handle x)
    {
      x->next->prev = x->prev;
      x->prev->next = x->next;
      delete x;
    }  
  void join(PQ<Item>& p)
    {
      tail->prev->next = p.head->next;
      p.head->next->prev = tail->prev;
      head->prev = p.tail; 
      p.tail->next = head;
      delete tail; delete p.head;
      tail = p.tail;
    }
-----
template <class Index>
class PQ 
  {
    private:
      // Implementation-dependent code
    public:
      PQ(int);
      int empty() const;
      void insert(Index);
      Index getmax();
      void change(Index);
      void remove(Index);
  };
-----
template <class Index>
class PQ 
  {
    private:
      int N; Index* pq; int* qp;
      void exch(Index i, Index j)
        { int t;
          t = qp[i]; qp[i] = qp[j]; qp[j] = t;
          pq[qp[i]] = i; pq[qp[j]] = j;
        }
    void fixUp(Index a[], int k);
    void fixDown(Index a[], int k, int N);
    public:
      PQ(int maxN)
        { pq = new Index[maxN+1]; 
          qp = new int[maxN+1];  N = 0; }
      int empty() const
        { return N == 0; }
      void insert(Index v)
        { pq[++N] = v; qp[v] = N; fixUp(pq, N); }
      Index getmax()
        { 
          exch(pq[1], pq[N]); 
          fixDown(pq, 1, N-1); 
          return pq[N--]; 
        }
      void change(Index k)
        { fixUp(pq, qp[k]); fixDown(pq, qp[k], N); }
  };
-----
static link pair(link p, link q)
  {
    if (p->item < q->item) 
      { p->r = q->l; q->l = p; return q; }
    else { q->r = p->l; p->l = q; return p; }
  }
-----
handle insert(Item v)
  { link t = new node(v), c = t;
    for (int i = 0; i < maxBQsize; i++)
      {
        if (c == 0) break;
        if (bq[i] == 0) { bq[i] = c; break; }
        c = pair(c, bq[i]); bq[i] = 0;
      }
    return t;
  }
-----
Item getmax()
  { int i, max; Item v = 0; 
    link* temp = new link[maxBQsize];
    for (i = 0, max = -1; i < maxBQsize; i++)
      if (bq[i] != 0) 
        if ((max == -1) || (v < bq[i]->item))
          { max = i; v = bq[max]->item; }
    link x = bq[max]->l; 
    for (i = max; i < maxBQsize; i++) temp[i] = 0; 
    for (i = max ; i > 0; i--)
      { temp[i-1] = x; x = x->r; temp[i-1]->r = 0; }
    delete bq[max]; bq[max] = 0;
    BQjoin(bq, temp);  
    delete temp;
    return v;
  }      
-----
static inline int test(int C, int B, int A)
  { return 4*C + 2*B + 1*A; }
static void BQjoin(link *a, link *b)
  { link c = 0;
    for (int i = 0; i < maxBQsize; i++)
      switch(test(c != 0, b[i] != 0, a[i] != 0))
        {
          case 2: a[i] = b[i]; break;
          case 3: c = pair(a[i], b[i]); 
                  a[i] = 0; break;
          case 4: a[i] = c; c = 0; break;
          case 5: c = pair(c, a[i]); 
                  a[i] = 0; break;
          case 6: 
          case 7: c = pair(c, b[i]); break;
        }
  }

----------
CHAPTER 10. Radix Sorting
-----
template <class Item>
void quicksortB(Item a[], int l, int r, int d)
  { int i = l, j = r;
    if (r <= l || d > bitsword) return;
    while (j != i)
      { 
        while (digit(a[i], d) == 0 && (i < j)) i++;
        while (digit(a[j], d) == 1 && (j > i)) j--;
        exch(a[i], a[j]);
      }
    if (digit(a[r], d) == 0) j++;
    quicksortB(a, l, j-1, d+1);
    quicksortB(a, j, r, d+1);
  }
template <class Item>
void sort(Item a[], int l, int r)
  { quicksortB(a, l, r, 0); }
-----
#define bin(A) l+count[A]
template <class Item>
void radixMSD(Item a[], int l, int r, int d)
  { int i, j, count[R+1]; 
    static Item aux[maxN];
    if (d > bytesword) return;
    if (r-l <= M) { insertion(a, l, r); return; }
    for (j = 0; j < R; j++) count[j] = 0;
    for (i = l; i <= r; i++) 
      count[digit(a[i], d) + 1]++;
    for (j = 1; j < R; j++) 
      count[j] += count[j-1];
    for (i = l; i <= r; i++) 
      aux[count[digit(a[i], d)]++] = a[i];
    for (i = l; i <= r; i++) a[i] = aux[i-l];
    radixMSD(a, l, bin(0)-1, d+1);
    for (j = 0; j < R-1; j++)
      radixMSD(a, bin(j), bin(j+1)-1, d+1);
  }
-----
#define ch(A) digit(A, d)
template <class Item>
void quicksortX(Item a[], int l, int r, int d)
  { 
    int i, j, k, p, q; int v;
    if (r-l <= M) { insertion(a, l, r); return; }
    v = ch(a[r]); i = l-1; j = r; p = l-1; q = r;
    while (i < j)
      { 
        while (ch(a[++i]) < v) ;
        while (v < ch(a[--j])) if (j == l) break;
        if (i > j) break;
        exch(a[i], a[j]);
        if (ch(a[i])==v) { p++; exch(a[p], a[i]); }
        if (v==ch(a[j])) { q--; exch(a[j], a[q]); }
      }
    if (p == q) 
      { if (v != '\0') quicksortX(a, l, r, d+1); 
        return; }
    if (ch(a[i]) < v) i++;
    for (k = l; k <= p; k++, j--) exch(a[k], a[j]);
    for (k = r; k >= q; k--, i++) exch(a[k], a[i]);
    quicksortX(a, l, j, d);
    if ((i == r) && (ch(a[i]) == v)) i++;
    if (v != '\0') quicksortX(a, j+1, i-1, d+1); 
    quicksortX(a, i, r, d); 
  }
-----
template <class Item>
void radixLSD(Item a[], int l, int r)
  { static Item aux[maxN];
    for (int d = bytesword-1; d >= 0; d--)
      {
        int i, j, count[R+1]; 
        for (j = 0; j < R; j++) count[j] = 0;
        for (i = l; i <= r; i++) 
          count[digit(a[i], d) + 1]++;
        for (j = 1; j < R; j++) 
          count[j] += count[j-1];
        for (i = l; i <= r; i++) 
          aux[count[digit(a[i], d)]++] = a[i];
        for (i = l; i <= r; i++) a[i] = aux[i-l];
      }
  } 

----------
CHAPTER 11. Special-Purpose Sorts
-----
template <class Item>
void shuffle(Item a[], int l, int r)
  { int i, j, m = (l+r)/2;
    static Item aux[maxN];
    for (i = l, j = 0; i <= r; i+=2, j++)
      { aux[i] = a[l+j]; aux[i+1] = a[m+1+j]; }
    for (i = l; i <= r; i++) a[i] = aux[i];
  }
template <class Item>
void unshuffle(Item a[], int l, int r)
  { int i, j, m = (l+r)/2;
    static Item aux[maxN];
    for (i = l, j = 0; i <= r; i+=2, j++)
      { aux[l+j] = a[i]; aux[m+1+j] = a[i+1]; }
    for (i = l; i <= r; i++) a[i] = aux[i];
  }
-----
template <class Item>
void merge(Item a[], int l, int m, int r)
  { 
    if (r == l+1) compexch(a[l], a[r]);
    if (r < l+2) return;
    unshuffle(a, l, r);
    merge(a, l, (l+m)/2, m); 
    merge(a, m+1, (m+1+r)/2, r);
    shuffle(a, l, r);
    for (int i = l+1; i < r; i+=2) 
      compexch(a[i], a[i+1]);
  }
-----
template <class Item>
void merge(Item a[], int l, int m, int r)
  { int N = r-l+1;  // assuming N/2 is m-l+1
    for (int k = N/2; k > 0; k /= 2)
      for (int j = k % (N/2); j+k < N; j += k+k) 
        for (int i = 0; i < k; i++) 
          compexch(a[l+j+i], a[l+j+i+k]);
  }
-----
template <class Item>
void batchersort(Item a[], int l, int r)
  { int N = r-l+1;
    for (int p = 1; p < N; p += p)
      for (int k = p; k > 0; k /= 2)
        for (int j = k%p; j+k < N; j += (k+k)) 
          for (int i = 0; i < N-j-k; i++) 
            if ((j+i)/(p+p) == (j+i+k)/(p+p)) 
              compexch(a[l+j+i], a[l+j+i+k]);
  }
-----
-----

----------
CHAPTER 12. Symbol Tables and BSTs
-----
#include <stdlib.h>
#include <iostream.h>
static int maxKey = 1000;
typedef int Key;
class Item 
  { 
    private:
      Key keyval; 
      float info;
    public:
      Item() 
        { keyval = maxKey; } 
      Key key()
        { return keyval; }
      int null()
        { return keyval == maxKey; }
      void rand()
        { keyval = 1000*::rand()/RAND_MAX;   
          info = 1.0*::rand()/RAND_MAX; }  
      int scan(istream& is = cin)
        { return (is >> keyval >> info) != 0; }
      void show(ostream& os = cout)
        { os << keyval << " " << info << endl; }
   }; 
ostream& operator<<(ostream& os, Item& x)
  { x.show(os); return os; }
-----
template <class Item, class Key>
class ST 
  {
    private:
      // Implementation-dependent code
    public:
      ST(int);
      int count();
      Item search(Key) ;
      void insert(Item);
      void remove(Item);
      Item select(int);
      void show(ostream&);
  };
-----
#include <iostream.h>
#include <stdlib.h>
#include "Item.cxx"
#include "ST.cxx"
int main(int argc, char *argv[])
  { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    ST<Item, Key> st(maxN);
    for (N = 0; N < maxN; N++)
      { Item v; 
        if (sw) v.rand(); else if (!v.scan()) break;
        if (!(st.search(v.key())).null()) continue;
        st.insert(v); 
      }
    st.show(cout); cout << endl;
    cout << N << " keys" << endl;
    cout << st.count() << " distinct keys" << endl;
  }
-----
template <class Item, class Key>
class ST 
  {
    private:
      Item nullItem, *st;
      int M;
    public:
      ST(int maxN)
        { M = nullItem.key(); st = new Item[M]; }
      int count()
        { int N = 0; 
          for (int i = 0; i < M; i++) 
            if (!st[i].null()) N++;
          return N;
        }
      void insert(Item x)
        { st[x.key()] = x; }
      Item search(Key v)
        { return st[v]; }
      void remove(Item x)
        { st[x.key()] = nullItem; }
      Item select(int k)
        { for (int i = 0; i < M; i++)
            if (!st[i].null()) 
              if (k-- == 0) return st[i];
          return nullItem;
        }
      void show(ostream& os)
        { for (int i = 0; i < M; i++)
            if (!st[i].null()) st[i].show(os); }
  };
-----
template <class Item, class Key>
class ST 
  {
    private:
      Item nullItem, *st; 
      int N;
    public:
      ST(int maxN)
        { st = new Item[maxN+1]; N = 0; }
      int count()
        { return N; }
      void insert(Item x)
        { int i = N++; Key v = x.key();
          while (i > 0 && v < st[i-1].key())
            {  st[i] = st[i-1]; i--; }
          st[i] = x;
        }
      Item search(Key v)
        {
          for (int i = 0; i < N; i++)
            if (!(st[i].key() < v)) break;
          if (v == st[i].key()) return st[i];
          return nullItem;
        }
      Item select(int k)
        { return st[k]; }
      void show(ostream& os)
        { int i = 0; 
          while (i < N) st[i++].show(os); }
  };
-----
#include <stdlib.h>
template <class Item, class Key>
class ST 
  {
    private:
      Item nullItem;
      struct node 
        { Item item; node* next; 
          node(Item x, node* t)
            { item = x; next = t; } 
        }; 
      typedef node *link;
      int N;
      link head;
      Item searchR(link t, Key v)
        { if (t == 0) return nullItem;
          if (t->item.key() == v) return t->item;
          return searchR(t->next, v);
        }
    public:
      ST(int maxN)
        { head = 0; N = 0; }
      int count()
        { return N; }
      Item search(Key v)
        { return searchR(head, v); }
      void insert(Item x)
        { head = new node(x, head); N++; }
    };
-----
    private:
      Item searchR(int l, int r, Key v)
        { if (l > r) return nullItem;
          int m = (l+r)/2;
          if (v == st[m].key()) return st[m];
          if (l == r) return nullItem;
          if (v < st[m].key()) 
               return searchR(l, m-1, v);
          else return searchR(m+1, r, v);
        }
    public:
      Item search(Key v)
        { return searchR(0, N-1, v); }
-----
template <class Item, class Key>
class ST 
  {
    private:
      struct node 
        { Item item; node *l, *r;
          node(Item x)
            { item = x; l = 0; r = 0; } 
        }; 
      typedef node *link;
      link head;
      Item nullItem;
      Item searchR(link h, Key v)
        { if (h == 0) return nullItem;
          Key t = h->item.key();
          if (v == t) return h->item;
          if (v < t) return searchR(h->l, v);
                else return searchR(h->r, v);
        }
      void insertR(link& h, Item x)
        { if (h == 0) { h = new node(x); return; }
          if (x.key() < h->item.key()) 
               insertR(h->l, x);
          else insertR(h->r, x);
        }
    public:
      ST(int maxN)
        { head = 0; }
      Item search(Key v) 
        { return searchR(head, v); } 
      void insert(Item x)
        { insertR(head, x); }
  };
-----
   private:
      void showR(link h, ostream& os)
        { 
          if (h == 0) return;
          showR(h->l, os);
          h->item.show(os); 
          showR(h->r, os);
        }
    public:
      void show(ostream& os)
        { showR(head, os); } 
-----
void insert(Item x)
  { Key v = x.key();
    if (head == 0) 
      { head = new node(x); return; }
    link p = head;
    for (link q = p; q != 0; p = q ? q : p)
      q = (v < q->item.key()) ? q->l : q->r; 
    if (v < p->item.key()) p->l = new node(x); 
                      else p->r = new node(x);
  }
-----
#include <iostream.h>
#include <fstream.h>
#include "Item.cxx"
#include "ST.cxx"
static char text[maxN];
int main(int argc, char *argv[])
  { int N = 0; char t;
    ifstream corpus; corpus.open(*++argv);
    while (N < maxN && corpus.get(t)) text[N++] = t; 
    text[N] = 0;
    ST<Item, Key> st(maxN);
    for (int i = 0; i < N; i++) st.insert(&text[i]);
    char query[maxQ]; Item x, v(query);
    while (cin.getline(query, maxQ))
      if ((x = st.search(v.key())).null())
           cout << "not found: " << query << endl;
      else cout <<  x-text << ": " << query << endl;
  }
-----
void rotR(link& h)
  { link x = h->l; h->l = x->r; x->r = h; h = x; }
void rotL(link& h)
  { link x = h->r; h->r = x->l; x->l = h; h = x; }
-----
private:
  void insertT(link& h, Item x)
    { if (h == 0) { h = new node(x); return; }
      if (x.key() <  h->item.key()) 
           { insertT(h->l, x); rotR(h); }
      else { insertT(h->r, x); rotL(h); }
    }
public:
  void insert(Item item)
    { insertT(head, item); }
-----
private:
  Item selectR(link h, int k)
    { if (h == 0) return nullItem;
      int t = (h->l == 0) ? 0: h->l->N;
      if (t > k) return selectR(h->l, k);
      if (t < k) return selectR(h->r, k-t-1);
      return h->item;
    }
public:
  Item select(int k)
    { return selectR(head, k); } 
-----
void partR(link& h, int k)
  { int t = (h->l == 0) ? 0: h->l->N;
    if (t > k )
      { partR(h->l, k); rotR(h); }
    if (t < k )
      { partR(h->r, k-t-1); rotL(h); }
  } 
-----
private:
  link joinLR(link a, link b)
    { 
      if (b == 0) return a;
      partR(b, 0); b->l = a; 
      return b;
    }
  void removeR(link& h, Key v)
    { if (h == 0) return;
      Key w = h->item.key(); 
      if (v < w) removeR(h->l, v);
      if (w < v) removeR(h->r, v);
      if (v == w) 
        { link t = h; 
          h = joinLR(h->l, h->r); delete t; }
    }
public:
  void remove(Item x)
    { removeR(head, x.key()); }
-----
    private:
      link joinR(link a, link b)
        { 
          if (b == 0) return a;
          if (a == 0) return b;
          insertT(b, a->item); 
          b->l = joinR(a->l, b->l); 
          b->r = joinR(a->r, b->r); 
          delete a; return b;
        }
    public:
      void join(ST<Item, Key>& b)
        { head = joinR(head, b.head); }

----------
CHAPTER 13. Balanced Trees
-----
void balanceR(link& h)
  {
    if ((h == 0) || (h->N == 1)) return;
    partR(h, h->N/2);
    balanceR(h->l);
    balanceR(h->r);
  }
-----
private:
  void insertR(link& h, Item x)
    { if (h == 0) { h = new node(x); return; }
      if (rand() < RAND_MAX/(h->N+1))
        { insertT(h, x); return; }
      if (x.key() < h->item.key()) 
           insertR(h->l, x);
      else insertR(h->r, x);
      h->N++; 
    }
public:
  void insert(Item x)
    { insertR(head, x); }
-----
private:
  link joinR(link a, link b)
    { 
      if (a == 0) return b;
      if (b == 0) return a;
      insertR(b, a->item); 
      b->l = joinR(a->l, b->l); 
      b->r = joinR(a->r, b->r); 
      delete a; fixN(b); return b;
    }
public:
  void join(ST<Item, Key>& b)
    { int N = head->N;
      if (rand()/(RAND_MAX/(N+b.head->N)+1) < N)
           head = joinR(head, b.head);
      else head = joinR(b.head, head); }
-----
link joinLR(link a, link b)
  { 
    if (a == 0) return b;
    if (b == 0) return a;
    if (rand()/(RAND_MAX/(a->N+b->N)+1) < a->N)
         { a->r = joinLR(a->r, b); return a; }
    else { b->l = joinLR(a, b->l); return b; }
  }
-----
private:
  void splay(link& h, Item x)
    { 
      if (h == 0) 
        { h = new node(x, 0, 0, 1); return; }
      if (x.key() < h->item.key())
        { link& hl = h->l; int N = h->N;
          if (hl == 0) 
            { h = new node(x, 0, h, N+1); return; }
          if (x.key() <  hl->item.key()) 
               { splay(hl->l, x); rotR(h); }
          else { splay(hl->r, x); rotL(hl); }
          rotR(h);
        }
      else
        { link &hr = h->r; int N = h->N;
          if (hr == 0) 
            { h = new node(x, h, 0, N+1); return; }
          if (hr->item.key() < x.key()) 
               { splay(hr->r, x); rotL(h); }
          else { splay(hr->l, x); rotR(hr); }
          rotL(h);
        }
    }
public:
  void insert(Item item)
    { splay(head, item); }
-----
private:
  int red(link x) 
    { if (x == 0) return 0; return x->red; }
  void RBinsert(link& h, Item x, int sw)
    { 
      if (h == 0) { h = new node(x); return; }
      if (red(h->l) && red(h->r)) 
      { h->red = 1; h->l->red = 0; h->r->red = 0; }
      if (x.key() < h->item.key())
        {
          RBinsert(h->l, x, 0); 
          if (red(h) && red(h->l) && sw) rotR(h); 
          if (red(h->l) && red(h->l->l)) 
            { rotR(h); h->red = 0; h->r->red = 1; }
        }
      else
        { 
          RBinsert(h->r, x, 1); 
          if (red(h) && red(h->r) && !sw) rotL(h); 
          if (red(h->r) && red(h->r->r)) 
            { rotL(h); h->red = 0; h->l->red = 1; }
        }
    }
public:
  void insert(Item x)
    { RBinsert(head, x, 0); head->red = 0; }
-----
private:
  Item searchR(link t, Key v, int k)
    { if (t == 0) return nullItem;
      if (v == t->item.key()) return t->item;
      link x = t->next[k];
      if ((x == 0) || (v < x->item.key())) 
        { 
          if (k == 0) return nullItem;
          return searchR(t, v, k-1); 
        }
      return searchR(x, v, k);
    }
public:
  Item search(Key v)
    { return searchR(head, v, lgN); }
-----
private:
  struct node 
    { Item item; node **next; int sz; 
      node(Item x, int k)
        { item = x; sz = k; next = new node*[k]; 
          for (int i = 0; i < k; i++) next[i] = 0; } 
    }; 
  typedef node *link;
  link head;
  Item nullItem;
  int lgN;
public:
  ST(int)
    { head = new node(nullItem, lgNmax); lgN = 0; }
-----
private:
  int randX()
    { int i, j, t = rand();
      for (i = 1, j = 2; i < lgNmax; i++, j += j)
        if (t > RAND_MAX/j) break;
      if (i > lgN) lgN = i;
      return i;
    }
  void insertR(link t, link x, int k)
    { Key v = x->item.key(); link tk = t->next[k];
      if ((tk == 0) || (v < tk->item.key())) 
        { 
          if (k < x->sz)
            { x->next[k] = tk; t->next[k] = x; }
          if (k == 0) return;
          insertR(t, x, k-1); return;
        }
      insertR(tk, x, k);
    }
public:
  void insert(Item v)
    { insertR(head, new node(v, randX()), lgN); }
-----
private:
  void removeR(link t, Key v, int k)
    { link x = t->next[k];
      if (!(x->item.key() < v)) 
        { 
          if (v == x->item.key())
            { t->next[k] = x->next[k]; }
          if (k == 0) { delete x; return; }
          removeR(t, v, k-1); return;
        }
      removeR(t->next[k], v, k);
    }
public:
  void remove(Item x)
    { removeR(head, x.key(), lgN); }

----------
CHAPTER 14. Hashing
-----
int hash(char *v, int M)
  { int h = 0, a = 127;
    for (; *v != 0; v++) 
      h = (a*h + *v) % M;
    return h;
  }
-----
int hashU(char *v, int M)
  { int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1)) 
        h = (a*h + *v) % M;
    return (h < 0) ? (h + M) : h;
  }
-----
private:
  link* heads;
  int N, M;
public:
  ST(int maxN)
    { 
      N = 0; M = maxN/5;
      heads = new link[M]; 
      for (int i = 0; i < M; i++) heads[i] = 0;
    }
  Item search(Key v)
    { return searchR(heads[hash(v, M)], v); }
  void insert(Item item)
    { int i = hash(item.key(), M);
      heads[i] = new node(item, heads[i]); N++; }
-----
private:
  Item *st; 
  int N, M;
  Item nullItem;
public:
  ST(int maxN)
    { 
      N = 0; M = 2*maxN;
      st = new Item[M]; 
      for (int i = 0; i < M; i++) st[i] = nullItem;
    }
  int count() const { return N; }
  void insert(Item item)
    { int i = hash(item.key(), M);
      while (!st[i].null()) i = (i+1) % M;
      st[i] = item; N++;
    }
  Item search(Key v)
    { int i = hash(v, M);
      while (!st[i].null())
      if (v == st[i].key()) return st[i];
        else i = (i+1) % M;
      return nullItem;
    }
-----
void remove(Item x)
  { int i = hash(x.key(), M), j;
    while (!st[i].null())
      if (x.key() == st[i].key()) break; 
        else i = (i+1) % M;
    if (st[i].null()) return;
    st[i] = nullItem; N--;
    for (j = i+1; !st[j].null(); j = (j+1) % M, N--)
    { Item v = st[j]; st[j] = nullItem; insert(v); }
  }
-----
void insert(Item item)
  { Key v = item.key();
    int i = hash(v, M), k = hashtwo(v, M);
    while (!st[i].null()) i = (i+k) % M;
    st[i] = item; N++;
  }
Item search(Key v)
  { int i = hash(v, M), k = hashtwo(v, M);
    while (!st[i].null())
    if (v == st[i].key()) return st[i];
      else i = (i+k) % M;
    return nullItem;
  }
-----
private:
  void expand()
    { Item *t = st;
      init(M+M);
      for (int i = 0; i < M/2; i++)
        if (!t[i].null()) insert(t[i]);
      delete t;
    }
public:
  ST(int maxN)
    { init(4); }
  void insert(Item item)
    { int i = hash(item.key(), M);
      while (!st[i].null()) i = (i+1) % M;
      st[i] = item; 
      if (N++ >= M/2) expand();
    }

----------
CHAPTER 15. Radix Search
-----
private:
  Item searchR(link h, Key v, int d)
    { if (h == 0) return nullItem;
      if (v ==  h->item.key()) return h->item;
      if (digit(v, d) == 0)
           return searchR(h->l, v, d+1);
      else return searchR(h->r, v, d+1);
    }
public:
  Item search(Key v) 
    { return searchR(head, v, 0); } 
-----
private:
  Item searchR(link h, Key v, int d)
    { if (h == 0) return nullItem;
      if (h->l == 0 && h->r == 0)
        { Key w = h->item.key();
          return (v == w) ? h->item : nullItem; }
      if (digit(v, d) == 0)
           return searchR(h->l, v, d+1);
      else return searchR(h->r, v, d+1);
    }
public:
  Item search(Key v) 
    { return searchR(head, v, 0); } 
-----
private:
  link split(link p, link q, int d)
    { link t = new node(nullItem); t->N = 2;
      Key v = p->item.key(); Key w = q->item.key();
      switch(digit(v, d)*2 + digit(w, d))
        { case 0: t->l = split(p, q, d+1); break;
          case 1: t->l = p; t->r = q; break;
          case 2: t->r = p; t->l = q; break;
          case 3: t->r = split(p, q, d+1); break;
        }
      return t;
    }
  void insertR(link& h, Item x, int d)
    { if (h == 0) { h = new node(x); return; }
      if (h->l == 0 && h->r == 0)
        { h = split(new node(x), h, d); return; }
      if (digit(x.key(), d) == 0) 
           insertR(h->l, x, d+1);
      else insertR(h->r, x, d+1);
    }
public:
  ST(int maxN)
    { head = 0; }
  void insert(Item item)
    { insertR(head, item, 0); }
-----
private:
  Item searchR(link h, Key v, int d)
    { 
      if (h->bit <= d) return h->item;
      if (digit(v, h->bit) == 0)
           return searchR(h->l, v, h->bit);
      else return searchR(h->r, v, h->bit);
    }
public:
  Item search(Key v) 
    { Item t = searchR(head, v, -1); 
      return (v == t.key()) ? t : nullItem;
    } 
-----
private:
  link insertR(link h, Item x, int d, link p)
    { Key v = x.key();
      if ((h->bit >= d) || (h->bit <= p->bit))
        { 
          link t = new node(x); t->bit = d;
          t->l = (digit(v, t->bit) ? h : t);
          t->r = (digit(v, t->bit) ? t : h);
          return t; 
        }
      if (digit(v, h->bit) == 0)
           h->l = insertR(h->l, x, d, h);
      else h->r = insertR(h->r, x, d, h);
      return h;
    }
public:
  void insert(Item x)
    { Key v = x.key(); int i;
      Key w = searchR(head->l, v, -1).key();
      if (v == w) return;
      for (i = 0; digit(v, i) == digit(w, i); i++) ;
      head->l = insertR(head->l, x, i, head);
    }
  ST(int maxN)
    { head = new node(nullItem); 
      head->l = head->r = head; }
-----
private:
  void showR(link h, ostream& os, int d)
    { 
      if (h->bit <= d) { h->item.show(os); return; }
      showR(h->l, os, h->bit);
      showR(h->r, os, h->bit);
    }
public:
  void show(ostream& os)
    { showR(head->l, os, -1); } 
-----
private:
  struct node 
    { node **next;
      node()
        { next = new node*[R];
          for (int i = 0; i < R; i++) next[i] = 0; } 
    }; 
  typedef node *link;
  link head;
  Item searchR(link h, Key v, int d)
    { int i = digit(v, d); 
      if (h == 0) return nullItem;
      if (i == NULLdigit) 
        { Item dummy(v); return dummy; }
      return searchR(h->next[i], v, d+1);
    }
  void insertR(link& h, Item x, int d)
    { int i = digit(x.key(), d);
      if (h == 0) h = new node;
      if (i == NULLdigit) return;
      insertR(h->next[i], x, d+1);
    }
public:
  ST(int maxN)
    { head = 0; }
  Item search(Key v) 
    { return searchR(head, v, 0); } 
  void insert(Item x)
    { insertR(head, x, 0); }
-----
private:
  struct node 
    { Item item; int d; node *l, *m, *r;
      node(int k)
        { d = k; l = 0; m = 0; r = 0; } 
    }; 
  typedef node *link;
  link head;
  Item nullItem; 
  Item searchR(link h, Key v, int d)
    { int i = digit(v, d); 
      if (h == 0) return nullItem;
      if (i == NULLdigit) 
        { Item dummy(v); return dummy; }
      if (i < h->d) return searchR(h->l, v, d);
      if (i == h->d) return searchR(h->m, v, d+1);
      if (i > h->d) return searchR(h->r, v, d);
    }
  void insertR(link& h, Item x, int d)
    { int i = digit(x.key(), d);
      if (h == 0) h = new node(i);
      if (i == NULLdigit) return;
      if (i < h->d) insertR(h->l, x, d);
      if (i == h->d) insertR(h->m, x, d+1);
      if (i > h->d) insertR(h->r, x, d);
    }
public:
  ST(int maxN)
    { head = 0; }
  Item search(Key v) 
    { return searchR(head, v, 0); } 
  void insert(Item x)
    { insertR(head, x, 0); }
-----
private:
  char word[maxW];
  void matchR(link h, char *v, int i)
    { 
      if (h == 0) return;
      if ((*v == 0) && (h->d == 0))
        { word[i] = 0; cout << word << " "; }
      if ((*v == '*') || (*v == h->d))
        { word[i] = h->d; matchR(h->m, v+1, i+1); }
      if ((*v == '*') || (*v < h->d))
        matchR(h->l, v, i);
      if ((*v == '*') || (*v > h->d))
        matchR(h->r, v, i);
    }
public:
  void match(char *v) 
    { matchR(head, v, 0); }
-----
  struct node 
    { Item item; int d; node *l, *m, *r; 
      node(Item x, int k)
        { item = x; d = k; l = 0; m = 0; r = 0; } 
      node(node* h, int k)
        { d = k; l = 0; m = h; r = 0; } 
      int internal() 
        { return d != NULLdigit; }
     }; 
  typedef node *link;
  link heads[R];
  Item nullItem;
-----
private:
  link split(link p, link q, int d)
    { int pd = digit(p->item.key(), d), 
          qd = digit(q->item.key(), d);
      link t = new node(nullItem, qd);
      if (pd < qd) 
        { t->m = q; t->l = new node(p, pd); }
      if (pd == qd) 
        { t->m = split(p, q, d+1); }
      if (pd > qd) 
        { t->m = q; t->r = new node(p, pd); }
      return t;
    }
  link newext(Item x) 
    { return new node(x, NULLdigit); }
  void insertR(link& h, Item x, int d)
    { int i = digit(x.key(), d);
      if (h == 0) 
        { h = new node(newext(x), i); return; }
      if (!h->internal())
        { h = split(newext(x), h, d); return; }
      if (i < h->d) insertR(h->l, x, d);
      if (i == h->d) insertR(h->m, x, d+1);
      if (i > h->d) insertR(h->r, x, d);
    }
public:
  ST(int maxN)
    { for (int i = 0; i < R; i++) heads[i] = 0; }
  void insert(Item x)
    { insertR(heads[digit(x.key(), 0)], x, 1); }
-----
private:
  Item searchR(link h, Key v, int d)
    { if (h == 0) return nullItem;
      if (h->internal())
        { int i = digit(v, d), k = h->d;
          if (i < k) return searchR(h->l, v, d);
          if (i == k) return searchR(h->m, v, d+1);
          if (i > k) return searchR(h->r, v, d);
        }
      if (v == h->item.key()) return h->item;
      return nullItem;
    }
public:
  Item search(Key v) 
    { return searchR(heads[digit(v, 0)], v, 1); } 
-----

----------
CHAPTER 16. External Searching
-----
template <class Item, class Key>
  struct entry
    { Key key; Item item; struct node *next; };
struct node
  { int m; entry<Item, Key> b[M]; 
    node() { m = 0; } 
  };
typedef node *link;
-----
private:
  Item searchR(link h, Key v, int ht)
    { int j;
      if (ht == 0)
        for (j = 0; j < h->m; j++)
          { if (v == h->b[j].key) 
              return h->b[j].item; }
      else
        for (j = 0; j < h->m; j++)
          if ((j+1 == h->m) || (v < h->b[j+1].key))
            return searchR(h->b[j].next, v, ht-1);
      return nullItem;
    }
public:
  Item search(Key v)
    { return searchR(head, v, HT); }
-----
private:
  link insertR(link h, Item x, int ht)
    { int i, j; Key v = x.key(); entry<Item, Key> t;
      t.key = v; t.item = x;
      if (ht == 0)
        for (j = 0; j < h->m; j++)
          { if (v < h->b[j].key) break; }
      else
        for (j = 0; j < h->m; j++)
          if ((j+1 == h->m) || (v < h->b[j+1].key))
            { link u;
              u = insertR(h->b[j++].next, x, ht-1);
              if (u == 0) return 0;
              t.key = u->b[0].key; t.next = u;
              break;
            }
     for (i = h->m; i > j; i--) h->b[i] = h->b[i-1];
     h->b[j] = t;
     if (++h->m < M) return 0; else return split(h);
    }
public:
  ST(int maxN)
    { N = 0; HT = 0; head = new node; }
  void insert(Item item)
    { link u = insertR(head, item, HT); 
      if (u == 0) return;
      link t = new node(); t->m = 2; 
      t->b[0].key = head->b[0].key; 
      t->b[1].key =  u->b[0].key;
      t->b[0].next = head; t->b[1].next = u;
      head = t; HT++;
    }
-----
link split(link h)
  { link t = new node();
    for (int j = 0; j < M/2; j++)
      t->b[j] = h->b[M/2+j]; 
    h->m = M/2; t->m = M/2; 
    return t;    
  }
-----
template <class Item, class Key>
class ST 
  {
    private:
      struct node
        { int m; Item b[M]; int k;
          node() { m = 0; k = 0; } 
        };
      typedef node *link;
      link* dir;
      Item nullItem;
      int N, d, D;
    public:
      ST(int maxN)
        { N = 0; d = 0; D = 1; 
          dir = new link[D]; 
          dir[0] = new node;
        }
    };
-----
private:
  Item search(link h, Key v)
    {
      for (int j = 0; j < h->m; j++)
        if (v == h->b[j].key()) return h->b[j];
      return nullItem;
    }
public:
  Item search(Key v)
    { return search(dir[bits(v, 0, d)], v); }
-----
private:
  void split(link h)
    { link t = new node;
      while (h->m == 0 || h->m == M)
        {
          h->m = t->m = 0;
          for (int j = 0; j < M; j++)
            if (bits(h->b[j].key(), h->k, 1) == 0)
                 h->b[h->m++] = h->b[j];
            else t->b[t->m++] = h->b[j];
          t->k = ++(h->k);
        }
      insertDIR(t, t->k);
    }
  void insert(link h, Item x)
    { int j; Key v = x.key(); 
      for (j = 0; j < h->m; j++)
        if (v < h->b[j].key()) break;
      for (int i = (h->m)++; i > j; i--) 
        h->b[i] = h->b[i-1];
      h->b[j] = x;
      if (h->m == M) split(h);
    }
public:
  void insert(Item x)
    { insert(dir[bits(x.key(), 0, d)], x); }
-----
void insertDIR(link t, int k)
  { int i, m, x = bits(t->b[0].key(), 0, k);
    while (d < k) 
      { link *old = dir;
        d += 1; D += D;
        dir = new link[D];
        for (i = 0; i < D; i++) dir[i] = old[i/2];        
        if (d < k) dir[bits(x, 0, d)^1] = new node;
      }
    for (m = 1; k < d; k++) m *= 2; 
    for (i = 0; i < m; i++) dir[x*m+i] = t;        
  }
