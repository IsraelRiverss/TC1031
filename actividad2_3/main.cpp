// =========================================================
// File: main.cpp
// Authors
//   - Daniel Aguilar Darío - A01750975
//   - Luis Daniel Garcia Espinosa - A01643058
// Created Date: Noviembre 12th, 2024
// Modification Date: Noviembre 17th, 2024
// =========================================================
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
#include "DLLNode.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  Bitacora bitacora;
  bitacora.leerArchivo("bitacora.txt");
  bitacora.quicksort();
  bitacora.mergesort();
  bitacora.printList();
  
  string fechaInicio, fechaFin;
  cout << "Introduce la fecha de inicio (mes dia hora:minutos:segundos): ";
  getline(cin, fechaInicio);
  cout << "Introduce la fecha de fin (mes dia hora:minutos:segundos): ";
  getline(cin, fechaFin);

  try {
    Registro inicio = bitacora.convertirEntradaFecha(fechaInicio);
    Registro fin = bitacora.convertirEntradaFecha(fechaFin);

    DLLNode<Registro>* resultado = bitacora.buscarRangoFechas(inicio, fin);

    std::ofstream outFile("rango_fechas.txt");

    if (resultado != nullptr) {
        std::cout << "Registros en el rango de fechas:" << std::endl;
        outFile << "Registros en el rango de fechas:" << std::endl;

        while (resultado != nullptr && resultado->getData() <= fin) {
            std::cout << resultado->getData().getAll() << std::endl;
            outFile << resultado->getData().getAll() << std::endl;
            resultado = resultado->getNext();
        }
    } else {
        std::cout << "No se encontraron registros en el rango de fechas." << std::endl;
        outFile << "No se encontraron registros en el rango de fechas." << std::endl;
    }
    outFile.close();
  } catch (const std::invalid_argument& e) {
      std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}