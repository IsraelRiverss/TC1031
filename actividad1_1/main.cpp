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

//Funcion para calcular la suma de 1 hasta n de forma iteratva
//Complejidad: O(n)
int sumaIterativa(int n){
int suma=0;
  for(int i=1;i<=n;i++){
    suma += i;
  }
  return suma;
}

//Funcion para calcular la suma de 1 hasta n de forma recursiva
//Complejidad: O(n)
int sumaRecursiva(int n){
  if (n==1){
    return 1;
  }else{
    return n+sumaRecursiva(n-1);
}
}

//Funcion para calcular el n-esimo numero de la serie de fibonacci de forma iterativa
//Complejidad: O(n)
vector<int>fibonaccilterativo(int n){
  vector<int> serie;
  if (n<=0){
    return serie;
  }

  serie.push_back(1); //F(1)
  if (n == 1){
    return serie;
  }

  serie.push_back(1); 
  for (int i = 2; i < n; ++i){
    serie.push_back(serie[i-1]+serie[i-2]);
  }
  return serie;
}


//Funcion para calcular el n-esimo numero de la serie de fibonacci de forma Recursiva
// Complejidad Temporal: O(2^n)
int fibonacciRecursivo(int n) {
if(n <= 1) {
  return n;
}
  else {
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
  }
}

//Funcion para calcular el promedio de un conjunto de n números enteros (almacenados en un vector) con un método Iterativo.
//Complejidad: O(n)
double promedioIterativo(int n,const vector<int>& numeros) {
  int suma = 0;
  for(int num : numeros) 
  {
    suma += num;
  }
  return static_cast<double>(suma) / numeros.size();
}

//Funcion para calcular el promedio de un conjunto de n números enteros (almacenados en un vector) con un método Recursivo.
//Complejidad: O(n^2)
double promedioRecursivo(int n, const vector<int>&numeros, int indice= 0) {
  if (indice == n-1){
    return static_cast<double>(numeros[indice])/n;
  }else{
    return (static_cast<double>(numeros[indice]) + promedioRecursivo(n, numeros, indice + 1)*(n- indice-1))/n;
  }
}


int main() {
  cout<<"Suma Iterativa: \n";
  cout<<sumaIterativa(20)<<"\n";
  cout<<sumaIterativa(50)<<"\n";
  cout<<sumaIterativa(100)<<"\n";
  cout<<sumaIterativa(1000)<<"\n";

  cout<<"\nSuma Recursiva: \n";
  cout<<sumaRecursiva(20)<<"\n";
  cout<<sumaRecursiva(50)<<"\n";
  cout<<sumaRecursiva(100)<<"\n";
  cout<<sumaRecursiva(1000)<<"\n";

  cout<<"\nFibonacci Iterativo: \n";
  vector<int> numeros_fib_iterativo = fibonaccilterativo(5);
  for(int num : numeros_fib_iterativo) {
    cout << num << " ";
  }
  cout << "\n";
  numeros_fib_iterativo = fibonaccilterativo(10);
  for(int num : numeros_fib_iterativo) {
    cout << num << " ";
  }
  cout << "\n";
  numeros_fib_iterativo = fibonaccilterativo(15);
  for(int num : numeros_fib_iterativo) {
    cout << num << " ";
  }
  cout<<"\n";
  numeros_fib_iterativo = fibonaccilterativo(30);
  for(int num : numeros_fib_iterativo) {
    cout << num << " ";
  }
  cout << "\n";

  cout<<"\nFibonacci Recursivo: \n";
  cout<<fibonacciRecursivo(5)<<"\n";
  cout<<fibonacciRecursivo(10)<<"\n";
  cout<<fibonacciRecursivo(15)<<"\n";
  cout<<fibonacciRecursivo(30)<<"\n";

  cout<<"\nPromedio Iterativo: \n";
  vector<int>numeros1={1,5,10,23,56,100};
  cout<<promedioIterativo(6, numeros1)<<"\n";

  cout<<"\nPromedio Recursivo: \n";
  vector<int>numeros2={51,35,140,323,566,1600,231,99,1,662};
  cout<<promedioRecursivo(10, numeros2)<<"\n";
  
  return 0;
}