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
bool arePair(char open, char close)
{
  if (open == '(' && close == ')')
    return true;
  if (open == '[' && close == ']')
    return true;
  if (open == '{' && close == '}')
    return true;
  return false;
}

bool areBalanced(string exp)
{
  stack<char> s;
  for (int i = 0; i < exp.length(); i++)
  {
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
    {
      s.push(exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
    {
      if (s.empty() && !arePair(s.top(), exp[i]))
      {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}


// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====
    string exp;
  cout << "Enter parentheses expression:\n";
  getline(cin, exp);
  if (areBalanced(exp))
    cout << "Balanced\n";
  else
    cout << "Not balanced\n";
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions
