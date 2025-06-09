#lang scheme

(define (secuencia-rotacional fs inicio xs)
  ;; Helper function to rotate a list one position left
  (define (rotate-left lst)
    (if (or (null? lst) (null? (cdr lst)))
        lst  ;; If empty or single element list, no change needed
        (append (cdr lst) (list (car lst)))))
  
  ;; Helper function for the recursive processing
  (define (process acc result current-fs remaining-xs)
    (if (null? remaining-xs)
        ;; Base case: no more inputs, return collected results
        result
        (let* (;; First rotate the functions list
               (rotated-fs (rotate-left current-fs))
               ;; Get the first function (after rotation)
               (current-f (car rotated-fs))
               ;; Apply function to accumulator and current input
               (new-acc (current-f acc (car remaining-xs)))
               ;; Add new accumulator value to results list
               (new-result (append result (list new-acc))))
          ;; Continue processing with updated values
          (process new-acc new-result rotated-fs (cdr remaining-xs)))))
  
  ;; Start the process with initial values
  (if (or (null? xs) (null? fs))
      '() ;; Handle empty inputs or functions
      (process inicio '() fs xs)))

;; 1. Suma acumulativa de porciones
(secuencia-rotacional
(list (lambda (ac x) (+ ac x)))
0
'(1 2 3 4)) ;; => (1 3 6 10)
;; 2. Multiplicacion acumulativa (prefijo de producto)
(secuencia-rotacional
(list (lambda (ac x) (* ac x)))
1
'(2 3 4)) ;; => (2 6 24)

;; 3. Construcción de etiqueta para cada paso
(secuencia-rotacional
(list (lambda (ac x) (string-append ac x "-")))
""
'("pan" "queso" "tomate")) ;; => ("pan-" "pan-queso-" "pan-queso-tomate-")