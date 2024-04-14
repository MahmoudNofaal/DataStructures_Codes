
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

    DoublyLinkedList<int> dll = new DoublyLinkedList<int>();
    dll.insertFirst(50);
    dll.insertFirst(40);
    dll.insertFirst(30);
    dll.insertLast(70);
    dll.insertLast(80);
    dll.insertAtPos(3, 60);
    dll.insertAtPos(6, 90);
    dll.insertAtPos(0, 20);
    dll.removeFirst();
    dll.removeLast();
    dll.removeElement(50);
    Console.WriteLine("Position of element: " + dll.search(60));
    Console.WriteLine("Doubly List Items:");
    dll.Display();
    Console.WriteLine("Reversed Doubly List Items:");
    dll.reverse();
    dll.Display();

    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
