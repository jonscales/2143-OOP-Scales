/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 1
  Vector Class
  ******************************************/

#include <fstream>
#include <iostream>

using namespace std;

struct node {
  int value;
  int nodenumber;
  node *previous;
  node *next;
  node(int nn, int x) {
    nodenumber = nn;
    value = x;
    next = nullptr;
    previous = nullptr;
  }
};

class Vector {
private:
protected:
  node *front;
  node *rear;
  node *current;
  node *before;
  node *travel;

public:
  Vector();
  Vector(int *A, int size);
  Vector(string FileName);
  ~Vector();
  // copy constructor to overload = operator
  Vector &operator=(const Vector &rhs) {
    // check for self assignment
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
      this->pushFront(travel->value);
      travel = travel->next;
    }
    // return new vector
    return *this;
  }
  // copy constructor that appends two vectors
  void pushRear(Vector V2);
  void pushFront(Vector V2);
  void pushFront(int val);
  void pushRear(int val);
  void pushAt(int loc, int val);
  void inOderPush(int val);
  void print();
  int frontVal();
  int frontNN();
  int rearVal();
  int rearNN();
  int popFront();
  int popRear();
  int popAt(int loc);
  int find(int);
  int numVals(int);
  friend ostream &operator<<(ostream &os, const Vector &v) {
    node *travel = v.front;
    os << "[";
    while (travel != nullptr) {
      os << travel->value;
      if (travel->next != nullptr) {
        os << ", ";
      }
      travel = travel->next;
    }
    os << " ]" << endl;
    return os;
  }
};
