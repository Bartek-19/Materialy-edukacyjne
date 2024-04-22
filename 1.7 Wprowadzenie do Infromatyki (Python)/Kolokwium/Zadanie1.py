print("Wykonaj tablice z jednym elementem wyrozniajacym sie od reszty (min. 4 elementy)\n")
n = int(input("Podaj ilosc elementow tablicy: "))
tab = [0]*n

if n <= 3:
    print("Za mala ilosc elementow")
else:
    i = 0
    while i < n:
        tab[i] = int(input("Podaj element: "))
        i += 1

    for x in range(0, n):
        element = tab[x]
        ilosc = tab.count(element)
        if ilosc == 1:
            wyjatek = tab.index(element)
            print("Podana liczba to " + str(element) + ", jej indeks to " + str(wyjatek))
