#include <iostream>
#include <list>

using namespace std;

template <class T>
struct Faculty
{
  public:
    int id;
    string name;
    string level;
    string department;
    list<int> advisee;

    Faculty(string id_, string name_, string level_, string department_, list<int> advisee_)
    {
      id = id_;
      name = name_;
      level = level_;
      department = department_;
      advisee = advisee_;
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
    list<int> getAdvisee()
    {
      return advisee;
    }

    void setAdvisee(int a)
    {
      advisee = a;
    }
};
