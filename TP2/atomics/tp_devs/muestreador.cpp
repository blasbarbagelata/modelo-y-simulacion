#include "muestreador.h"
void muestreador::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

tiempo_ini = va_arg(parameters,double);
sigma = tiempo_ini;
valor = 0;
}
double muestreador::ta(double t) {
//This function returns a double.
return sigma;
}
void muestreador::dint(double t) {
sigma = tiempo_ini;

}
void muestreador::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
valor = x.getDouble();
sigma -= e;
}
Event muestreador::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

y = valor;
return Event(&y,0);
}
void muestreador::exit() {
//Code executed at the end of the simulation.

}
