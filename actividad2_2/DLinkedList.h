#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "DLLNode.h"

template <class T>
class DLinkedList {
  private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;

  public:
    DLinkedList();
    ~DLinkedList();
    int getNumElements();
    void printList();
    void printReverseList();
    void addFirst(T value);
    void addLast(T value);
    
    bool deleteData(T value);
    bool deleteAt(int position);
    T getData(int position);
    void updateData(T value, T newValue);
    void updateAt(int position, T newValue);
    
};

// Complejidad O(1)
template <class T>
DLinkedList<T>::DLinkedList() {
  //std::cout << "--> Creando una lista ligada vacia: " << this << std::endl; 
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

// Complejidad O(n)
template <class T>
DLinkedList<T>::~DLinkedList() {
  //std::cout << "--> Liberando memoria de la lista ligada: " << this << std::endl;
  DLLNode<T> *p, *q;
  p = head;
  while (p != nullptr) {
    q = p->next;
    delete p;
    p = q;
  }
  head = nullptr;
  tail = nullptr;
  numElements = 0;
}

// Complejidad O(1)
template <class T>
int DLinkedList<T>::getNumElements() {
  return numElements;  
}

// Complejidad O(n)
template <class T>
void DLinkedList<T>::printList() {
  if (head == nullptr && tail == nullptr)
    std::cout << "La lista esta vacia" << std::endl;
  else {
    std::cout << "El contenido de la lista es: " << std::endl;
    DLLNode<T> *p = head;
    while(p != nullptr) {
      std::cout << p->data << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }    
}
// Complejidad O(n)
template <class T>
void DLinkedList<T>::printReverseList() {
  if (head == nullptr && tail == nullptr)
    std::cout << "La lista esta vacia" << std::endl;
  else {
    std::cout << "El contenido inverso de la lista es: " << std::endl;
    DLLNode<T> *p = tail;
    while(p != nullptr) {
      std::cout << p->data << " ";
      p = p->prev;
    }
    std::cout << std::endl;
  }    
}
// Complejidad O(1)
template <class T>
void DLinkedList<T>::addFirst(T value) {
  // 1. crear nuevo nodo
  DLLNode<T> *newNode = new DLLNode<T>(value);
  // si la lista esta vacia
  if (head == nullptr && tail == nullptr) {
    head = newNode;
    tail = newNode;
  }
  else {
    // 2. apuntar newNode->next al nodo apuntado por head
    newNode->next = head;
    // 3. apuntar head->prev a newNode
    head->prev = newNode;
    // 4. actualizar head para apuntar a newNode
    head = newNode;
  }
  numElements++;
}

// Complejidad O(1)
template <class T>
void DLinkedList<T>::addLast(T value) {
  // La lista esta vacia
  if (head == nullptr && tail == nullptr)
    addFirst(value);
  else {
      // 1. crear nuevo nodo
      DLLNode<T> *newNode = new DLLNode<T>(value);
      // 2. apuntar tail->next a newNode
      tail->next = newNode;
      // 3. apuntar newNode->prev a tail
      newNode->prev = tail;
      // 3. actualizar tail para apuntar a newNode
      tail = newNode;
      numElements++;
  }
}

// Complejidad O(n)
template <class T>
bool DLinkedList<T>::deleteData(T value) {
  // La lista esta vacia
  if (head == nullptr && tail == nullptr) {
    std::cout << "La lista esta vacia" << std::endl;
    return false;
  }
  else {
    // Buscar value en la lista
    DLLNode<T> *p = head;
    DLLNode<T> *previous = nullptr;
    while(p != nullptr && p->data != value) {
      previous = p;
      p = p->next;
    }
    // si value no esta en la lista
    if (p == nullptr) {
      std::cout << "El valor no existe en la lista" << std::endl;
      return false;
    }
    // si debo borrar el primer nodo de la lista
    if (p != nullptr && p == head) {
      head = p->next;
      if (head == nullptr) // habia solo un nodo en la lista
        tail = nullptr;
      else
        head->prev = nullptr;
    }
    else if (p->next == nullptr) { // borrar el ultimo nodo
      previous->next = nullptr;
      tail = previous;
    }
    else { // borrar cualquier otro nodo
      previous->next = p->next;
      p->next->prev = previous;
    }
    // borrar el nodo apuntado por p
    delete p;
    p = nullptr;
    numElements--;
    return true;
  }
}

// Complejidad O(n)
template <class T>
bool DLinkedList<T>::deleteAt(int position) {
  // Validar position
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  } 
  else if (position == 0) { // primer nodo 
    DLLNode<T> *p = head;
    // si la lista contiene un solo nodo
    if (p != nullptr && p->next == nullptr) {
      head = nullptr;
      tail = nullptr;
    }
    else {
      head = p->next;
      head->prev = nullptr;
    }
    delete p;
    p = nullptr;
    numElements--;
    return true;
  }
  else {
    // Buscar position en la lista
    DLLNode<T> *p = head;
    DLLNode<T> *previous = nullptr;
    int index = 0;
    while(index != position) {
      previous = p;
      p = p->next;
      index++;
    }
    // debo borrar el ultimo nodo
    if (p->next == nullptr) {
      previous->next = nullptr;
      tail = previous;
    }
    else { // borrar cualquier otro nodo
      previous->next = p->next;
      p->next->prev = previous;
    }
    delete p;
    p = nullptr;
    numElements--;
    return true;    
  }
}

// Complejidad O(n)
template <class T>
T DLinkedList<T>::getData(int position) {
  // Validar position
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  } 
  else if (position == 0) { // primer nodo 
    return head->data;
  }
  else { // si es cualquier otra posicion
    // Buscar position en la lista
    DLLNode<T> *p = head;
    int index = 0;
    while(index != position) {
      p = p->next;
      index++;
    }
    if (p != nullptr)
      return p->data;
    else
      return {};
  }
}

// Complejidad O(n)
template <class T>
void DLinkedList<T>::updateData(T value, T newValue) {
  // Buscar value en la lista
  DLLNode<T> *p = head;
  while(p != nullptr && p->data != value) {
    p = p->next;
  }
  if (p != nullptr)
    p->data = newValue;
  else
    throw std::out_of_range("El elemento a actualizar no existe en la lista");
}


// Complejidad O(n)
template <class T>
void DLinkedList<T>::updateAt(int position, T newValue) {
  // Validar position
  if (position < 0 || position >= numElements) {
    throw std::out_of_range("Indice fuera de rango");
  }
  else {
    // Buscar position en la lista
    DLLNode<T> *p = head;
    int index = 0;
    while(index != position) {
      p = p->next;
      index++;
    }
    if (p != nullptr)
      p->data = newValue;
  }
}


#endif  // _DOUBLELINKEDLIST_H_