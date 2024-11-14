sign1 x = if x>0 then 
            1 
          else
            if x==0 then
                0
            else
                -1

sign2 x | x>0 = 1
        | x==0 = 0
        | x<0 = -1

sign3 x = case compare x 0 of
            EQ -> 0
            GT -> 1
            _ -> -1

sign4 x = case x>0 of
            True -> 1
            False -> case x==0 of
                        True -> 0
                        False -> -1

sign5 x = case x==0 of
            True -> 0
            False -> x/abs x

sign6 x = case x==0 of
            True -> 0
            False -> x `div` abs x
