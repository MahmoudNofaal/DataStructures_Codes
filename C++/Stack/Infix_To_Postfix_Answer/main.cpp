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
bool isOperator(char c);

// function for isOperand
bool isOperand(char c);

// function for hasHigherPrecedence
bool hasHigherPrecedence(char op1, char op2);

// function for infix to posfix
string infixToPostfix(string infix);

// function for performOperation
int performOperation(int op1, int op2, char op);

// function for getTheAnswer
int getAnswer(string postfix);


// ==|Main|==
int main(void)
{
  Spider
    // ===|code here|====

    string infix;
  cout << "Enter infix expression:\n";
  getline(cin, infix);
  string postfix = infixToPostfix(infix);
  int answer = getAnswer(postfix);
  cout << "Answer: " << answer << endl;
  // ===|code ended|===
  system("pause>0");
  return 0;
}

#ifdef ONPC
cerr << endl
<< "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

// forFunctions

// isOperator function
bool isOperator(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

// isOperand function
bool isOperand(char c)
{
  if (c >= '0' && c <= '9')
    return true;
  if (c >= 'a' && c <= 'z')
    return true;
  if (c >= 'A' && c <= 'Z')
    return true;
  return false;
}

// hasHigherPrecedence function
// isRightAssociative function
int isRightAssociative(char op)
{
  if (op == '$')
    return true;
  return false;
}
// getOperatorWeight function
int getOperatorWeight(char op)
{
  int weight = -1;
  switch (op)
  {
  case '+':
  case '-':
    weight = 1;
    break;
  case '*':
  case '/':
    weight = 2;
    break;
  case '$':
    weight = 3;
  }
  return weight;
}

bool hasHigherPrecedence(char op1, char op2)
{
  int op1Weight = 0, op2Weight = 0;
  op1Weight = getOperatorWeight(op1);
  op2Weight = getOperatorWeight(op2);
  if (op1Weight == op2Weight)
  {
    return true;
  }
  return op1Weight > op2Weight ? true : false;
}

// infixToPostfix function
string infixToPostfix(string infix)
{
  string postfix = "";
  stack<char> s;
  for (int i = 0; i < infix.length(); i++)
  {
    if (infix[i] == ' ' || infix[i] == ',')
      continue;
    else if (isOperator(infix[i]))
    {
      while (!s.empty() && s.top() != '(' && hasHigherPrecedence(s.top(), infix[i]))
      {
        postfix += " ";
        postfix += s.top();
        s.pop();
      }
      postfix += " ";
      s.push(infix[i]);
    }
    else if (isOperand(infix[i]))
    {
      postfix += infix[i];
    }
    else if (infix[i] == '(')
    {
      s.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (!s.empty() && s.top() != '(')
      {
        postfix += " ";
        postfix += s.top();
        s.pop();
      }
      s.pop();
    }
  }
  while (!s.empty())
  {
    postfix += " ";
    postfix += s.top();
    s.pop();
  }
  return postfix;
}

// performOperation function
int performOperation(int op1, int op2, char op)
{
  int ans;
  switch (op)
  {
  case '+':
    ans = op2 + op1;
    break;
  case '-':
    ans = op2 - op1;
    break;
  case '*':
    ans = op2 * op1;
    break;
  case '/':
    ans = op2 / op1;
  }
  return ans;
}

int getAnswer(string postfix)
{

  string buffer;
  int op1, op2, x;
  stack<int> s;

  for (int i = 0; i < postfix.length(); i++)
  {
    if (postfix[i] >= '0' && postfix[i] <= '9')
    {
      buffer += postfix[i];
    }
    else if (postfix[i] == ' ')
    {
      if (!buffer.empty())
      {
        x = stoi(buffer);
        s.push(x);
        buffer.clear();
      }
    }
    else if (isOperator(postfix[i]))
    {
      op1 = s.top();
      s.pop();
      op2 = s.top();
      s.pop();
      s.push(performOperation(op1, op2, postfix[i]));
    }
  }

  return s.top(); // Return the final result
}