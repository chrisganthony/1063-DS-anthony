/** Chris Anthony
Data Structures : Dr. Griffin
Date: October 15th 2019
Homework 4 - Overloading and Queues
Description: List based Queue that holds an animal type
*/

#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;

int main() {

	ifstream fin("animals.txt");  // input file of animal info 

	Animal *a;

	// Variable Declarations
	string name;
	double weight;
	double scary;

	ListQueue LQ;                // Queue instance 
	
	while (!fin.eof()) {
		fin >> name >> weight >> scary;
		a = new Animal(name, weight, scary);  // allocate memory for an animal
		LQ.Push(a);                          // push animal onto the stack
	}
	
	LQ.Print();
	LQ.Pop();

	LQ.Print();
	LQ.Pop();

	LQ.Print();
	
	return (0);
}