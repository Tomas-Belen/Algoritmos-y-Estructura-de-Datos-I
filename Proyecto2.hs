-- Proyecto 2 - Laboratorio
-- Nombre: Belén Tomás - DNI: 45080754

-- EJERCICIO 1)

 --a) 

data Carrera = Matematica | Fisica | Computacion | Astronomia deriving (Eq,Show)

 --b)

titulo :: Carrera -> String

titulo Matematica = "Licenciatura en matematica"
titulo Fisica = " Licenciatura en fisica"
titulo Computacion = "Licenciatura en computacion"
titulo Astronomia = "Licenciatura en astronomia"

-- Ejemplos

-- ghci> titulo Matematica
-- "Licenciatura en matematica"
-- ghci> titulo Computacion
-- "Licenciatura en computacion"

-- c)

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Show, Ord, Bounded)

-- d)

cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

-- Ejemplo

-- ghci> cifradoAmericano Re
-- 'D'
-- ghci> cifradoAmericano Fa
-- 'F'

-- EJERCICIO 2)

 -- a) -- Para que puede comparar cual es mayor y menor tendria que usar Ord, pero para saber cual es el orden del menor a mayor tendria que usar Bounded

-- Ejemplo

-- ghci> Do > Sol
-- False
-- ghci> Sol `max` Fa
-- Sol

-- EJERCICIO 3)

 -- a)

minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)

-- Ejemplo 

-- ghci> minimoElemento ['a','b','f','r']
-- 'a'
-- ghci> minimoElemento [3333,56565,777, (-1)]
-- -1

 -- b)

minimoElemento' :: (Ord a , Bounded a) => [a] -> a
minimoElemento' [] = minBound
minimoElemento' [x] = x
minimoElemento' (x:xs) = min x (minimoElemento' xs)

-- Ejemplo

-- ghci> minimoElemento' ([1,2,3] :: [Int])
-- 1-- ghci> minimoElemento' ([] :: [Bool])    
-- False
-- ghci> minimoElemento' (['a','b','f','z'] :: [Char])
-- 'a'

-- c)

notaGrave :: [NotaBasica] -> NotaBasica
notaGrave xs = minimoElemento xs

-- Ejemplo

-- ghci> notaGrave [Fa, La, Sol, Re, Fa]
-- Re

-- EJERCICIO 4)

-- a)

type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera deriving (Eq,Show) -- para ej 4e
data TipoReves = DosManos | UnaMano deriving Show
data Modalidad = Carretera | Pista | Monte | BMX deriving Show
data PiernaHabil = Izquierda | Derecha deriving Show

type ManoHabil = PiernaHabil 

data Deportista = Ajedrecista 
 | Ciclista Modalidad
 | Velocista Altura
 | Tenista TipoReves ManoHabil Altura
 | Futbolista Zona NumCamiseta PiernaHabil Altura
 deriving Show

-- b)

-- Es del tipo Ciclista :: Modalidad -> Deportista

-- c)

contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista x):xs) = 1 + contar_velocistas xs
contar_velocistas (_:xs) = contar_velocistas xs

-- Ejemplo) 

-- ghci> contar_velocistas [Ajedrecista, Velocista 2, Tenista UnaMano Derecha 2]   
-- 1
-- ghci> contar_velocistas [Ajedrecista, Tenista UnaMano Derecha 176, Futbolista Arco 1 Derecha 198]
-- 0

-- d)

contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] zona = 0
contar_futbolistas (x:xs) zona = case x of
 Futbolista zona _ _ _  -> 1 + contar_futbolistas xs zona
 _ -> contar_futbolistas xs zona

-- Ejemplo

-- ghci> contar_futbolistas [Ajedrecista, Tenista UnaMano Derecha 176, Futbolista Arco 1 Derecha 198] Arco
-- 1
-- ghci> contar_futbolistas [Ajedrecista, Tenista UnaMano Derecha 176] Arco                                  
-- 0

-- e)

contar_futbolistas' :: [Deportista] -> Zona -> Int
contar_futbolistas' [] zona = 0
contar_futbolistas' xs zona = length (filter (siZona zona) xs)

siZona :: Zona -> Deportista -> Bool -- Funcion auxiliar de 4e
siZona z (Futbolista z' _ _ _) = z' == z
siZona _ _ = False

-- Ejemplos

-- ghci> contar_futbolistas' [Ajedrecista, Tenista UnaMano Derecha 176, Futbolista Arco 1 Derecha 198] Arco
-- 1
-- ghci> contar_futbolistas' [Ajedrecista, Tenista UnaMano Derecha 176, Futbolista Mediocampo 1 Derecha 198] Arco
-- 0

-- EJERCICIO 5)

--a)

sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

-- Ejemplo

-- ghci> sonidoNatural Do
-- 0
-- ghci> sonidoNatural Sol
-- 7

-- b)
 
data Alternacion = Bemol | Natural | Sostenido deriving (Eq)

-- c)

data NotaMusical = Nota NotaBasica Alternacion deriving (Eq)

-- d)

sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota n Bemol) = sonidoNatural n - 1
sonidoCromatico (Nota n Natural) = sonidoNatural n
sonidoCromatico (Nota n Sostenido) = sonidoNatural n + 1

-- Forma alternativa que tambien se me ocurrio pero menos eficiente y 

-- sonidoCromatico :: NotaMusical -> Int
-- sonidoCromatico (Nota n a) = (alternacion n a)

