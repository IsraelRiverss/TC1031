#ifndef _BITACORA_H_
#define _BITACORA_H_

// Librerias
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
// Class flies
#include "Registro.h"


class Bitacora {
private:
  std::vector<Registro> listaRegistros;
  std::vector<Registro> obtenerRegistrosEntreFechas(const Registro& inicio, const Registro& fin);
  int partition(int low, int high, unsigned int &compara, unsigned int &swap);
  void quickSort(int low, int high, unsigned int &compara, unsigned int &swap);

public:
  Bitacora();
  ~Bitacora();
  void leerArchivo(std::string filePath);
  void selectionSort(int n, unsigned int &compara, unsigned int &swap);
  void doQuickSort();
  int busquedaBinaria(Registro key, int &compara);
  void imprimirBitacora() const;
  void imprimirBitacoraOrdenada(std::string filePath) const;
  
};

#endif // _BITACORA_H_
