using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;



public class stackArray<T>
{
  private const int MAX_SIZE = 100;
  private int top;
  private T[] items;

  public stackArray()
  {
    top = -1;
    items = new T[MAX_SIZE];
  }


  public void push(T newItem)
  {
    if(top>= MAX_SIZE)
    {
      Console.WriteLine("Stack full on push");
    }
    else
    {
      top++;
      items[top] = newItem;
    }
  }


  public bool isEmpty()
  { return top == -1; }

  public void pop()
  {
    if(isEmpty())
    { Console.WriteLine("Stack empty on pop"); }
    else
    { top--; }
  }

  public T pop(out T popItem)
  {
    if (isEmpty())
    {
      Console.WriteLine("Stack empty on pop");
      popItem = default(T);
      return popItem;
    }
    else
    {
      popItem = items[top];
      top--;
      return popItem;
    }
  }

  public T getTop(out T topItem)
  {
    if (isEmpty())
    {
      Console.WriteLine("Stack empty on getTop");
      topItem = default(T);
      return topItem;
    }
    else
    {
      topItem = items[top];
      return topItem;
    }
  }

  public void print()
  {
    Console.Write("[ ");
    for (int i = top; i >= 0; i--)
    {
      Console.Write(items[i] + " ");
    }
    Console.WriteLine("]");
  }
}
