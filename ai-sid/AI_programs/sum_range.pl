sum_range(A,B,RESULT):-
A==B,
RESULT is A.

sum_range(A,B,RESULT):-
A1 is A+1,
sum_range(A1,B,R1),
RESULT is A+R1.