n = int(input('Podaj ilosc elementow: '))

tablica = [0]*n

i = 0

while i < n:
    tablica[i] = int(input('Podaj element: '))
    i += 1


def dodawanie_elementu():
    x = int(input('Podaj element, ktory chcesz dodac do tablicy: '))
    tablica.append(x)
    print(tablica)


def usuwanie_elementu(i):
    i = n-1
    tablica.pop(i)
    print(tablica)


def wynik(i):
    suma = 0
    i = 0
    for i in range(0, n):
        element = int(tablica[i])
        suma += element
        i += 1

    return suma


print('Opcje programu: \n')
print('1. Dodawanie elemnetu do tablicy. \n')
print('2. Usuwanie elementu z tablicy. \n')
print('3. Wynik tablicy (Suma elementow). \n')
print('0. Wyjscie z pogramu. \n')

wybor = None

while wybor != 0:
    wybor = int(input('Podaj co chcesz zrobic z tablica: '))

    if wybor == 1:
        dodawanie_elementu()

    elif wybor == 2:
        usuwanie_elementu(i)

    elif wybor == 3:
        print('Suma elementow: ' + str(wynik(i)))

    else:
        print('Podano zly wybor!')


print('*****  Koniec programu  *****')
