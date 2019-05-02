/*
Grady Lynch and Frank Entriken
Student ID: 2297574 and 2298368
Emails: grlynch@chapman.edu and entriken@chapman.edu
CPSC 350-01
Assignment 5 - Database
*/

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

struct Faculty
{
  public:
    int id;
    string name;
    string level;
    string department;
    DoublyLinkedList advisees;

    // == overload
    friend bool operator==(const Faculty& faculty1, const Faculty& faculty2)
    {
      return (faculty1.id == faculty2.id);
    }

    // != overload
    friend bool operator!=(const Faculty& faculty1, const Faculty& faculty2)
    {
      return (faculty1.id != faculty2.id);
    }

    // < overload
    friend bool operator<(const Faculty& faculty1, const Faculty& faculty2)
    {
      return (faculty1.id < faculty2.id);
    }

    // > overload
    friend bool operator>(const Faculty& faculty1, const Faculty& faculty2)
    {
      return (faculty1.id > faculty2.id);
    }

    // >> overload (for printing a faculty member's data)
    friend ostream& operator<<(ostream& os, const Faculty& f)
    {
      os << f.id << ", " << f.name << " | " << f.level << " of the " << f.department;
      return os;
    }

    // constructor
    Faculty(int id_, string name_, string level_, string department_, DoublyLinkedList advisees_)
    {
      id = id_;
      name = name_;
      level = level_;
      department = department_;
      advisees = advisees_; // rather that take a list as an argument, a list will be created and can be added to using setAdvisees()
    }

    // default constructor
    Faculty()
    {
      id = 0;
      name = "Unknown";
      level = "Unknown";
      department = "Unknown";
      advisees = DoublyLinkedList();
    }

    ~Faculty()
    {

    }
};
