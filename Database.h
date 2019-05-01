#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

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

    }

    //------------------- 6 -------------------
    void displayAdvisees(int id)
    {

    }

    //------------------- 7 -------------------
    void addStudent(const Student& s)
    {

    }

    //------------------- 8 -------------------
    void deleteStudent(int id)
    {

    }

    //------------------- 9 -------------------
    void addFaculty(const Faculty& f)
    {

    }

    //------------------- 10 -------------------
    void deleteFaculty(int id)
    {

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
