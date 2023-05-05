sumList([],0).
sumList([H|T],N):- 
	sumList(T,N1),
	N is H+N1.

start:-
writef("Enter list: \n"),nl,
read(Input),nl,
sumList(Input,Z),nl,
writef("The resultant is: %t",[Z]).