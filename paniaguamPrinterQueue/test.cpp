#include <iostream>
using namespace std;
#include "heap.h"
#include "pqtype.h"

//const int MAX = 25;  //maximum number of print jobs
int showMenu();

void addJob(PQType<Job>&, int);
void printJob(PQType<Job>&);
void showJobs(PQType<Job>&);

int main()
{
	int choice, count = 0;  //count tracks job number
	PQType<Job> p(MAX);		

	do
	{
		//display menu, capture user choice
		choice = showMenu();

		switch (choice)
		{
		//increment job count, call function to add job
		case 1: count++;
			addJob(p, count);
			break;
		//print top job in queue
		case 2: printJob(p);
			break;
		//list all jobs in queue
		case 3: showJobs(p);
			break;
		}
	} while (choice != 4);	//end program when user enters 4

	system("pause");
	return 0;
}

int showMenu()

{
	int select;
	
	//display menu
	cout << "Printer queue\n";
	cout << "========\n";
	cout << "1. Add job\n";
	cout << "2. Print job\n";
	cout << "3. View jobs\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	//return user choice
	return select;
}

void addJob(PQType<Job>& p, int c)
{
	Job input;
	//display choices
	cout << "Instructor (I or i), TA (T or t), or Student (S or s)? ";
	//capture user input
	cin >> input.staff;
	//assign priority
	if (input.staff == 'i' || input.staff == 'I')
	{
		input.num = 3;
	}
	else if (input.staff == 't' || input.staff == 'T')
	{
		input.num = 2;
	}
	else if (input.staff == 's' || input.staff == 'S')
	{
		input.num = 1;
	}
	//assign print job #
	input.printJob = c;
	//add to priority queue
	p.Enqueue(input);
}


void printJob(PQType<Job>& p)
{
	Job output;
	//check if pq empty
	if (p.IsEmpty())
	{
		cout << "No print jobs in queue." << endl;
	}
	else
	{
		//print first job in queue
		cout << "Job #";
		p.Dequeue(output);
		cout << output.printJob << ": ";
		if (output.staff == 'i' || output.staff == 'I')
		{
			cout << "Instructor" << endl;
		}
		else if (output.staff == 't' || output.staff == 'T')
		{
			cout << "TA" << endl;
		}
		else if (output.staff == 's' || output.staff == 'S')
		{
			cout << "Student" << endl;
		}
	}
}

void showJobs(PQType<Job>& p)
{
	PQType<Job> temp(MAX);
	Job output;
	//create temp pq in order to dequeue
	temp = p;
	//check if pq is empty
	if (temp.IsEmpty())
	{
		cout << "No print jobs in queue." << endl;
	}
	else
	{
		//dequeue until pq is empty
		while (!temp.IsEmpty())
		{
			cout << "Job #";
			temp.Dequeue(output);
			cout << output.printJob << ": ";
			if (output.staff == 'i' || output.staff == 'I')
			{
				cout << "Instructor" << endl;
			}
			else if (output.staff == 't' || output.staff == 'T')
			{
				cout << "TA" << endl;
			}
			else if (output.staff == 's' || output.staff == 'S')
			{
				cout << "Student" << endl;
			}
		}
	}
}