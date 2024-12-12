-- Proyecto 1 - Laboratorio
-- Nombre : Tomás Belén ; DNI: 45080754

-- Ejercicios 1)

esCero :: Int -> Bool  -- 1.a) 
esCero x |x == 0 = True
         |otherwise = False
         
-- Ejemplos: 
-- ghci> esCero 0
-- True
-- ghci> esCero 5
-- False


esPositivo :: Int -> Bool -- 1.b) esPositivo
esPositivo x |x > 0 = True
             |otherwise = False
-- Ejemplos: 
-- ghci> esPositvo 5
-- True
-- ghci> esPositvo (-1)
-- False


esVocal :: Char -> Bool -- 1.c) 
esVocal c | c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u' = True
          | otherwise = False

-- Ejemplos: 
-- ghci> esVocal a
-- True
-- ghci> esVocal A
-- False


valorAbsoluto :: Int -> Int -- 1.d) 
valorAbsoluto x | x >= 0 = x
                | otherwise = -x

-- Ejemplos: 
-- ghci> valorAbsoluto 5
-- 5
-- ghci> valorAbsoluto (-5)
-- 5



-- Ejercicios 2)

paratodo :: [Bool] -> Bool -- 2.a) 
paratodo [] = True
paratodo (x:xs) = x && paratodo xs

-- Ejemplos: 
-- ghci> paratodo [True,True.True]
-- True
-- ghci> paratodo [True,True.False]
-- False


sumatoria :: [Int] -> Int -- 2.b) 
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

-- Ejemplos: 
-- ghci> sumatoria [1,2,3,4]
-- 10
-- ghci> sumatoria [1,7,3,5]
-- 16


productoria :: [Int] -> Int -- 2.c) 
productoria [] = 1
productoria (x:xs) = x * productoria xs

-- Ejemplos: 
-- ghci> productoria [3,5,7]
-- 105
-- ghci> productoria [2,8,6]
-- 96


factorial :: Int -> Int -- 2.d) 
factorial 0 = 1
factorial n = n * factorial (n-1)

-- Ejemplos: 
-- ghci> factorial 3
-- 6
-- ghci> factorial 6
-- 720


promedio :: [Int] -> Int -- 2.e) 
promedio [] = 0
promedio (x:xs) = div (sumatoria (x:xs)) (length (x:xs))

-- Ejemplos: 
-- ghci> promedio [2,4]
-- 3
-- ghci> promedio [3,8,9]
-- 6



-- Ejercicio 3)

pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) | n == x = True
                   | n /= x = pertenece n xs

-- Ejemplos: 
-- ghci> pertenece 4 [2,4,6]
-- True
-- pertenece 5 [55,6,9]
-- False



 -- Ejercicios 4)

paraTodo' :: [a] -> (a -> Bool) -> Bool -- 4.a) 
paraTodo' [] r = True
paraTodo' (x:xs) r = r x && paraTodo' xs r

-- Ejemplos:
-- ghci> paraTodo' [0,0,1] esCero
-- False
-- ghci> paraTodo' [0,0] esCero
-- True


existe' :: [a] -> (a -> Bool) -> Bool -- 4.b)
existe' [] r = False
existe' (x:xs) r = r x || existe' xs r

-- Ejemplos: 
-- ghci> existe' [0,0,1] esCero
-- True
-- ghci> existe' [5,1,1] esCero
-- False


sumatoria' :: [a] -> (a -> Int) -> Int -- 4.c)
sumatoria' [] r = 0
sumatoria' (x:xs) r = (r x) + sumatoria' xs r

-- Ejemplos:
-- ghci> sumatoria' [5,7,(-3),3] sumaCuadrados
-- 126
-- ghci> sumatoria' [7,9,0,1] sumaCuadrados
-- 295


productoria' :: [a] -> (a -> Int) -> Int -- 4.d)
productoria' [] r = 1
productoria' (x:xs) r = (r x) * productoria' xs r

-- ghci> productoria' [5,7,3] sumaCuadrados
-- 13650
-- ghci> productoria' [7,9,2] sumaCuadrados
-- 18564



 -- Ejercicio 5)

paraTodo'' :: [Bool] -> Bool
paraTodo'' xs = paraTodo' xs (==True) -- o id es equiv

-- Ejemplos:
-- ghci> paraTodo'' [True,True,False]
-- False
-- ghci> paraTodo'' [True,True,True]
-- True



 -- Ejercicios 6)

todosPares :: [Int] -> Bool -- 6.a)
todosPares xs = paraTodo' xs even

-- Ejemplos: 
-- ghci> todosPares [2,4,6]
-- True
-- ghci> todosPares [2,8,16,22,5]
-- False


hayMultiplo :: Int -> [Int] -> Bool -- 6.b)
hayMultiplo n xs = existe' xs (esMultiplo n)

esMultiplo :: Int -> Int -> Bool -- Funcion auxiliar de b)
esMultiplo a b = mod b a == 0

-- Ejemplos: 
-- ghci> hayMultiplo 3 [2,5,9]
-- True
-- ghci> hayMultiplo 9 [2,5,3]
-- False


sumaCuadrados :: Int -> Int -- 6.c)
sumaCuadrados n = sumatoria' [0..n-1] (^2)

-- Ejemplos: 
-- ghci> sumaCuadrados 7
-- 91
-- ghci> sumaCuadrados 10
-- 285


existeDivisor :: Int -> [Int] -> Bool -- 6.d)
existeDivisor n ls = existe' ls (esDivisor n)

