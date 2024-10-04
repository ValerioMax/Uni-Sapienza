import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class CarteClient {
	
	public static void main(String[] args) throws UnknownHostException, IOException {
		
		//Connessione a Server
		System.out.println("Sono Client");
		Socket socket = new Socket("localhost", 4400);
		System.out.println("Connessione a Server stabilita");
		
		//Client invia messaggio
		PrintWriter write = new PrintWriter(socket.getOutputStream());
		write.println("carte");
		write.flush();
		
		//Client riceve messaggio   //devo fare while read.hasNextInt() prendendo un pezzo per volta e controllando il contenuto mentre la si legge
									//oppure read.nextLine() tutta insieme e poi controllo il contenuto 
		Scanner read = new Scanner(socket.getInputStream());
		String str = read.nextLine();
		
		int i = 0;
		int[] vec = new int[5];
		while (i < 5) {
			vec[i] = str.charAt(i);
			i++;
		}
		System.out.println("Inserisci posizione degli interi da cambiare fra: " + str);
		Scanner scanner = new Scanner(System.in);
		String cambi = scanner.nextLine();
		
		//Client invia messaggio a Server
		PrintWriter write2 = new PrintWriter(socket.getOutputStream());
		write2.println("cambio" + cambi);
		write2.flush();
		
		//Client riceve da Server
		Scanner read2 = new Scanner(socket.getInputStream());
		String str2 = read.nextLine();
		System.out.println("gli interi aggiornati sono: " + str2);
		
		
		//Chiusura Client
		socket.close();
		System.out.println("Fine collegameto");
	}

}
