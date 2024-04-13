#pragma once

#include <cassert>
#include <iostream>
using namespace std;


template <class T>

class arrayQueue
{
private:
  int rear;
  int front;
  T* items;
  int count;
  int maxSize;

public:
  arrayQueue(int size);

  bool isEmpty();

  bool isFull();

  void addQueue(T newItem);

  void deleteQueue();

  T deleteQueue(T& deleteItem);

  T rearQueue();

  T frontQueue();

  int searchQueue(T searchItem);

  void printQueue();

};

template <class T>
arrayQueue<T>::arrayQueue(int size)
{
  maxSize = (size < 0) ? -size : size;
  items = new T[maxSize];
  rear = maxSize - 1;
  front = 0;
  count = 0;
}

template <class T>
bool arrayQueue<T>::isEmpty()
{
  return count == 0;
}

template <class T>
bool arrayQueue<T>::isFull()
{
  return count == maxSize;
}

template <class T>
void arrayQueue<T>::addQueue(T newItem)
{
  if (isFull())
  {
    cout << "Queue full cannot enqueue\n";
  }
  else
  {
    rear = (rear + 1) % maxSize;
    items[rear] = newItem;
    count++;
  }
}

template <class T>
void arrayQueue<T>::deleteQueue()
{
  if (isEmpty())
  {
    cout << "Queue empty cannot delete\n";
  }
  else
  {
    front = (front + 1) % maxSize;
    count--;
  }
}

template <class T>
T arrayQueue<T>::deleteQueue(T& deleteItem)
{
  if (isEmpty())
  {
    cout << "Queue empty cannot delete\n";
  }
  else
  {
    deleteItem = items[front];
    front = (front + 1) % maxSize;
    count--;
    return deleteItem;
  }
}

template <class T>
T arrayQueue<T>::rearQueue()
{
  assert(!isEmpty());
  return items[rear];
}

template <class T>
T arrayQueue<T>::frontQueue()
{
  assert(!isEmpty());
  return items[front];
}

template <class T>
int arrayQueue<T>::searchQueue(T searchItem)
{
  int pos = -1;
  if (!isEmpty())
  {
    for (int i = front - 1; i != rear; i = (i + 1) % maxSize)
    {
      if (items[i + 1] == searchItem)
      {
        pos = i + 1;
        break;
      }
    }
    if (items[rear] == searchItem)
    {
      pos = rear;
    }
  }
  return pos;
}

template <class T>
void arrayQueue<T>::printQueue()
{
  cout << "Queue items: [ ";
  for (int i = front - 1; i != rear; i = (i + 1) % maxSize)
  {
    cout << items[i + 1] << " ";
  }
  cout << "]\n";
}