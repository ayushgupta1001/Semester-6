accRev([],A,A).
accRev([H|T],A,R):-  accRev(T,[H|A],R).