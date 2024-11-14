isMember(X,[Y|_]) :- X=Y.
isMember(X,[_|Y]) :- isMember(X,Y).
