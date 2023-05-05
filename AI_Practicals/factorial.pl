fact(A,Result):- A==0, Result = 0.
fact(A,Result):- A==1, Result = 1.
fact(A,Result):- (A1 is A-1, fact(A1,Result1),Result is A*Result1).