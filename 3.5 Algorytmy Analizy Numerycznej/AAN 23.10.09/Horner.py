n = -1

while n<0:
    n = int(input("Podaj stopien wielomianu:  "))

p = int(input("Podaj punkt:  "))

n+=1
wspolczynnikiPocz = [0]*n
wspolczynniki = [0]*n

i=0
while i<n:
    wspolczynnikiPocz[i] = int(input("Podaj wspolczynnik "+str(n-i-1)+":  "))
    i+=1

i=1
wspolczynniki[0] = wspolczynnikiPocz[0]

while i<n:
    wspolczynniki[i] = wspolczynniki[i-1]*p + wspolczynnikiPocz[i]
    i+=1

print(wspolczynniki)

