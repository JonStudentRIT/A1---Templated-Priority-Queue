#include "Queue.h"
#include "Alberto.h"
int main()
{
	MyQueue<AlbertoClass>* queueInt = new MyQueue<AlbertoClass>();
	std::cout << queueInt->IsEmpty() << "\n";
	queueInt->Push(AlbertoClass());
	queueInt->elements[0].SetAge(26);
	queueInt->Print();
	std::cout << queueInt->GetSize() << "\n\n";
	std::cout << queueInt->IsEmpty() << "\n";
	queueInt->Push(AlbertoClass());
	queueInt->Print();
	std::cout << queueInt->GetSize() << "\n\n";
	std::cout << queueInt->IsEmpty() << "\n";
	queueInt->Push(AlbertoClass());
	queueInt->Print();
	std::cout << queueInt->GetSize() << "\n\n";
	std::cout << queueInt->IsEmpty() << "\n";
	queueInt->Pop();
	queueInt->Print();
	std::cout << queueInt->GetSize() << "\n\n";
	delete queueInt;
	_CrtDumpMemoryLeaks;
}