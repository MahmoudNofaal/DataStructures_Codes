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
#include "linkedList.h"

// ===|forFunctions here|===



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    linkedList<int> l;
  l.insertFirst(50);
  l.insertFirst(40);
  l.insertFirst(30);
  l.insertLast(70);
  l.insertLast(80);
  l.insertLast(90);
  l.insertLast(100);
  l.insertAtPos(3, 60);
  l.removeFirst();
  l.removeLast();
  l.removeElement(60);
  cout << "First item: " << l.getFirst() << endl;
  cout << "Last item: " << l.getLast() << endl;
  cout << "Element pos: " << l.search(90) << endl;
  cout << "LinkedList items:";
  l.display();
  l.reverse();
  cout << "Items Reversed:";
  l.display();

  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
