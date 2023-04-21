%required to use simplex so we usre fminsearch
clc
options = optimset('Largescale','off','Largescale','off');
v0 =[0.6, -0.2, -0.1];

sol = fminsearch('ex9_func',v0,options)

