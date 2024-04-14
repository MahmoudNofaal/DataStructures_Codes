
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

    LinkedList<int> l = new LinkedList<int>();
    l.insertFirst(50);
    l.insertFirst(40);
    l.insertFirst(30);
    l.insertLast(70);
    l.insertLast(80);
    l.insertLast(90);
    l.insertLast(100);
    l.insertAtPos(3, 60); // 30 40 50 60 70 80 90 100
    l.removeFirst(); // 40 50 60 70 80 90 100
    l.removeLast(); // 40 50 60 70 80 90
    l.removeElement(60); // 40 50 70 80 90
    Console.WriteLine("First item: " + l.getFirst());
    Console.WriteLine("Last item: " + l.getLast());
    Console.WriteLine("Element pos: " + l.search(90));
    Console.WriteLine("LinkedList items:");
    l.Display();
    l.reverse();
    Console.WriteLine("Items Reversed:");
    l.Display();

    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
