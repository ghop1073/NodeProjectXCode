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

void NodeController::doMergesort()
{
    mergeData = new int[500000];
    for(int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ",";
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData, 5000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ",";
    }
    
    delete [] mergeData;
}

void NodeController::mergesort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size-sizeOne;
        
        mergesort(data, sizeOne);
        mergesort((data+sizeOne), sizeTwo);
        
        merge(data,sizeOne,sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    
    delete [] temp;
}