#include "Bitacora.h"
#include <fstream>
#include <sstream>

void Bitacora::leerArchivo(string filePath) {
    ifstream archivo(filePath);
    vector<Registro> listaRegistros;
  
    string line;
    while (getline(archivo, line)) {
        istringstream iss(line);
        string mes, dia, horas, minutos, segundos, ip, puerto, falla;
        if (iss >> mes >> dia >> horas >> minutos >> segundos >> ip >> puerto >> falla) {
            Registro nuevoRegistro(mes, dia, horas, minutos, segundos, ip, puerto, falla);
            listaRegistros.push_back(nuevoRegistro);
        } else {
            cerr << "Error: Imposible de leer el archivo: " << line << endl;
        }
    }
    archivo.close();
}

void Bitacora::selectionSort(vector<int> &A, int n, unsigned int &compara, unsigned int &swap){
  compara = swap = 0;
  for (int i = 0; i < n-1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      compara++;
      if (A[j] < A[minIndex])
        minIndex = j;
    }
    std::swap(A[minIndex], A[i]);
    swap++;
  }
}

int Bitacora::partition(vector<int> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  int pivot = A[high];
  int i = low - 1;
  for (int j = low; j < high-1; j++) {
    compara++;
    if (A[j] < pivot) {
      i++;
      std::swap(A[i], A[j]);
      swap++;
    }
  }
  std::swap(A[i+1], A[high]);
  swap++;
  return i + 1;  
}

void Bitacora::quickSort(vector<int> &A, int low, int high, unsigned int &compara, unsigned int &swap) {
  if (low < high) {
    // encontrar la particion del vector
    int pi = partition(A, low, high, compara, swap);
    // ordenar la particion izquierda y derecha
    quickSort(A, low, pi - 1, compara, swap);
    quickSort(A, pi + 1, high, compara, swap);
  }
}


int Bitacora::busquedaBinaria(vector<int> &A, int key, int &compara) {
  int l = 0;
  int r = A.size() - 1;
  compara = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    compara++;
    if (key == A[m])
      return m;
    else if (key < A[m]) 
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}


