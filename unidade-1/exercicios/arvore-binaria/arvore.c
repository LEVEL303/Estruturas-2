#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct info {
    char nome[100];
    int matricula;
    int turma;
    float nota;
}Info;

typedef struct node {
    Info info;
    struct node * esq;
    struct node * dir;
}Node;

Node * criarNode(Info * info);
int comparar(Info * a, Info * b);
Node * inserir(Node * raiz, Info * info);
void liberarArvore(Node * raiz);
void preOrdem(Node * raiz);
void inOrdem(Node * raiz);
void posOrdem(Node * raiz);

int main() {
    FILE * arquivo = fopen("alunos.txt", "r");
    Info info;
    Node * raiz = NULL;

    if (arquivo == NULL) {
        printf("Falha ao abrir arquivo!\n");
        exit(1);
    }

    while(fscanf(arquivo, " %d %d %[^\n]", &info.matricula, &info.turma, info.nome) == 3) {
        info.nota = (float) (rand() % 10);
        raiz = inserir(raiz, &info);
    }

    printf("# Pre-ordem:\n");
    preOrdem(raiz);
    printf("# Inordem:\n");
    inOrdem(raiz);
    printf("# Pos-ordem:\n");
    posOrdem(raiz);

    fclose(arquivo);
    liberarArvore(raiz);
    return 0;
}

Node * criarNode(Info * info) {
    Node * node = (Node *) malloc(sizeof(Node));

    if (node == NULL) {
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }
    
    strcpy(node->info.nome, info->nome);
    node->info.matricula = info->matricula;
    node->info.turma = info->turma;
    node->info.nota = info->nota;
    node->esq = NULL;
    node->dir = NULL;

    return node;
}

int comparar(Info * a, Info * b) {
    return strcmp(a->nome, b->nome);
}

Node * inserir(Node * raiz, Info * info) {
    if (raiz == NULL) {
        raiz = criarNode(info);
    } else if (comparar(&raiz->info, info) > 0) {
        raiz->dir = inserir(raiz->dir, info);
    } else if (comparar(&raiz->info, info) < 0) {
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz; 
}

void liberarArvore(Node * raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

void preOrdem(Node * raiz) {
    if (raiz != NULL) {
        printf("%d %d %s %.1f\n", raiz->info.matricula, raiz->info.turma, raiz->info.nome, raiz->info.nota);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(Node * raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%d %d %s %.1f\n", raiz->info.matricula, raiz->info.turma, raiz->info.nome, raiz->info.nota);
        inOrdem(raiz->dir);
    }
}

void posOrdem(Node * raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d %d %s %.1f\n", raiz->info.matricula, raiz->info.turma, raiz->info.nome, raiz->info.nota);
    }
}