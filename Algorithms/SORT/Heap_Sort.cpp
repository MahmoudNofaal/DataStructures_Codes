

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


void heapify(int arr[], int n, int i)
{
  // n==>sizeOfArr, currIndex
  // l==>left
  // r==>right
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  int max = i;
  if (l<n && arr[l]>arr[max]) // for minHeap change to <
    max = l;
  if (r<n && arr[r]>arr[max]) // for minHeap change to <
    max = r;

  if (max != i)
  {
    swap(arr[i], arr[max]);
    heapify(arr, n, max);
  }
}


void buildHeap(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i);
  }
}


void heapSort(int arr[], int n)
{

  buildHeap(arr, n);
  for (int i = n - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
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
    // ====| code here |====

    int arr[] = { 90,10,40,70,5 };
  int n = sizeof(arr) / sizeof(arr[0]);

  heapSort(arr, n);
  print(arr, n);

  // ====| code ended |====
    system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
