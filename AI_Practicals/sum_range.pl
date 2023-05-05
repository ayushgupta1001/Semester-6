sum_range(A,B,Result):- (A==B,Result is A).

sum_range(A,B,Result):- (A1 is A+1, sum_range(A1,B,Result1), Result is A + Result1).