esDivisor :: Int -> Int -> Bool -- Funcion auxiliar de d)
esDivisor n x = n `mod` x == 0

-- Ejemplos: 
-- ghci> existeDivisor 25 [5,7,8]
-- True
-- ghci> existeDivisor 16 [3,7,9]
-- False


esPrimo:: Int -> Bool -- 6.e)
esPrimo n = n > 1 && not (existeDivisor n [2 .. n-1])

-- Ejemplos: 
-- ghci> esPrimo 7
-- True
-- ghci> esPrimo 22
-- False


fact' :: Int -> Int -- 6.f)
fact' n = productoria' [1 .. n] id

-- Ejemplos: 
-- ghci> fact' 3
-- 6
-- ghci> fact' 6
-- 720


multiplicaPrimos :: [Int] -> Int -- 6.g)
multiplicaPrimos xs = productoria' (filter esPrimo xs) id

-- Ejemplos: 
-- ghci> multiplicaPrimos [7,10,9,5,3]
-- 105
-- ghci> multiplicaPrimos [2,6,8,16]
-- 2


esFib :: Int -> Bool -- 6.h)
esFib x = pertenece x (map fib [0 .. x+1])

fib :: Int -> Int -- Funcion auxiliar de h)
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n - 2)

-- Ejemplos: 
-- ghci> esFib 5
-- True
-- ghci> esFib 7            
-- False


todosFib :: [Int] -> Bool -- 6.i)
todosFib xs = paraTodo' xs esFib

-- Ejemplos: 
-- ghci> todosFib [1,2,3,5]                 
-- True
-- ghci> todosFib [1,7,11,4]
-- False



-- Ejercicios 7)

--a)
-- La funcion map toma una funcion y le aplica a cada elemento de la lista la funcion y devuelve una lista nueva con la aplicacion de la funcion en el mismo orden.
-- La funcion filter toma una funcion que devuelve un valor booleano y esta tambien devuelve una nueva lista, pero con los elementos que cumplan con la condicion de la funcion.

-- b)
 -- La expresion map succ [1, -4, 6, 2, -8], equivale al numero succesor que aparece en la lista, esta con la funcion map devolvera una lista [2, -3, 7, 3 , .7]

-- c)
-- La expresion filter esPositivo [1, -4, 6, 2, -8], por el nombre de la funcion, supondremos que todos los valores mayor a 0 daran true, entonces con filter este nos dara una nueva lista que satisfaga a la funcion lo que seria [1,6,2]



-- Ejercicios 8)

dobleLista :: [Int] -> [Int] -- 8.a)
dobleLista [] = []
dobleLista (x:xs) = x * 2 : dobleLista xs

-- Ejemplos: 
-- ghci> dobleLista [2,4,8]
-- [4,8,16]
-- ghci> dobleLista [5,9,0] 
-- [10,18,0]


dobleLista' :: [Int] -> [Int] -- 8.b)
dobleLista' xs = map (*2) xs

-- Ejemplos: 
-- ghci>  dobleLista' [4,8,3]
-- [8,16,6]
-- ghci>dobleLista' [7,4,1]
-- [14,8,2]


-- Ejercicio 9)

primosLista :: [Int] -> [Int] -- 9.a)
primosLista [] = []
primosLista (x:xs) | esPrimo x = x : primosLista xs
                   | otherwise = primosLista xs

-- Ejemplos: 
-- ghci> primosLista [3,4,6,8,11]
-- [3,11]
-- ghci> primosLista [5,4,6,16,25]
-- [5]


primosLista' :: [Int] -> [Int] -- 9.b)
primosLista' xs = filter esPrimo xs

-- Ejemplos: 
-- ghci> primosLista' [7,4,6]      
-- [7]
-- ghci> primosLista' [7,9,11]
-- [7,11]


-- c) Yo creo que la forma que utilize anteriormente, es lo mas compacta posible, y actualmente no se me ocurre una forma de mejorar la funcion.



-- Ejericios 10)

primIgualesA :: (Eq a) => a -> [a] -> [a] -- 10.a)
primIgualesA n [] = []
primIgualesA n (x:xs) | n == x = x : primIgualesA n xs
                      | otherwise = []

-- Ejemplos: 
-- ghci> primIgualesA 3 [3,3,3,4,3]
-- [3,3,3]
-- ghci> primIgualesA 3 [2,3,3,4,3]
-- []


primIgualesA' :: (Eq a) => a -> [a] -> [a] -- 10.b)
primIgualesA' n xs = takeWhile (n==) xs

-- Ejemplos: 
-- ghci> primIgualesA' 5 [5,5,5,7,5]
-- [5,5,5]
-- ghci> primIgualesA' 5 [8,5,5,7,5]
-- []


-- Ejercicios 11)

primIguales :: Eq a => [a] -> [a] -- 11.a)
primIguales [] = []
primIguales [x] = [x]
primIguales (x:(y:xs)) | x == y = x : primIguales (y:xs)
                     | x /= y = [x]

-- Ejemplos: 
-- ghci> primIguales [8,5,5,7,5]
-- [8]                    
-- ghci> primIguales [8,8,8,7,5]
-- [8,8,8]


primIguales' :: Eq a => [a] -> [a] -- 11.b)
primIguales' (x:xs) = primIgualesA' x (x:xs)

-- Ejemplos: 
-- ghci> primIguales' [8,8,8,7,5]
-- [8,8,8]
-- primIguales' [6,7,85,4] 
-- [6]
