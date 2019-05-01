#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
//#include "DoublyLinkedList.h"

using namespace std;

class Database
{
  public:
    BST<Student> sBST;
    BST<Faculty> fBST;

    Database()
    {
      sBST = BST<Student>();
      fBST = BST<Faculty>();
    }


    //------------------- 1 -------------------
    void printStudents()
    {
      sBST.recPrint(sBST.root);
    }

    //------------------- 2 -------------------
    void printFaculty()
    {
      fBST.recPrint(fBST.root);
    }

    //------------------- 3 -------------------
    void displayStudent(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(x))
        cout << sBST.retrieve(x) << endl;
      else
        cout << " Student " << id << " is not in our database." << endl;
    }

    //------------------- 4 -------------------
    void displayFaculty(int id)
    {
      Faculty x = Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList());
      if(fBST.contains(x))
        cout << fBST.retrieve(x) << endl;
      else
        cout << " Faculty member " << id << " is not in our database." << endl;
    }

    //------------------- 5 -------------------
    void displayAdvisor(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(x))
      {
        int advisor = sBST.retrieve(x).advisor;
        displayFaculty(advisor);
      }
      else
        cout << " Student " << id << " is not in our database." << endl;
    }

    //------------------- 6 -------------------
    void displayAdvisees(int id)
    {
      Faculty x = Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList());
      DoublyLinkedList advisees;
      if(fBST.contains(x))
      {
        advisees = fBST.retrieve(x).advisees;
        ListNode *ptr = advisees.front;
        while(ptr != NULL)
        {
          displayStudent(ptr->data);
          ptr = ptr -> next;
        }
      }
      else
        cout << " Faculty member " << id << " is not in our database." << endl;
    }

    //------------------- 7 -------------------
    void addStudent()
    {
      int id;
      string name;
      string grade;
      string major;
      double gpa;
      int advisor;

      cout << "ADD NEW STUDENT" << endl;
      cout << "What is the student's id? ... ";
      cin >> id;
      cout << "What is the student's name? ... "; //typing first name and last name ("Jon Apple") will skip the next cin (grade)
      cin >> name;
      cout << "What is the student's grade? ... ";
      getline(cin, grade);
      cout << "What is the student's major? ... ";
      cin >> major;
      cout << "What is the student's gpa? ... ";
      cin >> gpa;
      cout << "What is the id number of the student's advisor? ... ";
      cin >> advisor;

      sBST.insert(Student(id, name, grade, major, gpa, advisor));
      cout << "Student has been successfully added" << endl;
    }

    //------------------- 8 -------------------
    void deleteStudent(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      sBST.remove(x);
    }

    //------------------- 9 -------------------
    void addFaculty()
    {
      int id;
      string name;
      string level;
      string department;
      DoublyLinkedList advisees;
      int advisee;

      cout << "ADD NEW FACULTY" << endl;
      cout << "What is the faculty's id? ... ";
      cin >> id;
      cout << "What is the faculty's name? ... ";
      cin >> name;
      cout << "What is the faculty's level? ... ";
      cin >> level;
      cout << "What is the faculty's department? ... ";
      cin >> department;
      cout << "Enter the id's of this advisor's advisees one at a time" << endl;
      cout << "If you are finished entering advisees, enter any letter to finish ... ";
      while(cin >> advisee)
      {
        advisees.insertFront(advisee);
        cout << "Enter another id or type any letter to finish ... ";
      }
      fBST.insert(Faculty(id, name, level, department, advisees));
      cout << "Faculty has been successfully added" << endl;
    }

    //------------------- 10 -------------------
    void deleteFaculty(int id)
    {
      Faculty x = (Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
      fBST.remove(x);
    }


    //------------------- 11 -------------------
    void changeAdvisor(int student_id, int faculty_id)
    {

    }

    //------------------- 12 -------------------
    void removeAdvisee(int student_id, int faculty_id)
    {

    }

    //------------------- 13 -------------------
    void rollback()
    {

    }

    //------------------- 14 -------------------
    void exitProgram()
    {
      cout << "Exiting Program" << endl;
      exit(0);
    }

};
