// Programmer: Jonathan Karcher
// Date: 2022 / 09
// IGME 309
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
	// Arguments: none
	// Output: the empty queue
	MyQueue();
	// Copy Constructor: MyQueue
	// Purpose: set the inital state of the array to the array being compaired
	// Arguments: class object to copy
	// Output: a duplicet queue 
	MyQueue(const MyQueue& queue);
	// Destructor: MyQueue
	// Purpose: clear the array of elements
	// Arguments: none
	// Output: nothing 
	~MyQueue();
	// Method: Print 
	// Purpose: Print out the contents of the array 
	// Arguments: none
	// Output: the contents of the queue on a new line for each entery
	void Print();
	// Method: Pop
	// Purpose: Return the first element in the array
	// Arguments: none
	// Output: the first element
	E Pop();
	// Method: Push
	// Purpose: Add one element to the array
	// Output  nothing
	void Push(E element);
	// Method: GetSize
	// Purpose: Return the number of elements in the array
	// Arguments: element being added to the queue
	// Output:  the number of active elements
	int GetSize();
	// Method: IsEmpty
	// Purpose: Return true if there are no elements contained
	// Arguments: none
	// Output: true if empty or false if not empty
	bool IsEmpty();
	// Method: Copy
	// Purpose: Copy the elements from one array to another
	// Arguments: none
	// Output: a duplicte object
	void Copy(E* queue);
};

// Copy Constructor: MyQueue
// Purpose: set the inital state of the array to the array being compaired
// Arguments: none
// Output: the empty queue
template<class E>
inline MyQueue<E>::MyQueue()
{
	elements = new E[maxElements];
}
// Copy Constructor: MyQueue
// Purpose: set the inital state of the array to the array being compaired
// Arguments: class object to copy
// Output: a duplicet queue 
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
// Arguments: none
// Output: nothing 
template<class E>
inline MyQueue<E>::~MyQueue()
{
	delete[] elements;
}
// Method: Print 
// Purpose: Print out the contents of the array
// Arguments: none
// Output: the contents of the queue on a new line for each entery
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
// Arguments: none
// Output: the first element
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
// Purpose: Add one element to the array and reorder it from gratest to least
// Arguments: element being added to the queue
// Output: nothing 
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
// Arguments: none
// Output: true if empty or false if not empty
template<class E>
inline int MyQueue<E>::GetSize()
{
	return elementsContained;
}
// Method: IsEmpty
// Purpose: Return true if there are no elements contained
// Arguments: none
// Output: true if empty or false if not empty
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
// Arguments: class object to copy
// Output: a duplicet queue 
template<class E>
inline void MyQueue<E>::Copy(E* queue)
{
	for (int i = 0; i < elementsContained; i++)
	{
		queue[i] = elements[i];
	}
}