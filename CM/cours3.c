#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int vect[10];
typedef int real;
typedef struct
{
    int numerateur;
    int denominateur;
} fraction;

struct cell
{
    int head;
    struct cell *tail; // adresse / pointeur sur une cellule, c’est 1 nombre. On prendra une valeur différente de 0 pour représenter 1 fin de liste.
};

struct cell2 {
    char head;
    struct cell2 *tail;
};

typedef struct cell *list;
typedef struct cell2* list2;

list new_list(int h, list t);
list inter(list l1, list l2);
list difference(list l1, list l2);
int pgcd(int a, int b);

int base = 100;

int contient(list l, int v)
{
    if (l == 0)
    {
        return 0;
    }
    if (l->head == v)
    {
        return 1;
    }
    return contient(l->tail, v);
}

list inter(list l1, list l2)
{
    if (l1 == 0)
    {
        return 0;
    }
    if (contient(l2, l1->head))
    {
        return new_list(l1->head, inter(l1->tail, l2));
    }
    return inter(l1->tail, l2);
}

list difference(list l1, list l2)
{
    if (l1 == 0)
    {
        return 0;
    }
    if (contient(l2, l1->head))
    {
        return difference(l1->tail, l2);
    }
    return new_list(l1->head, difference(l1->tail, l2));
}

list new_list(int h, list t)
{
    list l = malloc(sizeof(struct cell));
    if (l == NULL)
    {
        return 0;
    }
    l->head = h;
    l->tail = t;
    return l;
}

void print_list(list l)
{
    if (l == 0)
    {
        printf("\n");
        return;
    }
    printf("%d ", l->head);
    print_list(l->tail);
}

int length(list l)
{
    if (l == 0)
    {
        return 0;
    }
    return 1 + length(l->tail);
}

// Calcule la somme des dix éléments du vecteur.
int sum(vect v)
{
    int r = 0;
    for (int i = 0; i < 10; i++)
    {
        r = r + v[i];
    }
    return r;
}

// Renvoie la plus grande valeur du vecteur.
int max(vect v)
{
    int m = v[0];
    for (int i = 1; i < 10; i++)
    {
        if (v[i] > m)
        {
            m = v[i];
        }
    }
    return m;
}

// Renvoie la plus petite valeur du vecteur.
int min(vect v)
{
    int m = v[0];
    for (int i = 1; i < 10; i++)
    {
        if (v[i] < m)
        {
            m = v[i];
        }
    }
    return m;
}

// Réduit les éléments du vecteur en appliquant successivement la fonction f.
int reduce(int f(int, int), vect v)
{
    int r = 0;
    for (int i = 0; i < 10; i++)
    {
        r = f(r, v[i]);
    }
    return r;
}

// Construit un réel en virgule fixe à partir de sa partie entière et décimale.
real new_real(int entier, int decimal)
{
    return entier * base + decimal;
}

// Additionne deux réels représentés en virgule fixe.
real add(real r1, real r2)
{
    return r1 + r2;
}

// Multiplie deux réels représentés en virgule fixe.
real mult(real r1, real r2)
{
    return (r1 * r2) / base;
}

// Affiche un réel représenté en virgule fixe.
void print_real(real r)
{
    printf("%d.%02d", r / base, r % base);
}

// Initialise le vecteur avec les valeurs de 1 à 10.
void new_vect(vect v)
{
    for (int i = 0; i < 10; i++)
    {
        v[i] = i + 1;
    }
}

// Affiche les dix éléments du vecteur.
void print_vect(vect v)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Construit une fraction à partir de son numérateur et de son dénominateur.
fraction new_fraction(int a, int b)
{
    fraction r;
    r.numerateur = a;
    r.denominateur = b;
    return r;
}

// Affiche une fraction sous la forme numérateur/dénominateur.
void print_fraction(fraction f)
{
    printf("%d/%d", f.numerateur, f.denominateur);
}

// Additionne deux fractions et simplifie le résultat.
fraction add_fraction(fraction f1, fraction f2)
{
    fraction f;
    f.numerateur = f1.numerateur * f2.denominateur + f1.denominateur * f2.numerateur;
    f.denominateur = f1.denominateur * f2.denominateur;
    int p = pgcd(f.numerateur, f.denominateur);
    f.numerateur = f.numerateur / p;
    f.denominateur = f.denominateur / p;
    return f;
}

// Calcule le plus grand commun diviseur de deux entiers.
int pgcd(int a, int b)
{

    if (b == 0)
    {
        return a;
    }
    else
    {
        return pgcd(b, a % b);
    }
}

void length (char* m) {
    int length;
    for (length = 0; m[length] != 0; length++)
    {
        printf("%i", length);
    }
}

char* shift (char* txt, int decalage) {
    for (int i = 0; i < strlen(txt); i++)
    {
        txt[i] = (txt[i+decalage])% 256;
    }
    return txt;
}

char* shift2 (const char* txt, int decalage) {
    char* txt2 = malloc(strlen(txt));
    for (int i = 0; i < strlen(txt); i++)
    {
        txt2[i] = (txt[i+decalage])% 256;
    }
    return txt2;
}

list2 to_list2 (char* t) {
    list2* l = 0;
    list2 l2 = malloc(sizeof(struct cell2));
    for (int i = 0; i < strlen(t); i++) {
        l2->head = t[i];
        l2->tail = l;
        l = l2; 
    }
    return l;
}

// Exécute les exemples de manipulation des vecteurs et des fractions.
int main(void)
{
    vect v;
    new_vect(v);
    print_vect(v);

    printf("sum: %d\n", reduce(add, v));

    fraction f = new_fraction(1, 2);
    print_fraction(f);
    printf("\n");

    fraction g = add_fraction(f, new_fraction(1, 3));
    print_fraction(g);
    printf("\n");

    list l = new_list(3, new_list(7, new_list(8, new_list(1, 0))));
    print_list(l);
    printf("%d element(s)\n", length(l));
    

    int n[] = {77, 65, 88};
    for (int i = 0; i < 3; i++)
    {
        printf("%i", n[i]);
    }
    
    char* p; 
    p = malloc(sizeof(char)*3);
    *p = 77; // p[0] = 77
    *(p+1) = 65; // p[1] = 65
    *(p+2) = 88;
    printf("\n%c%c%c\n", *p, *(p+1), *(p+2));

    char* c = "max";
    for (int i = 0; i < 3; i++)
    {
        printf("%c", c[i]);
    }


    printf("\n===========\n");
    // Déclaration correcte avec les guillemets
    char *m = "max est un etudiant serieux";

    // Calcul de la longueur
    

    

    
}
