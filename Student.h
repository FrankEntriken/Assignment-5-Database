/*
Grady Lynch and Frank Entriken
Student ID: 2297574 and 2298368
Emails: grlynch@chapman.edu and entriken@chapman.edu
CPSC 350-01
Assignment 5 - Database
*/

#include <iostream>

using namespace std;

struct Student
{
  public:
    int id;
    string name;
    string grade;
    string major;
    double gpa;
    int advisor;

    // == overload
    friend bool operator==(const Student& student1, const Student& student2)
    {
      return (student1.id == student2.id);
    }

    // != overload
    friend bool operator!=(const Student& student1, const Student& student2)
    {
      return (student1.id != student2.id);
    }

    // < overload
    friend bool operator<(const Student& student1, const Student& student2)
    {
      return (student1.id < student2.id);
    }

    // > overload
    friend bool operator>(const Student& student1, const Student& student2)
    {
      return (student1.id > student2.id);
    }

    // >> overload (for printing a students data)
    friend ostream& operator<<(ostream& os, const Student& s)
    {
      os << s.id << ", " << s.name << " | " << s.grade << " " << s.major << " major | GPA: " << s.gpa << " | Advisor ID: " << s.advisor;
      return os;
    }

    // constructor
    Student(int id_, string name_, string grade_, string major_, double gpa_, int advisor_)
    {
      id = id_;
      name = name_;
      grade = grade_;
      major = major_;
      gpa = gpa_;
      advisor = advisor_;
    }

    // default constructor
    Student()
    {
      id = 0;
      name = "Unknown";
      grade = "Unknown";
      major = "Unknown";
      gpa = 0.0;
      advisor = 0;
    }

    ~Student()
    {

    }
};
