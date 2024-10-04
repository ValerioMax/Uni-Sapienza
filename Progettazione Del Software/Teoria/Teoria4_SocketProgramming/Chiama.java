//Esercitazione del 17-10-23

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

//Creazione del client

public class Chiama {

	public static void main(String[] args) throws UnknownHostException, IOException {
		
		System.out.println("Sono il client");
		
		Socket socket = new Socket("localhost",1111);
		
		System.out.println("Connessione col server stabilita");
		
		//Invio della stringa, dal client al server
		
		PrintWriter scrivi = new PrintWriter(socket.getOutputStream());
		scrivi.println("carte");
		scrivi.flush();
		
		//Lettura dei cinque numeri inviati, dal server al client
		
		Scanner leggi = new Scanner(socket.getInputStream());
		int[] array = new int[5];
		int i = 0;
		while(leggi.hasNextInt() && i<5) {
			array[i] = leggi.nextInt();
			System.out.println(array[i]);
			i++;
			if(i==5) {
				break;
			}
		}
		
		//Invio della stringa contenente le posizioni dei numeri da cambiare, inviati dal client al server
		
		System.out.println("Inserisci le posizioni dei numeri da cambiare: ");
		@SuppressWarnings("resource")
		Scanner leggi2 = new Scanner(System.in);
		String s2 = leggi2.nextLine();
		
		PrintWriter scrivi2 = new PrintWriter(socket.getOutputStream());
		scrivi2.println("cambio " + s2);
		System.out.println("\n");
		scrivi2.flush();
		
		//Lettura dei cinque numeri aggiornati, inviati dal server al client
		
		Scanner leggi3 = new Scanner(socket.getInputStream());
		int[] array2 = new int[5];
		int k = 0;
		while(leggi3.hasNextInt() && k<5) {
			array2[k] = leggi3.nextInt();
			System.out.println(array2[k]);
			k++;
			if(k==5) {
				break;
			}
		}
		
		//Chiusura client
		
		socket.close();
		System.out.println("Fine collegameto");
	}
}
