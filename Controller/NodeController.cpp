/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: ghop1073
 */

#include "NodeController.h"
#include <iostream>
using namespace std;

NodeController :: NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}

NodeController :: ~NodeController()
{

}

void NodeController :: testLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
}

void NodeController :: start()
{
	codeTimer.startTimer();


	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (index * 7));
	}

	for(int index = notHipsterInts -> getSize() -  1; index >=0; index --)
	{
		cout << "the contents of not hipster ints array node " << index << " are " << notHipsterInts->get(index) << endl;
	}

	codeTimer.stopTimer();
	codeTimer.displayTimerInfo();
}
