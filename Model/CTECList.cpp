/*
 * CTECList.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mhop1073
 */

#include "CTECList.h"
#include <iostream>
#include <assert.h>
using namespace std;
template <class Type>

CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

template<class Type>
CTECList<Type>::~CTECList()
{

	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}
}

template<class Type>
void CTECList<Type>:: addAtIndex(int index, const Type& value)
{

	assert(size > 0);
	assert(index > 0);
	assert(index < size);

	ArrayNode<Type> * currentSpot = head;
	ArrayNode<Type> * nextSpot;
	ArrayNode<Type> * newNext;
	ArrayNode<Type> * newNode = new ArrayNode<Type>(value);

		for (int spot = 0; spot < index + 1; index++)
		{

			if (spot == index - 1)
			{
				newNext = newNode;
				currentSpot->setNext(newNext);
				newNext->setNext(nextSpot);

			}

			if (spot == index + 1)
			{
				nextSpot = currentSpot->getNext();
			}

			currentSpot = currentSpot->getNext();
		}

		calculateSize();


}

template<class Type>
void CTECList<Type>:: addToEnd(const Type& value)
{

	assert(size >= 0);

    ArrayNode<Type> * newEnd = new ArrayNode<Type>(value);
		
    if(size == 0)
    {
        head = newEnd;
    
    }
    else if(size == 1)
    {
        head->setNext(newEnd);
    }
    else
    {
        end->setNext(newEnd);
      
    }
      end = newEnd;

		
		
		calculateSize();
}

template<class Type>
void CTECList<Type>:: addToFront(const Type& value)
{
	ArrayNode<Type> * current = head;
		ArrayNode<Type> * newFirst = new ArrayNode<Type>(value);

		newFirst->setNext(current);
		head = newFirst;

		calculateSize();

}

template<class Type>
Type CTECList<Type>::removeFromFront()
{

	assert(this->size > 0);

	Type thingToRemove;
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();
	thingToRemove = this->head->getValue();
	delete this-> head;

	this->head = newHead;


	return thingToRemove;


}

template<class Type>
Type CTECList<Type>::removeFromIndex(int index)
{

	assert(index >= 0);
	assert(index < size);
	assert(this->size>0);
	Type storedValue;
	ArrayNode<Type> * current = head;
	ArrayNode<Type> * previous;
	ArrayNode<Type> * newNext;

	for(int spot = 0; spot < index +1; spot++)
	{
		if(spot == index-1)
		{
			previous = current;
		}
		if(spot == index)
		{
			storedValue = current->getValue();
			newNext = current->getNext();
			delete current;
		}

		current = current->getNext();
	}

	previous->setNext(newNext);

	return storedValue;
}

template <class Type>
Type CTECList<Type> :: removeFromEnd()
{
	assert(size>0);

	Type returnValue;

	if(size == 1)
	{
		ArrayNode<Type> * toRemove = end;
		returnValue = removeFromFront();
		end = nullptr;
		head = nullptr;
		delete toRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int index = 0;index < size - 1; index++)
		{
			current = current->getNext();
		}
		returnValue = end->getValue();
		delete end;
		current = end;
		current->setNext(nullptr);
	}

	calculateSize();

	return returnValue;
}

template<class Type>
Type CTECList<Type>::getEnd()
{
	return end->getValue();

}

template<class Type>
Type CTECList<Type>::getFront()
{
	return head->getValue();
}

template<class Type>
Type CTECList<Type>::set(int pos, const Type& value)
{

	assert(pos < size && pos >= 0);
	ArrayNode<Type> * current = head;
	Type returnValue;

	for (int spot = 0; spot <= pos; spot++)
	{
		if (spot != pos)
		{
			current = current->getNext();
		}
		else
		{
			returnValue = current->getValue();
			current->setValue(value);
		}

	}

	return returnValue;

}

template<class Type>
Type CTECList<Type>::getFromIndex(int index)
{
	ArrayNode<Type> * current = head;
	Type valueHolder;

	assert(index >= 0);
	assert(index < size);
	assert(this->size > 0);

	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current->getNext();
		}
		else
		{
			valueHolder = current->getValue();
		}
	}

	return valueHolder;

}

template <class Type>
void CTECList<Type> :: calculateSize()
{
	assert(size >= 0);

	int count = 0;
	if(head == nullptr)
	{
		size = count;
	}
	else
	{
		count++;
		ArrayNode<Type> * current = head;
		while(current->getNext() != nullptr)
		{
			count++;
			current = current->getNext();
		}
		size = count;
	}
}

template <class Type>
void CTECList<Type> :: swap(int indexOne, int indexTwo)
{
    assert(indexOne < size && indexTwo < size);
    Type temp = getFromIndex(indexOne);
    set(indexOne, getFromIndex(indexTwo));
    set(indexTwo, temp);
}

template <class Type>
void CTECList<Type> :: selectionSort()
{
    for(int outerLoop = 0; outerLoop < size -1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
           if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
           {
               selectedMinimum = innerLoop;
           }
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}
