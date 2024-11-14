silnia(X, W) :- X>1, X1 is X-1, silnia(X1, W1), W is X*W1.
silnia(1, 1).
silnia(0, 1).
