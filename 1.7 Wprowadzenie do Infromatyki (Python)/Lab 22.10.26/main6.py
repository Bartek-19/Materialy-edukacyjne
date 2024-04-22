print('Papier, Kamien, Nozyce\n')
print('0 - papier, 1 - kamien, 2 - nozyce')
player1 = (0, 2)
player2 = (0, 2)

while player1 == player2 or 0 > player1 > 2 or 0 > player2 > 2:
    print('Gra od nowa.\n')
    player1 = int(input('(Gracz pierwszy) podaj liczbe od 0 do 2: '))
    player2 = int(input('(Gracz drugi) podaj liczbe od 0 do 2: '))

    if player1 == 0 and player2 == 1 or player1 == 1 and player2 == 2 or player1 == 2 and player2 == 0:
        print('Gracz pierwszy wygrywa!')

    elif player2 == 0 and player1 == 1 or player2 == 1 and player1 == 2 or player2 == 2 and player1 == 0:
        print('Gracz drugi wygrywa!')
