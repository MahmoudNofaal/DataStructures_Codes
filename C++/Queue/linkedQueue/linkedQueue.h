#pragma once

#include <cassert>
#include <iostream>
using namespace std;

template <class T>

class linkedQueue
{
private:
  struct node
  {
    T item;
    node* next;
  };
  node* rearPtr;
  node* frontPtr;
  int length;

public:
  linkedQueue();

  bool isEmpty();

  void enqueue(T newItem);

  void dequeue();

  T dequeue(T& deleteItem);

  T getFront();

  T getRear();

  void clearQueue();

  void display();

  int getSize();

};


template <class T>
bool linkedQueue<T>::isEmpty()
{
  return length == 0;
}

template <class T>
void linkedQueue<T>::enqueue(T newItem)
{
  node* newItemPtr = new node;
  newItemPtr->item = newItem;
  newItemPtr->next = NULL;
  if (length == 0) {
    rearPtr = newItemPtr;
    frontPtr = newItemPtr;
  }
  else {
    rearPtr->next = newItemPtr;
    rearPtr = newItemPtr;
  }
  length++;
}

template <class T>
void linkedQueue<T>::dequeue()
{
  if (isEmpty()) {
    cout << "Queue empty cannot delete\n";
  }
  else {
    node* temp = frontPtr;
    frontPtr = frontPtr->next;
    if (rearPtr == frontPtr) {
      rearPtr = frontPtr = NULL;
    }
    length--;
    delete temp;
  }
}

template <class T>
T linkedQueue<T>::dequeue(T& deleteItem)
{
  if (isEmpty()) {
    cout << "Queue empty cannot delete\n";
  }
  else {
    deleteItem = frontPtr->item;
    node* temp = frontPtr;
    frontPtr = frontPtr->next;
    if (rearPtr == frontPtr) {
      rearPtr = frontPtr = NULL;
    }
    length--;
    return deleteItem;
  }
  return deleteItem;
}

template <class T>
T linkedQueue<T>::getFront()
{
  assert(!isEmpty());
  return frontPtr->item;
}

template <class T>
T linkedQueue<T>::getRear()
{
  assert(!isEmpty());
  return rearPtr->item;
}

template <class T>
void linkedQueue<T>::clearQueue()
{
  while (frontPtr != NULL) {
    node* currPtr = frontPtr;
    frontPtr = frontPtr->next;
    delete currPtr;
  }
  rearPtr = NULL;
  length = 0;
}

template <class T>
void linkedQueue<T>::display()
{
  node* currPtr = frontPtr;
  cout << "Queue items : [ ";
  while (currPtr != NULL) {
    cout << currPtr->item << " ";
    currPtr = currPtr->next;
  }
  cout << "]\n";
}

template <class T>
int linkedQueue<T>::getSize()
{
  return length;
}
