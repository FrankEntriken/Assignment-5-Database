#include <iostream>

using namespace std;

template <class T>
struct Student
{
  public:
    int id;
    string grade;
    string major;
    double gpa;
    int advisor;

    Student(string id_, string grade_, string major_, double gpa_, int advisor_)
    {
      id = id_;
      grade = grade_;
      major = major_;
      gpa = gpa_;
      advisor = advisor_;
    }

    ~Student()
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
    string getGrade()
    {
      return grade;
    }

    void setGrade(string g)
    {
      grade = g;
    }

    //--------------------------------------------------------------------------------
    string getMajor()
    {
      return major;
    }

    void setMajor(string m)
    {
      major = m;
    }

    //--------------------------------------------------------------------------------
    double getGpa()
    {
      return gpa;
    }

    void setGpa(double g)
    {
      gpa = g;
    }

    //--------------------------------------------------------------------------------
    int getAdvisor()
    {
      return advisor;
    }

    void setAdvisor(int a)
    {
      advisor = a;
    }
};
