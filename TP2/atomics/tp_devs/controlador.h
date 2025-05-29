//CPP:tp_devs/controlador.cpp
#if !defined controlador_h
#define controlador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class controlador: public Simulator { 
// Declare the state,
// output variables
// and parameters
double sigma;
double errRe;
double errAbs;
double k1, k2;
double y;
double lref;
double lon_cola;
double p;

#define INF 1e20;
public:
	controlador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
