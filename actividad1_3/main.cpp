/**
 * Ejemplo que implementa objetos de la clase Registro
 * que contienen una fecha-hora convertida a Linux timestamp
 * para realizar comparaciones (sobrecarga de operadores)
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 **/

#include "Bitacora.h"
#include "Registro.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  Bitacora bitacora;
  bitacora.leerArchivo("bitacora.txt");
  bitacora.doQuickSort();
  bitacora.imprimirBitacora();
/*
 string fechaInicio, fechaFin;
  cout << "Introduce la fecha de inicio (mes dia hora:minutos:segundos): ";
  getline(cin, fechaInicio);
  cout << "Introduce la fecha de fin (mes dia hora:minutos:segundos): ";
  getline(cin, fechaFin);
*/
  return 0;
}

/**
// Crear objetos de la clase Registro (un renglon de la bitacora)
Registro a("Feb", "04", "00", "01", "52", "1.1.1.1", "123", "Falla 1");
Registro b("Feb", "04", "00", "01", "03", "1.1.1.3", "1234", "Falla 2");
Registro c("Dec", "01", "00", "01", "03", "1.1.1.1", "123", "Falla 1");

std::cout << a.getAll() << std::endl;
std::cout << b.getAll() << std::endl;
std::cout << c.getAll() << std::endl;

if (a > b)
  std::cout << "a mayor b" << std::endl;
else
  std::cout << "a menor b" << std::endl;
**/