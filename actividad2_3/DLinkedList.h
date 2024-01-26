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
    DLLNode<T>* partition(DLLNode<T>* l, DLLNode<T>* h);
    void _quickSort(DLLNode<T>* l, DLLNode<T>* h);
    DLLNode<T>* middle(DLLNode<T>* start, DLLNode<T>* last);
    DLLNode<T>* binarySearch(DLLNode<T>* start, T value);
    DLLNode<T> *merge(DLLNode<T>*first, DLLNode<T>*second);
    DLLNode<T> *mergeSort (DLLNode<T>* head);
    DLLNode<T> *split(DLLNode<T>* head);


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
    DLinkedList<T>*getReversedSublist(int start, int end);
    void invert();
    void quickSort();
    void callMerge();
    DLLNode<T> *binarySearch(T value);
    DLLNode<T> *getHead();
};


//Constructor
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
DLLNode<T> *DLinkedList<T>::getHead(){
  return head;
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



/*
Descrpcion de getReversedSublist:
Regresa una nueva sublista que comprende los elementos, en orden inverso, que se ubican entre las posiciones inicio y fin de la lista (se incluyen los extremos del intervalo, i.e., inicio y fin).
*/
// Complejidad O(n)
template <class T>
DLinkedList<T>* DLinkedList<T>::getReversedSublist(int start, int end)
{
  //Verificar que el rango sea valido
  if (start <0 || end >= numElements || start > end)
  {
    throw std::out_of_range("Rango invalido");
    return nullptr;
  }
  else
  {
    //1. Crear una nueva lista
    DLinkedList<T>* newList = new DLinkedList<T>();
    DLLNode<T>* p = head;
    int index = 0;
    while (p != nullptr && index <= end)
    {
      if (index >= start)
        newList->addFirst(p->data);
      p = p->next;
      index++;
    }
      return newList;
  } 
}



// Complejidad O(n)
template<typename T>
DLLNode<T>* DLinkedList<T>::partition(DLLNode<T>* l, DLLNode<T>* h) {
    T x = h->data;
    DLLNode<T>* i = l->prev;
    DLLNode<T> *j = nullptr;
    for (j = l; j != h; j = j->next) {
        if (j->data <= x) {
            i = (i == nullptr) ? l : i->next;
            std::swap(i->data, j->data);
        }
    }
    i = (i == nullptr) ? l : i->next;
    std::swap(i->data, h->data);
    return i;
}

//Quick sort Complejidad O(n^2)
template<typename T>
void DLinkedList<T>::_quickSort(DLLNode<T>* l, DLLNode<T>* h)
{
    if (h != nullptr && l != h && l != h->next) {
        DLLNode<T>* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

// Cambia la función principal quickSort
template <class T>
void DLinkedList<T>::quickSort() {
    _quickSort(head, tail);
}



// Complejidad O(n)
template <class T>
void DLinkedList<T>::invert(){
  //Si la lista está vacía o tiene solo un elemento, no es necesario hacer nada
  if (head == nullptr || tail == nullptr){
    return;
  }
  DLLNode<T> *current = head;
  DLLNode<T> *temp = nullptr;
  // Recorre la lista e intercambia los punteros next y prev de cada nodo
  while (current != nullptr){
    temp = current->next;
    current->next = current->prev;
    current->prev = temp;
    // Avanza al siguiente nodo (que era el previo)
    current = temp;
  }
  // Intercambia head y tail
  temp = head;
  head = tail;
  tail = temp;
}

//Binary Search Complejidad O(log n)
template <class T>
DLLNode<T>* DLinkedList<T>::middle(DLLNode<T>* start, DLLNode<T>* last) {
    if (start == nullptr)
        return nullptr;

    DLLNode<T>* slow = start;
    DLLNode<T>* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

template <class T>
DLLNode<T>* DLinkedList<T>::binarySearch(DLLNode<T>* start, T value) {
    DLLNode<T>* last = nullptr;

    do {
        DLLNode<T>* mid = middle(start, last);
        if (mid == nullptr)
            return nullptr;

        if (mid->data == value)
            return mid;
        else if (mid->data < value)
            start = mid->next;
        else
            last = mid;

    } while (last == nullptr || last != start);

    return nullptr;
}

//Mergesort complejidad O(n log n)
template <class T>
DLLNode<T>* DLinkedList<T>::merge(DLLNode<T>*first, DLLNode<T>*second) {
  if (!first)
    return second;

  if (!second)
    return first;
  
  if (first->data < second->data){
    first->next = merge(first->next,second);
    first->next->prev = first;
    first->prev = NULL;
    return first;
  }


  else {
    second->next = merge(first, second->next);
    second->next->prev = second;
    second->prev = NULL;
    return second;
  }
}

template <class T>
DLLNode<T>* DLinkedList<T>::mergeSort (DLLNode<T>* head) {
  if (!head || !head->next)
    return head;
  DLLNode<T>*second = split(head);
  
  head = mergeSort (head);
  second = mergeSort(second);
  return merge(head, second);
}


template <class T>
DLLNode<T>* DLinkedList<T>::split(DLLNode<T> *head) 
{ 
    DLLNode<T> *fast = head,*slow = head; 
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    DLLNode<T> *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
} 


template<class T>
void DLinkedList<T>::callMerge( ){
  std::cout<< "Ordenar por MergeSort";
  head = mergeSort(head);
  DLLNode<T> *p, *q;
  p = head;
  q = nullptr;
  while (p != nullptr) {
    q = p->next;
    p = q;
  }
  tail = q;
     
}


#endif  // _DOUBLELINKEDLIST_H_