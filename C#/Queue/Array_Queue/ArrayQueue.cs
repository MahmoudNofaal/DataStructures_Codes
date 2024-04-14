using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

public class ArrayQueue<T>
{
  private int rear;
  private int front;
  private T[] items;
  private int length;
  private int maxSize;

  public ArrayQueue(int size)
  {
    maxSize = Math.Abs(size);
    items = new T[maxSize];
    rear = maxSize - 1;
    front = 0;
    length = 0;
  }

  public bool isEmpty()
  { return length == 0; }

  public bool isFull()
  { return length == maxSize; }


  public void addQueue(T newItem)
  {
    if (isFull())
    { Console.WriteLine("Queue is full"); }
    else
    {
      rear = (rear + 1) % maxSize;
      items[rear] = newItem;
      length++;
    }
  }

  public void deleteQueue()
  {
    if (isEmpty())
    { Console.WriteLine("Queue is empty"); }
    else
    {
      front = (front + 1) % maxSize;
      length--;
    }
  }


  public T deleteQueue(out T deleteItem)
  {
    if (isEmpty())
    {
      Console.WriteLine("Queue is empty");
      deleteItem = default(T);
      return deleteItem;
    }
    else
    {
      deleteItem = items[front];
      front = (front + 1) % maxSize;
      length--;
      return deleteItem;
    }
  }

  public T rearQueue()
  {
    if (!isEmpty())
    {
      return items[rear];
    }
    else
    {
      throw new InvalidOperationException("Queue is empty");
    }
  }

  public T frontQueue()
  {
    if (!isEmpty())
    {
      return items[front];
    }
    else
    {
      throw new InvalidOperationException("Queue is empty");
    }
  }

  public int searchQueue(T searchItem)
  {
    int pos = -1;
    if (!isEmpty())
    {
      for (int i = front; i != (rear + 1) % maxSize; i = (i + 1) % maxSize)
      {
        if (items[i].Equals(searchItem))
        {
          pos = i;
          break;
        }
      }
    }
    return pos;
  }



  public void printQueue()
  {
    Console.Write("Queue items: [ ");
    for (int i = front; i != (rear + 1) % maxSize; i = (i + 1) % maxSize)
    {
      Console.Write(items[i] + " ");
    }
    Console.WriteLine("]");
  }
}

