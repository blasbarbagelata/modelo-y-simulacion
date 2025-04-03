function [t,S,I,R] = epidemia(S0,I0,N,ti,tf,alph,gam)
  t=[ti:tf]
  S= zeros(1, length(t));
  I= zeros(1, length(t));
  R= zeros(1, length(t));
  S(1) =S0
  I(1) = I0
  R(1) = 0
  for k=1:length(t)-1
    S(k+1) = S(k)- (alph*S(k)*I(k))/N
    I(k+1) = I(k) + (alph*S(k)*I(k))/N - gam*I(k)
    R(k+1) = R(k) + gam*I(k)
  endfor
 end