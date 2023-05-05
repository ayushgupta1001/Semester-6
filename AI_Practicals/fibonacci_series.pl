fib(0, 0).
fib(1, 1).
fib(N,Result):-fibonacci(N,0,1,Result).

fibonacci(0,N,_,N).
fibonacci(N, P1,P2,Result):-
   N>0,
   New_P2 is P1+P2,
   N1 is N-1,
   fibonacci(N1,P2,New_P2,Result).