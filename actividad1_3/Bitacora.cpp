#include "Bitacora.h"

Bitacora::Bitacora() {}

Bitacora::~Bitacora() {}

void Bitacora::leerArchivo(std::string filePath) {
  std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
  int day, port;
  int numRecords = 0;
  std::ifstream archivo(filePath);
  if (!archivo.good()) {
    archivo.close();
    throw std::invalid_argument("File not found");
  } 
  else {
    while (!archivo.eof()) {
      std::getline(archivo, mes, ' ');
      std::getline(archivo, dia, ' ');
      std::getline(archivo, horas, ':');
      std::getline(archivo, minutos, ':');
      std::getline(archivo, segundos, ' ');
      std::getline(archivo, ip, ':');
      std::getline(archivo, puerto, ' ');
      std::getline(archivo, falla);
      numRecords++;
      Registro nuevoRegistro(mes, dia, horas, minutos, segundos, ip, puerto, falla);
      listaRegistros.push_back(nuevoRegistro);
      std::cout << mes << " " << dia << " " << ip << " ";
      std::cout << day << " " << port << std::endl;
    }
    archivo.close();
  }
}
/*
  while (getline(archivo, line)) {
    std::istringstream iss(line);
    std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
    if (iss >> mes >> dia >> horas >> minutos >> segundos >> ip >> puerto >>
falla) { Registro nuevoRegistro(mes, dia, horas, minutos, segundos, ip, puerto,
falla); listaRegistros.push_back(nuevoRegistro); } else { std::cerr << "Error:
Imposible de leer el archivo: " << line << std::endl;
    }
  }
  archivo.close();
}
*/

void Bitacora::selectionSort(int n, unsigned int &compara, unsigned int &swap) {
  compara = swap = 0;
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      compara++;
      if (listaRegistros[j] < listaRegistros[minIndex])
        minIndex = j;
    }
    std::swap(listaRegistros[minIndex], listaRegistros[i]);
    swap++;
  }
}

int Bitacora::partition(int low, int high, unsigned int &compara,
                        unsigned int &swap) {
  Registro pivot = listaRegistros[high];
  int i = low - 1;
  for (int j = low; j < high - 1; j++) {
    compara++;
    if (listaRegistros[j] < pivot) {
      i++;
      std::swap(listaRegistros[i], listaRegistros[j]);
      swap++;
    }
  }
  std::swap(listaRegistros[i + 1], listaRegistros[high]);
  swap++;
  return i + 1;
}

void Bitacora::quickSort(int low, int high, unsigned int &compara, unsigned int &swap) {
  if (low < high) {
    // encontrar la particion del vector
    int pi = partition(low, high, compara, swap);
    // ordenar la particion izquierda y derecha
    quickSort(low, pi - 1, compara, swap);
    quickSort(pi + 1, high, compara, swap);
  }
}

void Bitacora::doQuickSort() {
  unsigned int comparaQuicksort;
  unsigned int swapQuicksort;

  quickSort(0, listaRegistros.size() - 1, comparaQuicksort, swapQuicksort);

  std::cout << "Quicksort - Comparaciones: " << comparaQuicksort
            << ", Swaps: " << swapQuicksort << std::endl;
}

int Bitacora::busquedaBinaria(Registro key, int &compara) {
  int l = 0;
  int r = listaRegistros.size() - 1;
  compara = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    compara++;
    if (key == listaRegistros[m])
      return m;
    else if (key < listaRegistros[m])
      r = m - 1;
    else
      l = m + 1;
  }
  return -1;
}

void Bitacora::imprimirBitacora() const {
  for (int i = 0; i < (int)listaRegistros.size(); i++) {
    std::cout << listaRegistros[i].getAll() << std::endl;
  }
}

void Bitacora::imprimirBitacoraOrdenada(std::string filePath) const {
  std::ofstream archivo(filePath);
  for (int i = 0; i < (int)listaRegistros.size(); i++) {
    archivo << listaRegistros[i].getAll() << std::endl;
  }
  archivo.close();
}

std::vector<Registro> Bitacora::obtenerRegistrosEntreFechas(const Registro& inicio, const Registro& fin) {
  std::vector<Registro> registrosFiltrados;
  for (const auto& registro : listaRegistros) {
    if (registro >= inicio && registro <= fin) {
      registrosFiltrados.push_back(registro);
    }
  }
  return registrosFiltrados;
}

