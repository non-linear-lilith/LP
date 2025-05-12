package Javaling;
/**
 * Clase Agua
 * Representa un tipo de Javaling de tipo agua
 * @see Javaling
 */
public class Agua extends Javaling {

	public Agua(String name, int vida, int nivel, int tipo, int ataque, int defensa, int velocidad) {
		super(name,vida,nivel,tipo,ataque,defensa,velocidad);
	}
	
	@Override
	public int atacar(Javaling objetivo, int indiceMov) {

		int daño = getAtaque() - objetivo.getDefensa();
		if (daño < 0) daño = 0;
		
		if (objetivo.getTipo() == Tipo.FUEGO) {
			daño *= 2;
		}
		
		if (daño >= objetivo.getHpActual()) {
			objetivo.setHpActual(0);
		} else {
			objetivo.setHpActual(objetivo.getHpActual() - daño);
		}
		
		return daño;
	}
	
	@Override
	public void subir_nivel(int cantidad) {
		// Implementation of the subir_nivel method
		setNivel(getNivel() + cantidad);
	}
}