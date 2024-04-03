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

void selectionSort(int arr[], int n)
{
  int minIndex;

  for (int i = 0; i < n - 1; i++)
  {
    minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}


void swap(int x, int y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}


void print(int arr[], int size)
{
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << "]" << endl;
}



// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    int arr[] = { -60,0,50,30,10,20 };
  int n = size(arr);
  selectionSort(arr, n);
  cout << "Array After Selection Sort: ";
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
