pow(X, 0, 1).
pow(X, 1, X).
pow(X, Y, Z):- M is Y - 1, pow(X, M, A), Z is X * A.