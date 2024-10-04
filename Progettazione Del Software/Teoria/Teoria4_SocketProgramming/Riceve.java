import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.PrintWriter;
import java.net.UnknownHostException;
import java.util.Random;
import java.util.Scanner;

//Creazione del server

@SuppressWarnings("unused")

public class Riceve {

	public static void main(String[] args) throws IOException{
		
		ServerSocket server = new ServerSocket(1111);
		
		System.out.println("Sono il server");
		
		System.out.println("Pronto ad essere chiamato");
		
		Socket socket;
		
		socket = server.accept();
		
		System.out.println("Sono stato chiamato");
		
		//Lettura della stringa, inviata dal client al server
		
		Scanner read = new Scanner(socket.getInputStream());
		String s =read.nextLine();
		System.out.println("Ho letto " + s);
		
		//Invio di cinque numeri interi, dal server al client
		
		PrintWriter write = new PrintWriter(socket.getOutputStream());
		String str;
		String stringa = "";
		int number;
		int[] vettore = new int[5];
		Random random = new Random();
		for(int i=0;i<=4;i++) {
			number = random.nextInt(1,11);
			vettore[i] = number;
			str = String.valueOf(number);
			stringa = stringa + str + " ";
		}
		write.println(stringa);
		write.flush();
		
		//Lettura della stringa contenente le posizioni dei numeri da cambiare, inviata dal client al server
		
		Scanner  read2 = new Scanner(socket.getInputStream());
		String s2 = read2.nextLine();
		System.out.println("Ho letto " + s2);
		String[] splitstring = s2.split(" ");
		if (splitstring.length>1) {
			for(int j=1;j<splitstring.length;j++) {
				vettore[j-1] = random.nextInt(1,11);
			}
		}
		
		//Aggiornamento e invio dei numeri, dal server al client
		
		PrintWriter write2 = new PrintWriter(socket.getOutputStream());
		String str2;
		String stringa2 = "";
		for(int i=0;i<=4;i++) {
			str2 = String.valueOf(vettore[i]);
			stringa2 = stringa2 + str2 + " ";
		}
		write2.println(stringa2);
		write2.flush();
		
		//Chiusura server
		
		server.close();
		System.out.println("Fine collegameto");
		}
}

