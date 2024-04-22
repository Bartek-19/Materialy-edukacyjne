def sumowanie(liczba):
    S = 0
    while liczba > 9:
        S += liczba % 10
        liczba = liczba // 10
    S += liczba
    return S


x = int(input("Podaj liczbe calkowita: "))

Suma = sumowanie(x)
while Suma >= 10:
    x = Suma
    Suma = sumowanie(x)

print("Koncowa suma cyfr = ", Suma)
