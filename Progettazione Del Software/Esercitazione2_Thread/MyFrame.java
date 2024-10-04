import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;

//avrei anche potuto fare threadCheAspettaIlNextLine.join(10000) e questoThread.interrupt() in questo modo il mainThread avrebbe aspettato 10 secondi e se il messaggio è arrivato quel thread l'ha stampato altrimenti no, in ogni caso verrà interrotto dopo 10 sec

public class MyFrame extends JFrame implements ActionListener{
	
	JButton scarica;
	JButton interrompi;
	JButton visualizza;
	JButton attendi;
	
	Socket socket;
	PrintWriter write;
	Scanner read;
	Scanner scanner = new Scanner(System.in);
	
	MyThread t1;
	
	Run2 r2;
	Thread t2;
	
	Run3 r3;
	Thread t3;
	
	Run4 r4;
	Thread t4;
	
	String str;
	
	MyFrame(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new GridLayout(2,2, 20, 20));
		this.setSize(new Dimension(500, 500));
		
			scarica = new JButton("scarica");
			scarica.addActionListener(this);
			scarica.setEnabled(true);
			
			interrompi = new JButton("interrompi");
			interrompi.addActionListener(this);
			interrompi.setEnabled(false);
			
			visualizza = new JButton("visualizza");
			visualizza.addActionListener(this);
			visualizza.setEnabled(true);
			
			attendi = new JButton("attendi");
			attendi.addActionListener(this);
			attendi.setEnabled(false);
		
		this.add(scarica);
		this.add(interrompi);
		this.add(visualizza);
		this.add(attendi);
	
		
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			
			if (e.getSource() == scarica) {
				scarica.setEnabled(false);
				interrompi.setEnabled(true);
				
				attendi.setEnabled(true);
				
				//Si connette a Server, crea Scanner per l'inputStream, crea PrintWriter per l'outputStream
				//TODO aggiungere un if che crea il socket solo se non si è collegati perche cosi lo fa ogni volta
				socket = new Socket("127.0.0.1", 8080);
				System.out.println("Connesso!");
				
				read = new Scanner(socket.getInputStream());
				str = read.nextLine();
				
				write = new PrintWriter(socket.getOutputStream());
				//Prende da tastiera il numero da mandare a server
				System.out.println("Inserisci numero:");
				write.println(scanner.nextLine());
				write.flush();
				
				//creo thread che aspetta 10 sec e nel mentre t2  si mette in attesa del mesasggio
				t1 = new MyThread();
				t1.start(); //faccio partire il thread che inizia un timer da 10 sec
				
				r4 = new Run4();
				t4 = new Thread(r4);
				
				//creo thread che si mette in attesa della ricezione di RISPOSTA da server
				r2 = new Run2(read, t1, t4, socket, attendi, scarica, interrompi);
				t2 = new Thread(r2);
				t2.start();
			}
			
			if (e.getSource() == interrompi) {
				System.out.println("scaricamento interrotto" );
				System.out.println("Connessione Interrotta");
				
				t2.interrupt();
				
				socket.close();
				
				scarica.setEnabled(true);
				interrompi.setEnabled(false);
				attendi.setEnabled(false);
			}
			
			if (e.getSource() == attendi ) {
				attendi.setEnabled(false);
				t4.start();
			}
			
			if (e.getSource() == visualizza) {
				System.out.println("Al momento sono attivi " + Thread.activeCount() + " thread:");
				System.out.println("Main Thread: " + "ALIVE = " + Thread.currentThread().isAlive() + ", INTERRUPTED = " + Thread.currentThread().isInterrupted());
				if (t1 != null)
				System.out.println("t1: " + "ALIVE = " + t1.isAlive() + ", INTERRUPTED = " + t1.isInterrupted());
				if (t2 != null)
				System.out.println("t2: " + "ALIVE = " + t2.isAlive() + ", INTERRUPTED = " + t2.isInterrupted());
				if (t3 != null)
				System.out.println("t3: " + "ALIVE = " + t3.isAlive() + ", INTERRUPTED = " + t3.isInterrupted());
				if (t4 != null)
				System.out.println("t4: " + "ALIVE = " + t4.isAlive() + ", INTERRUPTED = " + t4.isInterrupted());
			}
			
		}
		catch(IOException e2){	
			System.out.println("error");
		}
	}
}

	
		

