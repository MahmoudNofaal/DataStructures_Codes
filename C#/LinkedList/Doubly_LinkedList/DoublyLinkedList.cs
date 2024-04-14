using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

internal class DoublyLinkedList<T>
{
  private class Node
  {
    public T item;
    public Node prev;
    public Node next;
  }

  private Node firstPtr;
  private Node lastPtr;
  private int count;

  public DoublyLinkedList()
  {
    firstPtr = lastPtr = null;
    count = 0;
  }

  public bool isEmpty()
  {
    return count == 0;
  }

  public void insertFirst(T newItem)
  {
    Node newNode = new();
    newNode.item = newItem;
    if (isEmpty())
    {
      firstPtr = lastPtr = newNode;
    }
    else
    {
      newNode.next = firstPtr;
      firstPtr.prev = newNode;
      firstPtr = newNode;
    }
    count++;
  }

  public void insertLast(T newItem)
  {
    Node newNode = new();
    newNode.item = newItem;
    if (isEmpty())
    {
      firstPtr = lastPtr = newNode;
    }
    else
    {
      newNode.prev = lastPtr;
      lastPtr.next = newNode;
      lastPtr = newNode;
    }
    count++;
  }

  public void insertAtPos(int pos, T newItem)
  {
    if (pos < 0 || pos > count)
    {
      Console.WriteLine("Out of range");
      return;
    }
    if (pos == 0)
    {
      insertFirst(newItem);
    }
    else if (pos == count)
    {
      insertLast(newItem);
    }
    else
    {
      Node newNode = new();
      newNode.item = newItem;
      Node curr = firstPtr;
      for (int i = 1; i < pos; i++)
      {
        curr = curr.next;
      }
      newNode.prev = curr;
      newNode.next = curr.next;
      curr.next.prev = newNode;
      curr.next = newNode;
      count++;
    }
  }

  public void removeFirst()
  {
    if (isEmpty())
    {
      Console.WriteLine("Empty doubly list cannot remove");
      return;
    }
    if (count == 1)
    {
      firstPtr = lastPtr = null;
    }
    else
    {
      firstPtr = firstPtr.next;
      firstPtr.prev = null;
    }
    count--;
  }

  public void removeLast()
  {
    if (isEmpty())
    {
      Console.WriteLine("Empty doubly list cannot remove");
      return;
    }
    if (count == 1)
    {
      firstPtr = lastPtr = null;
    }
    else
    {
      lastPtr = lastPtr.prev;
      lastPtr.next = null;
    }
    count--;
  }

  public void removeElement(T element)
  {
    if (isEmpty())
    {
      Console.WriteLine("Empty doubly list cannot remove");
      return;
    }
    if (firstPtr.item.Equals(element))
    {
      removeFirst();
    }
    else if (lastPtr.item.Equals(element))
    {
      removeLast();
    }
    else
    {
      Node curr = firstPtr.next;
      while (curr != lastPtr)
      {
        if (curr.item.Equals(element))
        {
          curr.prev.next = curr.next;
          curr.next.prev = curr.prev;
          count--;
          return;
        }
        curr = curr.next;
      }
      Console.WriteLine("Element not found");
    }
  }

  public int search(T item)
  {
    int pos = -1;
    Node curr = firstPtr;
    while (curr != null)
    {
      pos++;
      if (curr.item.Equals(item))
      {
        return pos;
      }
      curr = curr.next;
    }
    return -1;
  }

  public void reverse()
  {
    if (isEmpty() || firstPtr == lastPtr)
    {
      return;
    }

    Node curr = firstPtr;
    Node prevNode = null;
    while (curr != null)
    {
      Node nextNode = curr.next;
      curr.next = prevNode;
      curr.prev = nextNode;
      prevNode = curr;
      curr = nextNode;
    }
    lastPtr = firstPtr;
    firstPtr = prevNode;
  }

  public int getSize()
  {
    return count;
  }

  public void Display()
  {
    Node curr = firstPtr;
    Console.Write("[ ");
    while (curr != null)
    {
      Console.Write(curr.item + " ");
      curr = curr.next;
    }
    Console.WriteLine("]");
  }

  public void clear()
  {
    firstPtr = null;
    lastPtr = null;
    count = 0;
  }

  ~DoublyLinkedList()
  {
    clear();
  }
}

