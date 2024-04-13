using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

internal class ArrayList
{
  private int[] arr;
  private int maxSize;
  private int length;

  public ArrayList(int size)
  {
    maxSize = Math.Abs(size);
    arr = new int[maxSize];
    length = 0;
  }

  public bool isEmpty()
  { return length == 0; }

  public bool isFull()
  { return length == maxSize; }


  public void insertAtPos(int pos, int element)
  {
    if (isFull())
    { Console.WriteLine("Array is full"); }
    else if (pos < 0 || pos > length)
    { Console.WriteLine("Out of range"); }
    else
    {
      length++;
      for (int i = length; i <= pos; i++)
      {
        arr[i] = arr[i - 1];
      }
      arr[pos] = element;
    }
  }


  public void insertAtEnd(int element)
  {
    if (isFull())
    { Console.WriteLine("Array is full"); }
    else
    {
      arr[length] = element;
      length++;
    }
  }


  public int search(int element)
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


  public void insertNoDuplicate(int element)
  {
    if(search(element) == -1)
    {
      insertAtEnd(element);
    }
    else
    {
      Console.WriteLine("Element is already duplicated");
      return;
    }
  }


  public void updateAt(int pos, int element)
  {
    if(pos < 0 || pos> length)
    { Console.WriteLine("Out of range"); }
    else
    {
      arr[pos] = element;
    }
  }

  public void removeAtPos(int pos)
  {
    if (isEmpty())
    { Console.WriteLine("Array is empty"); }
    else if (pos < 0 || pos >= length)
    { Console.WriteLine("Out of range"); }
    else
    {
      for(int i=pos; i<length; i++)
      {
        arr[i] = arr[i + 1];
      }
      length--;
    }
  }


  public void removeElement(int element)
  {
    int pos = search(element);
    if (pos != -1)
    {
      removeAtPos(pos);
    }
    else
    {
      Console.WriteLine("Element not found");
    }
  }


  public int getElement(int pos)
  {
    if (isEmpty())
    {
      Console.WriteLine("Array is empty");
      return -1;
    }
    else if (pos < 0 || pos >= length)
    {
      Console.WriteLine("Out of range");
      return -1;
    }
    else
    {
      return arr[pos];
    }
  }


  public int getSize()
  {
    return length;
  }


  public void Display()
  {
    Console.Write("Array items: [ ");
    for (int i = 0; i < length; i++)
    {
      Console.Write(arr[i] + " ");
    }
    Console.WriteLine("]");
  }


  public void Clear()
  {
    length = 0;
  }
}

