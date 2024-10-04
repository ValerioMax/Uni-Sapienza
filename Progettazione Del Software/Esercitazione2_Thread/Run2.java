import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JButton;

public class Run2 implements Runnable{
	
	Scanner in;
	String str;
	
	Thread t1;
	Thread t4;
	Socket socket;
	JButton attendi;
	JButton scarica;
	JButton interrompi;
	
	Run2(Scanner in, Thread t1, Thread t4, Socket socket, JButton attendi, JButton scarica, JButton interrompi){
		this.in = in;
		this.t1 = t1;
		this.t4 = t4;
		this.socket = socket;
		this.attendi = attendi;
		this.scarica = scarica;
		this.interrompi = interrompi;
	}
	
	@Override
	public void run() {
		try {
			
			if (in.hasNextLine()) {
				str = in.nextLine();
				if (t1.isAlive() && !t4.isAlive()) //se la condizione si è risolta prima che t1 muoia (prima di 10 sec) allora entra qui
					System.out.println(str);
				
				else if ((t1.isAlive() && t4.isAlive()) || (!t1.isAlive() && t4.isAlive())) {
					System.out.println(str);
					t4.interrupt();
					//attendi.setEnabled(true);
				}
					
				else {
					System.out.println("timeout");
					System.out.println("Connessione Interrotta");
					socket.close();
				}
				
				scarica.setEnabled(true);
				attendi.setEnabled(false);
				interrompi.setEnabled(false);
			}
			
			
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
	}
		
}

