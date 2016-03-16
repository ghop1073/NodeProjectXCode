/*
 * Timer.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mhop1073
 */

#ifndef MODEL_TIMER_H_
#define MODEL_TIMER_H_

#include <time.h>

class Timer
{
private:
	clock_t executionTime;
public:

	Timer();
	void startTimer();
	virtual ~Timer();
	void stopTimer();
	void resetTimer();
	void displayTimerInfo();
	long getExecutionTimeInMicroSec();
};



#endif /* MODEL_TIMER_H_ */


