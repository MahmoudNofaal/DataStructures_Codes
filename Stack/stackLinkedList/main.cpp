/*
Author: Nofaal
  main:
lookk likke Spider>>>
*/

// ==|libraries|==
#include <cassert>
#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
//#define ONPC
#define sout(x) for (auto i : x)  cout << i << ' '; cout << endl;
#define Spider ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// =====|forClass|=====
#include "stackLinkedList.h"
// ===|forFunctions here|===


// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
    stackLinkedList<int> s;
  s.push(50);
  s.push(60);
  s.push(70);
  s.push(80);
  int y;
  cout << "Popped item: " << s.pop(y) << endl;
  int yy;
  cout << "Top item: " << s.getTop(yy) << endl;
  s.display();
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions