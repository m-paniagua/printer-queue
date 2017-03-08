// Assumes ItemType either a built-in simple data
// type or a class with overloaded relational operators.

//template< class  ItemType >
#ifndef HEAP_H
#define HEAP_H

const int MAX = 25;  //maximum number of print jobs

struct Job
{
	char staff;
	int num;	//3 for instructor, 2 for TA, 1 for student
	int printJob;	//number of jobs
};

template< class  ItemType >
struct  HeapType
{
	void   ReheapDown(int  root, int  bottom);
	void   ReheapUp(int  root, int  bottom);
	void   Swap(ItemType&, ItemType&);

	//  ItemType* elements; //array to be allocated dynamically
	ItemType elements[MAX];
	int  numElements;
};



#include "heap.cpp"
#endif