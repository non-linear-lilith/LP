package Javaling;

public class Objeto{
    private boolean esCurativo;
    private int cantidad;
    public Objeto(boolean esCurativo, int cantidad){
        this.esCurativo = esCurativo;
        this.cantidad = cantidad;
    }
    public boolean isEsCurativo() {
        return esCurativo;
    }
    public void setEsCurativo(boolean esCurativo) {
        this.esCurativo = esCurativo;
    }
    public int getCantidad() {
        return cantidad;
    }
    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

}