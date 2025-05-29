#include "fuente.h"
void fuente::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
jmin =va_arg(parameters,double);
jmax =va_arg(parameters,double);
tmin =va_arg(parameters,double);
tmax =va_arg(parameters,double);

job = (jmax - jmin) * rand()/ RAND_MAX + jmin;
sigma = (tmax - tmin) * rand()/ RAND_MAX + tmin;
}
double fuente::ta(double t) {
//This function returns a double.
return sigma;
}
void fuente::dint(double t) {
job = (jmax - jmin) * rand()/ RAND_MAX + jmin;
sigma = (tmax - tmin) * rand()/ RAND_MAX + tmin;
}
void fuente::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

}
Event fuente::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = job;
return Event(&y,0);
}
void fuente::exit() {
//Code executed at the end of the simulation.

}
