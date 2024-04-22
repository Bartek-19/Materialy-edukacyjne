n = int(input('Podaj ilosc elementow: '))
tablica = [0]*n

i = 0
while i < n:
    tablica[i] = int(input('Podaj element: '))
    i += 1

max = None
min = None

for element in tablica:
    if min == None or min > element:
        min = element

    if max == None or max < element:
        max = element

print("Najmnijesza liczba to:", min)
print("Najwieksza liczba to:", max)
