i = 1
n = 1
tab = [1]*n

while i != 0:
    tab[i] = int(input('Podaj element: '))
    i += 1
    n += 1

for i in tab:
    if tab%2 == 0:
        print('Ilosc elementow w tablicy jest symetryczna wzgledem srodka')
    else:
        print('Ilosc elementow w tablicy nie jest symetryczna wzgledem srodka')
