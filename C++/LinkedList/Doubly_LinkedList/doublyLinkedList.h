#pragma once


#include <iostream>

using namespace std;



template<class t>
struct Node
{
  int item;
  Node<t>* prev;
  Node<t>* next;
};



template<class t>
class doublyLinkedList
{
private:
  Node<t>* first;
  Node<t>* last;
  int count;
public:
  doublyLinkedList();

  bool isEmpty();

  void insertFirst(t newItem);

  void insertLast(t newItem);

  void insertAtPos(int pos, t newItem);

  void removeFirst();

  void removeLast();

  void removeElement(t element);

  int search(t item);

  void reverse();

  int getSize();

  void display();

  void destroy();

  void clear();

  ~doublyLinkedList();

};



template<class t>
doublyLinkedList<t>::doublyLinkedList()
{
  first = NULL;
  last = NULL;
  count = 0;
}



template<class t>
bool doublyLinkedList<t>::isEmpty()
{
  return count == 0;
}



template<class t>
void doublyLinkedList<t>::insertFirst(t newItem)
{
  Node<t>* newNode = new Node<t>;
  newNode->item = newItem;
  if (count == 0)
  {
    newNode->prev = NULL;
    newNode->next = NULL;
    first = last = newNode;
  }
  else
  {
    newNode->prev = NULL;
    newNode->next = first;
    first->prev = newNode;
    first = newNode;
  }
  count++;
}



template<class t>
void doublyLinkedList<t>::insertLast(t newItem)
{
  Node<t>* newNode = new Node<t>;
  newNode->item = newItem;

  if (count == 0)
  {
      newNode->prev = NULL;
      newNode->next = NULL;
      first = last = newNode;
  }
  else
  {
    newNode->next = NULL;
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
  }
  count++;
}



template<class t>
void doublyLinkedList<t>::insertAtPos(int pos, t newItem)
{
  if (pos<0 || pos>count)
  {
    cout << "Out of range\n";
  }
  else if (pos == 0)
  {
    insertFirst(newItem);
  }
  else if (pos == count)
  {
    insertLast(newItem);
  }
  else
  {
    Node<t>* newNode = new Node<t>;
    newNode->item = newItem;

    Node<t>* curr = first;
    for (int i = 1; i < pos; i++)
    {
      curr=curr->next;
    }
    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;
    curr->next->prev = newNode;
    count++;
  }
}



template<class t>
void doublyLinkedList<t>::removeFirst()
{
  if (isEmpty())
  {
    cout << "Empty doubly list cannot remove..\n";
  }
  else if (count == 1)
  {
    delete first;
    first = last = NULL;
    count--;
  }
  else
  {
    Node<t>* curr = first;
    first = first->next;
    first->prev = NULL;
    delete curr;
    count--;
  }
}



template<class t>
void doublyLinkedList<t>::removeLast()
{
  if (isEmpty())
  {
    cout << "Empty doubly list cannot remove..\n";
  }
  else if (count == 1)
  {
    delete first;
    first = last = NULL;
    count--;
  }
  else
  {
    Node<t>* curr = last;
    last = last->prev;
    last->next = NULL;
    delete curr;
    count--;
  }
}



template<class t>
void doublyLinkedList<t>::removeElement(t element)
{
  if (isEmpty())
  {
    cout << "Empty doubly list cannot remove..\n";
  }
  else if (first->item == element)
  {
    removeFirst();
  }
  else if (last->item == element)
  {
    removeLast();
  }
  else
  {
    Node<t>* curr = first->next;
    while (curr != last)
    {
      if (curr->item == element)
      {
        break;
      }
      curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    count--;
  }
}



template<class t>
int doublyLinkedList<t>::search(t item)
{
  int pos = -1;
  Node<t>* curr = first;
  while (curr != NULL)
  {
    pos++;
    if (curr->item == item)
    {
      return pos;
    }
    curr = curr->next;
  }
  return pos;
}




template<class t>
void doublyLinkedList<t>::reverse()
{
  if (isEmpty() || first == last)
  {
    return;
  }

  Node<t>* curr = first;
  Node<t>* prevNode = NULL;
  while (curr != NULL)
  {
    Node<t>* nextNode = curr->next;
    curr->next = prevNode;
    curr->prev = nextNode;
    prevNode = curr;
    curr = nextNode;
  }
  last = first;
  first = prevNode;
}




template<class t>
int doublyLinkedList<t>::getSize()
{
  return count;
}




template<class t>
void doublyLinkedList<t>::display()
{
  Node<t>* curr = first;
  cout << "[ ";
  while (curr != NULL)
  {
    cout << curr->item << " ";
    curr = curr->next;
  }
  cout << "]\n";
}



template<class t>
void doublyLinkedList<t>::destroy()
{
  Node<t>* temp;
  while (first != NULL)
  {
    temp = first;
    first = first->next;
    delete temp;
  }
  last = NULL;
  count = 0;
}



template<class t>
void doublyLinkedList<t>::clear()
{
  destroy();
}




template<class t>
doublyLinkedList<t>::~doublyLinkedList()
{
  destroy();
}

