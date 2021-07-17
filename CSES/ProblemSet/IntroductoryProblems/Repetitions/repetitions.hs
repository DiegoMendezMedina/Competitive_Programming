-- | repetitions: Recursive function, solves the problem.  
-- String, aux, cont, max
repetitions :: [Char] -> Char -> Integer -> Integer -> Integer
repetitions (x:[]) c cont m
  | x == c && m==cont = m+1
  | otherwise = maxx
  where
    maxx
      | m > cont = m
      | otherwise = cont
repetitions (x:xs) c cont m
  | x == c = repetitions xs c cont2 m2
  | x /= c = repetitions xs x 1 m
  where 
    cont2 = cont + 1
    m2
      | m > cont2 = m
      | otherwise = cont2

-- | Solution to CSES "Repetitions" problem.
--   link: https://cses.fi/problemset/task/1069
main :: IO()
main = do
  s <- getLine
  let r = repetitions s (head s) 0 0
  print r
