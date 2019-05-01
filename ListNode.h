#include <iostream>

using namespace std;

class ListNode
{
  public:
    int data;
    ListNode *next; //pointer to next
    ListNode *prev; //pointer to previous

    ListNode()
    {
      //default constructor
      /*data = T();
      ListNode *next = NULL;
      ListNode *prev = NULL;*/
    }
    ListNode(int d) //overload constuctor
    {
      data = d;
      next = NULL; //some compilers take nullptr
      prev = NULL;
    }
    ~ListNode()
    {
      // destructor
    }
};
