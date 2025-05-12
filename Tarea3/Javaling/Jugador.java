package Javaling;

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Jugador implements Batalla{
    private String Nombre;
    private List<Objeto> bolsa = new ArrayList<Objeto>(); 
    private Javaling[] equipo = new Javaling[6];
    //private Piso pisoactual;
    /**
     * Constructor de la clase Jugador
     * @param nombre Nombre del jugador
     *
     */
    public Jugador(String nombre){
        this.Nombre = nombre;
        //this.pisoactual = new Piso();
    }
    public String getNombre(){
        return Nombre;
    }
    public void setNombre(String nombre){
        this.Nombre = nombre;
    }
    public Javaling[] getEquipo(){
        return equipo;
    }
    public void setEquipo(Javaling[] equipo){
        this.equipo = equipo;
    }

    public List<Objeto> getBolsa(){
        return bolsa;
    }
    public void setBolsa(List<Objeto> bolsa){
        this.bolsa = bolsa;
    }
    public void agregarObjeto(Objeto objeto){
        this.bolsa.add(objeto);
    }
    public void eliminarObjeto(Objeto objeto){
        this.bolsa.remove(objeto);
    }
    public void usarObjeto(Objeto objeto){
        
    }
    public void elegirJavalingActivo(){
        System.out.println("Elige un javaling activo");
        for(int i = 0; i < equipo.length; i++){
            if(equipo[i] == null){
                System.out.println("No tienes javaling en la posicion " + (i + 1));
                break;
            }
            System.out.println(i + 1 + ". " + equipo[i].getNombre());
        }
        int opcion = 0;
        Scanner scanner = new Scanner(System.in);
        while(opcion < 1 || opcion > equipo.length){
            System.out.print("Selecciona un javaling: ");
            try {
                opcion = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Por favor, ingresa un número válido.");
            }
        }
        if(equipo[opcion - 1] != null){
            System.out.println("Has elegido a " + equipo[opcion - 1].getNombre());
        }
        scanner.close();
    }
}