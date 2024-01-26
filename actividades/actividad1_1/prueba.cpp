#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

// Función de Fibonacci con memoización
int fibonacciMemo(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 2) {
        memo[n] = 1;
    } else {
        memo[n] = fibonacciMemo(n - 1) + fibonacciMemo(n - 2);
    }
    return memo[n];
}

// Función para imprimir la serie completa hasta n
void printFibonacciSeries(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << fibonacciMemo(i) << " ";
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n: "; cin >> n;
    memo.resize(n + 1, -1); // Preparar el vector para memoización
    cout << "Serie de Fibonacci de los primeros " << n << " números:\n";
    printFibonacciSeries(n);
    return 0;
}

