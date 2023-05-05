gcd(A,B,RESULT):-
A==B,
RESULT is A.

gcd(0,B,RESULT):-
RESULT is B.

gcd(A,B,RESULT):-
A>B,
A1 is A,
B1 is B,
A is B1,
B is A1.


gcd(A,B,RESULT):-
A1 is B mod A,
gcd(A1,A,R1),
RESULT is R1.