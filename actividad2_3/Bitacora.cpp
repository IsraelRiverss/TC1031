#include "Bitacora.h"
#include <algorithm>
#include <iostream>

Bitacora::Bitacora() {
  
}

Bitacora::~Bitacora() {

}

void Bitacora::leerArchivo(std::string filePath) {
  std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
  std::ifstream archivo(filePath);

  if (!archivo.good()) {
    archivo.close();
    throw std::invalid_argument("File not found");
  } 
  else {
    while (!archivo.eof()) {
      numElements++;
      std::getline(archivo, mes, ' ');
      if (mes.length() > 0) {
        std::getline(archivo, dia, ' ');
        std::getline(archivo, horas, ':');
        std::getline(archivo, minutos, ':');
        std::getline(archivo, segundos, ' ');
        std::getline(archivo, ip, ':');
        std::getline(archivo, puerto, ' ');
        std::getline(archivo, falla);
        // Crear un objeto de la clase Registro
        Registro nuevalista(mes, dia, horas, minutos, segundos, ip, puerto, falla);

        listaRegistros.addLast(nuevalista);
      }
    }
    archivo.close();
  }
}


void Bitacora::printList() {
  std::ofstream archivo("bitacora_ordenada.txt");
  if (archivo.is_open()) {
    DLLNode<Registro>* p = listaRegistros.getHead();
    if (p == nullptr)
      archivo << "La lista esta vacia" << std::endl;
    else {
      while (p != nullptr) {
        archivo << p->data.getAll() << std::endl;
        p = p->next;
      }
      archivo << std::endl;
      archivo.close();
    }
  }
  else {
    std::cerr << "No se pudo abrir el archivo" << std::endl;
  }
}


void Bitacora::quicksort(){
  //std::cout<<"\nQuick Sort:"<<std::endl;
  listaRegistros.quickSort();
}

void Bitacora::mergesort(){
  std::cout<<"\nMerge Sort:"<<std::endl;
  listaRegistros.callMerge();
}

DLLNode<Registro>* Bitacora::buscarRangoFechas(const Registro& inicio, const Registro& fin) {
    DLLNode<Registro>* current = listaRegistros.getHead();
    DLLNode<Registro>* resultado = nullptr;

    while (current != nullptr) {
        if (current->data >= inicio && current->data <= fin) {
            if (resultado == nullptr) {
                resultado = current; 
            }
        } else if (current->data > fin) {
            break;
        }

        current = current->next;
    }

    return resultado;
}

Registro Bitacora::convertirEntradaFecha(const std::string& entrada) {
    std::string mesI, diaI, horaI, minI, segundoI;
    std::istringstream ss(entrada);

    std::getline(ss, mesI, ' ');
    std::getline(ss, diaI, ' ');
    std::getline(ss, horaI, ':');
    std::getline(ss, minI, ':');
    std::getline(ss, segundoI);

    return Registro(mesI, diaI, horaI, minI, segundoI, "", "", "");
}