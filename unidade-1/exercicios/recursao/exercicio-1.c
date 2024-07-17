#include <stdio.h>

double ss_fra(int n) {
    if (n <= 1) {
        return 1.0;
    } else if (n % 2 == 0) {
        return ss_fra(n-1) + (1.0/n);
    } else {
        return ss_fra(n-1) - (1.0/n);
    }
}

int main() {
    double r;

    r = ss_fra(2);
    printf("%f\n", r);

    return 0;
}