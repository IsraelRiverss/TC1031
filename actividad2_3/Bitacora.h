#ifndef _BITACORA_H_
#define _BITACORA_H_

#include "DLLNode.h"
#include "DLinkedList.h"
#include "Registro.h"
#include <fstream>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <sstream>

class Bitacora {
private:
  DLLNode<Registro> *head;
  DLLNode<Registro> *tail;
  int numElements;
  DLinkedList<Registro> listaRegistros; // lista de objetos de la clase Registro


public:
  Bitacora();
  ~Bitacora();
  void leerArchivo(std::string filePath);
  void printList();
  void imprimirBitacoraOrdenada(std::string filePath) const;
  void quicksort();
  void mergesort();
  DLLNode<Registro>binSearch(Registro key);
  DLLNode<Registro>* buscarRangoFechas(const Registro& inicio, const Registro& fin);
  Registro convertirEntradaFecha(const std::string& entrada);

};

#endif