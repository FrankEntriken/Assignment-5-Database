#include <iostream>
#include "Database.h"

using namespace std;

main()
{
  /*
  BST<int> bst;
  bst.insert(10);
  bst.insert(98);
  bst.insert(8);
  bst.insert(7);
  bst.insert(1);
  bst.insert(30);
  bst.insert(32);
  bst.insert(100);
  bst.recPrint(bst.root);

  cout << "REMOVE 8" << endl;
  bst.remove(8);
  bst.recPrint(bst.root);

  cout << "REMOVE 98" << endl;
  bst.remove(98);
  bst.recPrint(bst.root);

  cout << "REMOVE 30" << endl;
  bst.remove(30);
  bst.recPrint(bst.root);
  */
/*
  BST<Student> bst;
  bst.insert(Student(2297510, "Student A", "Freshman", "Business", 2.9, 0000005));
  bst.insert(Student(2297598, "Student B", "Freshman", "English", 3.6, 0000005));
  bst.insert(Student(2297508, "Student C", "Freshman", "Undecided", 2.3, 0000006));
  bst.insert(Student(2297507, "Student D", "Sophmore", "Comp Sci", 3.4, 0000006));
  bst.insert(Student(2297501, "Student E", "Sophmore", "Business", 3.1, 0000007));
  bst.insert(Student(2297530, "Student F", "Junior", "Political Sci", 3.5, 0000007));
  bst.insert(Student(2297532, "Student G", "Junior", "Physics", 3.7, 0000010));
  bst.insert(Student(2297600, "Student H", "Senior", "Chemistry", 3.1, 0000011));
  bst.recPrint(bst.root);

  cout << "REMOVE Student ID 2297508" << endl;
  bst.remove(Student(2297508, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000));
  bst.recPrint(bst.root);

  cout << "REMOVE Student ID 2297598" << endl;
  bst.remove(Student(2297598, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000));
  bst.recPrint(bst.root);

  cout << "REMOVE Student ID 2297530" << endl;
  bst.remove(Student(2297530, "irrelevant", "irrelevant", "irrelevant", 0.0, 0000000));
  bst.recPrint(bst.root);
  */

  BST<Faculty> bst;
  bst.insert(Faculty(2297356, "Faculty A", "Professor", "Science Department", DoublyLinkedList()));
  bst.insert(Faculty(2297832, "Faculty B", "Professor", "Business School", DoublyLinkedList()));
  bst.insert(Faculty(2297111, "Faculty C", "Professor", "Medical School", DoublyLinkedList()));
  bst.insert(Faculty(2297990, "Faculty D", "Professor", "Law School", DoublyLinkedList()));
  bst.insert(Faculty(2297586, "Faculty E", "Professor", "Art School", DoublyLinkedList()));
  bst.insert(Faculty(2297293, "Faculty F", "Professor", "Education Department", DoublyLinkedList()));
  bst.insert(Faculty(2297444, "Faculty G", "Department Head", "Science Department", DoublyLinkedList()));
  bst.insert(Faculty(2297600, "Faculty H", "Department Head", "Business School", DoublyLinkedList()));
  bst.recPrint(bst.root);

  cout << "REMOVE Faculty ID 2297832" << endl;
  bst.remove(Faculty(2297832, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
  bst.recPrint(bst.root);

  cout << "REMOVE Faculty ID 2297990" << endl;
  bst.remove(Faculty(2297990, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
  bst.recPrint(bst.root);

  cout << "REMOVE Faculty ID 2297356" << endl;
  bst.remove(Faculty(2297356, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList()));
  bst.recPrint(bst.root);

  cout << "testing insertion of a faculty member with > 0 advisees (Faculty X)" << endl;
  Faculty a = Faculty(2297356, "Faculty X", "Professor", "Science Department", DoublyLinkedList());
  a.advisees.insertFront(2297574);
  bst.insert(a);
  bst.recPrint(bst.root);

  cout << "SEARCH" << endl;
  cout << bst.contains(Faculty(2297356, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList())) << endl;
  cout << bst.retrieve(Faculty(2297356, "irrelevant", "irrelevant", "irrelevant", DoublyLinkedList())) << endl;

  cout << endl;
  cout << endl;
  cout << "testing the database functions" << endl;
  cout << endl;

  Database d = Database();

  d.sBST.insert(Student(2297510, "Student A", "Freshman", "Business", 2.9, 2297990));
  d.sBST.insert(Student(2297598, "Student B", "Freshman", "English", 3.6, 0000005));
  d.sBST.insert(Student(2297508, "Student C", "Freshman", "Undecided", 2.3, 0000006));
  d.sBST.insert(Student(2297507, "Student D", "Sophmore", "Comp Sci", 3.4, 0000006));
  d.sBST.insert(Student(2297501, "Student E", "Sophmore", "Business", 3.1, 0000007));
  d.sBST.insert(Student(2297530, "Student F", "Junior", "Political Sci", 3.5, 0000007));
  d.sBST.insert(Student(2297532, "Student G", "Junior", "Physics", 3.7, 0000010));
  d.sBST.insert(Student(2297600, "Student H", "Senior", "Chemistry", 3.1, 0000011));

  d.fBST.insert(Faculty(2297356, "Faculty A", "Professor", "Science Department", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297832, "Faculty B", "Professor", "Business School", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297111, "Faculty C", "Professor", "Medical School", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297990, "Faculty D", "Professor", "Law School", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297586, "Faculty E", "Professor", "Art School", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297293, "Faculty F", "Professor", "Education Department", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297444, "Faculty G", "Department Head", "Science Department", DoublyLinkedList()));
  d.fBST.insert(Faculty(2297600, "Faculty H", "Department Head", "Business School", DoublyLinkedList()));

  d.printStudents();
  cout << endl;
  d.printFaculty();
  cout << endl;

  d.displayStudent(2297530);
  cout << endl;
  d.displayFaculty(2297356);

  cout << "5. Display Advisor" << endl;
  d.displayAdvisor(2297510);

  //cout << "6. Display Advisees" << endl;
  //d.displayAdvisees(2297356);

  cout << "7. Add Student" << endl;
  //d.printStudents();
  //d.addStudent();
  //d.printStudents();
  d.printFaculty();
  d.addFaculty();
  d.printFaculty();
}
