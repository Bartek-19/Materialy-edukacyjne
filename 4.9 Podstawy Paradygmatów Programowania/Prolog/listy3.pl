czyLista([]).
czyLista([_|T]) :- write(T),czyLista(T).
