/*
Grady Lynch and Frank Entriken
Student ID: 2297574 and 2298368
Emails: grlynch@chapman.edu and entriken@chapman.edu
CPSC 350-01
Assignment 5 - Database
*/

#include <iostream>
#include "BST.h"
#include<limits>
#include <fstream>

using namespace std;

class Database
{
  public:
    //Binary Search Trees of Students and Faculty
    BST<Student> sBST;
    BST<Faculty> fBST;

    //Versions of BST used for saving states
    BST<Student> prev_sBST_1;
    BST<Student> prev_sBST_2;
    BST<Student> prev_sBST_3;
    BST<Student> prev_sBST_4;
    BST<Student> prev_sBST_5;
    BST<Faculty> prev_fBST_1;
    BST<Faculty> prev_fBST_2;
    BST<Faculty> prev_fBST_3;
    BST<Faculty> prev_fBST_4;
    BST<Faculty> prev_fBST_5;

    Database()
    {
      sBST = BST<Student>();
      fBST = BST<Faculty>();
      prev_sBST_1 = BST<Student>();
      prev_sBST_2 = BST<Student>();
      prev_sBST_3 = BST<Student>();
      prev_sBST_4 = BST<Student>();
      prev_sBST_5 = BST<Student>();
      prev_fBST_1 = BST<Faculty>();
      prev_fBST_2 = BST<Faculty>();
      prev_fBST_3 = BST<Faculty>();
      prev_fBST_4 = BST<Faculty>();
      prev_fBST_5 = BST<Faculty>();
    }

    //------------------- 1 -------------------
    //Prints all student information
    void printStudents()
    {
      sBST.recPrint(sBST.root);
    }

    //------------------- 2 -------------------
    //Prints all faculty information
    void printFaculty()
    {
      fBST.recPrint(fBST.root);
    }

