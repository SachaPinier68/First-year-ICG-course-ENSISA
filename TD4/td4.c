#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    TXT,
    PAIR
} Type;

struct sexp
{
    char txt[8];
    struct sexp *head;
    struct sexp *tail;
    Type type;
};

typedef struct sexp *exp;

exp text(char *t)
{ // constructeur
    exp e = malloc(sizeof(struct sexp));
    strcpy(e->txt, t);
    e->type = TXT;
    return e;
}

exp pair(exp h, exp t)
{
    exp e = malloc(sizeof(struct sexp));
    e->head = h;
    e->tail = t;
    e->type = PAIR;
    return e;
}

int eval(exp e)
{
    int res = 0;
    while (e->tail != NULL)
    {

        int gauche = atoi(e->tail->head->txt);
        int droite = atoi(e->tail->tail->txt);

        if (strcmp(e->head->txt, "+") == 0)
        {
            res = gauche + droite;
        }
        if (strcmp(e->head->txt, "*") == 0)
        {
            res = gauche * droite;
        }
        if (strcmp(e->head->txt, "-") == 0)
        {
            res = gauche - droite;
        }
    }

    return res;
}

void print(exp e)
{
    if (e->type == TXT)
    {
        printf("%s", e->txt);
    }
    else
    {
        printf("(");
        print(e->head);
        printf(",");
        print(e->tail);
        printf(")");
    }
}

int main()
{
    exp e1 = text("123");
    print(e1);
    exp e2 = text("456");
    exp e3 = pair(e1, e2);
    print(e3);
    exp e4 = pair(text("+"), pair(text("1"), text("2")));
    exp e5 = pair(text("+"),pair(text("1"),pair(text("2"),pair(text("+"),pair(text("3"), text("5")), pair(text("5"), text("6"))))));
    printf("\nResultat : %d\n", eval(e4));
}