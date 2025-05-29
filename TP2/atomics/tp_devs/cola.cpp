#include "cola.h"
void cola::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
for (int i = 0; i<20000; i++){
	jobs[i]= 0;
}
busy = false;
sigma = INF;
ini = 0;
fin = 0;
}
double cola::ta(double t) {
//This function returns a double.
return sigma;
}
void cola::dint(double t) {
busy = true;
sigma = INF;

ini=(ini+1)%20000;

}
void cola::dext(Event x, double t) {
if ( x.port == 0) {
	jobs[fin] = x.getDouble();
	fin = (fin+1) %20000;
	if ( busy) {
		sigma = INF;
	} else {
		sigma = 0;
	}
}
else {
	busy = false;
	if (ini == fin) {
		sigma = INF;
	} else {
		sigma = 0;
	}
}	

}
Event cola::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = jobs[ini];
return Event(&y,0);
}
void cola::exit() {
//Code executed at the end of the simulation.

}
