#include <stdio.h>
#include <string.h>

// int main(int argc, char *argv[])
// {
//     int a;
//     int b;
//     int error = 0;
//     float result = 0;
//     char operator;

//     printf("======Voici un mini calculatrice ========\n");

//     printf("Veuillez entrer un nombre\t");
//     scanf("%d", &a);
//     printf("Veuillez entrer un deuxième nombre\t");
//     scanf("%d", &b);
//     printf("Choisissez l'opérateur, ex: (+) (-) (x) (/)\t");
//     scanf("\n%c", &operator);

//     switch (operator)
//     {
//     case '+':
//         result = a + b;
//         printf("Voici le resultat de l'addition de a et b : %d", result);
//         break;
//     case '-':
//         result = a - b;
//         printf("Voici le résultat de la soustraction de a - b : %d", result);
//         break;
//     case 'x':
//         result = a * b;
//         printf("Voici le résultat de la multiplication de a * b : %d", result);
//         break;
//     case '/':
//         result = (float)a / (float)b;
//         printf("Voici le résultat de la division de a / b : %f", result);
//         break;
//     default:
//         error = 1;
//         break;
//     }

//     return 0;
// }

typedef struct 
{
    char prenom[7];
    char nom[7];
    int age;
    char sexe;
} personne;

typedef struct 
{
    int nomi;
    int denomi;
} fraction;


personne new_personne(const char *prenom, const char *nom, int age, char sexe) {
    personne p;
    snprintf(p.prenom, sizeof p.prenom, "%s", prenom);
    snprintf(p.nom, sizeof p.nom, "%s", nom);
    p.age = age;
    p.sexe = sexe;
    return p;
}

void print_personne(personne p) {
    printf("Voici la personne : %s %s, age : %d, sexe : %c\n", p.prenom, p.nom, p.age, p.sexe);
}

int pgcd(int x, int y) {
    if (x == 0) {
        return y;
    } else {
        return pgcd(y % x, x);
    }

}

fraction new_fraction(int x, int y){
    fraction f;
    f.nomi = x;
    f.denomi = y;
    printf("Voici la fraction : %d/%d\n", f.nomi, f.denomi);
    return f;
    
    
}

fraction add_fraction(fraction f1, fraction f2){
    fraction af;
    af.nomi = f1.nomi * f2.denomi + f1.denomi * f2.nomi;
    af.denomi = f1.denomi * f2.denomi;
    printf("Voici la somme des fractions pas simplifées : %d/%d\n", af.nomi, af.denomi);
    if (af.nomi % af.denomi == 0) {
        int res = af.nomi / af.denomi;
        printf("Voici le resultat de votre fraction : %i\n", res);
    } 
    int p = pgcd(af.nomi, af.denomi);
    af.nomi = af.nomi / p;
    af.denomi = af.denomi / p;
    printf("Voici le pgcd : %d/%d\n", p, p);
    
    return af;
}


void print_fraction(fraction f) {
    printf("Voici la fraction : %d/%d\n", f.nomi, f.denomi);
    printf("Voici la deuxième fraction : %i/%i\n", f.nomi, f.denomi);
    // printf("Voici le resultat de votre fraction %i", f.nomi / f.denomi);
}

void print_addfraction(fraction af){
    printf("Voici la somme des fractions simplifiées : %i/%i\n", af.nomi, af.denomi);
}

int main() {
    printf("===================\n");
    print_personne(new_personne("Sacha","Pinier", 21, 'M'));
    printf("===================\n");
    print_addfraction(add_fraction(new_fraction(10,4), new_fraction(5,3)));

    return 0;
} 