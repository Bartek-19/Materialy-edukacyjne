ile([], 0).
ile([_|T], X) :- ile(T, X1), X is X1+1.
