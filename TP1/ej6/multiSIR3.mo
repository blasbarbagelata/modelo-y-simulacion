model multiSIR3
discreteSIRimp M1, M2(I.start = 0), M3(I.start = 0);
algorithm
  when sample(0, 1) then
    M1.imp := pre(M2.exp) / 2;
    M2.imp := pre(M1.exp) + pre(M3.exp);
    M3.imp := pre(M2.exp) / 2;
  end when;
end multiSIR3;