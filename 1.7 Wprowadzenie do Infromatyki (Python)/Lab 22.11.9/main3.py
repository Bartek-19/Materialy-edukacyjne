n = int(input('Podaj dlugosc tablicy: '))
tab = [0]*n

i = 0
while i < n:
    tab[i] = float(input('Podaj kolejna liczbe: '))
    i += 1

print(tab)
