/**
 * Lecture 08
 *
 * List based queue
 *
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */
#include <iostream>
#include <fstream>
#include "ListQueue.hpp"

using namespace std;


int main() {

	ifstream fin("animal.txt");  // input file of animal info 

	Animal *a;
	string name;
	double weight;
	double scary;

	ListQueue LQ;                 // Queue instance 
	
	while (!fin.eof()) {
		fin >> name >> weight >> scary;
		a = new Animal(name, weight, scary);                         // allocate memory for an animal
		LQ.Push(a);                               // push animal onto the stack
	}
	
	LQ.Print();
	cout << "_____________" << endl;

	
	LQ.Pop();
	LQ.Print();
	cout << "_____________" << endl;
	

	LQ.Pop();
	LQ.Print();
	cout << "_____________" << endl;
	
	system("pause");
	return (0);
}