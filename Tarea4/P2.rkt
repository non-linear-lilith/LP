#lang scheme


(define (mezclador-gourmet-simple f inicio ls)
	(cond
		[(null? ls) inicio ] ;;condición de cierre
		[else (f (car ls) (mezclador-gourmet-simple f inicio (cdr ls)) )] ))

;;con colas
(define mezclador-gourmet-cola
  (lambda (f inicio ls)
	(define (aux acc rest)
	  (cond
		[(null? rest) acc] ;; condición de cierre
		[else (aux (f acc (car rest)) (cdr rest))])) ;; recursión de cola
	(aux inicio ls)))



(mezclador-gourmet-simple + 0 '(8000 12000 15000))
(mezclador-gourmet-cola + 0 '(8000 12000 15000))
(mezclador-gourmet-simple * 1 '(2 3 4))
(mezclador-gourmet-cola * 1 '(2 3 4))

;; torre de sandwich version simple y de cola
(mezclador-gourmet-simple
	(lambda ( ing pila) (cons ing pila))
	'()
	'(pan lechuga tomate queso))

(mezclador-gourmet-cola
	(lambda (pila ing) (cons ing pila))
	'()
	'(pan lechuga tomate queso))