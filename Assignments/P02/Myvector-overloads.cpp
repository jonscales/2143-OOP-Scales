/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 2
  MyVector Class - overloading operators
  ******************************************/

#include "Myvector.h"
#include <fstream>
#include <iostream>

using namespace std;
/*************************************
// Vector Class Function Definitions *
**************************************/

// CONSTRUCTORS
/***********************************
// Default constructor
*************************************/
Vector::Vector() { front = rear = current = travel = before = nullptr; }

/***********************************
/ Constructor from an array
*************************************/
Vector::Vector(int *A, int size) {
  cout << "constructing a vector from an array" << endl;
  front = rear = current = travel = before = nullptr;
  for (int i = 0; i < size; i++)
    pushRear(A[i]);
}

/***********************************
/ Constructor from from a file
*************************************/
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

/*************************************************
/ destructor
***************************************************/
Vector::~Vector() {}

/******************************************
/ MODIFYER FUNCTIONS
******************************************/

/****************************************
/     pushFront
/ add node to beginning of list and update
/ subsequent nodenumbers
****************************************/
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

/****************************************
/     pushRear
/ add node to rear of list
****************************************/
void Vector::pushRear(int val) {
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
/****************************************
/     pushAt
/ Add a node at a specified nodenumber location
/ within the list & increment subsequent nodenumbers
****************************************/
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

/*******************************************
/ inOrderPush
/ add smallest value to front of list, largest value
/ to rear of list if the value to add is smaller or
/ larger respectively than that at the front or rear
/ node, otherwise, it will search through list &
/ add new value to a new node following a node
/ with a value less than the new value.
*******************************************/
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

/*******************************************
/   print
/traversing function to print out each node's
/ contents w/o using overloaded <<
*********************************************/
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

/*******************************************
/   frontVal
/ return the data from the first node does
/ not remove the node
*****************************************/
// function to return the data value of 1st node
int Vector::frontVal() {
  int FVal = front->value;
  return FVal;
}

/*******************************************
/   frontNN
/ returns the node number of the 1st node
/ this should always be the value 1.  This
/ function is used to test other functions
*****************************************/
int Vector::frontNN() { return front->nodenumber; }

/*******************************************
/   rearVal
/ just returns the data of the last node does
/ not remove the node
*****************************************/
// function to return the data value of the last node
int Vector::rearVal() {
  int RVal = rear->value;
  return RVal;
}
/*******************************************
/   rearNN
/ returns the node number of the last node
/ This will give size of vector.  This
/ function is used to test other functions
*****************************************/
int Vector::rearNN() { return rear->nodenumber; }

/*******************************************
/   popFront
/ remove and return the data from the first
/ node & update all subsequent node numbers
*****************************************/
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

/*******************************************
/   popRear
/ remove and return the data from the last node
*****************************************/
int Vector::popRear() {
  if (rear == nullptr) {
    cout << "The list is empty";
  }
  int Rnodeval = rear->value;
  rear = rear->previous;
  rear->next = nullptr;
  return Rnodeval;
}

/*******************************************
/   popAt
/removes a node at a specified location
/and returns the data value of that node
/remaining nodes are renumbered
*****************************************/

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

/*******************************************
/   find
/ finds the first instance of a value in
/ the vector list & returns the list position
/ of the value
*****************************************/
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
  return -1;
}
/*******************************************
/   findAt
/ return the value at a given nodenumber
*****************************************/
int Vector::findAt(int loc) {
  if (front == nullptr) {
    cout << "The list is empty";
    return 0;
  } else {
    current = front;
    while (current->nodenumber != loc) {
      current = current->next;
    }
    return current->value;
  }
  return -1;
}
/*******************************************
/   popVal
/ finds the first instance of a value in
/ the vector list & returns the value, returns its
/ node number and removes the node. Subsequent
/ nodenumbers are decremented.  Calls find() &  popAt()
*****************************************/
int Vector::popVal(int val) {
  int nodenum = find(val);
  popAt(nodenum);
  return nodenum;
}

/*******************************************
/   numVals
/ counts the number of instances of a value in
/ the vector list & returns the value, returns 0
/ if list empty or value not in list.
*****************************************/
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
    if (count == 0) {
      return 0;
    }
    return count;
  }
}

