def mnozenie(a1, a2):

    wynik_mnozenia = float(a1 * a2)

    print('Wynik mnozenia = ' + str(wynik_mnozenia))

def dzielenie(b1, b2):

    if b2 != 0:
        wynik_dzielenia = float(b1 / b2)
        print('Wynik dizelenia = ' + str(wynik_dzielenia))

    else:
        print('Zla dziela! (Zero)')

def potegowanie(c1, c2):

    wynik_potegowania = float(c1 ** c2)

    print('Wynik potegowania = ' +str(wynik_potegowania))

print('Menu: \n 1.Mnozenie \n 2.Dzielenie \n 3.Potegowanie \n 0. Wyjscie z menu \n')

wybor = 1
while wybor != 0:
    wybor = int(input('Podaj numer z menu: '))

    if wybor == 1:
        a1 = float(input('Podaj pierwszy czynnik iloczynu: '))
        a2 = float(input('Podaj drugi czynnik iloczynu: '))

        mnozenie(a1, a2)

    elif wybor == 2:
        b1 = float(input('Podaj dzielna: '))
        b2 = float(input('Podaj dzielnik: '))

        dzielenie(b1, b2)

    elif wybor == 3:
        c1 = float(input('Podaj podstawe potegi: '))
        c2 = float(input('Podaj wykladnik potegi: '))

        potegowanie(c1, c2)

    else:
        print('Wybierz inny numer')