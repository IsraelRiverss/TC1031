#include <iostream>
#include <vector>
using namespace std;

void fibonacciRecursivo(int n, vector<int>& serie) {
    if(serie.size() == 0) {
        serie.push_back(0);  // F(0)
        if(n == 0) return;
    }
    if(serie.size() == 1) {
        serie.push_back(1);  // F(1)
        if(n == 1) return;
    }
    if(serie.size() == n+1) return;

    int nextValue = serie[serie.size() - 1] + serie[serie.size() - 2];
    serie.push_back(nextValue);
    fibonacciRecursivo(n, serie);
}