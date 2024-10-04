import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class ServerPotenziato {

	//funziona con n client (ciclo for)
	
	//creo 10 thread e a ognuno passo l'array list, in ogni thread l'array list verrà aggiornata e tale aggiornamento lo condivideranno tutti i thread.
	//In questo modo poi in ogni thread faccio che invio il messaggio solo a tutti gli elementi (list.size()) che l'array list possiede in quel momento
	
	public static void main(String[] args) throws UnknownHostException, IOException {
		System.out.println("Qui Server");
		ServerSocket server = new ServerSocket(1110);
		
		ArrayList<Socket> list = new ArrayList<Socket>();
		
		for (int i = 0; i < 10; i++) {
			TPowered t = new TPowered(list, server, i);
			t.start();
		}
		
	}

}
