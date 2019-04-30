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
