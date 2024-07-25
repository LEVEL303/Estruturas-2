#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct info {
    char nome[100];
    int mat;
    int turma;
    float nota;
}typedef struct info Info;

struct node {
    struct info info;
    struct node * esq;
    struct node * dir;
}typedef struct node Node;

Node * criarNode(Info info);
int comparar(Info a, Info b);
Node inserir(struct node * raiz, struct info info);

int main() {
    Node * raiz;
    Info * info;

    info.nome = "Levitico";
    info.mat = 123;
    info.turma = 1;
    info.nota = rand();
    
    return 0;
}

Node * criarNode(Info info) {
    Node * node = (Node *) malloc(sizeof(Node));
    
    strcpy(node->info.nome, info.nome);
    node->info.mat = info.mat;
    node->info.turma = info.turma;
    node->info.nota = info.nota;
    node->esq = NULL;
    node->dir = NULL;

    return node;
}

int comparar(struct info a, struct info b) {
    return strcmp(a,b);
}

Node * inserir(Node * raiz, Info info) {
    if (raiz == NULL) {
        raiz = criarNode(info);
    }
    if (comparar(raiz->info, info) > 0) {
        raiz->dir = inserir(raiz->dir, info);
    } else if (comparar(raiz->esq, info) < 0) {
        raiz->esq = inserir(raiz->esq, info);
    }

    return raiz; 
}
