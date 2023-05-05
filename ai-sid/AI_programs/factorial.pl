fact(0,RESULT):- RESULT is 1.

fact(A,RESULT):-
A>0,
A1 is A-1,
fact(A1,R1),
RESULT is A*R1.
