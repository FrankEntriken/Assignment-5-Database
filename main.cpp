#include <iostream>
#include "BST.h"

using namespace std;

main()
{
  BST<int> bst;
  bst.insert(10);
  bst.insert(98);
  bst.insert(8);
  bst.insert(7);
  bst.insert(1);
  bst.insert(30);
  bst.insert(32);
  bst.insert(100);
  bst.recPrint(bst.root);

  cout << "REMOVE 8" << endl;
  bst.remove(10);
  bst.recPrint(bst.root);
}
