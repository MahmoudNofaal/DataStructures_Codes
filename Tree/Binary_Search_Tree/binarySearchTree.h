

/*
Author: Nofaal

lookk likke Spider>>>
*/

#pragma once


#include <iostream>
#include <cassert>

using namespace std;


template<class T>
struct Node
{
  T item;
  Node* left;
  Node* right;
};


template<class T>
class binarySearchTree
{
private:
  Node<T>* root;

  void clear(Node<T>*& p);

  void preOrder(Node<T>* p);

  void inOrder(Node<T>* p);

  void postOrder(Node<T>* p);

  int height(Node<T>* p);

  int max(int x, int y);

  int countNodes(Node<T>* p);

  int countLeaves(Node<T>* p);

  void deleteFromTree(Node<T>*& p);


public:
  bool isEmpty();

  bool search(int);

  void insert(int newItem);

  void remove(int deleteItem);

  void preOrderTraversal();
  void inOrderTraversal();
  void postOrderTraversal();

  int treeHeight();

  int treeNodeCount();
  int treeLeavesCount();

  void clearTree();

  binarySearchTree();
  ~binarySearchTree();
};





template<class T>
binarySearchTree<T>::binarySearchTree()
{
  root = NULL;
}


template<class T>
bool binarySearchTree<T>::isEmpty()
{
  return (root == NULL);
}




//================ Pre-Order =============

template<class T>
void binarySearchTree<T>::preOrder(Node<T>* p)
{
  if (p != NULL)
  {
    cout << p->item << " ";
    preOrder(p->left);
    preOrder(p->right);
  }
}

template<class T>
void binarySearchTree<T>::preOrderTraversal()
{
  preOrder(root);
}

//========================================





//=============== In-Order ===============

template<class T>
void binarySearchTree<T>::inOrder(Node<T>* p)
{
  if (p != NULL)
  {
    inOrder( p->left );
    cout << p->item << " ";
    inOrder(p->right);
  }
}

template<class T>
void binarySearchTree<T>::inOrderTraversal()
{
  inOrder(root);
}

//========================================





//================== Post-Order ============

template<class T>
void binarySearchTree<T>::postOrder(Node<T>* p)
{
  if (p != NULL)
  {
    postOrder(p->left);
    postOrder(p->right);
    cout << p->item << " ";
  }
}

template<class T>
void binarySearchTree<T>::postOrderTraversal()
{
  postOrder(root);
}

//========================================




//==================Height================

template<class T>
int binarySearchTree<T>::max(int x, int y)
{
  return (x >= y) ? x : y;
}


template<class T>
int binarySearchTree<T>::height(Node<T>* p)
{
  if (p == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + max(height(p->left), height(p->right));
  }
}

template<class T>
int binarySearchTree<T>::treeHeight()
{
  return height(root);
}

//========================================




//=================Node Count=============

template<class T>
int binarySearchTree<T>::countNodes(Node<T>* p)
{
  if (p == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + countNodes(p->left) + countNodes(p->right);
  }
}

template<class T>
int binarySearchTree<T>::treeNodeCount()
{
  return countNodes(root);
}

//========================================




//===============Leaves Count=============

template<class T>
int binarySearchTree<T>::countLeaves(Node<T>* p)
{
  if (p == NULL)
  {
    return 0;
  }
  else if ((p->left == NULL) && (p->right == NULL))
  {
    return 1;
  }
  else
  {
    return countLeaves(p->left) + countLeaves(p->right);
  }
}

template<class T>
int binarySearchTree<T>::treeLeavesCount()
{
  return countLeaves(root);
}

//========================================





//=================== CLEAR ==============

template<class T>
void binarySearchTree<T>::clear(Node<T>* &p)
{
  if (p != NULL)
  {
    clear(p->left);
    clear(p->right);
    delete p;
    p = NULL;
  }
}

template<class T>
void binarySearchTree<T>::clearTree()
{
  clear(root);
}


template<class T>
binarySearchTree<T>::~binarySearchTree()
{
  clear(root);
}

//========================================




template<class T>
bool binarySearchTree<T>::search(int item)
{
  Node<T>* curr = root;
  while (curr != NULL)
  {
    if (curr->item == item)
    {
      return true;
    }
    else if (curr->item > item)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }
  return false;
}




//================= Insert Item =============

template<class T>
void binarySearchTree<T>::insert(int newItem)
{
  Node<T>* curr; // to discover first
  Node<T>* trailCurr; // to return to curr if discover failed
  Node<T>* newNode = new Node<T>;

  assert(newNode != NULL);
  newNode->item = newItem;
  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL)
  {
    root = newNode;
  }
  else
  {
    curr = root;

    trailCurr = NULL;

    while (curr != NULL)
    {
      trailCurr = curr;

      if (curr->item == newItem)
      {
        cout << "The inserted item is already exist -- "
          << "duplicates are not allowed.\n";
        return;
      }
      else
      {
        if (curr->item > newItem)
        {
          curr = curr->left;
        }
        else
        {
          curr = curr->right;
        }
      }
    } //end While

    if (trailCurr->item > newItem)
    {
      trailCurr->left = newNode;
    }
    else
    {
      trailCurr->right = newNode;
    }
  }
}

//========================================




//================ Remove ================

// how to search item first and delete it
template<class T>
void binarySearchTree<T>::remove(int deleteItem)
{
  Node<T>* curr; // pointer to discover first
  Node<T>* trailCurr; // pointer to return if discover failed

  if (root == NULL)
  {
    cout << "Cannot delete -- tree is empty --\n";
    return;
  }
  if (root->item == deleteItem)
  {
    deleteFromTree(root);
    return;
  }


  //if you get here, then the item to be deleted is not the root
  trailCurr = root;

  if (root->item > deleteItem)
    curr = root->left;
  else
    curr = root->right;

  // start to search after root
  while (curr != NULL)
  {
    if (curr->item == deleteItem)
    {
      break;
    }
    else
    {
      trailCurr = curr;
      if (curr->item > deleteItem)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }
  }//end while

  // now the curr points to NULL || deleteItem
  if (curr == NULL)
  {
    cout << "Delete item is not exist in the tree..\n";
  }
  else if(trailCurr->item > deleteItem)
  {
    deleteFromTree(trailCurr->left);
  }
  else
  {
    deleteFromTree(trailCurr->right);
  }
}




// this function is dedicated to remove the item after search it
template<class T>
void binarySearchTree<T>::deleteFromTree(Node<T>*& p)
{
  Node<T>* curr; // points (discovery)
  Node<T>* trailCurr; // return if (failed Discovery)
  Node<T>* temp; // used to be delete (deleteItem)

  if (p->left == NULL && p->right == NULL)
  {
    delete p;
    p = NULL;
  }
  else if (p->left == NULL) // right is exist
  {
    temp = p;
    p = p->right;
    delete temp;
  }
  else if (p->right == NULL) // left is exist
  {
    temp = p;
    p = p->left;
    delete temp;
  }
  else // left && right are exist
  {
    curr = p->left;
    trailCurr = NULL;

    while (curr->right != NULL)
    {
      trailCurr = curr;
      curr = curr->right;
    }

    p->item = curr->item;

    // curr did not move
    // => curr == p->left;
    // => adjust p
    if (trailCurr == NULL)
    {
      p->left = curr->left;
    }
    else // curr moved curr p-left == right
    {
      trailCurr->right = curr->left;
    }
    delete curr;
  }//end else
}

//========================================

