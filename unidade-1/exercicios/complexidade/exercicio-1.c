int f(int n) {
    if (n == 0) {
        return 1;
    }
    return f(n-1) + 1/f(n-1);
}

int main() {
    f(20);

    return 0;
}

/*
Chamada recursiva: 2ns
Retorno de chamada recursiva: 1ns
Atribuição e soma: 0.5ns
Divisão e multiplicação: 1.5ns

T(20) = 2 * 2097151 + 1 * 2097151 + 0.5 * (2097151 - 1) + 1.5 * (2097151 - 1)
T(20) = 4194302 + 2097151 + 1048575 + 3145725
T(20) = 10485753ns
*/