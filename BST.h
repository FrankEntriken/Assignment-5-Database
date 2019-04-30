#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class T>
struct BST{
  public:
    TreeNode<T> *root;

    BST()
    {
      root = NULL;
    }

    ~BST()
    {
      //iterate and delete
      //lets put on our research hats
    }

    //--------------------------------------------------------------------------------
    bool isEmpty()
    {
      return root == NULL;
    }

    //--------------------------------------------------------------------------------
    void recPrint(TreeNode<T> *node)
    {
      if(node == NULL)
        return;

      recPrint(node->left);
      cout << node->data << endl;
      recPrint(node->right);
    }

    //--------------------------------------------------------------------------------
    void insert(T value)
    {
      //check if value exist, if not continue
      TreeNode<T> *node = new TreeNode<T>(value);

      if(isEmpty()) //empty tree
      {
        root = node;
      }

      else //not an empty, need to find insertion point
      {
        TreeNode<T>* current = root;
        TreeNode<T>* parent; //empty node

        while(true)
        {
          parent = current;
          if(value < current->data)
          {
            current = current->left; //going left
            if(current == NULL) //found new home for new node
            {
              parent->left = node;
              break;
            }
            //else keep going
          }
          else
          {
            current = current->right;
            if(current == NULL)
            {
              parent->right = node;
              break;
            }
          }
        }
      }
    }

    //--------------------------------------------------------------------------------
    bool contains(T value)
    {
      if(isEmpty())
        return false;
      else
      {
        TreeNode<T> *current = root;
        while(current->data != value)
        {
          if(value < current->data) //go left
            current = current->left;
          else
            current = current->right;

          if(current == NULL) //we did not find it, does not exist
            return false;
        }
      }
      return true;
    }

    //--------------------------------------------------------------------------------
    bool remove(T k)
    {
      if(isEmpty())
        return false;

      //check if data/value exists before continuing to remove
      TreeNode<T> *current = root;
      TreeNode<T> *parent = root;
      bool isLeft;

      while(current->data != k) //lets look for our node
      {
        parent = current;
        if(k < current->data)
        {
          isLeft = true;
          current = current->left;
        }
        else //rightchild
        {
          isLeft = false;
          current = current->right;
        }

        if(current == NULL)
          return false;
      }

      //at this point we found our node
      //now lets check our cases

      if(current->left == NULL && current->right == NULL) //no children, leaf node
      {
        if(current == root)
          root == NULL;
        else if(isLeft) //left child
        {
          parent->left = NULL;
        }
        else //right child
        {
          parent->right = NULL;
        }
      }

      //check for nodes that have one child
      else if(current->right == NULL) //no right child
      {
        if(current == root)
          root = current->left;
        else if(isLeft)
        {
          parent->left = current->left;
        }
        else
        {
          parent->right = current->left;
        }
      }

      //opposite of above
      else if(current->left == NULL) //no right child
      {
        if(current == root)
          root = current->left;
        else if(isLeft)
        {
          parent->left = current->right;
        }
        else
        {
          parent->right = current->right;
        }
      }

      else //node has two children
      {
        TreeNode<T> *successor = getSuccessor(current); //find successor of the node to be deleted (in this case: current)

        if(current == root)
          root = successor;
        else if(isLeft)
        {
          parent->left = successor;
        }
        else
        {
          parent->right = successor;
        }

        successor->left = current->left;
      }
      return true;
    }

    //--------------------------------------------------------------------------------
    TreeNode<T> getSuccessor(TreeNode<T> *d) //d is the node to be deleted
    {
      TreeNode<T> *sp = d; //successors parent
      TreeNode<T> *successor = d;
      TreeNode<T> *current = d->right;

      while(current != NULL)
      {
        sp = successor;
        successor = current;
        current = current->left;
      }

      if(successor != d->right)
      {
        sp->left = successor->right;
        successor->right = d->right;
      }
      return successor;
    }
};
