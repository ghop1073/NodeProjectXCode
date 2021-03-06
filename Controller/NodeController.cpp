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
    //auto-generated constructor
    notHipsterInts = new CTECArray<int>(5);
    numbers = new CTECList<int>();
}

NodeController :: ~NodeController()
{
    //auto-generated destructor
}

//void NodeController :: testList()
//{
//    
//    
//    numbers->addToFront(3);
//    numbers->addToEnd(8);
//    numbers->addAtIndex(1,188);
//    
//    cout << "End should be 8 and is " << numbers->getEnd() << endl;
//    cout << "Front should be 3 and is " << numbers->getFront() << endl;
//    cout << "the middle should be 188 and is" << numbers->getFromIndex(2);
//    
//    numbers->addToEnd(19);
//    numbers->addToEnd(20);
//    
//    numbers->removeFromEnd();
//    cout << "the end should be 19 and is " << numbers->getEnd() << endl;
//    numbers->removeFromIndex(2);
//    cout << "the index 1 should be 188 and is" << numbers->getFromIndex(1) << endl;
//    numbers->removeFromFront();
//    cout << "the beginning should be 188 and is" << numbers->getFront() << endl;
//    
//    cout << "the size of the list should be 2 and is" << numbers->calculateSize();
//    cout << "the index of 19 should be 1 and is" << numbers->getFromIndex(<#int index#>)(2);
//    
//    
//    
//    
//    
//    
//}



void NodeController :: start()
{
//    tryTrees();
        doMergesort();
    
    	arrayTimer.startTimer();
    
    	for(int index = 0; index < notHipsterInts->getSize(); index++)
    	{
    		notHipsterInts->set(index, (index *23));
    	}
    
    	for(int index = notHipsterInts -> getSize() -  1; index >=0; index --)
    	{
    		cout << "tuh contents of not hipster ints array node " << index << " are " << notHipsterInts->get(index) << endl;
    	}
    
    	arrayTimer.stopTimer();
    	arrayTimer.displayTimerInfo();
    
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
        cout << mergeData[spot] << ", ";
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergesort(mergeData,500000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    for(int spot = 0; spot < 500000; spot++)
    {
        cout << mergeData[spot] << ", ";
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
        
        merge(data, sizeOne, sizeTwo);
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
        temp[copied++] = (data+ sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex - 1);
        quicksort(pivotIndex+1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last) /2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
            
            
        }
        
    }
    swap(first,smallIndex);
    return smallIndex;
}



void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::doQuick()
{
    mergeData = new int[100000000];
    
    for(int spot = 0; spot < 100000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0,100000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInfo();
    
    
    delete [] mergeData;
    
}



//void NodeController::tryGraphs()
//{
//        CTECGraph<int> testGraph;
//        testGraph.addVertex(4);
//}
//
//void NodeController::tryTrees()
//{
//    
//    CTECBinaryTree<int> testTree;
//    testTree.insert(1);
//    testTree.insert(5);
//    testTree.insert(7);
//    testTree.insert(3);
//    testTree.insert(2);
//    testTree.insert(8);
//    testTree.insert(12);
//    
//    testTree.getSize();
//    testTree.postorderTraversal(testTree.getRoot());
//    
//    
//    
//    
//}







