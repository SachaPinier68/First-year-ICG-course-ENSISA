#include <stdio.h>

int mem[512];

void index_pos(int p)
{
    for (int i = 0; i < 10; i++)
    {
        mem[p + i] = i + 1;
    }
}

void print(int p)
{
    printf("Position %d : [", p);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", mem[p + i]);
    }
    printf(" ]\n");
}

// map_inplace demandée
void map_inplace(int (*f)(int), int p)
{
    for (int i = 0; i < 10; i++)
    {
        mem[p + i] = f(mem[p + i]);
    }
}

// Deux exemples de fonctions à passer en paramètre
int carre(int x) { return x * x; }
int double_val(int x) { return x * 2; }

void add(int p1, int p2, int p3) {
    printf("Tableau de p1 + p2 :[");
    for (int i = 0; i<10; i++) {
        mem[p3+i] = mem[p1+i]+mem[p2+i];
        printf(" %i", mem[p3 + i]);
    }
    printf(" ]\n");
}

int main()
{
    int p = 0;

    index_pos(p);
    printf("Départ :\n");
    print(p);

    // Application du carré sur place
    map_inplace(carre, p);
    printf("Après carré sur place :\n");
    print(p);

    // Application de la multiplication par 2 sur place
    map_inplace(double_val, p);
    printf("Après double sur place :\n");
    print(p);

    add(1,2,10);
    

    return 0;
}