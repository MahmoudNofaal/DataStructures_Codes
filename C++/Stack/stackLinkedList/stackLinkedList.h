#pragma once

#include <iostream>

using namespace std;


template <class T>
class stackLinkedList
{
private:
  struct node
  {
    T item;
    node* next;
  };
  node* stackTop;
  node* stackCurr;

public:
  stackLinkedList();

  void push(T newItem);

  bool isEmpty();

  void pop();

  T pop(T& popItem);

  T getTop(T& topItem);

  void display();

};

template <class T>
stackLinkedList<T>::stackLinkedList()
{
  stackTop = NULL;
}

template <class T>
void stackLinkedList<T>::push(T newItem)
{
  node* newItemPtr = new node;
  if (newItemPtr == NULL)
  {
    cout << "Stack cannot allocate memory\n";
  }
  else
  {
    newItemPtr->item = newItem;
    newItemPtr->next = stackTop;
    stackTop = newItemPtr;
  }
}

template <class T>
bool stackLinkedList<T>::isEmpty()
{
  return stackTop == NULL;
}

template <class T>
void stackLinkedList<T>::pop()
{
  if (isEmpty())
  {
    cout << "Stack is empty on pop\n";
  }
  else
  {
    node* temp = new node;
    temp = stackTop;
    stackTop = stackTop->next;
    temp->next = NULL;
    delete temp;
  }
}

template <class T>
T stackLinkedList<T>::pop(T& popItem)
{
  if (isEmpty())
  {
    cout << "Stack is empty on popItem\n";
  }
  else
  {
    popItem = stackTop->item;
    node* temp = new node;
    temp = stackTop;
    stackTop = stackTop->next;
    temp->next = NULL;
    delete temp;
    return popItem;
  }
}

template <class T>
T stackLinkedList<T>::getTop(T& topItem)
{
  if (isEmpty())
  {
    cout << "Stack is empty on getTop\n";
  }
  else
  {
    topItem = stackTop->item;
    return topItem;
  }
}

template <class T>
void stackLinkedList<T>::display()
{
  stackCurr = stackTop;
  cout << "[ ";
  while (stackCurr != NULL)
  {
    cout << stackCurr->item << ' ';
    stackCurr = stackCurr->next;
  }
  cout << "]\n";
}