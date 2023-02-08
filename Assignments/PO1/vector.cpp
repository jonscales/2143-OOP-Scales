/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 1
  Vector Class
  ******************************************/

#include "vector.h"
#include <fstream>
#include <iostream>

using namespace std;
// Vector Class Function Definitions
// Constructors
// Default constructor
Vector::Vector() { front = rear = current = travel = before = nullptr; }
// Constructor to get values from an array
Vector::Vector(int *A, int size) {
  cout << "constructing a vector from an array" << endl;
  front = rear = current = travel = before = nullptr;
  for (int i = 0; i < size; i++)
    pushRear(A[i]);
}
// Constructor to get values from a file
Vector::Vector(string FileName) {
  cout << "constructing a vector from a file" << endl;
  front = rear = current = travel = before = nullptr;
  int val;
  ifstream fin;
  fin.open(FileName);
  while (fin >> val) { // get a value from the file
    pushRear(val);
  }
  fin.close();
}
// copy constructor to copy one vector into another
// inline function  in vector.h

// destructor
Vector::~Vector() {}

// add node to beginning of list and update all nodenumbers
void Vector::pushFront(int val) {
  node *temp = new node(1, val);
  // is there just a null node? Then make new node the 1st & last node
  if (front == nullptr && rear == nullptr) {
    front = rear = temp;
  } // else there are >1 existing nodes
  else {
    temp->next = front; // make new node point to existing front node
    front->previous =
        temp;     // make existing front previous pointer point to new node
    front = temp; // make existing 1st node pointer point to new node
    // delete temp;  //no longer need temp pointer
    current = front; // set the current position as the 1st node
  }
  // increment all the subsequent nodenumbers
  while (current->next != nullptr && current != nullptr) {
    current->next->nodenumber++; // add 1 to all other nodenumber values
    current = current->next;     // move the position of the current pointer
  }
  // current should now point to the last node so set rear=current
  rear = current;
}

// add node to rear of list
void Vector::pushRear(int val) {
  /*cout << "rear nodenumber = " << rearNN() << endl;
  cout << "rear value = " << rearVal() << endl;
  cout << "nodenumber of new node = " << rear->nodenumber + 1 << endl;*/

  // if only null node, new node becomes both front & rear node
  if (front == nullptr) {
    node *temp = new node(1, val);
    front = rear = temp;
  }
  // if >1 node
  else {
    node *temp = new node((rear->nodenumber + 1), val);
    rear->next = temp;     // points existing rear to new node
    temp->previous = rear; // points new previous node to existing rear node
    rear = temp;           // moves rear pointer to point to new last node
  }
}

// Add a node at a specified location within the list
void Vector::pushAt(int loc, int val) {
  // if position to insert beyond end of list add new node to end
  if (loc > rear->nodenumber) {
    cout << "Invalid position to insert - beyond list length. New value will "
            "be added to rear of list"
         << endl;
    pushRear(val);

    cout << "new list = " << endl;
    print();
    cout << endl;
  }
  // if location to insert is 1st position, just pushFront
  else if (loc == 1) {
    cout << "Value will be added to beginning of list " << endl;
    pushFront(val);
    cout << "New list is : " << endl;
    print();
    cout << endl;
  }
  // if insertion location is anywhere in middle of list
  else {
    current = front;
    before = front;
    cout << "in pushAt, at node = " << current->nodenumber << endl;
    // cout << "finding the correct node " << endl;
    while ((current->nodenumber) != loc) {
      // cout << "current node is " << current->nodenumber << endl;
      current = current->next;
      //  cout << "now current is " << current->nodenumber << endl;
      before = current->previous;
      //   cout << "before points to node " << before->nodenumber << endl;
    }
    // create new node at current position as nodenumber
    node *temp = new node(loc, val);
    cout << "Making a new node # " << temp->nodenumber << endl;
    current->previous = temp;
    temp->next = current;
    temp->previous = before;
    before->next = temp;
    // loop to add 1 to all following nodenumbers
    for (int i = 1; i <= ((rear->nodenumber) - (current->nodenumber)); i++) {
      current->nodenumber = current->nodenumber + 1;
      current = current->next;
    }
    cout << "The new list is : " << endl;
    print();
    cout << endl;
  }
}
// inOrderPush function will add smallest value to front of list, largest value
// to rear of list if the value to add is smaller or larger respectively than
// that at the front or rear node, otherwise, it will search through list and
// add new value to a new node following a node with a value less than the new
// value.
void Vector::inOderPush(int val) {
  if (val < front->value) {
    pushFront(val);
  } else if (val > rear->value) {
    pushRear(val);
  } else {
    current = front;
    before = current->previous;
    while (current->value < val) {
      current = current->next;
      before = current->previous;
    }
    pushAt((current->nodenumber), val);
  }
}
// traversing function to print out each node's contents w/o using overloaded <<
void Vector::print() {
  travel = front;
  cout << "[ ";
  while (travel != nullptr) {
    cout << travel->value;
    if (travel->next != nullptr) {
      cout << ", ";
    }
    travel = travel->next;
  }
  cout << " ]";
}
// function to return the data value of 1st node
int Vector::frontVal() {
  int FVal = front->value;
  return FVal;
}
// fuction to return the list position number of the first node
int Vector::frontNN() { return front->nodenumber; }

