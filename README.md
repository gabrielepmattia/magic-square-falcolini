# Magic Square
*Ansi C implementation of magic square game by C. Falcolini*

This is a tiny implementation of the magic square game by C. Falcolini. 

>The aim of the game is to fill a 10x10 square table with consecutive numbers from 1 to 100 starting from any box with the number 1 and proceeding to the next empty box jumping two squares horizontally or vertically, or one square diagonally (i.e. switching to any unitary box with 3 or 2√2 distance between their centers).
>After a number of moves the game can end if the box where he wrote the last number you can not jump, with the assigned rule to any other empty box.
 The number of occupied cells, and then the last number that has managed to enter, give your score: the game is to get the highest score, 100, that is, fill in the given rule all the cells.
 
The software tries to reach the highest score, nxn.
 
## Complexity
The problem is NP-complete i.e. of an algorithmic complexity that grows enormously as the number of the elements.

In particular, the solution found for a very large N, in case it is cyclic as for the case N = 10, would not be achieved with a general algorithm with no one of existing computer.

### Notes
Further readings:
 - [Quadrato magico 10x10](http://www.mat.uniroma3.it/users/falco/pls/ret10x10.doc) in *Italian*