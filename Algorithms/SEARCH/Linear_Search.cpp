
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
#include <queue>

using namespace std;

#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
//#define ONPC
#define sout(x) for (auto i : x)  cout << i << ' '; cout << endl;
#define Spider ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

// =====|forClass|=====

// ===|forFunctions here|===

int linearSearch(int arr[], int n, int element)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == element)
      return i;
  }
  return -1;
}




// ==|Main|==
int main(void)
{
  Spider
    // ====| code here |====

    int arr[] = { 90,10,40,70,5 };
  int n = sizeof(arr) / sizeof(arr[0]);

  int num;
  cout << "Enter an Integer: ";
  cin >> num;

  int result = linearSearch(arr, n, num);
  if (result == -1)
    cout << "The Number: (" << num << ") Was Not Found." << endl;
  else
    cout << "The Number: ( " << arr[result] << " ) Was Found At Index: [ " << result << " ]" << endl;

  // ====| code ended |====
    system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
