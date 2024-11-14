mul(X,Y,W) :- X>1, X1 is X-1, mul(X1,Y,W1), W is W1+Y, write(W).
mul(1,Y,W) :- W is Y.
mul(0,_,W) :- W is 0.
