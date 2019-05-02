/*
Grady Lynch and Frank Entriken
Student ID: 2297574 and 2298368
Emails: grlynch@chapman.edu and entriken@chapman.edu
CPSC 350-01
Assignment 5 - Database
*/

#include <iostream>

using namespace std;

template <class T>
struct TreeNode
{
  public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
      left = NULL;
      right = NULL;
    }

    TreeNode(T d)
    {
      data = d;
      left = NULL;
      right = NULL;
    }

    ~TreeNode()
    {

    }
};
