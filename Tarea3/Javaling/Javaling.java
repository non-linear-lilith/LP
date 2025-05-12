package Javaling;


public abstract class Javaling {
    private String nombre;
    private int hpTotal;
    private int hpActual;
    private int nivel;
    private int tipo;
    private int ataque;
    private int defensa;
    private int velocidad;
    private Movimiento[] movimientos = new Movimiento[4];
    /**
     * Constructor de la clase Javaling
     * 
     * @param name Nombre del Javaling
     * @param vida Vida total del Javaling
     * @param nivel Nivel del Javaling
     * @param tipo Tipo del Javaling (0: fuego, 1: agua, 2: planta, 3: dragon)
     * @param ataque 
     * @param defensa
     * @param velocidad
     */
    public Javaling(String name, int vida, int nivel, int tipo, int ataque, int defensa, int velocidad) {
        this.nombre = name;
        this.hpTotal = vida;
        this.hpActual = vida;
        this.nivel = nivel;
        this.tipo = tipo;
        this.ataque = ataque;
        this.defensa = defensa;
        this.velocidad = velocidad;
    }

    public abstract int atacar(Javaling objetivo,int indiceMov);
    public abstract void subir_nivel(int nivel);
    
    public String getNombre() {
        return nombre;
    }

    public int getHpTotal() {
        return hpTotal;
    }

    public int getHpActual() {
        return hpActual;
    }

    public int getNivel() {
        return nivel;
    }

    public Tipo getTipo() {
        return Tipo.values()[tipo];
    }

    public int getAtaque() {
        return ataque;
    }

    public int getDefensa() {
        return defensa;
    }

    public int getVelocidad() {
        return velocidad;
    }
    public Movimiento[] getMovimientos() {
        return movimientos;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    public void setHpTotal(int hpTotal) {
        this.hpTotal = hpTotal;
    }
    public void setHpActual(int hpActual) {
        this.hpActual = hpActual;
    }
    public void setNivel(int nivel) {
        this.nivel = nivel;
    }
    public void setTipo(int tipo) {
        this.tipo = tipo;
    }
    public void setAtaque(int ataque) {
        this.ataque = ataque;
    }
    public void setDefensa(int defensa) {
        this.defensa = defensa;
    }
    public void setVelocidad(int velocidad) {
        this.velocidad = velocidad;
    }
    public void setMovimientos(Movimiento[] movimientos) {
        this.movimientos = movimientos;
    }
    public void setMovimiento(int indice, Movimiento movimiento) {
        if (indice >= 0 && indice < movimientos.length) {
            this.movimientos[indice] = movimiento;
        } else {
            System.out.println("Índice fuera de rango");
        }
    }
}