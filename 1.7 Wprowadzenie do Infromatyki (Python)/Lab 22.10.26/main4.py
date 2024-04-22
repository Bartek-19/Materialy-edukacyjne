ile_gier = int(input('Podaj liczbe kupionych gier: '))

if ile_gier > 0:
    suma = 0
    licznik = 0

    while licznik < ile_gier:
        cena = int(input('Podaj cene kolejenj gry: '))
        suma += cena

        licznik += 1

    srednia_cena = suma / ile_gier
    print('Srednia cena pojedynczej gry: ' + str(srednia_cena))