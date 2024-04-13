
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

void merge(int arr[], int l, int m, int r)
{

  /*
  l => left, m => mid, r => right
  m = l + (r - l) / 2;
  */

  // first subarray [left] from (l,m)
  int n1 = m - l + 1;
  // second subarray [right] from (m+1, r)
  int n2 = r - m;

  int* left = new int[n1];
  int* right = new int[n2];

  for (int i = 0; i < n1; i++)
    left[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    right[j] = arr[m + 1 + j];

  int i, j, k;
  i = j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      arr[k] = left[i];
      i++;
    }
    else
    {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = right[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}



void print(int arr[], int n)
{
  cout << "[ ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "]" << endl;

}




// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    int arr[] = { 60,10,20,5,60,70 };
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);
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
