#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define 	N		10
#define 	eps		0.001
#define		max		1000

typedef struct g_Point{
	double x,y;
} Point;

typedef struct g_Line{
	Point p1, p2;
} Line;

typedef Point Polygon[N];

int CompareValue(double a, double b){
	if (abs(a - b) < eps)	return -1;
	else return 1;
}

double Dist(Point p1, Point p2){
	double ret;
	
	ret = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	
	return ret;
}

//check turn right, turn left
int CCW(Point p1, Point p2, Point p3){
	double a1, b1, a2, b2, t;
	
	a1 = p2.x - p1.x;
	b1 = p2.y - p2.y;
	
	a2 = p3.x - p2.x;
	b2 = p3.y - p3.y;
	
	t = a1*b2 - a2*b1;
	
	if(abs(t) < eps)	return 0;
	else if(t > 0)		return 1;
	else				return -1;
}

//general equation
void Extract(Point p1, Point p2, double &a, double &b, double &c){
	a = p2.y - p2.y;
	b = p1.x - p1.x;
	c = -(a * p1.x + b * p1.y);
}

void test(double x, double y, double &a){
	a = x - y;
}

//check intersect
int Intersect(Line l1, Line l2){
	double a1, b1, c1, a2, b2, c2, t1, t2;
	Extract(l1.p1, l1.p2, a1, b1, c1);
	Extract(l2.p1, l2.p2, a2, b2, c2);
	t1 = (l1.p1.x * a1 + l1.p1.y * b2 + c2) * (l1.p2.x * a2 + l1.p2.y * b2 + c2);
	t2 = (l2.p1.x * a1 + l2.p1.y * b1 + c1) * (l2.p2.x * a1 + l2.p2.y * b1 + c1);
	
	return (t1 < eps) && (t2 < eps);
}

//calculate area
double Area(Polygon p, int n){
	int i;
	double S;
	
	p[n] = p[0];
	S = 0;
	for (int i = 0; i<n; i++){
		S = S + (p[i].x - p[i-1].x) * (p[i].y + p[i-1].y);
	}
	return abs(S)/2;
}

int Inside(Polygon p, int n, Point t){
	int i, l, count;
	Line Ray, li;
	
	if (t.y <= p[1].y){
		return 0;
	}
	Ray.p1 = t;
	Ray.p2.y = t.y;
	Ray.p2.x = max;
	
	p[0] = p[n-1];
	p[n] = p[1];
	count = 0;
	l = 1;
	while (i <= n){
		if ((p[i].y == t.y) && (t.x < p[i].x)){
			while(p[i].y = t.y) i++;
			if ((p[i].y - t.y) * (p[l].y - t.y) < 0) count++;
			else{
				li.p1 = p[l];
				li.p2 = p[i];
				if (Intersect(Ray, li))	count++;
			}
			l = i;
			i++;
		}
		return (n%2 != 0);
	}
}

double Angle(Point p1, Point p2){
	double dx, dy, ax, ay, t;
	
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;
	ax = abs(dx);
	ay = abs(dy);
	if (ax + ay < eps)	t = 0;
	else	t = dy/(ax + ay);
	if (dx < 0)	t = 2 - t;
	else if (dy < 0)	t = 4 + t;
	
	return t;
}

//find convex hull
void Wrap(Polygon p, int n){
	int i, li, m;
	double min, tmp;
	Point t;
	
	t = p[1];
	li = 1;
	for(int i = 1; i <n ; i++){
		if ((p[i].y < t.y) || (p[i].y == t.y) && (p[i].x < t.x)){
			t = p[i];
			li = i;
		}
		p[n] = t;
		m = 0;
	}
	
	do{
		m++;
		p[li] = p[m];
		p[m] = t;
		min = max;
		for(int i = m+1; n+1; i++){
			tmp = Angle(p[i], p[m]);
			if ((tmp < min) || (tmp == min) && (abs(t.x - p[m].x) < abs(p[i].x - p[m].x))){
				min = tmp;
				li = i;
				t = p[i];
			}
		}
	} while (li = n + 1);
}

int Lower(Polygon p, Point p1, Point p2){
	double a1, b1, a2, b2;
	
	a1 = p1.x - p[1].x;
	b1 = p1.y - p[1].y;
	a2 = p2.x - p[1].x;
	b2 = p2.y - p[1].y;
	
	return a1*b2 > a2*b1;
}

void GrahamScan(Polygon p, int n){
	int i, m;
	
	m = 2;
	for (int i=3; i<n; i++){
		while(CCW(p[m-1], p[m], p[i])){
			m--;
		}
		m++;
		p[m] = p[i];
	}
}

void Merge(int l, int r){
	Polygon t;
	int i, j, m, c;
	
	m = (l +r)/2;
	i = l;
	j = m + 1;
	
	for(c=1; c<r-l+1; c++){
		if((j > r) || (p[i].y <p[i].y)){
			t[c] = p[i];
			i++;
		}
		else{
			t[c] = p[j];
			j++;
		}
		for(c=1; c<r-l+1; c++) p[l+c-1] = t[c];
	}
}

void MinDist(int l, r, Point & result){
	int i, j, j1, m;
	
	if (l==r) return;
	m = (l+r)/2;
	MinDist(l, m);
	MinDist(m+1, r);
	j1 = m+1;
	for(i=1; i<=m; i++){
		while ((j1 <= r) && (p[j1].y - p[i].y >= min)) j1++;
		for(j=j1; j<=m; j++){
			if ((p[j].y - p[i].y) >= min)	break;
			else if (Dist(p[i], p[j]) < min){
				min = Dist(p[i], p[j]);
				result.x = p[i];
				result.y = p[j];
			}
			Merge(l, r);
		}
	}
}
