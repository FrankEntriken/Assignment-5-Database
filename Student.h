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
