package src;
import Javaling.*;

public class Main {
    public static void main(String[] args) {
        // Initialize your application
        System.out.println("Starting application...");
        Javaling test_javaling = new Javaling("Pikachu",60,1,1,1,1,1) {
            @Override
            public int atacar(Javaling objetivo, int indiceMov) {
                return 0;
            }
            
            @Override
            public void subir_nivel(int nivel) {
                // Implement the method
            }
        };
        // Your program logic goes here
        System.out.println("Javaling created: " + test_javaling.getNombre());
        System.out.println("HP Total: " + test_javaling.getHpTotal());
        System.out.println("HP Actual: " + test_javaling.getHpActual());
        System.out.println("Nivel: " + test_javaling.getNivel());
        System.out.println("Tipo: " + test_javaling.getTipo());
        test_javaling.setHpActual(50);
        System.out.println("HP Actual after setting: " + test_javaling.getHpActual());
        System.out.println("Application finished.");
    }
}