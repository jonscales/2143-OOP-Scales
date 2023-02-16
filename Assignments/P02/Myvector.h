/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 2
  Myvector Class - header file
  ******************************************/

#include <fstream>
#include <iostream>

using namespace std;

struct node {
  int value;
  double valued;
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
struct dnode {
  double dvalue;
  int nodenumber;
  dnode *previous;
  dnode *next;
  dnode(int nn, double x) {
    nodenumber = nn;
    dvalue = x;
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
  dnode *dfront;
  dnode *drear;
  dnode *dcurrent;
  dnode *dbefore;
  dnode *dtravel;

public:
  // Destructor
  ~Vector();
  // Constructors
  Vector();
  Vector(int *A, int size);
  Vector(string FileName);

  // copy constructor overloading = operator
  Vector &operator=(const Vector &rhs) { // check for self assignment
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
  }

  // functions that appends two vectors
  void pushRear(Vector V2);
  void pushFront(Vector V2);

  // functions that add values onto vector
  void pushFront(int val);
  void pushRear(int val);
  void pushAt(int loc, int val);
  void inOderPush(int val);

  // print function
  void print();

  // functions to return values from specific nodes of list
  int frontVal();
  int frontNN();
  int rearVal();
  int rearNN();

  // functions to remove nodes and return data values
  int popFront();
  int popRear();
  int popAt(int loc);
  int popVal(int val);

  // function to find a specific value or count number of instances of that
  // value in the data of nodes of return the value at
  // a given node
  int find(int);
  int numVals(int);
  int findAt(int);

  // OVERLOADED operator functions
  //  overload << operator function to cout vector
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

  //  overload << operator function to fout vector
  friend fstream &operator<<(fstream &fo, const Vector &v) {
    ofstream fout;

    node *travel = v.front;
    fo << "[";
    while (travel != nullptr) {
      fo << travel->value;
      if (travel->next != nullptr) {
        fo << ", ";
      }
      travel = travel->next;
    }
    fo << " ]" << endl;
    return fo;
  }
  //  overload >> operator to imput vector values
  /*friend istream &operator>>(istream &is, const Vector &v) {
       node *travel = v.front;
    is >> "[";
    while (travel != nullptr) {
      is >> travel->value;
      if (travel->next != nullptr) {
        is >> ", ";
      }
      travel = travel->next;
    }
   is >> " ]" << endl;
    return is;
  }*/

  // overload [] to give value at [location]
  //int operator[](int location);

  // overload [] to change value at [location]
 int &operator[](int loc) {
    node *temp = findNode(loc);
    return temp->value;
  }
  // findNode function to allow overloading of []
  node *findNode(int loc) {
    node *travel = front; // front is red
    while (travel && loc--) {
      travel = travel->next;
    }
    return travel; // travel is read
  }
  // overload + to sum values of nodes
  Vector operator+(const Vector &rhs);

  // overload - subtract values of nodes
  Vector operator-(const Vector &rhs);

  // overload * to multiply values of nodes
  Vector operator*(const Vector &rhs);

  // overload / to
  Vector operator/(const Vector &rhs);

  // overload ==
  string operator==(const Vector &rhs);

  // overload
};
