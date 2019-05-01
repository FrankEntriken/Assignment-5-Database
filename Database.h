#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

class Database
{
  public:
    BST<int> sBST;
    BST<int> fBST;


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

    }

    //------------------- 4 -------------------
    void displayFaculty(int id)
    {

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
    void exit()
    {
      cout << "Exiting Program" << endl;
      exit(0);
    }

};
