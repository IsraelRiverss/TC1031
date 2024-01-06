#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include <vector>

const int MAX = 100;

template <class T>
class Lista {
  private:
    std::vector<T> data;
    int currentSize;

  public:
    Lista();
    ~Lista();
    bool insert(T value);
    void print();
    // TO-DO
    void erase();
    T getData(int index);
    int getCurrentSize();
    

};

template <class T> //constructor
Lista<T>::Lista() {
  data.clear();
  currentSize = 0;
}

template <class T> //destructor
Lista<T>::~Lista() {
  data.clear();
  currentSize = 0;
}

template <class T> //intsert funcion
bool Lista<T>::insert(T value) {
  if (currentSize < MAX) {
    data.push_back(value);
    currentSize++;
    return true;
  }
  return false;
}

template <class T>//print funcion
void Lista<T>::print() {
  std::cout << "Contenido de la lista:" << std::endl;
  for (int i = 0; i < currentSize; i++) {
    std::cout << "[" << i << "] - " << data[i] << std::endl;
  }

void Lista<T>::erase() 
{
  if (currentSize > 0)
  {
    std::cout << "Elemento eliminado" << std::endl;
    data[currentSize - 1];
  }
  else
  {
    std::cout << "No hay elementos en la lista" << std::endl;
  }
}

template <class T>
T Lista<T>::getData(int index)
{
  if (0 >= index && index > currentSize)
  {
    return data[index];
  }
  else 
  {
    return 0;
  }
}

template <class T>
int Lista<T>::getCurrentSize()
{
  return currentSize;
}

}

#endif // _LISTA_H_