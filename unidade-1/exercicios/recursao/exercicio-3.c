#include <stdio.h>
#include <string.h>

int palindromo(char expressao[], int i, int j) {
    if (i >= j) {
        return 1;
    }

    if (expressao[i] != expressao[j]) {
        return 0;
    }

    return palindromo(expressao, i + 1, j - 1);
}

int main() {
    char expressao[] = "roma e amor";
    int resposta;
    int i = 0, j = strlen(expressao) - 1;

    resposta = palindromo(expressao, i, j);

    if(resposta) {
        printf("A expressao e um palindromo!\n");
    } else {
        printf("A expressao nao e um palindromo!\n");
    }

    return 0;
}