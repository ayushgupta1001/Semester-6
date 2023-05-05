% WAP to implement to predicates:- evenlength(list) and oddlength(list) 
% so that they are true if their argument is a list of even and odd length respectively.

evenlist([]).
evenlist([H|T]):- oddlist(T).

oddlist([_]).
oddlist([H|T]):- evenlist(T). 

start:-
writef("Enter list: \n"),nl,
read(Input),nl,
(evenlist(Input) == true -> write('List is of even length'); write('List is of odd length')).