
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

    ArrayQueue<int> aq = new ArrayQueue<int>(5);
    aq.addQueue(50);
    aq.addQueue(60);
    aq.addQueue(70);
    aq.addQueue(80);
    aq.addQueue(90);
    int yy;
    Console.WriteLine("Deleted item: " + aq.deleteQueue(out yy));
    Console.WriteLine("Front item: " + aq.frontQueue());
    Console.WriteLine("Rear item: " + aq.rearQueue());
    Console.WriteLine("(70) item index: " + aq.searchQueue(70));
    aq.printQueue();

    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
