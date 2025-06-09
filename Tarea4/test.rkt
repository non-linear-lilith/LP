#lang scheme

(define (inverter-cola f inicio ls)
  (define (aux f inicio ls)
    (cond
      [(null? ls) inicio] ;; condición de cierre
      [else (aux f (f (car ls) inicio) (cdr ls))])) ;; recursión
  (aux f inicio ls))

  (display (inverter-cola + 0 '(8000 12000 15000)))