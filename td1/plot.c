#include <stdio.h>

// void main() {
//     for (int i = 1; i <= 100; i++){
//         printf("%i\t ", i);
//         if (i % 10 == 0) {
//             printf("%i\n", i);
//         }
//     }
// } 

// Exos 3
// int main() {
//     int x, y;
//     for (int i = 1; i <= 100; i++){
//         x = 1 + (i - 1) % 10; 
//         y = 1+ (i-1)/10;
//         printf("(%i,%i)\t ", x, y);
//         if (i % 10 == 0) {
//             printf ("\n");
//         }
//     }
//     return 0;
// } 

// exos 4 disque
// int disque(int x, int y) {
//     return (x-5)*(x-5) + (y-5)*(y-5) <= 5*5;
// }
// int disque2(int x, int y) {
//     return (x-10)*(x-10) + (y-5)*(y-5) <= 5*5;
// }

// void afficher (int d(int, int)) {
//     int x, y;
//     for (int i = 1; i <= 100; i++){
//         x = 1 + (i - 1) % 10; 
//         y = 1+ (i-1)/10;
//         if (d(x,y)) {
//             printf("**");
         
//         } else {
//             printf("  ");
//         }
//         if (i % 10 == 0) {
//           printf ("\n");
//        }
       
//     }
// }

// int main() {
   
//     int x,y;
//     afficher(disque);
//     afficher(disque2);
//     return 0;
// } 

// Exos 6
int disque(int x, int y) {
    return (x-5)*(x-5) + (y-5)*(y-5) <= 5*5;
}
int disque2(int x, int y) {
    return (x-10)*(x-10) + (y-5)*(y-5) <= 5*5;
}

void afficher (int d(int, int)) {
    int x, y;
    for (int i = 1; i <= 100; i++){
        x = 1 + (i - 1) % 10; 
        y = 1+ (i-1)/10;
        if (d(x,y)) {
            printf("**");
         
        } else {
            printf("  ");
        }
        if (i % 10 == 0) {
          printf ("\n");
       }
       
    }
}
void lune () {
    int x, y;
    for (int i = 1; i <= 100; i++){
        x = 1 + (i - 1) % 10;
        y = 1 + (i - 1) / 10;

        if (disque(x, y) && !disque2(x, y)) {
            printf("**");
        } else {
            printf("  ");
        }

        if (i % 10 == 0) {
            printf("\n");
        }
    }
}


// vect convertir (int d(int, int)) {
//     vect result = new_vect();
//     int x,y;
//     for (int i = 1; i <= 100; i++){
//         x = 1 + (i - 1) % 10; 
//         y = 1+ (i-1)/10;
//         result[i] = d(x,y);
       
//     }
//     return result;
// }

void afficherNeg (int d(int, int)) {
    int x, y;
    for (int i = 1; i <= 100; i++){
        x = 1 + (i - 1) % 10; 
        y = 1+ (i-1)/10;
        if (d(x,y)) {
            printf("  ");
         
        } else {
            printf("**");
        }
        if (i % 10 == 0) {
          printf ("\n");
       }
       
    }
}



int main() {
    // vect v1 = convertir (disque);
    // vect v2 = convertir (disque2);
    // printf("Similitude image 1 & image 1 = %i / 100\n", sim100(v1,v2));
    // printf("Similitude image 1 & image 1 = %i / 100\n", sim100(v1,v2));
    // afficherNeg(disque);
    lune();
    
    return 0;
} 