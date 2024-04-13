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

// ===|forFunctions here|===
int binarySearch(int arr[], int low, int high, int numToSearch)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (numToSearch == arr[mid])
    {
      return mid;
    }
    if (numToSearch > arr[mid])
    {
      low = mid + 1;
    }
    if (numToSearch < arr[mid])
    {
      high = mid - 1;
    }
  }
  return -1;
}



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    int arr[] = { 2,4,7,9,10,13,20 };
  int n = size(arr);

  int num;
  cout << "Enter an Integer: ";
  cin >> num;

  int result = binarySearch(arr, 0, n - 1, num);
  if (result == -1)
    cout << "The Number : [" << num << "] Was Not Found." << endl;
  else
    cout << "The Number : [" << arr[result] << "] Was Found At Index : (" << result << ")" << endl;
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