-- alternacion :: NotaBasica -> Alternacion -> Int -- Funcion auxiliar de 5d
-- alternacion y Sostenido = (sonidoNatural y + 1 )
-- alternacion y Bemol = (sonidoNatural y - 1)
-- alternacion y Natural = (sonidoNatural y)


-- Ejemplo

-- ghci> sonidoCromatico (Nota Do Natural)
-- 0
-- ghci> sonidoCromatico (Nota Sol Bemol)
-- 6
-- ghci> sonidoCromatico (Nota La Sostenido)
-- 10

 -- e) Incluı el tipo NotaMusical a la clase Eq de manera tal que dos notas que tengan el mismo valor de sonidoCromatico se consideren iguales.

--instance Eq NotaMusical where
--nota1 == nota2 = sonidoCromatico nota1 == sonidoCromatico nota2

 -- f)  Incluı el tipo NotaMusical a la clase Ord definiendo el operador <=. Se debe definirque una nota es menor o igual a otra si y s´olo si el valor de sonidoCromatico para la primera es menor o igual al valor de sonidoCromatico para la segunda

-- instance Ord NotaMusical where
-- nota1 <= nota2 = sondioCromatico nota1 <= sonidoCromatico nota2

-- EJERCICIO 6) 

 -- a)

primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just x

-- Ejemplo

-- ghci> primerElemento []
-- Nothing
-- ghci> primerElemento [1,2,3,4,5]
-- Just 1

-- EJERCICIO 7)
data Cola = VaciaC | Encolada Deportista Cola deriving (Show)

-- a)

--1a) 

atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada d c) = Just c 

-- Ejemplo

-- ghci> atender (Encolada Ajedrecista (Encolada (Ciclista BMX) (Encolada (Velocista 176) VaciaC)))
-- Just (Encolada (Ciclista BMX) (Encolada (Velocista 176) VaciaC))
-- ghci> atender VaciaC                            
-- Nothing

-- 2a) 

encolar :: Deportista -> Cola -> Cola
encolar d VaciaC = Encolada d VaciaC
encolar d (Encolada d' c) = Encolada d' (encolar d c) 

-- 3a)


busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC _ = Nothing
busca (Encolada d c) zona = case d of 
 Futbolista zona' _ _ _
  | zona' == zona -> Just d
  | otherwise -> busca c zona 
 _ -> busca c zona 

-- Ejemplo

-- ghci> busca (Encolada (Futbolista Arco 6 Derecha 7) (Encolada Ajedrecista VaciaC)) Arco
-- Just (Futbolista Arco 6 Derecha 7)
-- ghci> busca (Encolada (Futbolista Arco 6 Derecha 7) (Encolada Ajedrecista VaciaC)) Mediocampo
-- Nothing

-- 7b

-- Se parece demasiado al tipo lista

-- EJERCICIO 8)

data ListaAsoc a b = LVacia | Nodo a b ( ListaAsoc a b ) deriving (Show,Eq)

-- a)

-- Para representar esta forma deberia ser de la forma "type GuiaTelefono = ListaAsoc String Int"

-- b)

-- 1b) 
la_long :: ListaAsoc a b -> Int
la_long LVacia = 0
la_long (Nodo a b (li)) = 1 + la_long li

-- Ejemplo

-- ghci> la_long (Nodo 23 'a'(Nodo 44 'v' LVacia))
-- 2
-- ghci> la_long  LVacia                          
-- 0

-- 2b)
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat LVacia n = n
la_concat (Nodo a b (li)) li2 = (Nodo a b (la_concat li li2))

-- Ejemplo

-- ghci> la_concat (Nodo 23 'a'(Nodo 44 'v' LVacia)) (Nodo 43 'b' LVacia)
-- Nodo 23 'a' (Nodo 44 'v' (Nodo 43 'b' LVacia))
-- ghci> la_concat LVacia (Nodo 55 'n' LVacia )
-- Nodo 55 'n' LVacia

-- 3b)
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar LVacia y z = (Nodo y z LVacia)
la_agregar (Nodo a b (li)) y z = (Nodo a b (Nodo y z (li)))

-- Ejemplo
 
-- ghci> la_agregar (Nodo 3 'n' (Nodo 5 'm' LVacia)) 5 'l'
-- Nodo 3 'n' (Nodo 5 'l' (Nodo 5 'm' LVacia)) 

-- 4b)

la_pares :: ListaAsoc a b -> [(a, b)]
la_pares LVacia = []
la_pares (Nodo a b (li)) = (a,b) : la_pares li

-- Ejemplo 

-- ghci> la_pares (Nodo 777 'v'(Nodo 444 'h' LVacia))
-- [(777,'v'),(444,'h')]
-- ghci> la_pares (Nodo "doscientos" 200 (Nodo "diez" 10 LVacia)) 
-- [("doscientos",200),("diez",10)]

-- 5b)
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca LVacia _ = Nothing 
la_busca (Nodo a b (li)) c | (a == c) = Just b 
                           | otherwise = la_busca li c

-- Ejemplo 

-- ghci> la_busca (Nodo 2 'm' LVacia) 2
-- Just 'm'
-- ghci> la_busca (Nodo 33 'f' LVacia) 3
-- Nothing

-- 6b) 
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar _ LVacia = LVacia
la_borrar c (Nodo a b (li)) | (c == a) = li
                            | otherwise = Nodo a b (la_borrar c li)
                            
-- Ejemplo

-- ghci> la_borrar 2 (Nodo 1 'm' (Nodo 2 'n' LVacia))
-- Nodo 1 'm' LVacia                   

