#ifndef _BITACORA_H_
#define _BITACORA_H_

#include "Registro.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Bitacora {
private:
  vector<Registro> listaRegistros;
  int partition(std::vector<int> &A, int low, int high, unsigned int &compara, unsigned int &swap);

public:
  Bitacora();
  ~Bitacora();
  // TO-DO
  void leerArchivo(string filePath);
  void selectionSort(vector<int> &A, int n, unsigned int &compara, unsigned int &swap);
  void quickSort(vector<int> &A, int low, int high, unsigned int &compara, unsigned int &swap);
  int busquedaBinaria(vector<int> &A, int key, int &compara);
  void imprimirBitacora(vector<int> &A) const;
  
};

#endif // _BITACORA_H_
