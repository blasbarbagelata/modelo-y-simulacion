model DiscreteSEIR
  parameter Real N = 1e6;
  discrete Real S(start = N), I(start = 10), R;
  parameter Real alpha = 1, gamma = 0.5;
algorithm
  when sample(0, 1) then
  end when;

end DiscreteSEIR;