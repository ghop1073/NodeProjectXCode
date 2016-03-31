/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: ghop1073
 */

#include "NodeController.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

NodeController :: NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
	numbers = new CTECList<int>();
}

NodeController :: ~NodeController()
{

}

void NodeController :: testList()
{
    numbers->addToFront(3);
    
    numbers->addToEnd(8);
    
    cout << "End should be 8 and is " << numbers->getEnd() << endl;
    
    
}

void NodeController :: start()
{
    testList();
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

void NodeController::sortData()
{
    CTECArray<int> randomNumberArray(5000);
    CTECList<int> randomNumberList;
    int myCPlusPlusArray[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        randomNumberArray.set(spot, myRandom);
        randomNumberList.addToEnd(myRandom);
        myCPlusPlusArray[spot] = myRandom;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    randomNumberArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    std::sort(std::begin(myCPlusPlusArray), std::end(myCPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInfo();
    
    sortTimer.resetTimer();
}
