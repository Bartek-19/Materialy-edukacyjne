n = -1
while n<=0:
    n = int(input("Podaj ilosc wezlow:  "))

wezly = [0]*n
wartosci = [0]*n

for i in range(0, n, 1):
    wezly[i] = int(input("x["+str(i)+"]:  "))

for i in range(0, n-1, 1):
    if wezly[i] >= wezly[i+1]:
        print("Warunki interpolacji nie sa spelnione")
        exit(1)

for i in range(0, n, 1):
    wartosci[i] = int(input("y["+str(i)+"]:  "))

p = int(input("Podaj punkt X:  "))
if p<wezly[0] or p>wezly[n-1]:
    print("Punkt X nie należy do zakresu < "+str(wezly[0])+" ; "+str(wezly[n-1])+" >")
    exit(1)

wynik = 0

for i in range(0, n, 1):
    wielomian = 1
    for j in range(0, n, 1):
        if j!=i:
            wielomian *= ((p-wezly[j])/(wezly[i]-wezly[j]))
    wynik += wartosci[i]*wielomian

print("Wynik interpolacji dla punktu ", p, ":  ", wynik)