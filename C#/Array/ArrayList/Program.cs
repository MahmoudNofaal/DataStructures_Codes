
/*
Author: Nofaal
  Main:
lookk likke Spider>>>
*/


using System.Collections;

namespace Nofaal;


public class Program
{
  // ====| for functions |====

  static void Main(string[] args)
  {
    // ===| Code Starts Here |=====

    ArrayList arr = new ArrayList(100);
    arr.insertAtPos(0, 50);
    arr.insertAtPos(1, 60);
    arr.insertAtPos(2, 70);
    arr.insertAtPos(3, 80);
    arr.insertAtPos(4, 90);
    arr.insertAtEnd(59);
    arr.insertNoDuplicate(50);
    arr.updateAt(3, 88);
    Console.WriteLine("Element: " + arr.getElement(4));
    arr.removeAtPos(0);
    arr.removeElement(90);
    arr.Display();


    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
