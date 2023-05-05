start:-
writef("Enter the list : \n"),
read([H|T]),nl,

sum_list([H|T],RESULT),

writef("Sum is %t",[RESULT]).

sum_list([],0).
sum_list([H|T],RESULT):-
sum_list(T,R1),
RESULT is H+R1.