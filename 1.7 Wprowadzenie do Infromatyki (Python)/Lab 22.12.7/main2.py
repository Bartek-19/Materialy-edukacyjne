n = int(input('Podaj ilosc kolejnych liczb naturalnych: '))
liczby = [1]*n
liczby[0] = 1
i = 1

while i < n:
    liczby[i] = liczby[i-1] + 1
    i += 1

print(liczby)

for x in range(n-1, 0, -1):
    IloscDziel = 0
    i = 0
    while i <= x:
        if liczby[x] % liczby[i] == 0:
            IloscDziel += 1
        i += 1
    if IloscDziel > 2:
        liczby.pop(x)

print('liczby po przesortowaniu:  ')
print(liczby)
