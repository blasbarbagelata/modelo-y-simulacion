//CPP:tp_devs/sensor.cpp
#if !defined sensor_h
#define sensor_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class sensor: public Simulator { 
// Declare the state,
// output variables
// and parameters
double sigma;
int jobs_count;
double y;

#define INF 1e20
public:
	sensor(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
