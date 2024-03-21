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
#include "arrayQueue.h"
// ===|forFunctions here|===



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
    arrayQueue<int> aq(5);
  aq.addQueue(50);
  aq.addQueue(60);
  aq.addQueue(70);
  aq.addQueue(80);
  aq.addQueue(90);
  int y = 0;
  cout << "Deleted item: " << aq.deleteQueue(y) << endl;
  cout << "Front item: " << aq.frontQueue() << endl;
  cout << "Rear item: " << aq.rearQueue() << endl;
  cout << "(70) item index: " << aq.searchQueue(70) << endl;
  aq.printQueue();
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
