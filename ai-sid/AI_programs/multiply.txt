multiply(0,N,0).
multiply(M,N,R):-
M<0,N<0,
M1 is -M,
N1 is -N,
multiply(M1,N1,R).

multiply(M,N,R):-
M<0, N>0,
M1 is -M,
N1 is -N,
multiply(M1,N1,R).

multiply(M,N,R):-
M1 is M-1,
multiply(M1,N,R1),
R is N+R1.