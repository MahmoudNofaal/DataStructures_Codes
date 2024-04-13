#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

template<class t>
class stackArray
{
private:
  int top;
  t items[MAX_SIZE];

public:
  stackArray();

  void push(t newItem);

  bool isEmpty();

  void pop();

  t pop(t& popItem);

  t getTop(t& topItem);

  void print();

};


template <class T>
stackArray<T>::stackArray()
{
  top = -1;
}

template <class T>
void stackArray<T>::push(T newItem)
{
  if (top >= MAX_SIZE)
  {
    cout << "Stack is full on push\n";
  }
  else
  {
    top++;
    items[top] = newItem;
  }
}

template <class T>
bool stackArray<T>::isEmpty()
{
  return top == -1;
}

template <class T>
void stackArray<T>::pop()
{
  if (isEmpty())
  {
    cout << "Stack is empty on pop\n";
  }
  else
  {
    top--;
  }
}

template <class T>
T stackArray<T>::pop(T& popItem)
{
  if (isEmpty())
  {
    cout << "Stack is empty on pop\n";
  }
  else
  {
    popItem = items[top];
    top--;
    return popItem;
  }
}

template <class T>
T stackArray<T>::getTop(T& topItem)
{
  if (isEmpty())
  {
    cout << "Stack is empty on getTop\n";
  }
  else
  {
    topItem = items[top];
    return topItem;
  }
}

template <class T>
void stackArray<T>::print()
{
  cout << "[ ";
  while (top != -1)
  {
    cout << items[top] << ' ';
    top--;
  }
  cout << "]\n";
}