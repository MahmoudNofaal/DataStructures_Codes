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
#include "linkedQueue.h"
// ===|forFunctions here|===



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    linkedQueue<int> lq;
  lq.enqueue(50);
  lq.enqueue(60);
  lq.enqueue(70);
  lq.enqueue(80);
  lq.enqueue(90);
  lq.enqueue(98);
  lq.dequeue();
  int y;
  cout << "Deleted item: " << lq.dequeue(y) << endl;
  cout << "Front item: " << lq.getFront() << endl;
  cout << "Rear item: " << lq.getRear() << endl;
  cout << "Size: " << lq.getSize() << endl;
  lq.display();
  lq.clearQueue();
  lq.display();
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
