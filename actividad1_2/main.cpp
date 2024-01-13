// =========================================================
// File: main.cpp
// Authors
//   - Fernando Israel Rios Garcia-A01709118
// Date: Noviembre 12th, 2024
// =========================================================

/*
 Compilación con debug:
 *  g++ -std=c++17 *.cpp -Wall -g -o main
 *
 * Compilación para ejecucion:
 *  g++ -std=c++17 *.cpp -Wall -O3 -o main
 *
 * Ejecución con redireccion (input and output):
 *  ./main < TestCases/t1.txt
 *  ./main < TestCases/t2.txt > salida.txt
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
    //Vairables for the size of the array, the type of sorting algorithm, the type of search algorithm and the serched number in a sorted array
    int size, typeSortAlgoritm, typeSearchAlgorithm, n; //Initialize variables
    cin >> size; cin >> typeSortAlgoritm; cin >> typeSearchAlgorithm; cin >> n; //Delcare and read vairiables
    vector<int> vector; //Vector to store test cases

    vector.resize(size); //Resize vector to size
    for (int i = 0; i < size; i++) //Read test cases
    {
        cin >> vector[i];
    }

    //print vector
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " " << endl;
    }    

    //Instancia un objeto de la clase AlgoritmoSort, nombrado "sortObj"
    AlgorithmSort<int> sortObj;
    //Instancia un objeto de la clase SearchAlgorithm, nombrado "searchObj"
    SearchAlgorithm<int> searchObj;

    return 0;
    

}