czyLista([]).
czyLista([_|T]) :- czyLista(T),write(T).
