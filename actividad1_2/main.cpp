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
    int size, typeSortAlgorithm, typeSearchAlgorithm, numberToSearch; //Initialize variables
    cin >> size; cin >> typeSortAlgorithm; cin >> typeSearchAlgorithm; cin >> numberToSearch; //Delcare and read vairiables
    vector<int> vector; //Vector to store test cases

    vector.resize(size); //Resize vector to size
    for (int i = 0; i < size; i++) //Read test cases
    {
        cin >> vector[i];
    }
/* 
NOTA DE FER:
Puse este codigo para ver si el vector se leyo bien. si lo hace. Pero no se como mandar el vector a los metodos de ordenamiento y busqueda con los argumentos que piden para cada metedo

    //print vector. 
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " " << endl;
    }    
*/
    // Instancia de los objetos para los algoritmos
    AlgorithmSort<int> sortObj;
    SearchAlgorithm<int> searchObj;

    // Selección del algoritmo de ordenamiento
    switch (typeSortAlgorithm) {
        case 1: // Burbuja
            sortObj.bubbleSort(vector); //Nota de Fer: No se que argumentos me faltan para que el metodo funcioe, ya defini las variables que nos que nospiden para leer el test case. 
            break;
        case 2: // Merge
            sortObj.mergeSort(vector); //Nota de Fer: No se que argumentos me faltan para que el metodo funcioe, ya defini las variables que nos que nospiden para leer el test case. 
            break;
        case 3: // Quicksort
            sortObj.quickSort(vector); //Nota de Fer: No se que argumentos me faltan para que el metodo funcioe, ya defini las variables que nos que nospiden para leer el test case. 
            break;
        default:
            cerr << "Algoritmo de ordenamiento no válido" << endl;
            return 1;
    }

    // Ejecución del algoritmo de búsqueda
    int searchResult = -1;
    switch (typeSearchAlgorithm) {
        case 1: // Búsqueda Secuencial
            searchResult = searchObj.busquedaSecuencial(vector, numberToSearch); //Nota de Fer: No se que argumentos me faltan para que el metodo funcioe, ya defini las variables que nos que nospiden para leer el test case. 
            break;
        case 2: // Búsqueda Binaria
            searchResult = searchObj.busquedaBinaria(vector, numberToSearch); //Nota de Fer: No se que argumentos me faltan para que el metodo funcioe, ya defini las variables que nos que nospiden para leer el test case. 
            break;
        default:
            cerr << "Algoritmo de búsqueda no válido" << endl;
            return 1;
    }

    return 0;
}