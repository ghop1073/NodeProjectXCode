/*
 * ArrayNode.h
 *
 *  Created on: Jan 29, 2016
 *      Author: nhay7834
 */

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

#include "Node.h"
template<class Type>
class ArrayNode: public Node<Type>
{
private:
	ArrayNode * next;
	Type value;

public:
	ArrayNode();
	ArrayNode(const Type& value);
	ArrayNode( const Type& value, ArrayNode * next);
	virtual ~ArrayNode();
	ArrayNode * getNext();
	void setNext(ArrayNode * next);
    void swap(int indexOne, int indexTwo);

};

#endif /* MODEL_ARRAYNODE_H_ */
