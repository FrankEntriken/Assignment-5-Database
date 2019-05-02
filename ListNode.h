/*
Grady Lynch and Frank Entriken
Student ID: 2297574 and 2298368
Emails: grlynch@chapman.edu and entriken@chapman.edu
CPSC 350-01
Assignment 5 - Database
*/

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
