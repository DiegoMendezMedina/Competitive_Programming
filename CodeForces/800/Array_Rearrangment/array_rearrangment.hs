module Main where

quickSort :: (Ord a) -> [a] -> [a]
quickSort [] = []
quickSort (x:xs) = masPequenos ++ [x] ++ masGrandes
  where
    masPequenos = [y | y <- xs, y < x]
    masGrandes  = [y | y <- xs, y >= x]

  
