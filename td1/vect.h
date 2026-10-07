#ifndef VECT_H
#define VECT_H

#define SIZE 10

typedef int* vect;

int factoriel(int n);
int sqrt(int n);

int add(int x, int y);
int mul(int x, int y);
int min(int x, int y);
int max(int x, int y);

vect map(int f(int), vect v);
int reduce(int f(int, int), vect v);
vect map2(int f(int, int), vect v1, vect v2);

vect new_vect();
void print_vect(vect tab);
int dot(vect v1, vect v2);
int norm(vect v);

int sim100(vect v1, vect v2);

#endif
