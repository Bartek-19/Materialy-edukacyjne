n = -1

while n<=0:
    n = int(input("Podaj stopien wielomianu:  "))

p = int(input("Podaj punkt:  "))

n+=1
wspolczynniki = [[0]*n]*(n+1)

i=0
while i<n:
    wspolczynniki[0][i] = int(input("Podaj wspolczynnik "+str(n-i-1)+":  "))
    i+=1

i=0
while i<n:
    wspolczynniki[i+1][0] = wspolczynniki[i][0]
    i+=1

m = n
i = 1
while i<n+1:
    j=1
    while j<m:
        wspolczynniki[i][j] = wspolczynniki[i][j-1]*p + wspolczynniki[i-1][j]
        j+=1
    m-=1
    i+=1

print(wspolczynniki)

#Zrobić pentlę wyświetlającą tabelkę