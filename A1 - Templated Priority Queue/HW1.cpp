// Programmer: Jonathan Karcher
// Date: 2022 / 09
// IGME 309

#include "Queue.h"
using namespace std;
// basic class to test the custom priority queue
class ToTest
{
	int number = 0;
public: 
	// Constructor: ToTest
	// Purpose: create a testing object
	// Arguments: none
	// Output: a testing object
	ToTest(){}
	// Constructor: ToTest
	// Purpose: create a testing object
	// Arguments: an integer
	// Output: a testing object
	ToTest(int num)
	{
		number = num;
	}
	// Operator: <<
	// Purpose: access the out stream operator to display the number to print
	// Arguments: The ToTest to read
	// Output: the out stream
	friend ostream& operator<<(ostream& out,  ToTest element)
	{
		out << element.number;
		return out;
	}
	// Operator: >
	// Purpose: set the greater than condition
	// Arguments: The ToTest to compair
	// Output: the greater object
	bool operator>(ToTest const& other)
	{
		return this->number > other.number;
	}
	// Operator: <
	// Purpose: set the less than condition
	// Arguments: The ToTest to compair
	// Output: the smaller object
	bool operator<(ToTest const& other)
	{
		return this->number < other.number;
	}
};
int main()
{
	// objects to be stored
	ToTest* t1 = new ToTest(100);
	ToTest* t2 = new ToTest(67);
	ToTest* t3 = new ToTest(104);

	// the custom queue
	MyQueue<ToTest>* queueInt = new MyQueue<ToTest>();
	// is it empty
	std::cout << queueInt->IsEmpty() << "\n";
	// add first item
	queueInt->Push(*t1);
	// what is contained
	queueInt->Print();
	// what is the updated size
	std::cout << queueInt->GetSize() << "\n\n";
	// is it empty
	std::cout << queueInt->IsEmpty() << "\n";
	// add second item
	queueInt->Push(*t2);
	// what is contained
	queueInt->Print();
	// what is the updated size
	std::cout << queueInt->GetSize() << "\n\n";
	// is it empty
	std::cout << queueInt->IsEmpty() << "\n";
	// add third item
	queueInt->Push(*t3);
	// what is contained
	queueInt->Print();
	// what is the updated size
	std::cout << queueInt->GetSize() << "\n\n";
	// is it empty
	std::cout << queueInt->IsEmpty() << "\n";
	// remove first item
	queueInt->Pop();
	// what is contained
	queueInt->Print();
	// what is the updated size
	std::cout << queueInt->GetSize() << "\n\n";
	// delete the custom queue
	delete queueInt;
	// search for memeory leaks
	_CrtDumpMemoryLeaks;
}