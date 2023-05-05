max(X, Y, M):- 
X > Y, 
M is X, 
write(M).
max(X, Y, M):- 
Y > X, 
M is Y,
write(M).
max(X,Y):-
X=Y,
write('Both are equal').