model ej10b
discrete Real x,y,th,v,psi,a,w,psiref;
parameter Real L=1, h=0.1,Kv=1,Kpsi=2,Ky=0.5,L0=4,vref=2,yref=1;
algorithm
 when sample(0,h)then
  x:=pre(x)+h*cos(pre(th))*cos(pre(psi))*pre(v);
  y:=pre(y)+h*sin(pre(th))*cos(pre(psi))*pre(v);
  th:=pre(th) + h*(sin(pre(psi)) *pre(v)/L);
  v:= pre(v) + h * pre(a);
  psi:= pre(psi) + h*pre(w);
  
  a:= Kv*(vref - pre(v));
  w:= Kpsi * (pre(psiref)-pre(psi));
  psiref:= Ky * (atan(yref-pre(y))/L0-pre(th));
  end when;

end ej10b;