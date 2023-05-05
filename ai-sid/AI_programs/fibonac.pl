fibo(1,RESULT):-
RESULT is 0.

fibo(2,RESULT):-
RESULT is 1.

fibo(N,RESULT):-
N>2,
N1 is N-1,
N2 is N1-1,
fibo(N1,T1),
fibo(N2,T2),
RESULT is T1+T2.