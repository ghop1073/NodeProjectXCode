/*
 * CTECList.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mhop1073
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_
#include "ArrayNode.h"

template<class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;

public:
	CTECList();
	virtual ~CTECList();
	void addAtIndex(int index, const Type& value);
	void addToFront(const Type& value);
	void addToEnd(const Type& value);
	void calculateSize();
	Type removeFromIndex(int index);
	Type removeFromFront();
	Type removeFromEnd();
	Type getEnd();
	Type getFront();
	Type getFromIndex(int index);
	Type set(int index, const Type& value);
};

#endif /* MODEL_CTECLIST_H_ */


