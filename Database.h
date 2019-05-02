#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include<limits>

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
      cin.clear();
      cout << "What is the student's name? ... "; //typing first name and last name ("Jon Apple") will skip the next cin (grade)
      cin.ignore();
      getline(cin, name);
      cout << "What is the student's grade? ... ";
      getline(cin, grade);
      cout << "What is the student's major? ... ";
      getline(cin, major);
      cout << "What is the student's gpa? ... ";
      cin >> gpa;
      cin.clear();
      cout << "What is the id number of the student's advisor? ... ";
      cin >> advisor;

      sBST.insert(Student(id, name, grade, major, gpa, advisor));
      Faculty x = (Faculty(advisor, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
      fBST.retrieve(x).advisees.insertFront(id);

      cout << "Student has been successfully added" << endl;
    }

    //------------------- 8 -------------------
    void deleteStudent(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(x))
      {
        sBST.remove(Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000));
      }
      else
      {
        cout << " Student " << id << " is not in our database." << endl;
      }
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
      cin.ignore();
      getline(cin, name);
      cout << "What is the faculty's level? ... ";
      getline(cin, level);
      cout << "What is the faculty's department? ... ";
      getline(cin, department);
      cout << "If you are finished entering advisees, enter any letter to finish" << endl;
      cout << "Enter the id's of this advisor's advisees one at a time ... ";
      while(cin >> advisee)
      {
        advisees.insertFront(advisee);
        cout << "Enter another id or type any letter to finish ... ";
      }
      fBST.insert(Faculty(id, name, level, department, advisees));
      cout << "Faculty has been successfully added" << endl;
      cin.ignore();
      cin.clear();
    }

    //------------------- 10 -------------------
    void deleteFaculty(int id)
    {
      Faculty x = (Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
      if(fBST.contains(x))
      {
        fBST.remove(x);
      }
      else
      {
        cout << " Faculty " << id << " is not in our database." << endl;
      }
    }

    //------------------- 11 -------------------
    void changeAdvisor(int student_id, int faculty_id)
    {
      Student a = Student(student_id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(a))
      {
        Student x = Student(sBST.retrieve(a).id, sBST.retrieve(a).name, sBST.retrieve(a).grade, sBST.retrieve(a).major, sBST.retrieve(a).gpa, faculty_id);
        sBST.remove(a);
        sBST.insert(x);
      }
      else
      {
        cout << " Student " << student_id << " is not in our database." << endl;
      }
    }

    //------------------- 12 -------------------
    void removeAdvisee(int student_id, int faculty_id)
    {
      Student a = Student(student_id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      Faculty b = Faculty(faculty_id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList());
      DoublyLinkedList advisees;

      if(sBST.contains(a) && fBST.contains(b))
      {
        advisees = fBST.retrieve(b).advisees;
        advisees.deleteNode(student_id);
        Faculty x = Faculty(fBST.retrieve(b).id, fBST.retrieve(b).name, fBST.retrieve(b).level, fBST.retrieve(b).department, advisees);
        fBST.remove(b);
        fBST.insert(x);
      }
      else if(sBST.contains(a))
      {
        cout << " Student " << student_id << " is not in our database." << endl;
      }
      else if(fBST.contains(b))
      {
        cout << " Faculty " << faculty_id << " is not in our database." << endl;
      }
      else
      {
        cout << " Student " << student_id << " is not in our database." << endl;
        cout << " Faculty " << faculty_id << " is not in our database." << endl;
      }
    }
    //------------------- 13 -------------------
    void rollback()
    {
      cout << "not implemented" << endl;

      /*
      Create a list that is written to whenever a change happens
      Functions that can be rolled back: 7-12
      Whenever these functions run, they insert to a stack
      Pop stack and see what the last change was to revert
      */
    }

    //------------------- 14 -------------------
    void exitProgram()
    {

      //write to file

      cout << "Exiting Program" << endl;
      exit(0);
    }

    //------------------------------------------
    void Process()
    {

      //read from file and create BST

      int response;
      int id;
      while(true)
      {
        response = 0;
        cout << "\n------------------------- STUDENT AND FACULTY DATABASE -------------------------" << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)"             << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)"              << endl;
        cout << "3. Find and display student information given the students id"                      << endl;
        cout << "4. Find and display faculty information given the faculty id"                       << endl;
        cout << "5. Given a student’s id, print the name and info of their faculty advisor"          << endl;
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees"            << endl;
        cout << "7. Add a new student"                                                               << endl;
        cout << "8. Delete a student given the id"                                                   << endl;
        cout << "9. Add a new faculty member"                                                        << endl;
        cout << "10. Delete a faculty member given the id"                                           << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id"         << endl;
        cout << "12. Remove an advisee from a faculty member given the ids"                          << endl;
        cout << "13. Rollback"                                                                       << endl;
        cout << "14. Exit"                                                                           << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << " ... ";
        cin >> response;

        if(response == 1)
        {
          printStudents();
          cin.clear();
        }
        if(response == 2)
        {
          printFaculty();
        }
        if(response == 3)
        {
          cout << "Enter the id of the student you would like to print ... ";
          cin >> id;
          displayStudent(id);
        }
        if(response == 4)
        {
          cout << "Enter the id of the faculty you would like to print ... ";
          cin >> id;
          displayFaculty(id);
        }
        if(response == 5)
        {
          cout << "Enter the id of the student whose advisor you would like to print ... ";
          cin >> id;
          displayAdvisor(id);
        }
        if(response == 6)
        {
          cout << "Enter the id of the faculty whose advisees you would like to print ... ";
          cin >> id;
          displayAdvisees(id);
        }
        if(response == 7)
        {
          addStudent();
        }
        if(response == 8)
        {
          cout << "Enter the id of the student who you would like to delete ... ";
          cin >> id;
          deleteStudent(id);
        }
        if(response == 9)
        {
          addFaculty();
        }
        if(response == 10)
        {
          cout << "Enter the id of the faculty who you would like to delete ... ";
          cin >> id;
          deleteFaculty(id);
        }
        if(response == 11)
        {
          int sid, fid;
          cout << "Enter the id of the student whose advisor you would like to change ... ";
          cin >> sid;
          cout << "Enter the id of the advisor ... ";
          cin >> fid;
          changeAdvisor(sid, fid);
        }
        if(response == 12)
        {
          int sid, fid;
          cout << "Enter the id of the faculty whose advisee you would like to remove ... ";
          cin >> fid;
          cout << "Enter the id of the advisee (student) ... ";
          cin >> sid;
          removeAdvisee(sid, fid);
        }
        if(response == 13)
        {
          cout << "Not yet implemented" << endl;
        }
        if(response == 14)
        {
          exitProgram();
          return;
        }
        else
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); //https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
          cout << "Please enter a valid number" << endl;
        }
      }
    }
};
