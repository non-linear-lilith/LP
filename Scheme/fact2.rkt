#lang scheme

(define factorial
    (lambda (n)
    (let fact ([i n] [a 1])
        (display "Calculating the factorial of ") (display n) (display "\n") (display (/ i n)) (display "%") (display "cls")
        (if (= i 0)
            a
            (fact (- i 1) (* a i))))))

(define filename "resultados.txt")
(define out (open-output-file filename #:exists 'replace))
(write (factorial 1000) out)
(close-output-port out)