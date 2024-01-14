// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
// Date: Noviembre 12th, 2024
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

//Files 
#include "AlgorithmSort.h"
#include "SearchAlgorithm.h"
//Libraries
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;




int main ()
{
    //Vairables for the size of the vector, the type of sorting algorithm, the type of search algorithm and the serched number in a sorted vector
    int size, typeSortAlgorithm, typeSearchAlgorithm, key, compara; //Initialize variables
    unsigned int comparaciones, swaps;
    cin >> size; cin >> typeSortAlgorithm; cin >> typeSearchAlgorithm; cin >> key; //Delcare and read vairiables
    vector<int> vector; //Vector to store test cases

    vector.resize(size); //Resize vector to size
    for (int i = 0; i < size; i++) //Read test cases
    {
        cin >> vector[i];
    }
/* 
    //print vector. 
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " " << endl;
    }    
*/
    // Instancia de los objetos para los algoritmos
    AlgorithmSort<int> sortObj;
    SearchAlgorithm<int> searchObj;

    switch (typeSortAlgorithm) {
        case 1: // Burbuja
          comparaciones = swaps = 0;
          sortObj.bubbleSort(vector, size, comparaciones, swaps);
          sortObj.printVector(vector);
          cout << comparaciones << endl;
          cout << swaps << endl;
          break;
      
        case 2: // Merge
          comparaciones = swaps = 0;
          sortObj.mergeSort(vector, 0, size-1, comparaciones);
          sortObj.printVector(vector);
          cout << comparaciones << endl;
            break;
      
        case 3: // Quicksort
          comparaciones = swaps = 0;
          sortObj.quickSort(vector, 0, size-1, comparaciones, swaps);
          sortObj.printVector(vector);
          cout << comparaciones << endl;
          cout << swaps << endl;
            break;
      
        default:
            cerr << endl;
            return 1;
    }

    // Ejecución del algoritmo de búsqueda
    int searchResult = -1;
    switch (typeSearchAlgorithm) {
        case 1: // Búsqueda Secuencial
            cout << searchObj.busquedaSecuencialVectorOrdenado(vector, key, compara) << endl;
            cout << compara << endl;
            break;
        case 2: // Búsqueda Binaria
            cout << searchObj.busquedaBinaria(vector, key, compara) << endl;
            cout << compara << endl;
            break;
        default:
            cerr << "Algoritmo de búsqueda no válido" << endl;
            return 1;
    }

    return 0;
}