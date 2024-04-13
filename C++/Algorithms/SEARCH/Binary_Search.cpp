
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

int binarySearch(int arr[], int l, int h, int element)
{
  while (l <= h)
  {
    int m = (l + h) / 2;

    if (arr[m] == element)
      return m;
    
    if (arr[m] > m)
      h = m - 1;
    else
      l = m + 1;
  }
  return -1;
}



int binarySearchRecursive(int arr[], int l, int h, int element)
{
  if (h >= l)
  {
    int mid = (l + h) / 2;

    if (arr[mid] == element)
      return mid;

    if (arr[mid] > element)
      return binarySearch(arr, l, mid - 1, element);
    else
      return binarySearch(arr, mid + 1, h, element);
  }
  return -1;
}




// ==|Main|==
int main(void)
{
  Spider
    // ====| code here |====

    int arr[] = { 2,4,7,9,10,13,20 };
  int n = size(arr);

  int num;
  cout << "Enter an Integer: ";
  cin >> num;

  int result = binarySearch(arr, 0, n - 1, num);
  //int result = binarySearchRecursive(arr, 0, n - 1, num);
  if (result == -1)
    cout << "The Number : [" << num << "] Was Not Found." << endl;
  else
    cout << "The Number : [" << arr[result] << "] Was Found At Index : (" << result << ")" << endl;

  // ====| code ended |====
    system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
