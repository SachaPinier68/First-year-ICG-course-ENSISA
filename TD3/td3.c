#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK 100

struct Stack {
    int tab[MAX_STACK];
    int top_index;
};

typedef struct Stack *Stack;

Stack new_Stack() {
    Stack s = (Stack)malloc(sizeof(struct Stack)); 
    s->top_index = -1;
    return s;
}

// Function
void push(Stack s, int val) {
    if (s->top_index < MAX_STACK - 1) {
        s->tab[++(s->top_index)] = val;
    }
}

int pop(Stack s) {
    if (s->top_index >= 0) {
        return s->tab[(s->top_index)--];
    }
    return 0;
}

int top(Stack s) {
    return s->tab[s->top_index];
}

void add(Stack s){
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 + v2);
}

void sub(Stack s){
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 - v2);
}

void mult(Stack s){
    int v2 = pop(s);
    int v1 = pop(s);
    push(s, v1 * v2);
}

void dup(Stack s) {
    push(s, top(s));
}

void swap (Stack s) {
    int v2 = pop(s);
    int v1 = pop(s);
    push (s, v1); 
    push (s, v2);   
}

// PRINT
void print_stack(Stack s) {
    printf("Voici la pile : [");
    for(int i = 0; i <= s->top_index; i++) {
        printf(" %d", s->tab[i]);
    }
    printf("]\n");
    
}


void print_top(Stack s) {
    if (s->top_index >= 0) {
        printf("Voici le top de la pile : %d\n", top(s));
    }
}

// Suite TD Parsing et Interprétation


void run(char* code) {
    int head = 0;
    int tail = 0;
    while (code[head] != 0) {
        head = head + 1;
        if (code[head] == ' '){
            for (int i = tail; i <= head; i++) {
                printf("%c", code[i]);
            }
            printf("\n");
            tail = head + 1;
        }
    }
    if (head > tail) {
        for (int i = tail; i < head; i++) {
            printf("%c", code[i]);
        }
        printf("\n");
    }
}

int value(char* texte) {
    int res = 0;
    int i = 0;
    while (texte[i] >= '0' && texte[i] <= '9') {
        res = res * 10 + (texte[i] - '0');
        i++;
    }
    return res;
}


void print_value(char* texte) {
    printf("Voici la valeur de sortie : %s\n", texte);
}

int main() {
    Stack s = new_Stack();
    

    push(s, 3); 
    dup(s);
    push(s, 1);
    swap(s);
    sub(s);
    mult(s);
    print_stack(s);

    // Parsing et interprétation
    char* code = "3 DUP 1 SWAP - * .";
    run(code);

    char* texte = "123";
    value(texte);
    print_value(texte);


    push(s , value(texte));
    print_stack(s);

    free(s);
    return 0;
}
