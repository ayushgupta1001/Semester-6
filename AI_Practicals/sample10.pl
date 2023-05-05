start:- 
writef("Enter your name: \n"),
read(Input),nl,
writef("Your name is %t",[Input]).

designation('divyanshi',cr).
designation('ayush',student).

find_designation:-
writef("whose position\n"),
read(Input_1),nl,
designation(Input_1,Output),nl,
writef(Output).