
-- | getInt': Turns the string representation of numbers to a list of the same
--            numbers as Integers.
getInt' :: [String] -> [Integer]
getInt' (x:[]) = (read x :: Integer):[]
getInt' (x:xs) = (read x :: Integer):[] ++(getInt' xs)

-- | missing: Gets the missing number
--  Params: list(Input) -> i -> sum -> sumaux
missing :: [Integer] -> Integer -> Integer -> Integer ->Integer
missing _ 1 x y = x+1-y
missing (x:xs) i sum sumaux = missing xs (i-1) (sum+i) (sumaux+x)

-- | Solution to CSES "Missing Number" problem.
--  link: https://cses.fi/problemset/task/1083
main :: IO()
main = do
  s <- getLine
  let n = read s :: Integer
  s <- getLine
  let lista = getInt' (words s)
  let r = missing lista n 0 0
  putStrLn (show r)
