gold(S,W) :- S>0, S1 is S-1, fib(S,W1), fib(S1,W2), W is W1/W2.
fib(N,X) :- fib(0,0,1,N,X).
fib(N,X,_,N,X):-!.
fib(N1,X1,X2,N,X) :- N2 is N1+1, X3 is X1+X2, fib(N2,X2,X3,N,X).
