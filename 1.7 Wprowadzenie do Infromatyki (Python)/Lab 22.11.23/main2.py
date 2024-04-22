def oblicz_srednia(n):
    i = 0
    suma = 0

    for i in range(0, n, 1):
        suma += tablica[i]

    srednia = suma/n

    return srednia


n = 5
i = 0
tablica = [0]*n

while i < n:
    element = int(input('Podaj ocene: '))
    if 2 <= element <= 5:
        tablica[i] = element
        i += 1
    else:
        print('Podano zla ocene!')
        break

if tablica[0] != 2 and tablica[1] != 2 and tablica[2] != 2 and tablica[3] != 2 and tablica[4] != 0:
    status = 'zaliczenie'
else:
    status = 'brak zaliczenia'

print('Lista ocen: ')
print(tablica)

print('Status: ' + str(status))

print('Srednia: ', oblicz_srednia(n))

srednia = oblicz_srednia(n)

tablica.append(srednia)

tablica.sort()

print(tablica)
