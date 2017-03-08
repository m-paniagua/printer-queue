#include "heap.h"

#ifndef PQTYPE_H
#define PQTYPE_H

template<class ItemType>
class PQType
{
public:
	PQType(int);
	//~PQType();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType&);

private:
	int length;
	HeapType<ItemType> items;
	int maxItems;
};

#include "pqtype.cpp"
#endif