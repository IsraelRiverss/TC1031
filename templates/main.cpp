/**
 * Compilar:
 *   g++ -std=c++17 -Wall -o main *.cpp
 *
 * Ejecutar:
 *   ./main
**/
#include <iostream>
#include "Lista.h"

int main() {

  std::cout << "Template example" << std::endl;
  Lista<int> listaInt; // Lista de enteros
  // agregar valores
  for (int i = 1; i < 6; i++) {
    if (!listaInt.insert(i*10))
      std::cout << "no se pudo insertar el valor: " << i*10 << std::endl;
  }
  listaInt.print();

}