#ifndef BUSYWAIT_H
#define BUSYWAIT_H 



#include "core/TaskLoad.h"

class BusyWait : public TaskLoad{
private:

	unsigned long count;

public:
	BusyWait();

	virtual ~BusyWait();

	// void setWCET();

	bool runLoads(unsigned long _wcet_us);

};












#endif