fun1 x = 
    sum [ 1 | _  <- x]

fun2:: String -> Int
fun2 x = 
    sum [ 1 | a  <- x, b <- ['A' .. 'Z'], a == b]


rm1 xs = [x | x <- xs, x `elem` ['a'..'z']]


