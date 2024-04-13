/*
Author: Nofaal
  main:
lookk likke Spider>>>
*/

// ==|libraries|==
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
//#define ONPC
#define sout(x) for (auto i : x)  cout << i << ' '; cout << endl;
#define Spider ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// =====|forClass|=====
#include "arrayList.h"
// ===|forFunctions here|===


// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
    arrayList arr(100);
  arr.insertAtPos(0, 50);
  arr.insertAtPos(1, 60);
  arr.insertAtPos(2, 70);
  arr.insertAtPos(3, 80);
  arr.insertAtPos(4, 90);
  arr.insertAtEnd(59);
  arr.insertNoDuplicate(50);
  arr.updateAt(3, 88);
  cout << "Element: " << arr.getElement(4) << endl;
  arr.removeAtPos(0);
  arr.removeElement(90);
  arr.display();
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions