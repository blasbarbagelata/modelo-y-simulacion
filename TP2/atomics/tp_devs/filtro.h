//CPP:tp_devs/filtro.cpp
#if !defined filtro_h
#define filtro_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class filtro: public Simulator { 
// Declare the state,
// output variables
// and parameters
double sigma;
double y;
double job;
double p;
double ra;
#define INF 1e20;
public:
	filtro(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
