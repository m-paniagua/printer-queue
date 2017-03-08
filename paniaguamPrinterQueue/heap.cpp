//  IMPLEMENTATION  OF RECURSIVE HEAP MEMBER FUNCTIONS
#ifdef HEAP_H


template< class  ItemType >
void   HeapType<ItemType>::Swap(ItemType& a, ItemType& b)
{
	ItemType temp;
	temp = a;
	a = b;
	b = temp;
}

template< class  ItemType >
void   HeapType<ItemType>::ReheapDown(int root, int  bottom)

// Pre:  root is the index of the node that may violate the
// heap order property
// Post: Heap order property is restored between root and bottom

{
	int  maxChild;
	int  rightChild;
	int  leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild].num < elements[rightChild].num)
				maxChild = rightChild;
			else if (elements[leftChild].num == elements[rightChild].num)
			{
				if (elements[leftChild].printJob < elements[rightChild].printJob)
				{
					maxChild = leftChild;
				}
				else
				{
					maxChild = rightChild;
				}
			}
			else
				maxChild = leftChild;
		}
		if (elements[root].num < elements[maxChild].num)
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}

		if (elements[root].num == elements[maxChild].num)
		{
			if (elements[root].printJob  >  elements[maxChild].printJob)
			{
				Swap(elements[root], elements[maxChild]);
				ReheapDown(maxChild, bottom);
			}
		}
	}
}

template< class  ItemType >
void   HeapType<ItemType>::ReheapUp(int  root, int  bottom)

//  Pre:  bottom is the index of the node that may violate the heap
//  order property.  The order property is satisfied from root to
//  next-to-last node.
//  Post:  Heap order property is restored between root and bottom

{
	int  parent;

	if (bottom  > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent].num  <  elements[bottom].num)
		{
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
		//if same priority, compares job number
		if (elements[parent].num == elements[bottom].num)
		{
			if (elements[parent].printJob  >  elements[bottom].printJob)
			{
				Swap(elements[parent], elements[bottom]);
				ReheapUp(root, parent);
			}
		}
	}
}
#endif