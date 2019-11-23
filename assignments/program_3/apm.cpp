// Author:           CHRIS ANTHONY
// Assignment:       Program_03
// Date:             21 November 2019
// Title:            Program 3 - Arbitrary Precision Math
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            apm.cpp 
//                   input_data.txt 
//                   output.num
//
// Description:	This program reads in arbitrarily long positive integers as
//		strings,converts it into integers and then reads each number
//		into a doubly linked list. It then utilizes functions to add,
//              subtract and multiply the contents of the two lists and places
//              the result in a third doubly linked list. The results are then
//		printed to the output file. 
//       

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Node {	 	  // node setup for a list. 
	int data;	 // simple integer data.
	Node* Next;
	Node* Prev;

	Node()		// default constructor
	{
		data = 0;
		Next = NULL;
		Prev = NULL;
	}

	Node(int d) // overloaded constructor
	{ 
		data = d;
		Next = NULL;
		Prev = NULL;
	}
};

class DoubleyLinked {
private:
	Node *Head;		// Head of list pointer
	Node *Tail;		// Tail of list pointer	
	Node *Result;	
	int size;		//size of the list
	void FrontSert(Node*& Temp);
	void EndSert(Node*& Temp);

public:
	DoubleyLinked();
	void InsertEnd(int);
	void InsertFront(int);
	void Add(DoubleyLinked, DoubleyLinked);
	void Sub(DoubleyLinked, DoubleyLinked);
	void Print(ofstream &);
};

/**
 * Public Default Constructor
 */
DoubleyLinked::DoubleyLinked() 
{
	Head = Tail = Result = NULL;
	size = 0;
}

/**
 * Public FrontSert
 *
 * Adds item to the the front of the list
 *
 * @Params:
 *
 *     Node*& Temp : Address of new node to be placed in list
 *
 * @Returns:
 *
 *     void
 */

void DoubleyLinked::FrontSert(Node*& Temp) {

	if (!Head)	// If list is empty point head and tail to new node
	{
		Head = Temp;
		Tail = Temp;
	}
	else {		
		Head->Prev = Temp;     // Point to temp with head previous pointer 
		Temp->Next = Head;    //  Link new node by pointing its next to Head
		Head = Temp;	     //   Now update head to point to the new node
		
	}
	size++;
}


/**
 * Public EndSert
 *
 * Adds item to the the end of the list
 *
 * @Params:
 *
 *     Node*& Temp : Address of new node to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void DoubleyLinked::EndSert(Node*& Temp) {

	if (!Head)	// If list is empty just point head and tail to new node
	{
		Head = Temp;
		Tail = Temp;
	}
	else 	 
	{
		Tail->Next = Temp;   // link last node to new one
		Temp->Prev = Tail;  // Point to tail with temp previous pointer 
		Tail = Temp;	   // Now update tail to point to the new node

	}
	size++;
}

/**
 * Public InsertFront
 *
 * Creates new node and calls the frontsert function to add items to the 
 * front of list
 *
 * Params:
 *
 *     int n : item to be placed in list
 *
 * Returns:
 *
 *     void
 */

void DoubleyLinked::InsertFront(int n) {
	Node* num = new Node(n);   // allocate new memory
	FrontSert(num);
}

/**
 * Public InsertEnd
 *
 * Creates new node and calls the endsert function to add items
*  to the tail of list
 *
 * Params:
 *
 *     int n : item to be placed in list
 *
 * Returns:
 *
 *     void
 */

void DoubleyLinked::InsertEnd(int n) {
	Node* num = new Node(n);   // allocate new memory
	EndSert(num);
}
/**
 * Public Add
 *
 * Description:
 *      Adds two linked lists together and returs a doubly linked list.
 *
 * Params:
 *      DoubleyLinked num1: A linked list  representation of an integer number.
 *      DoubleyLinked num2: A linked list  representation of an integer number.
 *
 * Returns:
 *
 *        void
 */
void DoubleyLinked::Add(DoubleyLinked num1, DoubleyLinked num2) {

	int min;
	int val,			// actual value the 2 nodes equal to
		digit,			// the digit dropped down in addition
		carry = 0;		//  carries to the next digit

	Node * trail1 = num1.Tail;	// Point to tail of list 1 with trail1 pointer
	Node * trail2 = num2.Tail;	// Point to tail of list 2 with trail2 pointer

	if (num1.size < num2.size)	// compares the size of both lists to determine
		min = num1.size;       //  which is smaller	
	else
		min = num2.size;

	for (int i = 0; i < min; i++) {	
		val = trail1->data + trail2->data;	//add values in same placement
		val += carry;
		carry = 0;
		digit = val % 10;	         	//actual digit to push
		if (val > 9) {
			carry = 1;			//push 1 to next placement
		}

		this->InsertFront(digit);			
		trail1 = trail1->Prev;			//edit placements points
		trail2 = trail2->Prev;
	}

	if (num1.size > num2.size) {			//drops down remaining 
		trail1->data = trail1->data + carry;	//digits from largest number
		while (trail1 != num1.Head) {		//if num on top is bigger
			this->InsertFront(trail1->data);
			trail1 = trail1->Prev;
		}
		this->InsertFront(trail1->data);
	}
	else if (num2.size > num1.size) {			//bottom is bigger so drop down	
		trail2->data = trail2->data + carry;
		while (trail2 != num2.Head) {
			this->InsertFront(trail2->Prev->data);
			trail2 = trail2->Prev;
		}
		this->InsertFront(trail2->data);
	}
	else {
		if (carry != 0) {
			this->InsertFront(carry);	//insert most significant 
		}					//bit if there is a carry
	}
}


