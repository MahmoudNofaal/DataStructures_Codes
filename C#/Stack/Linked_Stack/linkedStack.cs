using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

public class linkedStack<T>
{
  private class Node
  {
    public T item;
    public Node next;
  }

  private Node stackTop;

  public linkedStack()
  {
    stackTop = null;
  }


  public void push(T newItem)
  {
    Node newNode = new Node();
    newNode.item = newItem;
    newNode.next = stackTop;
    stackTop = newNode;
  }

  public bool isEmpty()
  { return stackTop == null; }

  public void pop()
  {
    if(isEmpty())
    {
      Console.WriteLine("Stack empty on pop");
      return;
    }
    else
    {
      Node temp = stackTop;
      stackTop = stackTop.next;
      temp.next = null;
    }
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
      popItem = stackTop.item;
      Node temp = stackTop;
      stackTop = stackTop.next;
      temp.next = null;
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
      topItem = stackTop.item;
      return topItem;
    }
  }


  public void Display()
  {
    Node stackCurr = stackTop;
    Console.Write("[ ");
    while(stackCurr!=null)
    {
      Console.Write(stackCurr.item + " ");
      stackCurr = stackCurr.next;
    }
    Console.WriteLine("]");
  }
}
