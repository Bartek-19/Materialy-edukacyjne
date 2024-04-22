n = 0
suma = 0
pobrana = 10

while 10 <= pobrana <= 50:
    pobrana = int(input('Podaj liczbe od 10 do 50: '))

    if 10 <= pobrana <= 50:
        n += 1
        k = pobrana * pobrana
        suma += k

print('koniec programu')
print('Podano liczb: ' + str(n))
print('Suma ich kwadratow wynosi: ' + str(suma))
