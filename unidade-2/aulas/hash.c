#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define N 255

typedef struct Aluno {
    char nome[20];
    char email[30];
    int matricula;
} Aluno;

typedef Aluno * HashAluno[N];

void print(Aluno A);
int toInt(Aluno A);
int h(Aluno A);
int add(HashAluno hash, Aluno A);

int main() {
    HashAluno hash;
    Aluno novoAluno;
    int i;
    
    for (i = 0; i < N; i++) {
        hash[i] = NULL;
    }
 
    strcpy(novoAluno.nome, "Levitico");
    strcpy(novoAluno.email, "levitico@.com");
    novoAluno.matricula = 1;
    
    print(novoAluno);
    i = h(novoAluno);
    add(hash, novoAluno);
    print(*hash[i]);

    return 0;
}

void print(Aluno A) {
    printf("Aluno: %s\n", A.nome);
    printf("Email: %s\n", A.email);
    printf("Matricula: %d\n", A.matricula);
}

int toInt(Aluno A) {
    char* r = A.nome;
    int s = 0, i = 0;
    while (r[i] != '\0') {
        s += r[i++];
    }
    return s;
}

int h(Aluno A) {
    return toInt(A) % N;
}

int add(HashAluno hash, Aluno A) {
    int x = h(A);
    if (hash[x] == NULL) {
        hash[x] = (Aluno*)malloc(sizeof(Aluno));
        if (hash[x] == NULL) {
            printf("Erro ao alocar memória.\n");
            return 0;
        }
        *hash[x] = A;
        return 1;
    }
    return 0;
}
