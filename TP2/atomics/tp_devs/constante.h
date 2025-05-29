//CPP:tp_devs/constante.cpp
#if !defined constante_h
#define constante_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class constante: public Simulator { 
// Declare the state,
// output variables
// and parameters
double y;
double sigma;

#define INF 1e20;
public:
	constante(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
