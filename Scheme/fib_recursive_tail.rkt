#lang scheme
(define fibonacci
(lambda (n)
(if (= n 0)
0
(let fib ([i n] [a1 1] [a2 0])
(if (= i 1)
a1
(fib (- i 1) (+ a1 a2) a1))))))
