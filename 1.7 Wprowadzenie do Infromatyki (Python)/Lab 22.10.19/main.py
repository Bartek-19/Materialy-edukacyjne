from random import *

losowa = randint(1, 10)
gratrwa = True

while gratrwa:
    podana = int(input('Zgadnij liczbe od 1 do 10: '))

    if podana == losowa:
        print('Wygrales!')
        gratrwa = False
    elif podana < losowa:
        print('Podana liczba jest za mala')
    else:
        print('Podana liczba jest za duza')