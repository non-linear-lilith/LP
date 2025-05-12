package Javaling;

public class Piso{
    private boolean centroSansanito;
    private int decision;
    public int numPiso;
    public Piso(int numPiso){
        this.numPiso = numPiso;
        if(numPiso%10==0){
            this.centroSansanito = true;
        centroSansanito = true;
        }else{
            this.centroSansanito = false;
        }
        this.decision = 0; //default
    }
    int getDecision(){
        return decision;
    }
    void setDecision(int decision){
        this.decision = decision;
    }
    boolean isCentroSansanito(){
        return centroSansanito;
    }
    void setCentroSansanito(boolean centroSansanito){
        this.centroSansanito = centroSansanito;
    }
    public int getNumPiso() {
        return numPiso;
    }
    public void setNumPiso(int numPiso) {
        this.numPiso = numPiso;
    }
    public void curar(Jugador jugador){
        if(centroSansanito){
            System.out.println("El jugador " + jugador.getNombre() + " ha curado a Sansanito en el piso " + numPiso);
            for(int i =0;i<jugador.getBolsa().size();i++){
                if(jugador.getEquipo()[i]!=null){
                    jugador.getEquipo()[i].setHpActual(jugador.getEquipo()[i].getHpTotal());
                }
            }
        }else{
            System.out.println("No hay un centro de Sansanito en este piso.");
        }
    }

    public void ejecutarDecision(Jugador jugador){
        if(this.centroSansanito){
            curar(jugador);
            //funcion para regalar 2 objetos aleatorios
        }
        System.out.println("Seleccione que quiere hacer en este piso:");
        System.out.println("1. Captura");
        System.out.println("2. Pelea");
        System.out.println("3. Tomar objeto");


    }
}