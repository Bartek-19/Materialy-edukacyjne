from random import *
from math import *

print('Kamien, papier, nozyce\n')
print('papier - 0, nożyce - 1, kamień - 2\n')
player = int(input('(player) podaj liczbe od 0 do 2: '))
losowa = randint(0, 2)

if player == 1 and losowa == 0 or player == 2 and losowa == 1 or player == 0 and losowa == 2:
    print('Wygrywasz!', end=' ')

elif player == losowa:
    print('Remis!', end=' ')

elif player < 0 or player > 2:
    print('Blad!', end=' ')

else:
    print('Komputer wygrywa!', end=' ')