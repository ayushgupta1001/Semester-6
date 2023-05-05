gcd(X,0,X).
gcd(X,Y,R):- Z is mod(X,Y), gcd(Y,Z,R).