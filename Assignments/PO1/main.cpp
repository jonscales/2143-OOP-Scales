/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 1
  Vector Class
  ******************************************/

#include <fstream>
#include <iostream>
//#include "vector.cpp"
#include "vector.h"

using namespace std;

int main() {
  ofstream fout;
  fout.open("ScalesOOP P01 output");
  // constructor
  Vector victor;
  // push values to front
  victor.pushFront(5);
  victor.pushFront(8);
  victor.pushFront(13);

  cout << "values added to front gives vector so far: " << victor << endl;
  fout << "values added to front gives vector so far: " << victor << endl;
  /* cout << "front node data = " << victor.frontVal()
        << " front nodenumber = " << victor.frontNN() << endl;
   cout << "rear nodenumber = " << victor.rearNN()
        << " rear val = " << victor.rearVal() << endl;*/

  // push values onto rear
  victor.pushRear(2);
  victor.pushRear(1);
  victor.pushRear(1);
  victor.pushRear(0);

  cout << "adding to the rear gives this vector: " << endl;
  fout << "adding to the rear gives this vector: " << endl;

  cout << victor << endl;
  fout << victor << endl;
  cout << endl;
  /*cout << "front node data = " << victor.frontVal()
       << " front nodenumber = " << victor.frontNN() << endl;
  cout << "rear node data= " << victor.rearVal()
       << " rear node number = " << victor.rearNN() << endl;*/

  // pushing values to specific locations
  cout << "now add the value 3 at position 4 in the list. " << endl;
  fout << "now add the value 3 at position 4 in the list. " << endl;
  victor.pushAt(4, 3);
  fout << victor << endl;
  cout << "\n now add a value at position past end of list. " << endl;
  fout << "\n now add a value at position past end of list. " << endl;
  victor.pushAt(10, 8);
  fout << victor << endl;
  cout << "\n now add a value at position 1 in the list. " << endl;
  fout << "\n now add a value at position 1 in the list. " << endl;
  victor.pushAt(1, 21);
  fout << victor << endl;

  // return front or rear node values
  cout << "\n pop the first value :" << victor.popFront()
       << " from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the first value :" << victor
       << " from the vector giving a revised vector of \n"
       << victor << endl;

  cout << "\n pop the last value: " << victor.popRear()
       << " from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the last value: " << victor
       << " from the vector giving a revised vector of \n"
       << victor << endl;

  // return from a specific node
  cout << "\n pop the nth node value (4th node) \'" << victor.popAt(4)
       << "\' from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the nth node value (4th node) \'" << victor
       << "\' from the vector giving a revised vector of \n"
       << victor << endl;

  // cout << "\n now copy one vector into another new vector. " << endl;
  // Vector V2 = victor;

  //  cout << V2 << endl;

  int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

  // cout<<"does the array exist?"<<endl;
  /*for(int i=0;i<10;i++){
    cout<<array[i]<<", ";
  }cout<<endl;*/

  // constructor from array
  Vector AV3(array, 10);
  cout << AV3 << endl;
  fout << "New vector from an array of 1st 10 digits of pi " << AV3 << endl;
  // find the 1st instance of a specific value in the vector list
  cout << "Find the 1st instance of the value 5 in the digits of pi" << endl;
  cout << "The 1st 5 in the digits of pi is at position " << AV3.find(5) << endl
       << endl;
  fout << "Find the 1st instance of the value 5 in the digits of pi" << endl;
  fout << "The 1st 5 in the digits of pi is at position " << AV3.find(5) << endl
       << endl;

  // constructor from file
  Vector FV4("vectorvals.txt");
  cout << FV4 << endl;
  fout << "New vector from af file of 1st 10 digits of e " << FV4 << endl;
  cout << "How many times is the number 2 repeated in the 1st 10 digits of e? "
       << endl;
  cout << "2 is repeated " << FV4.numVals(2) << " times." << endl << endl;
  fout << "How many times is the number 2 repeated in the 1st 10 digits of e? "
       << endl;
  fout << "2 is repeated " << FV4.numVals(2) << " times." << endl << endl;

  cout << "Let's put the 1st 10 digits of e onto the end of the list of pi's "
          "1st 10 digits just for shits and giggles"
       << endl;
  fout << "Let's put the 1st 10 digits of e onto the end of the list of pi's "
          "1st 10 digits just for shits and giggles"
       << endl;
  AV3.pushRear(FV4);
  cout << "This produces a modified vector: " << endl;
  cout << AV3 << endl;
  fout << "This produces a modified vector: " << endl;
  fout << AV3 << endl;

  cout << "Let's put the 1st 6 digits of the Fibanacci sequence onto the "
          "beginning of ";
  cout << "the previous vector just for shits and giggles" << endl;
  fout << "Let's put the 1st 6 digits of the Fibanacci sequence onto the "
          "beginning of ";
  fout << "the previous vector just for shits and giggles" << endl;
  AV3.pushFront(victor);
  cout << " This produces a modified vector: " << endl;
  cout << AV3 << endl;
  fout << " This produces a modified vector: " << endl;
  fout << AV3 << endl;
  fout.close();
  return 0;
}
