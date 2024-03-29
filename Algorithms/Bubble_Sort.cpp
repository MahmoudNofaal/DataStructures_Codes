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


void swap(int& x, int& y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
}


void bubbleSort(int arr[], int n)
{
  bool flag = true;
  int c = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        flag = false;
      }
      c++;
    }
    if (flag)
    {
      break;
    }
  }
  cout << c << "# of round" << endl;
}



void bubbleSortRec(int arr[], int n)
{
  if (n == 1) //base case
    return;

  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
  bubbleSortRec(arr, n - 1);
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

    int arr[] = { 30,20,40,5,60,2 };
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  //bubbleSortRec(arr, n);
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