/*******************************************
/   pushRear
/ appends second vector to rear of current vector
/ modifies a vector by adding all values from a
/ 2nd vector to the rear of the 1st vector in
/ their original order.  calls pushRear()
*****************************************/
void Vector::pushRear(Vector V2) {
  cout << "appending 2nd vector to rear of 1st; modifying the origional vector"
       << endl;
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
/*******************************************
/   pushFront
/ appends second vector to front of current vector
/ modifies a vector by adding all values from a
/ 2nd vector to the front of the 1st vector in
/ their original order.  calls pushFront()
*****************************************/
void Vector::pushFront(Vector V2) {
  cout << "appending 2nd vector to front of 1st ; modifying the origional "
          "vector "
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
// OVERLOADED OPERATOR FUNCTIONS
/*************************************************
/ copy constructor
/OVERLOADS = operator
/to copy one vector into another
/ can't get syntax for this copy constructor to work in vector.cpp
/ made function inline in class definition vector.h
/ Vector::Vector &operator=(const Vector &rhs)
***************************************************/
/*Vector Vector:: &operator=(const Vector &rhs) { // check for self assignment
    if (this == &rhs) {
      return *this;
    }
    // if new vector has items in it frees the memory & deletes values
    if (front != nullptr) {
      delete this;
    }
    // get reference to beginning of incoming list values
    node *travel = rhs.front;
    // traverse the linked list
    while (travel != nullptr) {
      this->pushRear(travel->value);
      travel = travel->next;
    }
    // return new vector
    return *this;
  }*/
/****************************************
/    cout vector
/ OVERLOADS << operator
/ allows << to be used to cout vector
/ can't get syntax for this function to work in vector.cpp
/ made function inline in class definition vector.h
/ friend ostream &operator<<(ostream &os, const Vector &v)
****************************************/

/****************************************
/    fout vector
/ OVERLOADS << operator
/ allows << to be used to fout vector
/ can't get syntax for this function to work in vector.cpp
/ made function inline in class definition vector.h
/ friend fstream &operator<<(fstream &fo, const Vector &v)
****************************************/

/****************************************
/     find                       *
/ OVERLOADS [] operator
/ allows vector to be treated as an array
/ to retrieve values at a given node. node
/ referenced as array index [].
****************************************/
//int Vector::operator[](int location) { return findAt(location + 1); }

/****************************************
/     put                       *
/ OVERLOADS [] operator
/ allows vector to be treated as an array
/ to replace values in the vector at a given node.
/ node number treated as array index [].
****************************************/
/*double Vector::&operator[](double loc) //& is red
{
  node *temp = findNode(loc + 1.0);
  return temp->value;
}
node Vector::*findNode(double loc) {
  node *travel = front;//front is red
    while (travel && loc--) {
    travel = travel->next;
  }
  return travel;//travel is read
}
*/
/****************************************
/     sumValues                       *
/ OVERLOADS + operator
/ sum together the data values in each
/ comparably positioned node of 2 vectors.
/ Incomparable nodes are added to 0
/ (remain unchanged). A new vector is
/ is generated containing the sum of
/ comparable nodes (those nodes with same
/ positions in each vector)
****************************************/
Vector Vector ::operator+(const Vector &rhs) {
  Vector V;
  node *shorter;
  node *longer;
  if (rhs.rear->nodenumber < this->rear->nodenumber) {
    shorter = rhs.front;
    longer = this->front;

  } else {
    longer = rhs.front;
    shorter = this->front;
  }
  while (shorter != nullptr) {
    // cout << shorter->value + longer->value << endl;
    V.pushRear(shorter->value + longer->value);
    shorter = shorter->next;
    longer = longer->next;
  }
  if (shorter == nullptr) {
    // shorter->previous = longer->next;
    while (longer != nullptr) {
      V.pushRear(longer->value);
      longer = longer->next;
    }
  }
  return V;
}

/****************************************
/     subtractValues                       *
/ OVERLOADS - operator
/ subtract the data values in each
/ comparably positioned node of 2 vectors.
/ Incomparable nodes are added to 0
/ (remain unchanged). A new vector is
/ is generated containing the difference of
/ comparable nodes (those nodes with same
/ positions in each vector)
****************************************/
Vector Vector ::operator-(const Vector &rhs) {
  Vector V;
  node *shorter;
  node *longer;
  if (rhs.rear->nodenumber < this->rear->nodenumber) {
    shorter = rhs.front;
    longer = this->front;

  } else {
    longer = rhs.front;
    shorter = this->front;
  }
  while (shorter != nullptr) {
    // cout << shorter->value - longer->value << endl;
    V.pushRear(shorter->value - longer->value);
    shorter = shorter->next;
    longer = longer->next;
  }
  if (shorter == nullptr) {
    // shorter->previous = longer->next;
    while (longer != nullptr) {
      V.pushRear(longer->value);
      longer = longer->next;
    }
    return V;
  }
}

/****************************************
/     multiplyValues                       *
/ OVERLOADS * operator
/ multiply together the data values in each
/ comparably positioned node of 2 vectors.
/ Incomparable nodes are added to 0
/ (remain unchanged). A new vector is
/ is generated containing the product of
/ comparable nodes (those nodes with same
/ positions in each vector)
****************************************/
Vector Vector ::operator*(const Vector &rhs) {
  Vector V;
  node *shorter;
  node *longer;
  if (rhs.rear->nodenumber < this->rear->nodenumber) {
    shorter = rhs.front;
    longer = this->front;

  } else {
    longer = rhs.front;
    shorter = this->front;
  }
  while (shorter != nullptr) {
    // cout << shorter->value * longer->value << endl;
    V.pushRear(shorter->value * longer->value);
    shorter = shorter->next;
    longer = longer->next;
  }
  while (longer != nullptr) {
    V.pushRear(longer->value);
    longer = longer->next;
  }
  return V;
}

/****************************************
/     divideValues
/ OVERLOADS / operator
/ divide the data values in each
/ comparably positioned node of 2 vectors.
/ Incomparable nodes are added to 0
/ (remain unchanged). A new vector is
/ is generated containing the quotient of
/ comparable nodes (those nodes with same
/ positions in each vector)
****************************************/
Vector Vector::operator/(const Vector &rhs) {
  Vector V;
  string function = "";
  node *shorter;
  node *longer;
  node *currentR;
  node *currentL;
  currentR = rhs.front;
  currentL = this->front;
  if (rhs.rear->nodenumber < this->rear->nodenumber) {
    shorter = rhs.front;
    longer = this->front;
    function = "zeros";

  } else {
    longer = rhs.front;
    shorter = this->front;
    function = "dividebyZero";
  }
  while (shorter != nullptr) {
    // cout << shorter->value / longer->value << endl;
    V.pushRear(currentL->value / currentR->value);
    shorter = shorter->next;
    longer = longer->next;
    currentL = currentL->next;
    currentR = currentR->next;
  }
  if (shorter == nullptr && function == "zeros") {
    // shorter->previous = longer->next;
    while (longer != nullptr) {
      V.pushRear(0);
      longer = longer->next;
    }
    return V;
  } else if (shorter == nullptr && function == "dividebyZero") {
    return V;
  }
}

/****************************************
/     isEqual
/ OVERLOADS == operator
/ compares all values at all nodes to
/ check for identical values
/ returns true if all same, false if any
/ different
****************************************/
string Vector ::operator==(const Vector &rhs) {
  string answer = "";
  node *compareR;
  node *compareL;
  compareR = rhs.front;
  compareL = this->front;
  // are vectors same size?
  if (rhs.rear->nodenumber != this->rear->nodenumber) {
    answer = "false";
    return answer;
  }
  // compare to see if 1t 2 values are the same
  // if they are enter while loop to continue testing subsequent
  // nodes. if all nodes match, vectors are same, return true
  else if (compareR->value == compareL->value) {
    while ((compareR->value == compareL->value) && (compareR != nullptr)) {
      compareR = compareR->next;
      compareL = compareL->next;
    }
    answer = "true";
    return answer;
  }
  // if any nodes fail to match (including 1st) return false
  else {
    answer = "false";
    return answer;
  }
}
