# def zwiekszanie():


def main():
    x = int(input('Podaj liczbe: '))
    n = 1
    temp = x
    while temp > 0:
        temp = temp//2
        n += 1
    tabx = []*n
    for i in range(0, n, 1):
        tabx[n - 2 - i] = x % 2
        x = x//2

    for i in range(0, n-1, 1):
        print(tabx[i])
