n = int(input('Podaj dlugosc tablicy: '))
tab = [0]*n

i = 0
while i < n:
    tab[i] = int(input('Podaj kolejna liczbe: '))
    i += 1

for element in tab:
    if element % 2 == 1:
        print(element)
