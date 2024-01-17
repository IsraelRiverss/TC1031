// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
//   - Daniel Aguilar Darío - A01750975
//   - Luis Daniel Garcia Espinosa - A01643058
// Created Date: Noviembre 12th, 2024
// Modification Date: Noviembre 13th, 2024
// =========================================================

/*
 Compilación con debug:
    g++ -std=c++17 .cpp -Wall -g -o main

  Compilación para ejecucion:
    g++ -std=c++17 ./actividad1_2/main.cpp -Wall -o3 -o main

  Ejecución con redireccion (input and output):
    ./main < ./actividad1_2/TestCases/test01.txt
    ./main < ./actividad1_2/TestCases/test01.txt > salida.txt
*/

/* 
Este programa es una herramienta para evaluar diferentes algoritmos de ordenamiento y búsqueda.
Recibe datos como entrada por medio de la redirección en consola de un archivo testCase.txt. Aplica dos algoritmos uno de ordenamiento y uno de búsqueda para procesar estos parámetros.

    El programa admite los siguientes algoritmos de ordenamiento:
        1. Burbuja
        2. Merge Sort
        3. Quick Sort

    Y los siguientes algoritmos de búsqueda:
        1. Búsqueda Secuencial
        2. Búsqueda Binaria

La entrada consiste en el tamaño del conjunto de parámetros, el tipo de algoritmo de ordenamiento, el tipo de algoritmo de búsqueda y la clave a buscar. Seguido de los parámetros del conjunto.

La salida muestra el conjunto ordenado, el número de comparaciones y swaps (para ordenamiento), y el resultado de la búsqueda junto con el número de comparaciones realizadas.
*/

// Inclusión de Archivos y Bibliotecas
#include "AlgorithmSort.h"
#include "SearchAlgorithm.h"
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;


int main ()
{
    // Declaración de variables
    int size;                     // Tamaño del vector
    int typeSortAlgorithm;        // Tipo de algoritmo de ordenamiento
    int typeSearchAlgorithm;      // Tipo de algoritmo de búsqueda
    int key;                      // Clave a buscar en el vector ordenado
    int compara;
    unsigned int comparaciones; // Contador de comparaciones
    unsigned int swaps;       // Contador de intercambios (swaps)
    vector<int> vector;           // Vector para almacenar los casos de prueba
    // Lectura de valores desde la entrada estándar
    cin >> size >> typeSortAlgorithm >> typeSearchAlgorithm >> key;

    // Redimensionamiento y lectura de valores para el vector
    vector.resize(size);
    for (int i = 0; i < size; i++) {
        cin >> vector[i];
    }

    // Instanciación de objetos para los algoritmos
    AlgorithmSort<int> sortObj;
    SearchAlgorithm<int> searchObj;

    
    switch (typeSortAlgorithm) {
        case 1: // Burbuja
          // Ordenamiento del vector utilizando bubble sort
          comparaciones = swaps = 0;//Inicializa las variables de comparaciones y swaps en 0
          sortObj.bubbleSort(vector, size, comparaciones, swaps);//Llama a la función de ordenamiento bubbleSort
          sortObj.printVector(vector);//Imprime el vector ordenado
          cout << comparaciones << endl;// Imprime las comparaciones y swaps
          cout << swaps << endl;
          break;
      
        case 2: // Merge
          // Ordenamiento del vector utilizando merge sort
          comparaciones = swaps = 0;//Inicializa las variables de comparaciones y swaps en 0
          sortObj.mergeSort(vector, 0, size-1, comparaciones);//Llama a la función de ordenamiento mergeSort
          sortObj.printVector(vector);//Imprime el vector ordenado
          cout << comparaciones << endl;// Imprime las comparaciones y swaps
            break;
      
        case 3: // Quicksort
          // Ordenamiento del vector utilizando quick sort
          comparaciones = swaps = 0;//Inicializa las variables de comparaciones y swaps en 0
          sortObj.quickSort(vector, 0, size-1, comparaciones, swaps);//Llama a la función de ordenamiento quickSort
          sortObj.printVector(vector);//Imprime el vector ordenado
          cout << comparaciones << endl;// Imprime las comparaciones y swaps
          cout << swaps << endl;// Imprime las comparaciones y swaps
            break;
      
        default:
            cerr << endl;// Imprime un mensaje de error si el tipo de algoritmo de ordenamiento no es válido
            return 1;// Retorna un código de error
    }

    // Ejecución del algoritmo de búsqueda
    switch (typeSearchAlgorithm) {
        case 1: // Búsqueda Secuencial
            cout << searchObj.busquedaSecuencialVectorOrdenado(vector, key, compara) << endl;// Llama a la función de búsqueda secuencial y imprime el resultado
            //Imprime la comparaciones
            cout << compara << endl;
            break;
        case 2: // Búsqueda Binaria
            cout << searchObj.busquedaBinaria(vector, key, compara) << endl;// Llama a la función de búsqueda binaria y imprime el resultado
            //Imprime la comparaciones
            cout << compara << endl;
            break;
        default:
            cerr << "Algoritmo de búsqueda no válido" << endl;// Imprime un mensaje de error si el tipo de algoritmo de búsqueda no es válido
            return 1;// Retorna un código de error
    }

    return 0;
}