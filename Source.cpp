// Chris Anthony
// Data Structures : Dr. Griffin
// Assignment 1
// Description:This program reads data from a file and utilizes arrays to load and print the results to an output file. 
 
#include <iostream> // write to and read from stdin and stdout
#include <string>   
#include <fstream>  
#include<iomanip>

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program \
                // we capitalize constants so we know they are not variables!

using namespace std;

struct Student
{
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};

/**
 * Function: loadClassList
 * Description:
 *      Reads a file with student data, and loads it into an array of Students.
 *
 * Params:
 *      Student *classlist  : array of Students
 *      string  filename    : name of file to process
 *
 * Returns:
 *      int - number of students read in.
 */
int loadClassList(Student *classList, string filename)
{
	ifstream fin;       // get a stream variable
	fin.open(filename); // open the stream using our fileName param
	int i = 0; // index (counter)

	// While we have not reached the end of file
	while (!fin.eof())
	{
		// Read one line in the file into one struct at array location `i`
		fin >> classList[i].fname >> classList[i].lname >> classList[i].numGrades;

		for (int j = 0; j < classList[i].numGrades; j++)
		{
			fin >> classList[i].grades[j];
		}

		// increment `i`
		i++;
	}

	// return sudent count
	return i;
}

/**
 * Function: printClassList
 *
 * Description:
 *      Prints an array of students to stdout
 *
 * Params:
 *
 *      Student *classList : array of structs (and the structs are `Students`)
 *      int     classSize  : size of class (returned from `loadClassList` )
 *
 * Returns:
 *
 *      void
 */
void printClassList(Student *classList, int classSize)
{
	ofstream outfile; // declare an output file
	outfile.open("student_output.dat"); // create "output.txt" for writing

	outfile << "Chris Anthony\n\n"; // write your name to "output.txt"
	outfile << "Students \n"
		<< "=================================\n";

	for (int i = 0; i < classSize; i++)
	{
		outfile << i + 1 << ". " << classList[i].fname << " "
			<< classList[i].lname << ":\t";

		for (int j = 0; j < classList[i].numGrades; j++)
		{
			outfile << classList[i].grades[j] << " ";
		}
		outfile << '\n';
	}

	string fname, lname;
	int numGrades;
	int grades[10];

	outfile.close(); // Command to close file
}

int main()
{

	ofstream outfile; // declare an output file
	outfile.open("student_output.dat"); // create "output.txt" for writing
	Student classList[100];
	int classSize = 0;

	// Call the loadClassList function to open a file and load an array
	// of `Student` structs.
	classSize = loadClassList(classList, "input_data.txt");

	// Function to print out an array of students in a formatted way.
	printClassList(classList, classSize);

	return 0;
}