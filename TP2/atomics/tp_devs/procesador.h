//CPP:tp_devs/procesador.cpp
#if !defined procesador_h
#define procesador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class procesador: public Simulator { 
// Declare the state,
// output variables
// and parameters
bool busy;
double sigma;

double y;

#define INF 1e20
public:
	procesador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
