// Chris Anthony
// Data Structures : Dr. Griffin
// Program 1
// Description:This program 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool substringMatch(string macro, string micro)
{
	int index = macro.find(micro);
	return index >= 0;
}

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

	Employee(string id, string first, string last, string sex, string mail, double pay) {
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
	Employee emp;
	Node *next;

	Node(Employee data, Node *n = NULL)
	{
		emp = data;
		next = n;
	}
};

class LinkedList {
private:
	Node* Head;

public:
	LinkedList() {
		Head = NULL;
	}

	void push(Employee emp)
	{
		Node *temp = new Node(emp, Head);
		Head = temp;
	}


	Employee pop()
	{
		Employee result = Head->emp;
		Node *temp_del = Head;
		Head = Head->next;
		delete temp_del;
		return result;
	}


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

	void print() {
		Node* Temp = Head;

		while (Temp != NULL)
		{
			cout << Temp->emp.emp_id << ", " << Temp-> emp.first_name << ", " << Temp-> emp.last_name << ", " << Temp-> emp.gender << Temp-> emp.email << ", " << ", " << Temp-> emp.hourly_pay;
			if (Temp->next)
			{
				cout << "->";
			}
			Temp = Temp->next;
		}
	};


int menu() 
{
	int choice = 0;
	while (choice < 1 || choice > 3) 
	{
		cout << "\nMenu of Operations:\n";
		cout << "    1 - Find Employee\n";
		cout << "    2 - Delete Employee\n";
		cout << "    3 - Quit\n";
		cout << "Choice: ";
		cin >> choice;
	}
	return choice;
}

int main()
{
	ifstream fin;
	fin.open("employees.dat");

	ofstream outfile; // Declare an output file
	outfile.open("output.txt"); // Create "output.txt" for writing

	cout << "Chris Anthony\n\n"; // Write my name to "output.txt"

	LinkedList EmpList;

	while (!fin.eof())
	{

		Employee finemp;
		fin >> finemp.emp_id >> finemp.first_name >> finemp.last_name >> finemp.gender >> finemp.email >> finemp.hourly_pay;

		EmpList.push(finemp);
	}

	EmpList.print();

	int choice = 0;

	while (choice != 3)
	{
		choice = menu();
	}

	cout << EmpList.find("salon") << endl;

	system("pause");
	outfile.close();
	return 0;
}