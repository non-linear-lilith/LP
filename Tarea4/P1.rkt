#lang scheme

(define (coincide? n ls)
    (cond
        [(null? ls) (= n 0)]
        [else (coincide? (- n 1) (cdr ls))]
))

(coincide? 3 '(pan ketchup lechuga))
(coincide? 0 '())
(coincide? 2 '(hamburguesa queso tomate))