    //------------------- 3 -------------------
    //Prints student information based on given id
    void displayStudent(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(x))
        cout << sBST.retrieve(x) << endl;
      else
        cout << " Student " << id << " is not in our database." << endl;
    }

    //------------------- 4 -------------------
    //Prints faculty information based on given id
    void displayFaculty(int id)
    {
      Faculty x = Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList());
      if(fBST.contains(x))
        cout << fBST.retrieve(x) << endl;
      else
        cout << " Faculty member " << id << " is not in our database." << endl;
    }

    //------------------- 5 -------------------
    //Prints student's advisor based on student id
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
    //Prints advisor's advisees based on faculty id
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
    //Adds student to BST
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
      cout << "What is the student's name? ... ";
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

      Student x = Student(id, name, grade, major, gpa, advisor);
      Faculty y = (Faculty(advisor, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
      if(sBST.contains(x))
      {
        cout << "\nStudent with id: " << id << " already exists!" << endl;
      }
      else
      {
        sBST.insert(x);
        cout << "Student has been successfully added" << endl;
        if(fBST.contains(y))
        {
          fBST.retrieve(y).advisees.insertFront(id);
        }
        else
        {
          cin.clear();
        }
      }
    }

    //------------------- 8 -------------------
    //Deletes student from BST
    void deleteStudent(int id)
    {
      Student x = Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(x))
      {
        save();
        sBST.remove(Student(id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000));
      }
      else
      {
        cout << " Student " << id << " is not in our database." << endl;
      }
    }

    //------------------- 9 -------------------
    //Adds faculty to BST
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
      Faculty x = Faculty(id, name, level, department, advisees);
      if(fBST.contains(x))
      {
        cout << "\nFaculty with id: " << id << " already exists!" << endl;
      }
      else
      {
        fBST.insert(x);
        cout << "Faculty has been successfully added" << endl;
        cin.ignore();
        cin.clear();
      }
    }

    //------------------- 10 -------------------
    //Deletes faculty from BST
    void deleteFaculty(int id)
    {
      Faculty x = (Faculty(id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
      if(fBST.contains(x))
      {
        save();
        fBST.remove(x);
      }
      else
      {
        cout << " Faculty " << id << " is not in our database." << endl;
      }
    }

    //------------------- 11 -------------------
    //Changes advisor of student
    void changeAdvisor(int student_id, int faculty_id)
    {
      Student a = Student(student_id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      if(sBST.contains(a))
      {
        save();
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
    //Removes advisee from advisor
    void removeAdvisee(int student_id, int faculty_id)
    {
      Student a = Student(student_id, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000);
      Faculty b = Faculty(faculty_id, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList());
      DoublyLinkedList advisees;

      if(sBST.contains(a) && fBST.contains(b))
      {
        save();
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
    //Rolls back state of BST to one previous
    void rollback()
    {
      // set sBST and fBST to their most recent previous versions
      sBST = prev_sBST_1;
      fBST = prev_fBST_1;

      // rotate all previous BSTs forward
      prev_sBST_1 = prev_sBST_2;
      prev_sBST_2 = prev_sBST_3;
      prev_sBST_3 = prev_sBST_4;
      prev_sBST_4 = prev_sBST_5;

      prev_fBST_1 = prev_fBST_2;
      prev_fBST_2 = prev_fBST_3;
      prev_fBST_3 = prev_fBST_4;
      prev_fBST_4 = prev_fBST_5;
    }

    void save()
    {
      // save current as prev_sBST_1 and rotate all down, deleting memory of prev_sBST_5
      prev_sBST_5 = prev_sBST_4;
      prev_sBST_4 = prev_sBST_3;
      prev_sBST_3 = prev_sBST_2;
      prev_sBST_2 = prev_sBST_1;
      prev_sBST_1 = sBST;

      // save current as prev_fBST_1 and rotate all down, deleting memory of prev_fBST_5
      prev_fBST_5 = prev_fBST_4;
      prev_fBST_4 = prev_fBST_3;
      prev_fBST_3 = prev_fBST_2;
      prev_fBST_2 = prev_fBST_1;
      prev_fBST_1 = fBST;
    }

    void readFile()
    {
    	string line;
      string delimiter = "|";
    	ifstream myfile ("studentTable.txt");
      Student x = Student();
      size_t pos = 0;
      string token;
      int counter = 0;

      if(myfile.is_open())
      {
        while( getline (myfile,line) )
        {
          while((pos = line.find(delimiter)) != std::string::npos)
          {
              token = line.substr(0, pos);
              if(counter == 0)
              {
                // id number
                x.id = stoi(token);
              }
              else if(counter == 1)
              {
                // name
                x.name = token;
              }
              else if(counter == 2)
              {
                // grade
                x.grade = token;
              }
              else if(counter == 3)
              {
                // major
                x.major = token;
              }
              else if(counter == 4)
              {
                // gpa
                x.gpa = stod(token);
              }
              line.erase(0, pos + delimiter.length());
              counter ++;
          }
          // advisor
          x.advisor = stoi(line);
          counter = 0;

          // add student x
          sBST.insert(x);
    		}
    		myfile.close();
    	}

      ifstream myfile2 ("facultyTable.txt");
      Faculty y = Faculty();

      if(myfile2.is_open())
      {
        while( getline (myfile2,line) )
        {
          while((pos = line.find(delimiter)) != std::string::npos)
          {
              token = line.substr(0, pos);
              if(counter == 0)
              {
                // id number
                y.id = stoi(token);
              }
              else if(counter == 1)
              {
                // name
                y.name = token;
              }
              else if(counter == 2)
              {
                // level
                y.level = token;
              }
              else if(counter == 3)
              {
                // department
                y.department = token;
              }
              else
              {
                // advisees
                y.advisees.insertFront(stoi(token));
              }
              line.erase(0, pos + delimiter.length());
              counter ++;
          }
          // remaining advisee
          y.advisees.insertFront(stoi(line));
          counter = 0;

          // add faculty member y
          fBST.insert(y);
    		}
    		myfile2.close();
    	}
    }

    //Clears tables
    void clearFiles()
    {
      std::ofstream myfile;
      myfile.open("studentTable.txt", std::ofstream::out | std::ofstream::trunc);
      myfile.open("facultyTable.txt", std::ofstream::out | std::ofstream::trunc);
    }

    //Writes student tables to output file
    void recWriteFileS(TreeNode<Student> *node)
    {
      if(node == NULL)
        return;

      recWriteFileS(node->left);

      std::ofstream myfile;
      myfile.open("studentTable.txt", std::ofstream::app);
      if (myfile.is_open())
      {
        myfile << (node->data).id << "|" << (node->data).name << "|" << (node->data).grade << "|" << (node->data).major << "|" << (node->data).gpa << "|" << (node->data).advisor << "\n";
      }
      myfile.close();

      recWriteFileS(node->right);
    }

    //Writes faculty tables to output file
    void recWriteFileF(TreeNode<Faculty> *node)
    {
      if(node == NULL)
        return;

      recWriteFileF(node->left);

      std::ofstream myfile;
      myfile.open("facultyTable.txt", std::ofstream::app);
      if (myfile.is_open())
      {
        myfile << (node->data).id << "|" << (node->data).name << "|" << (node->data).level << "|" << (node->data).department << (node->data).advisees << "\n";
      }
      myfile.close();

      recWriteFileF(node->right);
    }

    //------------------- 14 -------------------
    //Exits database
    void exitProgram()
    {

      //write to file
      clearFiles();
      recWriteFileS(sBST.root);
      recWriteFileF(fBST.root);

      cout << "Exiting Program" << endl;
      exit(0);
    }

    //------------------------------------------
    //Runs database
    void Process()
    {
      //read from file and create BST
      readFile();

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
          rollback();
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
        }
      }
    }
};
