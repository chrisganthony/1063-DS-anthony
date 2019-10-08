/** Chris Anthony
Data Structures : Dr. Griffin
Homework 2 - Resizable Array Stack
Description:This program reads data from a file and uses three methods
to check, enlarge and shrink the size of an array based stack. The results
are printed to an output file.
*/

#include <iostream> // write to and read from stdin and stdout
#include <fstream>

using namespace std;

class Stack
{
private:
	int *A;  // container of items (could make it a list)
	int Top; // keep track of top
	int count; // Arrays need a size
	int Size;
	bool hasEnlarged;

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
		count = Top + 1;
		hasEnlarged = false;
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
		hasEnlarged = false;
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

	bool Push(int val) // Push value onto stack
	{
		if (!Full())
		{
			Top++;
			count++;
			A[Top] = val;
			checkResize();
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

	int Pop() // Remove item from top of stack
	{
		if (!Empty())
		{
			int temp = 0;
			temp = A[Top];
			Top--;
			count--;
			checkResize();
			return temp;
		}
		else
		{
			cout<< "Cannot remove item from empty stack" << endl;
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
	/**
	 * checkResize
	 * Description:
	 *    looks at the current ratio the stack contains and decides whether
	      to enlarge or shrink it.
	 * Params:
	 *    void
	 * Returns:
		  void
	 */

	void checkResize()
	{

		if (count >= int(Size * .8))
		{
			Enlarge();
		}
		else if (count <= int(Size * .2))
		{
			if (hasEnlarged)
			{
				Reduce();
			}
		}
	}

	/**
	 * Enlarge
	 * Description:
	 *    grows the array
	 * Params:
	 *    void
	 * Returns:
		  void
	 */

	void Enlarge()
	{
		int newsize = int(Size * 1.5);
		int *b = new int[newsize];
		int *deleter = NULL;


		for (int i = 0; i < Size; i++)
		{
			b[i] = A[i];
		}
		Size = newsize;

		deleter = A;
		A = b;
		delete[] deleter;
		hasEnlarged = true;
	}

	/**
	 * Reduce
	 * Description:
	 *    shrinks the array
	 * Params:
	 *    void
	 * Returns:
		  void
	 */

	void Reduce()
	{
		int oldSize = int(Size * .5);
		int *C = new int[oldSize];
		int *deleter1 = NULL;

		for (int i = 0; i < oldSize; i++)
		{
			C[i] = A[i];
		}
		Size = oldSize;

		deleter1 = A;
		A = C;
		delete[] deleter1;
	}

	/**
	 * MaxSize
	 * Description:
	 *    returns the current max size
	 * Params:
	 *    void
	 * Returns:
	 *     int : Size
	 */
	int GetSize()
	{
		return Size;
	}

	/**
	 * Print
	 * Description:
	 *    Prints stack for inspection
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */

	void Print(ostream& out) // function to print the contents of the list
	{

		for (int i = Top; i >= 0; i--)
		{
			out<< A[i] << ' ';
		}
		out<< endl;
	}
};

/**
 * Main Program
 *
 */
int main()
{
	ofstream outfile; // declare an output file
	outfile.open("stack_out.dat.txt"); // create "stack_out.dat" for writing

	ifstream fin; // get a stream variable
	fin.open("input_data.txt"); // open "input_data.txt" for reading

	Stack S;         // Instance of our stack default constructor
	char operation;  // '+' or '-', represents push or pop
	int number;      // the number to push or pop
	int maxsize = 0; // initializes maxsize to 0

	while (fin >> operation >> number)
	{
		switch (operation)
		{
		case '+':
			S.Push(number);
			if (S.GetSize() > maxsize)
			{
				maxsize = S.GetSize();
			}
			// if s getsize is bigger than maxsize
			// maxsize equal s getsize
			break;
		case '-':
			S.Pop();
			break;
		default:
			outfile<< "BAD OPERATION!" << endl;
		}
		
	}

	outfile << "Chris Anthony\n";
	outfile << "10 / 08 / 19\n";
	outfile << "Homework 2\n\n";
	outfile << "Stack Size: " << S.GetSize() << endl;
	outfile << "Largest Size: " << maxsize << endl;
	outfile << "Values: ";
	S.Print(outfile);
	outfile << endl;

	// Command to close file
	fin.close();
	outfile.close();

	return 0;
}

