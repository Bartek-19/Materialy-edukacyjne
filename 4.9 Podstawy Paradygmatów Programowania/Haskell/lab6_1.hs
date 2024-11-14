kw1 = [x*x | x<-[1..20]]

kw2 = map (^2) [x | x<-[1..20]]

kw3 = map (\y -> y*y) [x | x<-[1..20]]

list1 = last [x | x <- [1..1000000], mod x 3829 == 0]

list2 = head [x | x <- [1000000,999999..], mod x 3829 == 0]

sum1 = sum [1 | x <- [1..10000], odd (x*x)]

silnia1 0 = 1
silnia1 x = x*silnia1(x-1)

silnia2 x | x==0 = 1
          | mod x 2 == 0 = x*(x-1)*silnia2(x-2)
          | mod x 2 == 1 = error "liczba nieparzysta"

silnia3 x | x==0 = 1
          | even x = x*(x-1)*silnia2(x-2)
          | odd x = error "liczba nieparzysta"

silnia4 = [silnia3 x | x<-[2,4..20]]
