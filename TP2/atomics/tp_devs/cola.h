//CPP:tp_devs/cola.cpp
#if !defined cola_h
#define cola_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class cola: public Simulator { 
// Declare the state,
// output variables
// and parameters
double sigma;
double jobs[20000];
int ini, fin;
double y;
bool busy;

#define INF 1e20

public:
	cola(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
