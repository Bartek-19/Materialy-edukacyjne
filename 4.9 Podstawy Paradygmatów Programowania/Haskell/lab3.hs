volume1 r = a * pi * cube
    where
    a = 4 / 3
    cube = r ^ 3

volume2 r = a * pi * cube r
    where a = 4 / 3
          cube x = x ^ 3

volume3 r = let a = 4 / 3
                cube = r ^ 3
            in a * pi * cube