// function to return the data value of the last node
int Vector::rearVal() {
  int RVal = rear->value;
  return RVal;
}
// function to return the list position number of the last node = the size of
// the list
int Vector::rearNN() { return rear->nodenumber; }

// remove and return the data from the 1st node & update node numbers
int Vector::popFront() {
  if (front == nullptr) {
    cout << "The list is empty";
  }
  int Fnodeval = front->value;
  if (front->next != nullptr) {
    front = front->next;
    front->previous = nullptr;
    current = front;
  }
  // remove the 1st node pointer and decrement remaining nodevalues
  for (int i = 1; i <= ((rear->nodenumber) - 1); i++) {
    current->nodenumber = current->nodenumber - 1;
    current = current->next;
  }
  return Fnodeval;
}

// remove and return the data from the last node
int Vector::popRear() {
  if (rear == nullptr) {
    cout << "The list is empty";
  }
  int Rnodeval = rear->value;
  rear = rear->previous;
  rear->next = nullptr;
  return Rnodeval;
}
int Vector::popAt(int loc) {
  if (front == nullptr) {
    cout << "The list is empty";
  }
  current = front;
  while ((current->nodenumber != loc) && (current != nullptr)) {
    current = current->next;
  }
  int Curnodeval = current->value;
  current->previous->next = current->next;
  current->next = nullptr;
  // decrement nodes after pop position
  for (int i = 1; i <= ((rear->nodenumber) - (current->nodenumber)); i++) {
    current->nodenumber = current->nodenumber - 1;
    current = current->next;
  }
  return Curnodeval;
}
// finds the firts instance of a value in the vector list
int Vector::find(int val) {
  if (front == nullptr) {
    cout << "The list is empty";
    return 0;
  } else {
    current = front;
    while (current->value != val) {
      current = current->next;
    }
    return current->nodenumber;
  }
}
// counts how many times a specified value appears in the list
int Vector::numVals(int val) {
  if (front == nullptr) {
    cout << "The list is empty";
    return 0;
  } else {
    current = front;
    int count = 0;
    for (int i = 1; i <= rear->nodenumber; i++) {
      if (current->value == val) {
        count++;
        current = current->next;
      } else
        current = current->next;
    }
    return count;
  }
}
// appends second vector to rear of current vector
void Vector::pushRear(Vector V2) {
  cout << "appending 2nd vector to rear of 1st; modifying the origional vector" << endl;
  if (V2.front == nullptr) {
    cout << "second vector is empty";
    cout << "The new vector " << this << " was not modified " << endl;
  } else {
    node *travel = V2.front;
    while (travel) {
      pushRear(travel->value);
      travel = travel->next;
    }
  }
}
// appends second vector to front of current vector
void Vector::pushFront(Vector V2) {
  cout << "appending 2nd vector to front of 1st ; modifying the origional vector "
       << endl;
  if (V2.front == nullptr) {
    cout << "second vector is empty";
    cout << "The new vector " << this << " was not modified " << endl;
  } else {
    node *travel = V2.rear;
    while (travel) {
      pushFront(travel->value);
      travel = travel->previous;
    }
  }
}
