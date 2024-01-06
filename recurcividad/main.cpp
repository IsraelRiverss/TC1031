/**
 * Ejemplo que implementa el factorial recursivo para un numero n
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include <iostream>


unsigned long long int factorialRecursivo (unsigned long long int n) {
  if (n == 0) // caso base
    return 1;
  else // caso general
    return factorialRecursivo(n-1) * n;
}

unsigned long long int factorialIterativo(unsigned long long int n) {
  unsigned long long int f = 1;
  for(unsigned long long int i = 1; i<=n; i++) {
    f *= i;
  }
  return f;
}


int main() {
  unsigned long long int num;
  std::cout << "Dame un numero positivo:" << std::endl;
  std::cin >> num;
  std::cout << "Su factorial es: " << factorialRecursivo(num) << std::endl;
  std::cout << "Su factorial es: " << factorialIterativo(num) << std::endl;
  return 0;
}