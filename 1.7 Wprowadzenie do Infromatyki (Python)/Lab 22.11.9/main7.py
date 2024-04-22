n = int(input('Podaj ilosc elementow: '))
tablica = [0]*n

i = 0
while i < n:
    tablica[i] = int(input('Podaj element: '))
    i += 1

a = int(input('Podaj wartosc minimalna: '))
b = int(input('Podaj wartosc aksymalna: '))

for element in tablica:
    if element in range(a, b):
        print(element)
    else:
        print('Brak elementow')
