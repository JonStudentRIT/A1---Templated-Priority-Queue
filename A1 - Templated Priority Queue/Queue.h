#pragma once
#include <iostream>
template <class  E>
class MyQueue
{
public:
	// the number of active elements that the object holds
	int elementsContained = 0;
	// the amount of memeory that this object has use of
	int maxElements = 1;
	// the array of elements
	E* elements;
	// Constructor: MyQueue
	// Purpose: sets the initial state of the array of elements
	MyQueue();
	// Copy Constructor: MyQueue
	// purpose: set the inital state of the array to the array being compaired
	MyQueue(const MyQueue& queue);
	// Destructor: MyQueue
	// Purpose: clear the array of elements
	~MyQueue();
	// Method: Print 
	// Purpose: Print out the contents of the array 
	void Print();
	// Method: Pop
	// Purpose: Return the first element in the array
	E Pop();
	// Method: Push
	// Purpose: Add one element to the array
	void Push(E element);
	// Method: GetSize
	// Purpose: Return the number of elements in the array
	int GetSize();
	// Method: IsEmpty
	// Purpose: Return true if there are no elements contained
	bool IsEmpty();
	// Method: Copy
	// Purpose: Copy the elements from one array to another
	void Copy(E* queue);
};


// Copy Constructor: MyQueue
// purpose: set the inital state of the array to the array being compaired
template<class E>
inline MyQueue<E>::MyQueue()
{
	elements = new E[maxElements];
}
// Copy Constructor: MyQueue
// purpose: set the inital state of the array to the array being compaired
template<class E>
inline MyQueue<E>::MyQueue(const MyQueue& queue)
{
	elements = new E[maxElements];
	for (int i = 0; i < queue.elementsContained; i++)
	{
		Push(queue.elements[i]);
	}
}
// Destructor: MyQueue
// Purpose: clear the array of elements
template<class E>
inline MyQueue<E>::~MyQueue()
{
	delete[] elements;
}
// Method: Print 
// Purpose: Print out the contents of the array
template<class E>
inline void MyQueue<E>::Print()
{
	int i = 0;
	// while there are still more elements to check
	while (i < elementsContained)
	{
		// print the element
		std::cout << elements[i] << std::endl;
		i++;
	}
}
// Method: Pop
// Purpose: Return the last element in the array
template<class E>
inline E MyQueue<E>::Pop()
{
	// store the last element to return
	E temp = elements[0];
	// shift the list of elements forward one
	for(int i = 0; i < elementsContained - 1; i++)
	{
		elements[i] = elements[i + 1];
	}
	// change the number of active elements
	elementsContained--;
	// set the position in the array to null
	elements[elementsContained] = NULL;
	// if the array was not empty
	if (elementsContained >= 1)
	{
		return temp;
	}
	// if the array was empty
	else
	{
		return NULL;
	}
}
// Method: Push
// Purpose: Add one element to the end of the array
template<class E>
inline void MyQueue<E>::Push(E element)
{
	// if we have reached the maximum amount of memeory allocated
	if (elementsContained >= maxElements)
	{
		// double the amount of memeory
		maxElements *= 2;
		// resize the array
		E* temp = new E[maxElements];
		// copy over the elements
		Copy(temp);
		delete[] elements;
		elements = temp;
	}
	// add an element to the end of the list
	elements[elementsContained] = element;
	// order from largest to smallest
	for (int i = elementsContained; i > 0; i--)
	{
		if (elements[i] > elements[i - 1])
		{
			E temp = elements[i];
			elements[i] = elements[i - 1];
			elements[i - 1] = temp;
		}
	}
	elementsContained++;
}
// Method: GetSize
// Purpose: Return the number of elements in the array
template<class E>
inline int MyQueue<E>::GetSize()
{
	return elementsContained;
}
// Method: IsEmpty
// Purpose: Return true if there are no elements contained
template<class E>
inline bool MyQueue<E>::IsEmpty()
{
	if (elementsContained > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
// Method: Copy
// Purpose: Copy the elements from one array to another
template<class E>
inline void MyQueue<E>::Copy(E* queue)
{
	for (int i = 0; i < elementsContained; i++)
	{
		queue[i] = elements[i];
	}
}