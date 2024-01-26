// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
//   - Daniel Aguilar Darío - A01750975
//   - Luis Daniel Garcia Espinosa - A01643058
// Created Date: Noviembre 12th, 2024
// Modification Date: Noviembre 13th, 2024
// =========================================================

/**
 * Ejemplo que implementa una lista doblemente ligada con head y tail
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -Wall -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *    https://www.youtube.com/watch?v=8JEEYwdrexc
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -Wall -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include "DLinkedList.h"
#include <iostream>

int main() {
  DLinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  // addFirst
  std::cout << "Agregando 10 elementos al frente..." << std::endl;
  for (int i = 1; i < 11; i++) {
    miLista.addFirst(i);
  }
  // addLast
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 20; i < 26; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  miLista.quickSort();
  miLista.printList();
  
  return 0;
}