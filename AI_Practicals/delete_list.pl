del(Y,[Y],[]).
del(X,[X|List1],List1).
del(X,[Y|List],[Y|List1]):- del(X,List,List1).