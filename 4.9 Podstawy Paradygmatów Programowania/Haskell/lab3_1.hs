delta a b c = b*b - 4*a*c

wynik a b c = 
    if delta a b c > 0 then 
        [x1, x2]
    else 
        if delta a b c == 0 then 
            [x]
        else
            error "Brak pierwiastkow"
    where x1 = (-sqrt (delta a b c) - b) / (2 * a) 
          x2 = (sqrt (delta a b c) - b) / (2 * a)
          x = (-b) / (2 * a)
