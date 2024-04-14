using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

public class LinkedQueue<T>
{
  private class Node
  {
    public T item;
    public Node next;
  }

  private Node rearPtr;
  private Node frontPtr;
  int length;

  public LinkedQueue()
  {
    rearPtr = null;
    frontPtr = null;
    length = 0;
  }

  public bool IsEmpty()
  {
    return (length == 0);
  }

  public void Enqueue(T newItem)
  {
    Node newNode = new();
    newNode.item = newItem;
    if (IsEmpty())
    {
      rearPtr = newNode;
      frontPtr = newNode;
    }
    else
    {
      rearPtr.next = newNode;
      rearPtr = newNode;
    }
    length++;
  }

  public void Dequeue()
  {
    if (IsEmpty())
    {
      Console.WriteLine("Queue empty, cannot delete");
      return;
    }
    else
    {
      Node temp = frontPtr;
      frontPtr = frontPtr.next;
      if (rearPtr == frontPtr)
      {
        rearPtr = frontPtr = null;
      }
      length--;
    }
  }

  public T Dequeue(out T deleteItem)
  {
    if (IsEmpty())
    {
      Console.WriteLine("Queue empty, cannot delete");
      deleteItem = default(T);
      return deleteItem;
    }
    else
    {
      deleteItem = frontPtr.item;
      Node temp = frontPtr;
      frontPtr = frontPtr.next;
      if (rearPtr == frontPtr)
      {
        rearPtr = frontPtr = null;
      }
      length--;
      return deleteItem;
    }
  }

  public T GetFront()
  {
    if (!IsEmpty())
    {
      return frontPtr.item;
    }
    else
    {
      throw new InvalidOperationException("Queue is empty");
    }
  }

  public T GetRear()
  {
    if (!IsEmpty())
    {
      return rearPtr.item;
    }
    else
    {
      throw new InvalidOperationException("Queue is empty");
    }
  }

  public void ClearQueue()
  {
    frontPtr = null;
    rearPtr = null;
    length = 0;
  }

  public void Display()
  {
    Node currPtr = frontPtr;
    Console.Write("Queue items : [ ");
    while (currPtr != null)
    {
      Console.Write(currPtr.item + " ");
      currPtr = currPtr.next;
    }
    Console.WriteLine("]");
  }

  public int GetSize()
  {
    return length;
  }
}
