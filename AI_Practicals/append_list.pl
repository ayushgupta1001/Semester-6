append([],L,L).
append([H|T],L2,[H|RT]):- append(T,L2,RT).