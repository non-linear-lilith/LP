    #lang scheme 



;; busqueda-almacen: list symbol -> listof listof number
;; Finds all occurrences of a product in a warehouse tree structure
;; Returns paths as lists of indices, sorted by path length
(define (busqueda-almacen arbol producto)
  ;; Helper function to search through the structure
  (define (search-tree estructura camino)
    (cond
      [(null? estructura) '()]  ;; Empty structure, no matches
      [(not (list? estructura))  ;; It's a symbol, check if it matches
       (if (eq? estructura producto) (list camino) '())]
      [else
       ;; Get the room name and contents
       (let ((nombre-sala (car estructura))
             (contenido (cdr estructura)))
         ;; Process each item in the contents
         (let loop ((indice 1) (elementos contenido) (resultados '()))
           (if (null? elementos)
               resultados  ;; Return all found paths
               (let* ((elemento (car elementos))
                      (camino-actual (append camino (list indice)))
                      (resultados-elemento
                       (cond
                         ;; Direct match
                         [(eq? elemento producto) (list camino-actual)]
                         ;; Recursive search in sublists
                         [(list? elemento) (search-tree elemento camino-actual)]
                         [else '()])))
                 ;; Continue with rest of the list
                 (loop (+ indice 1)
                       (cdr elementos)
                       (append resultados resultados-elemento))))))]))
  
  ;; Start the search and sort the results by path length
  (sort (search-tree arbol '()) (lambda (a b) (< (length a) (length b)))))


  (define bodega
'(bodega
(pasillo1 leche pan)
(pasillo2 (estanteA pan queso) (estanteB manzana pan))
(pasillo3 fruta)))

;; 1. Buscar “pan”
(busqueda-almacen bodega 'pan) ;; => '((1 2) (2 1 1) (2 2 2))

;; 2. Buscar “queso”
(busqueda-almacen bodega 'queso) ;; => '((2 1 2))

;; 3. Buscar fruta
(busqueda-almacen bodega 'fruta) ;; => '((3 1))
