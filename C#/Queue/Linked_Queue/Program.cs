
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

    LinkedQueue<int> lq = new LinkedQueue<int>();
    lq.Enqueue(50);
    lq.Enqueue(60);
    lq.Enqueue(70);
    lq.Enqueue(80);
    lq.Enqueue(90);
    lq.Enqueue(98); // 50 60 70 80 90 98
    lq.Dequeue(); // 60 70 80 90 98
    int y;
    Console.WriteLine("Deleted Item: " + lq.Dequeue(out y)); // [60]  70 80 90 98
    Console.WriteLine("Front Item: " + lq.GetFront());
    Console.WriteLine("Rear Item: " + lq.GetRear());
    Console.WriteLine("Size: " + lq.GetSize());
    lq.Display();
    lq.ClearQueue();

    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
