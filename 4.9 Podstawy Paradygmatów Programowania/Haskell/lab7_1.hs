dzielniki x = [ a | a <- [1..x], mod x a == 0]

czyLustrzana xs = xs == reverse xs

faktoryzacja x = [ (b, c) | b <- dzielniki x, c <- dzielniki x, b*c == x ]

pierwsze = take 100 [ a | a <- [1..], faktoryzacja a == [(1,a),(a,1)]]

czworacze = [ (a,b,c,d) | a <- pierwsze, b <- pierwsze, c <- pierwsze, d <- pierwsze, b==a+2, c==a+6, d==a+8]
