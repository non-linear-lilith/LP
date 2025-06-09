#lang scheme
(define (factorial x acc)
    ;;(display "x: ") (display x) (display " | acc: ")
    ;;(display acc) (display "\n")
    (if (zero? x)
            acc
            (factorial (- x 1) (* x acc))))

(factorial 1000 1) ; => 