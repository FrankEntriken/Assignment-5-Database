#include <iostream>
#include "ListNode.h"

using namespace std;

class DoublyLinkedList
{
  public:
    ListNode *front;
    ListNode *back;
    unsigned int size;

    // >> overload
    friend ostream& operator<<(ostream& os, const DoublyLinkedList& d)
    {
      ListNode *curr = d.front;

      while(curr != NULL)
      {
        os << "|" << curr -> data;
        curr = curr -> next;
      }
      return os;
    }

    DoublyLinkedList()
    {
      front = new ListNode();
      back = new ListNode();
      size = 0;
    }
    ~DoublyLinkedList()
    {
      //build some character
      //doubly linked list differ a bit from a single linked list
      //clear(); is a function from the example that clears the list
      //delete front;
      //delete back;
    }
    void insertFront(int d)
    {
      ListNode *node = new ListNode(d);

      if(isEmpty())
      {
        front = node;
        back = node;
        node->next = NULL;
        node->prev = NULL;
      }
      else
      {
        ListNode *actualFirst = front;

        front = node;
        node->next = actualFirst;
        actualFirst->prev = node;
        node->prev = NULL;
      }
      size++;
    }
    void insertBack(int d)
    {
      ListNode *node = new ListNode(d);

      if(isEmpty())
      {
        front = node;
      }
      else
      {
        back->next = node;
        node->prev = back;
      }

      back = node;

      size++;
    }
    int removeFront()
    {
      --size;
      int temp = front -> data;
      ListNode *ft = front;
      front = front -> next;
      ft -> next = NULL;
      delete ft;
      return temp;
    }
    void removePosition(int pos)
    {
      ListNode *curr = front;

      for(int i = 0; i < pos; i++)
      {
        curr = curr -> next;
      }

      if(curr == NULL)
      {
        cout << "removePosition Error: Position is NULL" << endl;
        return;
      }

      //we found our ListNode
      if(curr == front)
      {
        front = curr -> next;
      }
      else
      {
        curr -> prev -> next = curr -> next;
      }

      //check if back ListNode
      if(curr == back)
      {
        back = curr -> prev;
      }
      else
      {
        curr -> next -> prev = curr -> prev;
      }
    }
    void deleteNode(int d)
    {
      int pos = find(d);
      removePosition(pos);
    }
    void printList()
    {
      ListNode *curr = front;

      while(curr != NULL)
      {
        cout << curr -> data << " ";
        curr = curr -> next;
      }
      cout << endl;
    }
    int find(int d) //search method
    {
      int index = -1;
      ListNode *curr = front;

      while(curr != NULL)
      {
        ++index;
        if(curr -> data == d)
        {
          break;
        }
        else
        {
          curr = curr -> next;
        }
      }

      if(curr == NULL)
      {
        index = -1;
      }
      return index;
    }
    bool isEmpty()
    {
      return (size == 0);
    }
    unsigned int getSize()
    {
      return size;
    }
    int getFront()
    {
      return front->data;
    }
};
