%multi(2,3,R).
% 2+2+2
 
multi(0,_, 0):- !.
multi(X,Y,Z):-
    X>0,Y>0,
    X1 is X-1,
    multi(X1,Y,Z1),
    Z is Y + Z1.

start:-
writef("Enter 2 numbers which you want to multiply: \n"),nl,
writef("Enter first number: \n"),
read(Input_1),nl,
writef("Enter second number: \n"),
read(Input_2),nl,
multi(Input_1,Input_2,Z),nl,
writef("The resultant is: %t",[Z]).
