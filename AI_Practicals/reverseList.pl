append([],L,L).
append([H|T],L2,[H|RT]):- append(T,L2,RT).

reverseList([],[]).
reverseList([E],[E]).
reverseList([H|T],R):- 
	reverseList(T,R1),
	append(R1,[H],R).