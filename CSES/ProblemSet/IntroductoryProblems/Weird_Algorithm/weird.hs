
weird :: Integer -> [Integer]
weird 1 = 1:[]
weird x 
  | x `mod`2 == 0 = x:[] ++ weird(x `div` 2)
  | otherwise = x:[] ++ weird((3*x)+1)

output :: [Char] -> String
output "]" = []
output (x:xs)
  | x == '[' = output(xs)
  | x == ',' = " " ++ output(xs)
  | otherwise = x:[] ++ output(xs)
  
main :: IO()
main = do
  s <- getLine
  let n = read s :: Integer
  let l = weird(n)
  let s = show(l)
  putStrLn (output(s))
  
