n = -1
while n<=0:
    n = int(input("Podaj ilosc wezlow:  "))

wezly = [0]*n
w_czastkowe = [[0]*n]*n

for i in range(0, n):
    wezly[i] = int(input("x["+str(i)+"]:  "))

for i in range(0, n):
    for j in range(i+1, n):
        if wezly[i] == wezly[j]:
            print("Wezly nie sa parami rozne")
            exit(1)

for i in range(0, n):
    w_czastkowe[i][0] = int(input("y["+str(i)+"]:  "))

p = float(input("p:  "))

Xmin = min(wezly)
Xmax = max(wezly)

if p<Xmin or p>Xmax:
    print("Punkt p znajduje sie poza zakresem ["+str(Xmin)+";"+str(Xmax)+"]")
    exit(1)

k = 1
while k < n:
    j = 0
    while j < n-k:
        w_czastkowe[j][k] = ((p-wezly[j])*w_czastkowe[j+1][k-1] - (p-wezly[j+k])*w_czastkowe[j][k-1])/(wezly[j+k]-wezly[j])
        j+=1
    k+=1

print(w_czastkowe)
#wynik = w_czastkowe[0][n-1]
#print(wynik)
