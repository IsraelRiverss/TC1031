/**
 * Compilar:
 *   g++ -std=c++17 -Wall -o main *.cpp
 *
 * Ejecutar:
 *   ./main
**/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum from 1 to n iteratively.
// Complexity: O(n) - Linear time
int sumaIterativa(int n){
    int suma = 0;
    for(int i = 1; i <= n; i++){
        suma += i;
    }
    return suma;
}

// Function to calculate the sum from 1 to n recursively.
// Complexity: O(n) - Linear time
int sumaRecursiva(int n){
    if (n == 1){
        return 1;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

// Function to calculate the n-th number of the Fibonacci series iteratively.
// Complexity: O(n) - Linear time
vector<int> fibonaccilterativo(int n){
    vector<int> serie;
    if (n <= 0){
        return serie;
    }

    serie.push_back(1); // F(1)
    if (n == 1){
        return serie;
    }

    serie.push_back(1);
    for (int i = 2; i < n; ++i){
        serie.push_back(serie[i - 1] + serie[i - 2]);
    }
    return serie;
}

// Function to calculate the n-th number of the Fibonacci series recursively.
// Complexity: O(2^n) - Exponential time
int fibonacciRecursivo(int n) {
    if(n <= 1) {
        return n;
    } else {
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
}

// Function to calculate the average of a set of n integers (stored in a vector) iteratively.
// Complexity: O(n) - Linear time
double promedioIterativo(int n, const vector<int>& numeros) {
    int suma = 0;
    for(int num : numeros) {
        suma += num;
    }
    return static_cast<double>(suma) / n;
}

// Function to calculate the average of a set of n integers (stored in a vector) recursively.
// Complexity: O(n) - Linear time
double promedioRecursivo(int n, const vector<int>& numeros, int indice = 0) {
    if (indice == n - 1){
        return static_cast<double>(numeros[indice]) / n;
    } else {
        return (static_cast<double>(numeros[indice]) + promedioRecursivo(n, numeros, indice + 1) * (n - indice - 1)) / n;
    }
}

// Main function with a menu to select different operations
int main() {
    int choice;
    do {
        cout << "Seleccione la operacion que desea realizar: \n";
        cout << "1. Suma Iterativa\n2. Suma Recursiva\n3. Fibonacci Iterativo\n4. Fibonacci Recursivo\n5. Promedio Iterativo\n6. Promedio Recursivo\n7. Salir\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Suma Iterativa:\n";
                cout << sumaIterativa(20) << "\n";
                cout << sumaIterativa(50) << "\n";
                cout << sumaIterativa(100) << "\n";
                cout << sumaIterativa(1000) << "\n";
                break;
            }
            case 2: {
                cout << "\nSuma Recursiva:\n";
                cout << sumaRecursiva(20) << "\n";
                cout << sumaRecursiva(50) << "\n";
                cout << sumaRecursiva(100) << "\n";
                cout << sumaRecursiva(1000) << "\n";
                break;
            }
            case 3: {
                vector<int> numeros_fib_iterativo = fibonaccilterativo(10);
                cout << "\nFibonacci Iterativo (primeros 10 términos):\n";
                for(int num : numeros_fib_iterativo) {
                    cout << num << " ";
                }
                cout << "\n";
                break;
            }
            case 4: {
                cout << "\nFibonacci Recursivo (10mo término):\n";
                cout << fibonacciRecursivo(10) << "\n";
                break;
            }
            case 5: {
                vector<int> numeros = {1, 5, 10, 23, 56, 100};
                cout << "\nPromedio Iterativo:\n";
                cout << promedioIterativo(numeros.size(), numeros) << "\n";
                break;
            }
            case 6: {
                vector<int> numeros = {51, 35, 140, 323, 566, 1600, 231, 99, 1, 662};
                cout << "\nPromedio Recursivo:\n";
                cout << promedioRecursivo(numeros.size(), numeros) << "\n";
                break;
            }
            case 7: {
                cout << "Saliendo...\n";
                break;
            }
            default: {
                cout << "Opcion no valida, intente de nuevo.\n";
            }
        }
    } while(choice != 7);

    return 0;
}