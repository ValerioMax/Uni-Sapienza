import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class TPowered extends Thread{
	
	ArrayList<Socket> list;
	ServerSocket server;
	int j;
	String name;
	
	int numSocket = 0;
	String str = "";
		
	TPowered(ArrayList<Socket> list, ServerSocket server, int j){
		this.list = list;
		this.server = server;
		this.j = j; //identificativo thread
	}
	
	@Override
	public void run() {
		
		try {
			Socket s = null;
			s = server.accept();
			list.add(s);
			numSocket++; //quando un altro thread si chiude dovro fare --
			
			//PrintWriter out1 = new PrintWriter(s.getOutputStream());
			//out1.println("Inserisci Username: ");
			//out1.flush();
			
			Scanner in = new Scanner(s.getInputStream());
			name = in.nextLine();
			
			while (!str.equals("disconnected")) {
				if (in.hasNextLine()) {
					str = in.nextLine();
					
					for (int i = 0; i < list.size(); i++) {
						//System.out.println(list.get(i));
						if (list.get(i) != s) { //se non funziona questa condizione passare al costruttore del thread un numero identificativo e usarlo come indice da saltare
							PrintWriter out = new PrintWriter(list.get(i).getOutputStream()); //da rivedere perche cosi ne crea sempre di nuovi anche se alcuni ce li aveva già
							out.println(name + " (Client" + j +  ") : " + str);
							out.flush();
						}
					}	
				}
			}
			
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
