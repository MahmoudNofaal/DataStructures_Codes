
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


int partition_1(int arr[], int l, int h)
{
  int p = arr[l];
  int i = l;
  int j = h;

  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] <= p);

    do
    {
      j++;
    } while (arr[j] > p);

    if (i < j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[l], arr[j]);
  return j;
}



void quickSort_1(int arr[], int l, int h)
{
  if (l < h)
  {
    int piv = partition_1(arr, l, h);
    quickSort_1(arr, l, piv);
    quickSort_1(arr, piv + 1, h);
  }
}


//=======================================


int partition_2(int arr[], int iBegin, int jEnd)
{
  int i = iBegin;
  int j = jEnd;
  int pivLoc = i;

  while (true)
  {
    while (arr[pivLoc] <= arr[j] && pivLoc != j)
    {
      j--;
    }

    if (pivLoc == j)
      break;
    else if (arr[pivLoc] > arr[j])
    {
      swap(arr[j], arr[pivLoc]);
      pivLoc = j;
    }


    while (arr[pivLoc] >= arr[i] && pivLoc != i)
    {
      i++;
    }

    if (pivLoc == i)
      break;
    else if (arr[pivLoc] < arr[i])
    {
      swap(arr[i], arr[pivLoc]);
      pivLoc = i;
    }
  }
  return pivLoc;
}


void quickSort_2(int arr[], int l, int h)
{

  if (l < h) {
    int piv = partition_2(arr, l, h);
    quickSort_2(arr, l, piv - 1);
    quickSort_2(arr, piv + 1, h);
  }

}





// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====


    int arr[] = { 2,-1,4,7,0 };
  int n = sizeof(arr) / sizeof(arr[0]);

  quickSort_2(arr, 0, n - 1);

  cout << "[ ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "]\n";


  // ===|code ended|===
    system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
