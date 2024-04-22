def posortuj_dane(rozbita_tablica):
    rozbita_tablica.sort()
    return rozbita_tablica


separator = '\n'

with open("wejscie.txt", "r") as plik_we:
    rozbita_tablica = plik_we.read().split(separator)
    tab = [int(x) for x in rozbita_tablica]

tab = posortuj_dane(tab)

with open('wynik.txt', 'w') as plik_wy:
    for x in tab:
        plik_wy.write(str(x) + separator)
