
/*
Author: Nofaal
  Main:
lookk likke Spider>>>
*/


using System.Collections;
using System.Collections.Generic;

namespace Nofaal;


public class Program
{
  // ====| for functions |====

  static void Main(string[] args)
  {
    // ===| Code Starts Here |=====

    Console.WriteLine("======= [ Binary Search Tree ] =======\n");

    BinarySearchTree<int> b = new BinarySearchTree<int>();
    b.Insert(40);
    b.Insert(45);
    b.Insert(30);
    b.Insert(35);
    b.Insert(29);
    b.Insert(22);
    b.Insert(50);
    b.Insert(10);

    b.Remove(10);

    Console.WriteLine($"Count Of Leaves: [ {b.TreeLeavesCount()} ]\n");
    Console.WriteLine($"Count Of Nodes: [ {b.TreeNodeCount()} ]\n");
    Console.WriteLine($"Tree Height: [ {b.TreeHeight()} ] Nodes\n");
    Console.WriteLine($"Is Element (29) Is Exist: {(b.Search(29) ? "Yes" : "No")}\n");

    Console.Write("Items In [Pre-Order]: ");
    b.PreOrderTraversal();
    Console.WriteLine();
    Console.Write("Items In [In-Order]: ");
    b.InOrderTraversal();
    Console.WriteLine();
    Console.Write("Items In [Post-Order]: ");
    b.PostOrderTraversal();
    Console.WriteLine();

    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
