
/*
Author: Nofaal
  Main:
lookk likke Spider>>>
*/


namespace Nofaal;


public class Program
{
  // ====| for functions |====

  static void Main(string[] args)
  {
    // ===| Code Starts Here |=====

    linkedStack<int> s = new linkedStack<int>();
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    int y;
    Console.WriteLine("Poped item: " + s.pop(out y));
    int yy;
    Console.WriteLine("Top item: " + s.getTop(out yy));
    Console.WriteLine("Stack elements:");
    s.Display();


    // =======| Code ended |=======
  }
}




// |for spilt input|
//int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray(); 
