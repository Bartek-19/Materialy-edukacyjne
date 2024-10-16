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

p = float(input("Podaj punkt X:  "))
if p<wezly[0] or p>wezly[n-1]:
    print("Punkt X nie należy do zakresu < "+str(wezly[0])+" ; "+str(wezly[n-1])+" >")
    exit(1)

IR = [0]*n

for i in range(0, n, 1):
    IR[i] = wartosci[i]

k = 1
for k in range(1, n, 1):
    i = n-1
    while i>=k:
        IR[i] = (IR[i]-IR[i-1])/(wezly[i]-wezly[i-k])
        i-=1

wynik = 0

for i in range(0, n, 1):
    temp = IR[i]
    k = 0
    while k<=i-1:
        temp *= p-wezly[k]
        k+=1
    wynik+=temp

print("Wynik interpolacji Newtona: " + str(wynik))
