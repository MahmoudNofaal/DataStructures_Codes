/*
Author: Nofaal
  main:
lookk likke Spider>>>
*/

// ==|libraries|==
#include <cassert>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>

using namespace std;

#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
//#define ONPC
#define sout(x) for (auto i : x)  cout << i << ' '; cout << endl;
#define Spider ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// =====|forClass|=====
#include "doublyLinkedList.h"

// ===|forFunctions here|===



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
    doublyLinkedList<int> dll;
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
  cout << "Position of element: " << dll.search(60) << endl;
  cout << "Doubly List Items:";
  dll.display();
  cout << "Reversed Doubly List Items:";
  dll.reverse();
  dll.display();

  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
