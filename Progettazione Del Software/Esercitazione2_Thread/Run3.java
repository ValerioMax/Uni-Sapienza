import javax.swing.JButton;

public class Run3 implements Runnable {

	Thread t2;
	JButton scarica;
	JButton interrompi;
	JButton attendi;
	
	Run3(Thread t2, JButton scarica, JButton interrompi, JButton attendi){
		this.t2 = t2;
		this.scarica = scarica;
		this.interrompi = interrompi;
		this.attendi = attendi;
	}
	
	@Override
	public void run() {
		while (t2.isAlive() && !t2.isInterrupted()) {
			 
		}
		scarica.setEnabled(true);
		interrompi.setEnabled(false);
		attendi.setEnabled(false);
	}

}
