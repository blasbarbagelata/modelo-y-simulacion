model ej10
discrete Real x,y,th,v,psi,a,w;
parameter Real L=1, h=0.1;
algorithm
 when sample(0,h)then
  x:=pre(x)+h*cos(pre(th))*cos(pre(psi))*pre(v);
  y:=pre(y)+h*sin(pre(th))*cos(pre(psi))*pre(v);
  th:=pre(th) + h*(sin(pre(psi)) *pre(v)/L);
  v:= pre(v) + h * pre(a);
  psi:= pre(psi) + h*pre(w);
  if time <1 then
    a:=1;
    w:=0.1;
  elseif time>=2 then
    a:=0;
  x:=pre(x)+h*cos(pre(th))*cos(pre(psi))*pre(v);
  y:=pre(y)+h*sin(pre(th))*cos(pre(psi))*pre(v);
  th:=pre(th) + h*(sin(pre(psi)) *pre(v)/L);
  v:= pre(v) + h * pre(a);
  psi:= pre(psi) + h*pre(w);
    w:=0;
  else
    a:=1;
    w:=-0.1;
  end if;
  end when;
end ej10;