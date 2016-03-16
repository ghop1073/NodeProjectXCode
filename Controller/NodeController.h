/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: ghop1073
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include "../Model/Node.h"
#include "../Model/Node.cpp"
#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"

#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"
#include "../Model/CTECList.h"

#include <string>

#include "../Model/ArrayNode.cpp"
#include "../Model/ArrayNode.h"
using namespace std;

class NodeController
{
private:

	CTECArray<int> * notHipsterInts;
	Timer codeTimer;
	void testLists();
	CTECList<int> * numbers;

public:
	virtual ~NodeController();
	NodeController();
	void start();
};



#endif /* CONTROLLER_NODECONTROLLER_H_ */
