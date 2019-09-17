// Chris Anthony
// Data Structures : Dr. Griffin
// Program 1
// Description: This program writes a list class that stores employee
// information, using different list methods to perform some basic tasks
// and prints the results to the output file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// function which compares two strings
bool substringMatch(string macro, string micro)
{
	int index = macro.find(micro);
	return index >= 0;
}

// structure which holds employee information
struct Employee {
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee *Next;

	Employee() {
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;
	}

	Employee(string id, string first, string last, string sex, string mail,
		double pay) 
	{
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
	}
};

struct Node
{
	Employee emp; // the data portion of this node
	Node *next; // pointer(of same type) to link things together

	Node(Employee data, Node *n = NULL) // constructor to initialize our node
	{
		emp = data;
		next = n;
	}
};

class LinkedList
{
private:
	Node* Head;

public:
	LinkedList()
	{
		Head = NULL;
	}

	// function which adds an employee to the front of the list
	void push(Employee emp)
	{
		Node *temp = new Node(emp, Head);
		Head = temp;
	}

	// removes an employee from the front of the list
	Employee pop()
	{
		Employee result = Head->emp;
		Node *temp_del = Head;
		Head = Head->next;
		delete temp_del;
		return result;
	}

	// function which returns a boolean true / false if an item is in the list
	bool find(string employee_email)
	{
		Node *temp = Head;
		while (temp != NULL)
		{
			
			if (substringMatch(temp->emp.email, employee_email))
			{
				return true;
			}
			else
			{
				temp = temp->next;
			}
		}
		return false;
	}

	// function which finds all instances of a particular string in a list
	void findall(string employee_email, ofstream & outfile)
	{
		Node *temp = Head;
		while (temp != NULL)
		{
			if (substringMatch(temp->emp.email, employee_email))
			{
				outfile << temp->emp.email << '\n';
			}
			temp = temp->next;
		}
	}


	// function to print the contents of the list
	void print(ofstream & outfile) {
		Node* Temp = Head;

		int i;
		i = 30;
		while (i != NULL) // Loop through the list and print stuff out
		{
			outfile << Temp->emp.emp_id;
			if (Temp->next)
			{
				outfile << endl;;
			}
			Temp = Temp->next;
			i--;
		}
	};
};

int main()
{
	ifstream fin; //declare an input file
	fin.open("employees.dat"); //open "employees.datt" for reading

	ofstream outfile; // Declare an output file
	outfile.open("output.txt"); // Create "output.txt" for writing

	outfile << "Chris Anthony\n\n"; // Write my name to "output.txt"

	LinkedList EmpList;

	while (!fin.eof()) // While we are not at the end of file
	{
		Employee finemp;
		fin >> finemp.emp_id >> finemp.first_name >> finemp.last_name
			>> finemp.gender >> finemp.email >> finemp.hourly_pay;

		EmpList.push(finemp);
	}

	EmpList.print(outfile);

	outfile << "\nIf salon exists, print 1 for true and 0 for false:\n"
			<< "___________________________________________________\n\n";
	outfile << EmpList.find("salon");

	outfile << "\n\nList of emails that contain salon:\n"
		<< "___________________________________________________\n\n";
	EmpList.findall("salon", outfile);

	outfile.close();
	return 0;
}