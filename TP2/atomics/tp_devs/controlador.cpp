#include "controlador.h"
void controlador::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
sigma = 0;
lref = va_arg(parameters,double);
k1 = va_arg(parameters,double);
k2 = va_arg(parameters,double);
p = 1;
errAbs = 0;
}
double controlador::ta(double t) {
//This function returns a double.
return sigma;

}
void controlador::dint(double t) {
sigma = INF;
errRe = lref -lon_cola;
errAbs = errAbs + errRe;
p = (k1 * errRe + k2 * errAbs);
if( p > 1 ) {
	 p = 1;
} else if( p < 0) {
	p = 0;
}

	


}
void controlador::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
lon_cola = x.getDouble();
sigma = 0;


}
Event controlador::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = p;
return Event(&y,0);
}
void controlador::exit() {
//Code executed at the end of the simulation.

}
