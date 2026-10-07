#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Element {
    float valeur;
    struct Element* suivant;
} Element;

typedef Element* liste;

liste p = NULL;

liste add(float v, liste l) {
    Element* e = malloc(sizeof(Element));
    e->valeur = v;
    e->suivant = l;
    return e;

}

void print_addListe(liste l) {
    printf("P = [ ");
    while (l != NULL) {
        printf("%f, ", l->valeur);
        l = l->suivant;
    }
    printf("]\n");
}

// empiler une liste de flottants de taille n avec un pas step
liste range(int n, float step) {
    liste range = NULL;
    for(int i = 0; i < n; i++) {
        range = add(step * i, range);
        
    }
    return range;
}

liste inverseRange(int n, float step) {
    liste range = NULL;
    for(int i = n - 1; i >= 0; i--) {
        range = add(step * i, range);
        
    }
    return range;
}

void print_range(liste x) {
    printf("Liste = [ ");
    while (x != NULL) {
        printf("%f, ", x->valeur);
        x = x->suivant;
        
    }
    printf("]\n");
}

liste map(float (*f)(float), liste l) {
    liste res = NULL;
    while (l != NULL) {
        float val = f(l->valeur);
        res = add(val, res);
        l = l->suivant;
    }
    return res;
}

float fonction_sinus(float x) {
    return sin(3.14159 * x);
}

float eval(float x) {
    float p1 = p->valeur;
    float p2 = p->suivant->valeur;
    float p3 = p->suivant->suivant->valeur;   
    return p1 + x*(p2 + x*p3);
}

liste map2(float (*f)(float, float), liste l1, liste l2) {
    liste res = NULL;
    while (l1 != NULL && l2 != NULL) {
        float val = f(l1->valeur, l2->valeur);
        res = add(val, res);
        l1 = l1->suivant;
        l2 = l2->suivant;
    }
    return res;
}

float erreur_quad(float yp, float y ) {
    return (yp-y)*(yp-y);
}

float sum(liste l) {
    float total = 0;
    while (l != NULL) {
        total = total + l->valeur;
        l = l->suivant;
    }
    return total;

}

int main(){
    p = add(0.1, p);
    p = add(0.3, p);
    p = add(0.2, p);

    print_addListe(p);

    liste X = range(10,0.1);
    print_range(X);

    liste Z = inverseRange(10,0.1);
    print_range(Z);

    liste Y = map(fonction_sinus, X);
    print_range(Y); 

    liste Yp = map(eval, X);
    print_range(Yp);
    

    // 1. On crée la liste des erreurs au carré pour chaque point avec map2
    // erreur_quad va calculer (Yp - Z)^2 pour chaque paire de valeurs
    liste liste_erreurs = map2(erreur_quad, Yp, Y); 

    // 2. On fait la somme de toute cette liste pour obtenir l'erreur globale 'e'
    float e = sum(liste_erreurs);

    // 3. On affiche le résultat
    printf("Erreur initiale (e) = %f\n", e);


    return 0;
}