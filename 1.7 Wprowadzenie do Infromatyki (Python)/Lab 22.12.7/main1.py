n = int(input('Podaj liczbe elementow: '))
i = 0

tab = [0]*n

while i < n:
    tab[i] = int(input('Podaj element: '))
    i += 1

while n > 1:
    i = 0
    while i < n-1:
        if tab[i] > tab[i+1]:
            temp = tab[i]
            tab[i] = tab[i+1]
            tab[i+1] = temp
        i += 1
    n -= 1

print(tab)
