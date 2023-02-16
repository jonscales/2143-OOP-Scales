/*****************************************
  Jon Scales
  CMPS 2143
  Spring 2023
  Program 2
  MyVector Class
  ******************************************/

#include <fstream>
#include <iostream>
//#include "Myvector-overloads.cpp"
#include "Myvector.h"

using namespace std;
// asdfsg
int main() {
  ofstream fout;
  fout.open("MyVector_output.txt");
  // Demonstrate default constructor
  cout << "Let's make a vector named victor & push the values 5, 8 & 13 onto "
          "it's front."
       << endl;
  Vector victor;
  // Demonstrate pushFront for single value function
  //  push values to front
  victor.pushFront(5);
  victor.pushFront(8);
  victor.pushFront(13);

  cout << "Victor = " << victor << endl;
  fout << "Victor = " << victor << endl;

  // Demonstrate pushRear for single value function
  //  push values onto rear
  victor.pushRear(2);
  victor.pushRear(1);
  victor.pushRear(1);
  victor.pushRear(0);

  cout << "adding 2, 1, 1, & 0 to the rear of victor  gives a bit of the "
          "Fibonacci series "
       << endl;
  fout << "adding 2, 1, 1, & to the rear of victor  gives a bit of the "
          "Fibonacci series "
       << endl;

  cout << victor << endl << endl;
  fout << victor << endl;

  // Demonstrate pushAt function
  //  pushing values to specific locations
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
  //  Demonstrate popFront
  int frontval = victor.popFront();
  cout << "\n pop the first value :" << frontval
       << " from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the first value :" << frontval
       << " from the vector giving a revised vector of \n"
       << victor << endl;

  // Demonstrate popRear
  int rearval = victor.popRear();
  cout << "\n pop the last value: " << rearval
       << " from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the last value: " << rearval
       << " from the vector giving a revised vector of \n"
       << victor << endl;

  // Demonstrate popAt
  // return from a specific node
  int poppedat = victor.popAt(4);
  cout << "\n pop the nth node value (4th node) \'" << poppedat
       << "\' from the vector giving a revised vector of \n"
       << victor << endl;
  fout << "\n pop the nth node value (4th node) \'" << poppedat
       << "\' from the vector giving a revised vector of \n"
       << victor << endl;

  // Demonstrate copy constructor
  cout << "\n now copy one vector into another new vector V2. " << endl;
  Vector V2;
  V2 = victor;
  cout << "New vector V2 : " << V2 << endl;
  fout << "New vector V2 : " << V2 << endl;
  cout << "Add a couple of values to V2" << endl;
  V2.pushFront(50);
  V2.pushRear(50);
  cout << "pushed value 50 onto front & rear of V2. This gives: " << V2 << endl;
  // demonstrate that the copy constructor makes a deep copy
  cout << "But it does not change victor " << victor << endl;

  // Demonstrate constructor from array
  int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
  Vector AV3(array, 10);
  cout << AV3 << endl;
  fout << "New vector from an array of 1st 10 digits of pi " << AV3 << endl;

  // Demonstrate find function
  // find the 1st instance of a specific value in the vector list
  cout << "Find the 1st instance of the value 5 in the digits of pi" << endl;
  cout << "The 1st 5 in the digits of pi is at position " << AV3.find(5) << endl
       << endl;
  fout << "Find the 1st instance of the value 5 in the digits of pi" << endl;
  fout << "The 1st 5 in the digits of pi is at position " << AV3.find(5) << endl
       << endl;

  // Demonstrate constructor from file
  Vector FV4("vectorvals.txt");
  cout << FV4 << endl;
  fout << "New vector from af file of 1st 10 digits of e " << FV4 << endl;
  cout << "How many times is the number 2 repeated in the 1st 10 digits of e? "
       << endl;
  cout << "2 is repeated " << FV4.numVals(2) << " times." << endl << endl;
  fout << "How many times is the number 2 repeated in the 1st 10 digits of e? "
       << endl;
  fout << "2 is repeated " << FV4.numVals(2) << " times." << endl << endl;

  // Demonstrate pushRear function for entire vector
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
  // Demonstrate pushFront function for entire vector
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

  // Demonstrate popVal function
  cout << "Find the value '7' in the previous vector and remove it" << endl;
  fout << "Find the value '7' in the previous vector and remove it" << endl;
  int node = AV3.popVal(7);

  cout << "The value 7 was 1st found at node " << node
       << ". That value and node were removed from the list" << endl;
  cout << "This gives the modified AV3 vector of " << endl << AV3 << endl;
  fout << "The value 7 was 1st found at node " << node
       << ". That value and node were removed from the list" << endl;
  fout << "This gives the modified AV3 vector of " << endl << AV3 << endl;
  // MyVector Test operations
  // test arrays
  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};
  // construct vectors from arrays
  Vector MV1(a1, 5);
  Vector MV2(a2, 3);
  cout << "MV1 = " << MV1 << endl;
  cout << "MV2 = " << MV2 << endl;
  fout << "MV1 = " << MV1 << endl;
  fout << "MV2 = " << MV2 << endl;

  cout << "Demonstration of cout & fout overloads as well as overloaded [] to "
          "return value of vector as an array index"
       << endl;
  cout << "Content of MV1 index 2 is : " << MV1[2] << endl;
  fout << "Content of MV1 index 2 is : " << MV1[2] << endl;

  cout << "Demonstrate overloaded + operator" << endl;
  Vector MV3 = MV1 + MV2;
  cout << "MV1 + MV2 =" << MV3 << endl;
  fout << "MV1 + MV2 =" << MV3 << endl;

  cout << "Demonstrate overloaded - operator" << endl;
  Vector MV4 = MV1 + MV2;
  Vector MV5 = MV2 - MV1;
  cout << "MV1 - MV2 =" << MV4 << endl;
  fout << "MV1 - MV2 =" << MV4 << endl;

  cout << "MV2 - MV1 =" << MV5 << endl;
  fout << "MV2 - MV1 =" << MV5 << endl;

  cout << "Demonstrate overloaded * operator" << endl;
  Vector MV6 = MV1 * MV2;

  cout << "MV1 * MV2 =" << MV6 << endl;
  fout << "MV1 * MV2 =" << MV6 << endl;

  cout << "Demonstrate overloaded / operator" << endl;
  Vector MV7 = MV1 / MV2;

  cout << "MV1 / MV2 =" << MV7 << endl;
  fout << "MV1 / MV2 =" << MV7 << endl;
  Vector MV8 = MV2 / MV1;

  cout << "MV2 / MV1 =" << MV8 << endl;
  fout << "MV2 / MV1 =" << MV8 << endl;
  
  cout << "Demonstrate overloaded [] " << endl;
  cout<<" MV1[3] = 12"<<endl;
  fout << "Demonstrate overloaded [] " << endl;
  fout<<" MV1[3] = 12"<<endl;
  MV1[3]=12;
  cout<< MV1<<endl;
  fout<< MV1<<endl;

  cout << "Demonstrate overloaded == operator" << endl;
  cout << " Is MV1 equivalent to MV2? " << (MV1 == MV2) << endl;
   fout << " Is MV1 equivalent to MV2? " << (MV1 == MV2) << endl;
  Vector MV9 = MV1;
  cout << "MV9 was made from MV1 by copy constructor. Is MV9 = to MV1? "
       << (MV9 == MV1) << endl;
  fout << "MV9 was made from MV1 by copy constructor. Is MV9 = to MV1? "<< (MV9 == MV1) << endl;
  fout.close();
  return 0;
}
