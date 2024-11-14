ostatni([X],X).
ostatni([H|T],X) :- ostatni(T,X).
