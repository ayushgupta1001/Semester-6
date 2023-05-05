% REVERSE 
reverse([],A,A).
reverse([H|T],A,R):-  reverse(T,[H|A],R).

% EQUAL 
equal([],[]):-write('List is palindrome'),nl,choice.
equal([H1|L1],[H1|L2]):-equal(L1,L2).
equal([H1|L1],[H2|L2]):-write('List is not a palindrome'),nl,choice.

% PALINDROME
pal(L):-reverse(L,R),equal(L,R),!.

start:-
writef("Enter list: \n"),nl,
read(Input),nl,
pal(Input).

choice:-
writef("Do you want to continue? (y/n) \n"),nl,
read(Choice),nl,
(Choice == y -> start; Choice == n -> writef("Thank you! \n")).
