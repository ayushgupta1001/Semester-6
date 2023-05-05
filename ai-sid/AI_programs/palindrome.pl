equal([],[]).
equal([H1|R1],[H2|R2]):-
H1 == H2,
equal(R1,R2).

rev([],L1,L1).
rev([H|T],L1,R1):-
rev(T,[H|L1],R1).

palindrome(L):-
rev(L,[],R),
equal(L,R).