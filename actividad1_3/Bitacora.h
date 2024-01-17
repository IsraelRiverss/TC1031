//Guard
#ifndef _BITACORA_H_
#define _BITACORA_H_

//Librerias
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
//Class flies
#include "Registro.h"

class Bitacora {
private:
std::vector<Registro> listaRegistros;
int partition(int low, int high, unsigned int &compara,unsigned int &swap);
void quickSort(int low, int high, unsigned int &compara,unsigned int &swap);

public:
  Bitacora();
  ~Bitacora();
  void leerArchivo(std::string filePath);
  void selectionSort(int n, unsigned int &compara, unsigned int &swap);
  void doQuickSort();
  int busquedaBinaria(Registro key, int &compara);
  void imprimirBitacora() const;
};

#endif // _BITACORA_H_
