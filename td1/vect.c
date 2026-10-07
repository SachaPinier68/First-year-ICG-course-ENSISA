#include <stdio.h>
#include <stdlib.h>

#include "vect.h"

int factoriel(int n){
    int acc = 1;
    for (int i = 0; i<= n; i++){
        acc *= (i+1);
    }
    return acc;
}

vect new_vect(){
    int* tab = malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++){
        tab[i] = i;
    }
    return tab;
}

void print_vect(vect tab){
    printf("[");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", tab[i]);
    }
    printf("]");
}

vect map(int f(int), vect v){
    for (int i = 0; i < SIZE; i++){
        v[i] = f(v[i]);
    }
    return v;
}

int red(int f(int, int), vect v){
    int acc = v[0];
    for (int i = 1; i < SIZE; i++){
        acc = f(acc, v[i]);
    }
    return acc;
}

int add(int x, int y){
    return x + y;
}
int mul(int x, int y){
    return x * y;
}
int min(int x, int y){
    return (x < y) ? x : y;
}
int max(int x, int y){
    return (x > y) ? x : y;
}

vect map2(int f(int, int), vect v1, vect v2){
    for (int i = 0; i < SIZE; i++){
        v1[i] = f(v1[i], v2[i]);
    }
    return v1;
}

int dot(vect v1, vect v2){
    return red(add, map2(mul, v1, v2));
}

int sqrt(int n) {
    for (int i = 1; i<n; i++){
        if (i*i > n){
            return i - 1;
        }
    }
    return -1;
}

int norm(vect v){
    return sqrt(dot(v, v));
}

int sim100(vect v1, vect v2){
    return min((100 * dot(v1, v2)) / (norm(v1) * norm(v2)), 100);
}