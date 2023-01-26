/*********************************************************************************
*  Author:          Jon Scales
*  Email:           jon.scales@msutexas.edu
*  Label:           A03
*  Title:           making banner & commenting code
*  Course:          CMPS 2143
*  Semester:        Spring 2023
* 
*  Description:
*          The code below was provided by the instructor as part of the assignmen
*          commments have be added by the author. 
*
*  Usage:
*
*
*  Files: 
*
*
*
*
*************************************************************************/

#include <iostream>

using namespace std;

/*
CircularArray Class 
Description
  This class uses an array to hold a queue 

Private Methods: 
void    init(int)
bool    Full()

Public methods:
  constructors
        CicularArrayQue()
        CicularArrayQue(int)
void    Push(int)
int     Pop()
ostream operator

Usage:
  CircularArrayQue()      //Creates default instance of class queue of size 10
  CircularArrayQue(int)   //Creates instance of class queue of specified size
  init(int)               //Initiallizes the queue pointers for front & rear to null
                          //initiallizes current size of array to 0
  Full()                  //checks array to see if the queue is full
  Push(int)               //checks for full, if not full adds a data value to the rear 
                          //of the queue & moves pointers accordingly,
                          //if full returns FULL response
  Pop()                   //removes contents of front node (FIFO), moves the front pointer
                          //adjusts queue size variables
  operator                //overloads the << operator to allow direct printing of entire array
              

*/
class CircularArrayQue {
private:
    int *Container;            // creates an array that will be a dynamic queue
    int Front;                 // location of 1st node of queue
    int Rear;                  // location of last node of queue
    int QueSize;               // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};
/*
<< operator overload Function

allows sending entire queue contents to console with the << operator

*/
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);  //instance of class created with size 5

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);    //every instance of .Push(int) adds (int) to the end of the queue
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}