/**
 * Public Sub
 *
 * Description:
 *      Subtracts two linked lists together and returs a doubly linked list.
 *
 * Params:
 *      DoubleyLinked num1: A linked list  representation of an integer number.
 *      DoubleyLinked num2: A linked list  representation of an integer number.
 *
 * Returns:
 *
 *        void
 */
void DoubleyLinked::Sub(DoubleyLinked num1, DoubleyLinked num2) {

	int min;
	int val,			//actual value the 2 nodes equal to
		digit,			//the digit we drop down in the addition
		carry = 0;		//carries to the next digit

	Node * trail1 = num1.Tail;
	Node * trail2 = num2.Tail;

	if (num1.size < num2.size)
		min = num1.size;
	else
		min = num2.size;

	for (int i = 0; i < min; i++) {

		if (trail1->data < trail2->data) {	//if number on top is bigger
			carry = 10;			//carry from the place on the left
			trail1->Prev->data -= 1;

			val = (trail1->data - trail2->data) + carry;
		}
		else
			val = (trail1->data - trail2->data); //do the subtraction
						       	    //from placement

		this->InsertFront(val);	             	   //insert the result to list

		trail1 = trail1->Prev;
		trail2 = trail2->Prev;
	}
	
	if (num1.size > num2.size) {			//carry and the drop down other
		trail1 = trail1->Next;			//digits
		while (trail1 != num1.Head) {
			if (trail1->Prev->data == -1) {
				trail1->Prev->data = 9;
				trail1->Prev->Prev->data--;
			}
			this->InsertFront(trail1->Prev->data);
			trail1 = trail1->Prev;
		}
	}
	else if (num2.size > num1.size) {
		trail2 = trail2->Next;
		while (trail2 != num2.Head) {
			this->InsertFront(trail2->Prev->data);
			trail2 = trail2->Prev;
		}
	}
	if (Head->data == 0)				//delete zeros from front of list
		Head = Head->Next;
}


/**
 * Public Print
 *
 * Prints list to outfile from head to tail
 *
 * Params:
 *
 *     Void
 *
 * Returns:
 *
 *     void
 */
void DoubleyLinked::Print(ofstream & out) {

	Node* Temp = Head;

	while (Temp) {
		out << Temp->data;
		if (Temp->Next) {
			out << "";
		}
		Temp = Temp->Next;
	}
	out << endl;
}


/**
 * Main Driver
 *
 */
int main() {

	ifstream fin; //declare an input file
	ofstream out; // Declare an output file

	fin.open("input_data.txt"); //Open "input_data" for reading
	out.open("output.num"); // Create "output.num" for writing

	out << "Chris Anthony\n"; // Write my name to "output.txt"
	out << "Program 3\n";
	out << "Arbitrary Precision Math\n\n";

	int runs;		//number of runs
	char op;		//operation
	char c;			//current character
	char d;			//current character
	int x;			//interger converted
	string line;

	fin >> runs;
	
	for (int i = 0; i < runs; i++) {
	
		DoubleyLinked num1, num2, num3; // Creates 3 lists called num1, num2, num3 respectively;

		fin >> op;
		getline(fin, line); 	         // read file line by line
		getline(fin, line);	

		istringstream ss(line);		//strip line from file
		while (ss >> c) {		//split up number in ASCII
			x = (int)c - 48;	//convert to regular digit
			num1.InsertEnd(x);
		}

		getline(fin, line);		//strip line from file
		istringstream tt(line);		
		while (tt >> d) {
			x = (int)d - 48;
			num2.InsertEnd(x);
		}

		switch (op) // calls the appropriate operation 
		{
		case '+': 
			num3.Add(num1, num2);
			
			out << "\nOperation 1: Addition\n";
			out << "Answer : \n\n\n";

			num3.Print(out); 

			out << "";
			
			break;
		case '-':
			num3.Sub(num1, num2);

			out << "\nOperation 2: Subtraction\n";
			out << "Answer : \n\n\n";

			num3.Print(out);

			out << "";
			break;
		default:
			out << "Invalid Operation!" << endl;
		}
	}

	out.close(); //command to close outfile
	fin.close(); //command to input outfile

	return 0;
}
