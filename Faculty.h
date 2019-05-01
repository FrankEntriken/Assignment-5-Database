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

    //--------------------------------------------------------------------------------
    int getId()
    {
      return id;
    }

    void setId(int i)
    {
      id = i;
    }

    //--------------------------------------------------------------------------------
    string getName()
    {
      return name;
    }

    void setName(string n)
    {
      name = n;
    }

    //--------------------------------------------------------------------------------
    string getLevel()
    {
      return level;
    }

    void setLevel(string l)
    {
      level = l;
    }

    //--------------------------------------------------------------------------------
    string getDepartment()
    {
      return department;
    }

    void setDepartment(string d)
    {
      department = d;
    }

    //--------------------------------------------------------------------------------
    DoublyLinkedList getAdvisees()
    {
      return advisees;
    }

    void setAdvisees(int a)
    {
      advisees.insertFront(a);
    }
};
