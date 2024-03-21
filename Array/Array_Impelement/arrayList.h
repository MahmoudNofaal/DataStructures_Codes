#pragma once
#include <array>
#include <iostream>
using namespace std;

class arrayList
{
private:
  int* arr;
  int maxSize;
  int length;

public:
  arrayList(int size)
  {
    maxSize = size;
    if (maxSize < 0)
    {
      maxSize *= -1;
    }
    arr = new int[maxSize];
    length = 0;
  }

  bool isEmpty();

  bool isFull();

  void insertAtPos(int pos, int element);

  void insertAtEnd(int element);

  int search(int element);

  void insertNoDuplicate(int element);

  void updateAt(int pos, int element);

  void removeAtPos(int pos);

  void removeElement(int element);

  int getElement(int pos);

  int getSize();

  void display();

  void clear();

  ~arrayList()
  {
    delete[] arr;
  }
};


bool arrayList::isEmpty()
{
  return length == 0;
}

bool arrayList::isFull()
{
  return length == maxSize;
}

void arrayList::insertAtPos(int pos, int element)
{

  if (isFull())
  {
    cout << "Array is full\n";
  }
  else if (pos < 0 || pos > length)
  {
    cout << "Out of range\n";
  }
  else
  {
    length++;
    for (int i = length; i > pos; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[pos] = element;
  }
}

void arrayList::insertAtEnd(int element)
{

  if (isFull())
  {
    cout << "Array is full\n";
  }
  else
  {
    arr[length] = element;
    length++;
  }
}

int arrayList::search(int element)
{

  int pos = -1;
  for (int i = 0; i < length; i++)
  {
    if (arr[i] == element)
    {
      pos = i;
      break;
    }
  }
  return pos;
}


void arrayList::insertNoDuplicate(int element)
{

  if (search(element) == -1)
  {
    insertAtEnd(element);
  }
  else
  {
    cout << "Element is exist already\n";
  }
}

void arrayList::updateAt(int pos, int element)
{

  if (pos < 0 || pos > length)
  {
    cout << "Out of range\n";
  }
  else
  {
    arr[pos] = element;
  }
}


void arrayList::removeAtPos(int pos)
{

  if (isEmpty())
  {
    cout << "Array is empty\n";
  }
  else if (pos < 0 || pos > length)
  {
    cout << "Out of range\n";
  }
  else
  {
    for (int i = pos; i < length - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    length--;
  }
}

void arrayList::removeElement(int element)
{

  int pos = search(element);
  if (pos != -1)
  {
    removeAtPos(pos);
  }
  else
  {
    cout << "Element not found\n";
  }
}

int arrayList::getElement(int pos)
{

  if (isEmpty())
  {
    cout << "Array is empty\n";
  }
  else if (pos < 0 || pos > length)
  {
    cout << "Out of range\n";
  }
  else
  {
    return arr[pos];
  }
}

int arrayList::getSize()
{
  return length;
}


void arrayList::display()
{
  cout << "Array items: [ ";
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "]\n";
}

void arrayList::clear()
{
  length = 0;
}