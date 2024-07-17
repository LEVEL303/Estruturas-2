#include <stdio.h>

void cubos(int n) {
    if (n > 1) {
        cubos(n-1);
    }
    printf("%d ", n*n*n);
}

int main() {
    cubos(5);
    printf("\n");
    return 0;
}