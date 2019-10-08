/** Chris Anthony
Data Structures : Dr. Griffin
Homework 2 - Resizable Array Stack
Description:This program reads data from a file and utilizes three methods
to check, enlarge and shrink the size an array based stack. The results
are printed to an output file.
*/

#include<iostream>
#include<fstream>

using namespace std;

class Stack
{
private:
	int *A;         // container of items (could make it a list)
	int Top;        // keep track of top
	int Size;       // Arrays need a size
	int count;

public:

	/**
	 * Stack constructor (default)
	 * Description:
	 *    Inits an array of ints and sets our top
	 */

	Stack()
	{
		Size = 10;
		A = new int[Size];
		Top = -1;
		count = Size;
	};

	/**
	 * Stack constructor (overloaded)
	 * Description:
	 *    Inits an array of ints to a specified size and sets our top
	 * Params:
	 *    int s : integer size
	 */

	Stack(int s)
	{
		Size = s;
		A = new int[Size];
		Top = -1;
	};

	/**
	 * Push
	 * Description:
	 *    Adds item to top of stack
	 * Params:
	 *    int val : integer size
	 * Returns:
	 *     bool : true = success
	 */

	bool Push(int val)	// Push value onto stack
	{
		if (!Full()) {
			Top++;
			A[Top] = val;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * Pop
	 * Description:
	 *    Removes top of stack and returns it
	 * Params:
	 *    void
	 * Returns:
	 *     int : item on stack
	 */

	int Pop()	// Remove item from top of stack
	{
		if (!Empty()) {
			int temp = 0;
			temp = A[Top];
			Top--;
			return temp;
		}
		else {
			// should return a value that implies failuer, but good enough for now
			cout << "Cannot remove item from empty stack" << endl;
		}
		return 0;
	}

	/**
	 * Empty
	 * Description:
	 *    Is stack empty
	 * Params:
	 *    void
	 * Returns:
	 *    bool : true = empty
	 */

	bool Empty()
	{
		return Top < 0;
	}

	/**
	 * Full
	 * Description:
	 *    Is stack full
	 * Params:
	 *    void
	 * Returns:
	 *    bool : true = full
	 */

	bool Full()
	{
		return (Top == Size - 1);
	}

	//void checkResize(int newSize)
	{

		if (count = .8 * Size)
		{
			Enlarge();
		}
		else (count = .2 * newSize)
		{
			Reduce();
		}
	}

	//void Enlarge()
	{
		int newSize = Size * 1.5;
		int *B = new int[newSize];
		int *deleter = NULL;

		for (int i = 0; i < Size; i++)
		{
			B[i] = A[i];
		}

		for (int i = Size; i <= newSize; i++)
		{
			B[i] = NULL;
		}

		deleter = A;
		A = B;
		delete[] deleter;
	}

	//void Reduce()
	{
		int oldSize = Size;
		int *C = new int(oldSize);
		int *deleter1 = NULL;


		for (int i = 0; i < oldSize; i++)
		{
			C[i] = B[i];
		}

		deleter1 = B;
		B = C;
		delete[] deleter1;
	}
	/**
 * Print
 * Description:
 *    Prints stack for inspection
 * Params:
 *    void
 * Returns:
 *     void
 */

	void Print() // function to print the contents of the list
	{
		for (int i = Top; i >= 0; i--) {
			cout << A[i] << endl;
		}
	}
};

/**
 * Main Program
 *
 */
int main() 
{
	ofstream outfile;
	outfile.open("stack_out.dat");

	ifstream fin;
	fin.open("input_data.txt");

	Stack S; // Instance of our stack default constructor
	int values[] = { 1,2,3,4,5,6,7,8,9,10 };
	int val;

	// Load the stack with data from file
	for (int i = 0; i < 10; i++)
	{
		s.Push(values[i]);
	}

	cout << values[i] << endl;

	system("pause");
	return 0;
}

