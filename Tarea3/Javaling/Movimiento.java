package Javaling;


public class Movimiento {
    private String nombre;
    private int potencia;
    private int precision;
    private Tipo tipo;
    private boolean esEstado;

    public Movimiento(String nombre, int potencia, int precision, Tipo tipo, boolean esEstado) {
        this.nombre = nombre;
        this.potencia = potencia;
        this.precision = precision;
        this.tipo = tipo;
        this.esEstado = esEstado;
    }
    
    public String getNombre() {
        return nombre;
    }
    
    public int getPotencia() {
        return potencia;
    }
    
    public int getPrecision() {
        return precision;
    }
    
    public Tipo getTipo() {
        return tipo;
    }
    
    public boolean esEstado() {
        return esEstado;
    }
}