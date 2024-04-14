using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

public class LinkedList<T>
{
  private class Node
  {
    public T item;
    public Node next;
  }

  Node firstPtr;
  Node lastPtr;
  int length;

  public LinkedList()
  {
    firstPtr = lastPtr = null;
    length = 0;
  }


  public bool isEmpty()
  {
    return length == 0;
  }


  public void insertFirst(T newItem)
  {
    Node newNode = new();
    newNode.item = newItem;

    if (length == 0)
    {
      newNode.next = null;
      firstPtr = lastPtr = newNode;
    }
    else
    {
      newNode.next = firstPtr;
      firstPtr = newNode;
    }
    length++;
  }


  public void insertLast(T newItem)
  {
    Node newNode = new();
    newNode.item = newItem;
    newNode.next = null;

    if (length == 0)
    {
      firstPtr = lastPtr = newNode;
    }
    else
    {
      lastPtr.next = newNode;
      lastPtr = newNode;
    }
    length++;
  }


  public void insertAtPos(int pos, T newItem)
  {
    if (pos < 0 || pos > length)
    {
      Console.WriteLine("Out of range");
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
      Node newNode = new();
      newNode.item = newItem;

      Node currPtr = firstPtr;
      for(int i=1; i<pos; i++)
      {
        currPtr = currPtr.next;
      }
      newNode.next = currPtr.next;
      currPtr.next = newNode;
      length++;
    }
  }


  public void removeFirst()
  {
    if(isEmpty())
    {
      Console.WriteLine("Empty list cannot remove..");
      return;
    }
    else if(length == 1)
    {
      firstPtr = lastPtr = null;
      length--;
    }
    else
    {
      firstPtr = firstPtr.next;
      length--;
    }
  }


  public void removeLast()
  {
    if (isEmpty())
    {
      Console.WriteLine("Empty list cannot remove..");
      return;
    }
    else if (length == 1)
    {
      firstPtr = lastPtr = null;
      length--;
    }
    else
    {
      Node prevPtr = firstPtr;
      Node nextPtr = firstPtr.next;

      while(nextPtr != lastPtr)
      {
        prevPtr = nextPtr;
        nextPtr = nextPtr.next;
      }
      prevPtr.next = null;
      lastPtr = prevPtr;
      length--;
    }
  }


  public void removeElement(T element)
  {
    if (isEmpty())
    {
      Console.WriteLine("Empty list cannot remove..");
      return;
    }
    else
    {
      Node prevPtr, nextPtr;
      if(firstPtr.item.Equals(element))
      {
        nextPtr = firstPtr;
        firstPtr = firstPtr.next;
        length--;
        if(length==0)
        {
          lastPtr = null;
        }
      }
      else
      {
        prevPtr = firstPtr;
        nextPtr = firstPtr.next;
        while (nextPtr != null)
        {
          if (nextPtr.item.Equals(element))
          {
            break;
          }
          prevPtr = nextPtr;
          nextPtr = nextPtr.next;
        }
        if (nextPtr == null)
        {
          Console.WriteLine("Element not found");
        }
        else
        {
          prevPtr.next = nextPtr.next;
          if (lastPtr == firstPtr)
          {
            lastPtr = prevPtr;
          } 
          length--;
        }
      }
    }
  }


  public int search(T element)
  {
    Node currPtr = firstPtr;
    int pos = -1;
    while(currPtr!=null)
    {
      pos++;
      if(currPtr.item.Equals(element))
      {
        return pos;
      }
      currPtr = currPtr.next;
    }
    return pos;
  }


  public void reverse()
  {
    Node prevPtr, nextPtr, currPtr;
    prevPtr = null;
    currPtr = firstPtr;
    nextPtr = currPtr.next;

    while(nextPtr != null)
    {
      nextPtr = currPtr.next;
      currPtr.next = prevPtr;
      prevPtr = currPtr;
      currPtr = nextPtr;
    }
    firstPtr = prevPtr;
  }


  public T getFirst()
  { return firstPtr.item; }

  public T getLast()
  { return lastPtr.item; }


  public int getSize()
  { return length; }


  public void Display()
  {
    Node currPtr = firstPtr;
    Console.Write("[ ");
    while (currPtr != null)
    {
      Console.Write(currPtr.item + " ");
      currPtr = currPtr.next;
    }
    Console.WriteLine("]");
  }


  public void clear()
  {
    Node currPtr;
    while (firstPtr != null)
    {
      currPtr = firstPtr;
      firstPtr = firstPtr.next;
    }
    lastPtr = null;
    length = 0;
  }
}
