using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nofaal;

internal class BinarySearchTree<T> where T : IComparable<T>
{
  private class Node
  {
    public T item;
    public Node left;
    public Node right;
  }

  private Node root;

  private void Clear(ref Node p)
  {
    if (p != null)
    {
      Clear(ref p.left);
      Clear(ref p.right);
      p = null;
    }
  }

  private void PreOrder(Node p)
  {
    if (p != null)
    {
      Console.Write(p.item + " ");
      PreOrder(p.left);
      PreOrder(p.right);
    }
  }

  private void InOrder(Node p)
  {
    if (p != null)
    {
      InOrder(p.left);
      Console.Write(p.item + " ");
      InOrder(p.right);
    }
  }

  private void PostOrder(Node p)
  {
    if (p != null)
    {
      PostOrder(p.left);
      PostOrder(p.right);
      Console.Write(p.item + " ");
    }
  }

  private int Height(Node p)
  {
    if (p == null)
      return 0;
    else
      return (1 + Max(Height(p.left), Height(p.right)));
  }

  private int Max(int x, int y)
  {
    return (x >= y) ? x : y;
  }

  private int CountNodes(Node p)
  {
    if (p == null)
      return 0;
    else
      return (1 + CountNodes(p.left) + CountNodes(p.right));
  }

  private int CountLeaves(Node p)
  {
    if (p == null)
      return 0;
    else if (p.left == null && p.right == null)
      return 1;
    else
      return (CountLeaves(p.left) + CountLeaves(p.right));
  }

  private void DeleteFromTree(ref Node p)
  {
    Node curr; // points (discovery)
    Node trailCurr; // return if (failed Discovery)
    Node temp; // used to be delete (deleteItem)

    if (p.left == null && p.right == null)
    {
      p = null;
    }
    else if (p.left == null) // right is exist
    {
      temp = p;
      p = p.right;
    }
    else if (p.right == null) // left is exist
    {
      temp = p;
      p = p.left;
    }
    else // left && right are exist
    {
      curr = p.left;
      trailCurr = null;

      while (curr.right != null)
      {
        trailCurr = curr;
        curr = curr.right;
      }

      p.item = curr.item;
      DeleteFromTree(ref curr);
    }//end else
  }




  public BinarySearchTree()
  { root = null; }

  public bool IsEmpty()
  { return (root == null); }

  public bool Search(int item)
  {
    Node curr = root;
    while (curr != null)
    {
      int cmp = item.CompareTo(curr.item);

      if (cmp == 0)
        return true;
      else if (cmp < 0)
        curr = curr.left;
      else
        curr = curr.right;
    }
    return false;
  }

  public void Insert(T newItem)
  {
    Node curr;
    Node trailCurr;
    Node newNode = new Node();
    newNode.item = newItem;

    if (root == null)
    {
      root = newNode;
    }
    else
    {
      curr = root;
      trailCurr = null;

      while (curr != null)
      {
        trailCurr = curr;
        int cmp = newItem.CompareTo(curr.item);
        if (cmp == 0)
        {
          Console.WriteLine("The inserted item already exists - duplicates are not allowed.");
          return;
        }
        else if (cmp < 0)
        {
          curr = curr.left;
        }
        else
        {
          curr = curr.right;
        }
      }

      if (newItem.CompareTo(trailCurr.item) < 0)
      {
        trailCurr.left = newNode;
      }
      else
      {
        trailCurr.right = newNode;
      }
    }
  }

  public void Remove(T deleteItem)
  {
    Node curr, trailCurr;

    if (root == null)
    {
      Console.WriteLine("Cannot delete -- tree is empty --");
      return;
    }
    if (root.item.CompareTo(deleteItem) == 0)
    {
      DeleteFromTree(ref root);
      return;
    }

    trailCurr = root;

    if (root.item.CompareTo(deleteItem) > 0)
      curr = root.left;
    else
      curr = root.right;

    while (curr != null)
    {
      if (curr.item.CompareTo(deleteItem) == 0)
      {
        break;
      }
      else
      {
        trailCurr = curr;
        if (curr.item.CompareTo(deleteItem) > 0)
        {
          curr = curr.left;
        }
        else
        {
          curr = curr.right;
        }
      }
    }

    if (curr == null)
    {
      Console.WriteLine("Delete item is not exist in the tree..");
    }
    else if (trailCurr.item.CompareTo(deleteItem) > 0)
    {
      DeleteFromTree(ref trailCurr.left);
    }
    else
    {
      DeleteFromTree(ref trailCurr.right);
    }
  }

  public void PreOrderTraversal()
  { PreOrder(root); }
  public void InOrderTraversal()
  { InOrder(root); }
  public void PostOrderTraversal()
  { PostOrder(root); }

  public int TreeHeight()
  { return Height(root); }

  public int TreeNodeCount()
  { return CountNodes(root); }
  public int TreeLeavesCount()
  { return CountLeaves(root); }

  public void ClearTree()
  { Clear(ref root); }
}
