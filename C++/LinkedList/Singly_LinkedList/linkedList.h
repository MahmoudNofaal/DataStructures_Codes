#pragma once

#include <iostream>

using namespace std;


template<class t>
struct node
{
  t item;
  node* next;
};


template<class t>
class linkedList
{
private:
  node<t>* firstPtr;
  node<t>* lastPtr;
  int length;
public:
  linkedList();

  bool isEmpty();

  void insertFirst(t newItem);

  void insertLast(t newItem);

  void insertAtPos(int pos, t newItem);

  void removeFirst();

  void removeLast();

  void removeElement(t element);

  int search(t element);

  void reverse();

  t getFirst();

  t getLast();

  int getSize();

  void display();

  void clear();

  ~linkedList();

};


template<class t>
linkedList<t>::linkedList()
{
  firstPtr = lastPtr = NULL;
  length = 0;
}

template<class t>
bool linkedList<t>::isEmpty()
{
  return length == 0;
}

template<class t>
void linkedList<t>::insertFirst(t newItem)
{
  node<t>* newNode = new node<t>;
  newNode->item = newItem;
  if (length == 0)
  {
    newNode->next = NULL;
    firstPtr = lastPtr = newNode;
  }
  else
  {
    newNode->next = firstPtr;
    firstPtr = newNode;
  }
  length++;
}

template<class t>
void linkedList<t>::insertLast(t newItem)
{
  node<t>* newNode = new node<t>;
  newNode->item = newItem;
  newNode->next = NULL;
  if (length == 0)
  {
    firstPtr = lastPtr = newNode;
  }
  else
  {
    lastPtr->next = newNode;
    lastPtr = newNode;
  }
  length++;
}


template<class t>
void linkedList<t>::insertAtPos(int pos, t newItem)
{
  if (pos<0 || pos>length)
  {
    cout << "Out of range\n";
  }
  else if (pos == 0)
  {
    insertFirst(newItem);
  }
  else if (pos == length)
  {
    insertLast(newItem);
  }
  else
  {
    node<t>* newNode = new node<t>;
    newNode->item = newItem;

    node<t>* currPtr = firstPtr;
    for (int i = 1; i < pos; i++)
    {
      currPtr = currPtr->next;
    }
    newNode->next = currPtr->next;
    currPtr->next = newNode;
    length++;
  }
}


template<class t>
void linkedList<t>::removeFirst()
{
  if (isEmpty())
  {
    cout << "Empty list cannot remove..\n";
  }
  else if (length == 1)
  {
    delete firstPtr;
    firstPtr = lastPtr = NULL;
    length--;
  }
  else
  {
    node<t>* currPtr = firstPtr;
    firstPtr = firstPtr->next;
    delete currPtr;
    length--;
  }
}


template<class t>
void linkedList<t>::removeLast()
{
  if (isEmpty())
  {
    cout << "Empty list cannot remove..\n";
  }
  else if (length == 1)
  {
    delete lastPtr;
    firstPtr = lastPtr = NULL;
    length--;
  }
  else
  {
    node<t>* prevPtr = firstPtr;
    node<t>* nextPtr = firstPtr->next;
    while (nextPtr != lastPtr)
    {
      prevPtr = nextPtr;
      nextPtr = nextPtr->next;
    }
    prevPtr->next = NULL;
    lastPtr = prevPtr;
    delete nextPtr;
    length--;
  }
}


template<class t>
void linkedList<t>::removeElement(t element)
{
  if (isEmpty())
  {
    cout << "Empty list cannot remove..\n";
  }
  else
  {
    node<t>* prevPtr, * nextPtr;
    if (firstPtr->item == element)
    {
      nextPtr = firstPtr;
      firstPtr = firstPtr->next;
      delete nextPtr;
      length--;
      if (length == 0)
      {
        lastPtr = NULL;
      }
    }
    else
    {
      prevPtr = firstPtr;
      nextPtr = firstPtr->next;
      while (nextPtr != NULL)
      {
        if (nextPtr->item == element)
        {
          break;
        }
        prevPtr = nextPtr;
        nextPtr = nextPtr->next;
      }
      if (nextPtr == NULL)
      {
        cout << "Element not found\n";
      }
      else
      {
        prevPtr->next = nextPtr->next;
        if (lastPtr == firstPtr)
        {
          lastPtr = prevPtr;
        }
        delete nextPtr;
        length--;
      }
    }
  }
}


template<class t>
int linkedList<t>::search(t element)
{
  node<t>* currPtr = firstPtr;
  int pos = -1;
  while (currPtr != NULL)
  {
    pos++;
    if (currPtr->item == element)
    {
      return pos;
    }
    currPtr = currPtr->next;
  }
  return pos;
}


template<class t>
void linkedList<t>::reverse()
{
  node<t>* prevPtr, * nextPtr, * currPtr;
  prevPtr = NULL;
  currPtr = firstPtr;
  nextPtr = currPtr->next;
  while (nextPtr != NULL)
  {
    nextPtr = currPtr->next;
    currPtr->next = prevPtr;
    prevPtr = currPtr;
    currPtr = nextPtr;
  }
  firstPtr = prevPtr;
}

template<class t>
t linkedList<t>::getFirst()
{
  return firstPtr->item;
}

template<class t>
t linkedList<t>::getLast()
{
  return lastPtr->item;
}



template<class t>
int linkedList<t>::getSize()
{
  return length;
}



template<class t>
void linkedList<t>::display()
{
  node<t>* currPtr = firstPtr;
  cout << "[ ";
  while (currPtr != NULL)
  {
    cout << currPtr->item << " ";
    currPtr = currPtr->next;
  }
  cout << "]\n";
}


template<class t>
void linkedList<t>::clear()
{
  node<t>* currPtr;
  while (firstPtr != NULL)
  {
    currPtr = firstPtr;
    firstPtr = firstPtr->next;
    delete currPtr;
  }
  lastPtr = NULL;
  length = 0;
}


template<class t>
linkedList<t>::~linkedList()
{
  clear();
}