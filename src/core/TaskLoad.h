#ifndef TASKLOAD_H
#define TASKLOAD_H

#include <time.h>
#include <atomic>
#include <semaphore.h>

#include "utils/TimeUtil.h"
#include "utils/Operators.h"

#define setCheckBlockBegin() \
    ++TASKLOADCOUNTER;                  \
	if(sem_trywait(&stop_sem) == 0){ 	\
		TASKLOADSTOPCOUNTER = TASKLOADSTOPCOUNTER>TASKLOADCOUNTER? TASKLOADSTOPCOUNTER: TASKLOADCOUNTER; \
        return false;							\
	}                                      \
    if (TASKLOADCOUNTER >= TASKLOADSTOPCOUNTER){ \




#define setCheckBlockEnd() \
    }                           \



class TaskLoad {

protected:

	sem_t suspend_sem;

	sem_t resume_sem;

	struct timespec sleepEnd;

	sem_t stop_sem;

	unsigned long wcet_us;

    unsigned long TASKLOADCOUNTER;

    unsigned long TASKLOADSTOPCOUNTER;

    // bool isInterrupted;

public:

	TaskLoad();

	virtual ~TaskLoad();

    bool LoadsInterface(unsigned long _wcet_us);

	virtual bool runLoads(unsigned long _wcet_us);

	inline void setSuspendPoint(){
    	if (sem_trywait(&suspend_sem) == 0)//successfully read a suspend singal, go to sleep immediately
    	{
    		// struct timespec now = TimeUtil::getTime();
    		// struct timespec sleepEnd = now + sleepLength;
    		int resumeVal;

      		// make sure the resume semaphore is cleared
    		sem_getvalue(&resume_sem, &resumeVal);
    		for (int i = 0; i < resumeVal; ++i)
    		{
    			sem_trywait(&resume_sem);
    		}

      		// two exit conditions: reach the sleepEnd time, or recieves a resume_sem signal
    		sem_timedwait(&resume_sem, &sleepEnd);
    	}

    };

    inline void initCheckCounter(){
        TASKLOADCOUNTER = 0;
    }

    void suspend(const struct timespec& length);

    void stop();

    void resume();




};





#endif