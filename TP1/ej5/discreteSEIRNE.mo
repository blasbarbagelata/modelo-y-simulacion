model discreteSEIRNE
parameter Real N = 1e6, R0 = 1.5;
parameter Integer TI = 3, TR = 12;
discrete Real S(start = N), E(start = 10000), I(start = 0), R, NE[12](start = {10000,0,0,0,0,0,0,0,0,0,0,0});
algorithm
  when sample(0, 1) then
    S := pre(S) - (R0 / (TR - TI) * pre(S) * pre(I) / N);
    E := pre(E) + (R0 / (TR - TI) * pre(S) * pre(I) / N) - pre(NE[TI]);
    I := pre(I) + pre(NE[TI]) - pre(NE[TR]);
    R := pre(R) + pre(NE[TR]);
    NE[1] := R0 / (TR - TI) * pre(S) * pre(I) / N;
    NE[2:end] := pre(NE[1:TR-1]);
  end when;
end discreteSEIRNE;