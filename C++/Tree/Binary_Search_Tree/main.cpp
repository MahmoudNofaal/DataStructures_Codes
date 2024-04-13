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
#include "binarySearchTree.h"
// ===|forFunctions here|===



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
 cout << "======= [ Binary Search Tree ] =======\n\n" << endl;
  binarySearchTree<int> b;
  b.insert(40);
  b.insert(45);
  b.insert(30);
  b.insert(35);
  b.insert(29);
  b.insert(22);
  b.insert(50);
  b.insert(10);

  b.remove(10);

  cout << "Count Of Leaves: [ " << b.treeLeavesCount() << " ]" << endl;

  cout << endl;

  cout << "Count Of Nodes: [ " << b.treeNodeCount() << " ]" << endl;

  cout << endl;

  cout << "Tree Height: [ " << b.treeHeight() << " ] Nodes" << endl;

  cout << endl;

  cout << "Is Element (29) Is Exist: " << ((b.search(29)) ? "Yes" : "No") << endl;

  cout << endl;

  cout << "Items In [Pre-Order]: ";
  b.preOrderTraversal();
  cout << endl;
  cout << "Items In [In-Order]: ";
  b.inOrderTraversal();
  cout << endl;

  cout << "Items In [Post-Order]: ";
  b.postOrderTraversal();
  cout << endl;


  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
