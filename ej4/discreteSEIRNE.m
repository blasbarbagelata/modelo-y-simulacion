function x = discreteSEIRNE(pre_x, t)
  N = 1e6;
  TR = length(pre_x) - 4;
  TI = 3;
  R0 = 1.5;
  pre_S = pre_x(1);
  pre_E = pre_x(2);
  pre_I = pre_x(3);
  pre_R = pre_x(4);
  pre_NE = pre_x(5:length(pre_x));
  NEAux = R0 / (TR - TI) * pre_S * pre_I / N;
  S = pre_S - NEAux;
  E = pre_E + NEAux - pre_NE(TI);
  I = pre_I + pre_NE(TI) - pre_NE(TR);
  R = pre_R + pre_NE(TR);
  NE = [NEAux; pre_NE(1:TR-1)];
  x = [S;E;I;R;NE];
endfunction
