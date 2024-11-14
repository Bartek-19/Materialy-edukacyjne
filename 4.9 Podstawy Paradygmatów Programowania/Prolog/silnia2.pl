silnia(N, W) :- silnia(1, 1, N, W).
silnia(1, 1, 0, W) :- silnia(1, 1, 1, W), !.
silnia(N, W, N, W) :- !.
silnia(N1, W1, N, W) :- N2 is N1+1, W2 is W1*N2, silnia(N2, W2, N, W).
