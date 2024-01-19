// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
//   - Daniel Aguilar Darío - A01750975
//   - Luis Daniel Garcia Espinosa - A01643058
// Created Date: Noviembre 15th, 2024
// Modification Date: Noviembre 17th, 2024
// =========================================================

/**
 * Ejemplo que implementa una lista ligada con head y tail
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

#include "LinkedList.h"
#include <iostream>

int main() {
  LinkedList<int> miLista;
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  // addFirst
  std::cout << "Agregando 10 elementos al frente..." << std::endl;
  for (int i = 1; i < 11; i++) {
    miLista.addFirst(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // addLast
  std::cout << "Agregando 5 elementos al final..." << std::endl;
  for (int i = 20; i < 26; i++) {
    miLista.addLast(i);
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // deleteData
  std::cout << "Delete 12: " << std::endl;
  miLista.deleteData(12);
  std::cout << "Delete 5: " << std::endl;
  miLista.deleteData(5);
  std::cout << "Delete 14: " << std::endl;
  miLista.deleteData(14);
  std::cout << "Delete 114: " << std::endl;
  miLista.deleteData(114);
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // DeleteAt puede lanzar una excepcion
  std::cout << "DeleteAt 2: " << std::endl;
  try {
    miLista.deleteAt(2);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();

  std::cout << "DeleteAt 49: " << std::endl;
  try {
    miLista.deleteAt(49);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();

  std::cout << "DeleteAt 0: " << std::endl;
  try {
    miLista.deleteAt(0);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();

  std::cout << "DeleteAt 12: " << std::endl;
  try {
    miLista.deleteAt(12);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << "numElements: " << miLista.getNumElements() << std::endl;
  miLista.printList();
  std::cout << std::endl;

  // getData
  try {
    std::cout << "getData(0): " << miLista.getData(0) << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "getData(3): " << miLista.getData(3) << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "getData(11): " << miLista.getData(11) << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << std::endl;
  try {
    std::cout << "getData(113): " << miLista.getData(113) << std::endl;
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  std::cout << std::endl;

  // updateData
  try {
    std::cout << "updateData(9, 777): " << std::endl;
    miLista.updateData(9, 777);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(24, 345): " << std::endl;
    miLista.updateData(24, 345);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(20, 999): " << std::endl;
    miLista.updateData(20, 999);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(110, 55): " << std::endl;
    miLista.updateData(110, 55);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  // updateAt
  try {
    std::cout << "updateAt(0, 899): " << std::endl;
    miLista.updateAt(0, 899);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(11, 5775): " << std::endl;
    miLista.updateAt(11, 5775);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(5, 333): " << std::endl;
    miLista.updateAt(5, 333);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  try {
    std::cout << "updateData(1111, 5775): " << std::endl;
    miLista.updateAt(1111, 5775);
  } catch (std::out_of_range &e) {
    std::cout << "Error: " << e.what() << std::endl
              << "No se modifico la lista" << std::endl;
  } catch (...) {
    std::cout << "Error desconocido, no se modifico la lista" << std::endl;
  }
  miLista.printList();
  std::cout << std::endl;

  // Agregar elementos a la lista
  miLista.addLast(10);
  miLista.addLast(20);
  miLista.addLast(30);
  miLista.addLast(40);

  // Imprimir la lista
  std::cout << "La lista contiene: ";
  miLista.printList();

  // Buscar un elemento en la lista
  int valorABuscar = 30;
  int posicion = miLista.findData(valorABuscar);

  // Imprimir el resultado de la búsqueda
  if (posicion != -1) {
    std::cout << "El valor " << valorABuscar
              << " se encuentra en la posición: " << posicion << std::endl;
  } else {
    std::cout << "El valor " << valorABuscar << " no se encuentra en la lista."
              << std::endl;
  }

  std::cout << "miLista antes de la copia: ";
  miLista.printList();

  // Crear una copia de miLista
  LinkedList<int> listaCopia = miLista;

  std::cout << "Lista Copia: ";
  listaCopia.printList();

  // Modificar miLista para demostrar que la copia es independiente
  miLista.addLast(40);
  std::cout << "miLista modificada: ";
  miLista.printList();

  std::cout << "Lista Copia (sin cambios): ";
  listaCopia.printList();

  return 0;
}