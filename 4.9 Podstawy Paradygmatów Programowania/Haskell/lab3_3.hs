delta a b c = b*b - 4*a*c

x1 a b c = (-sqrt (delta a b c) - b) / (2 * a) 

x2 a b c = (sqrt (delta a b c) - b) / (2 * a)

x a b = (-b) / (2 * a)

wynik a b c
    | delta a b c > 0 = [x1(a b c), x2(a b c)]
    | delta a b c == 0 = [x(a b)]
    | otherwise error "Brak pierwiastkow"
