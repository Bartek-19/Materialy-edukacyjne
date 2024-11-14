mul1 x y | x==0 || y==0 = 0
         | x>0 && y>0 = x + mul1 x (y-1)
         | x>0 && y<0 = -x + mul1 x (y+1)
         | x<0 && y>0 = x + mul1 x (y-1)
         | x<0 && y<0 = -x + mul1 x (y+1)
