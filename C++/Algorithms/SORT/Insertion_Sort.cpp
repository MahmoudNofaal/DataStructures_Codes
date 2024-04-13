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

void insertionSort(int arr[], int n)
{
  int key, j;

  for (int i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] < key)
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = key;
  }
}


void print(int arr[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;
}


// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    int arr[] = { 80,90,60,30,50,70,40 };
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);
  print(arr, n);

  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
