import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

//DA FIXARE: non è esatto perchè se esce 10 non funziona (per ogni 10 prende una stringa di n+1 numeri avendo 10 due cifre)
//NOTA:	
//-Scanner divide la Stringa in Token! (sottostringhe separate da Whitespaces di deafult)
//	->questi Token li posso poi leggere in vari modi: 
//		String str	= read.nextLine();
//		Int x		= read.nextInt(); 
//		boolean b	= read.nextByte();
//		...
//-In questo esercizio ad esempio io ricevo una stringa e faccio read.nextLine();
//-Inoltre averei potuto usare read.hasNextInt() che divide la stringa in Token (sottostringhe separate da Whitespaces) e restituisce true se il Token successivo è convertibile in int
//												es.: "2 34 566sd 9 3asdgga 10 aaa"  (in questo caso, se chiamato 7 volte, restituirà: true true false true false true false) 
public class CarteServer {

	public static void main(String[] args) throws IOException {
		
		//Connessione a Client
		System.out.println("Sono Server");
		ServerSocket server = new ServerSocket(4400);
		System.out.println("In attesa di connessione...");
		Socket socket = server.accept();
		System.out.println("Connessione a Client stabilita");
		
		//Server riceve
		Scanner read1 = new Scanner(socket.getInputStream());
		String str1 = read1.nextLine();
		System.out.println("Client ha mandato: " + str1);
		
		//Server invia carte
		String set = generaSet();
		PrintWriter write1 = new PrintWriter(socket.getOutputStream());
		write1.println(set);
		write1.flush();
		
		//Server riceve posizioni da cambiare
		Scanner read2 = new Scanner(socket.getInputStream());
		String str2 = read1.nextLine();
		System.out.println("Client ha mandato: " + str2);
		
		//Serve manda set con nuove posizioni
		PrintWriter write2 = new PrintWriter(socket.getOutputStream());
		write2.println(nuovoSet(str2, set));
		write2.flush();
		
		
		//Chiusura del server
		server.close();
		System.out.println("Fine collegameto");
	}

	private static String nuovoSet(String str2, String set) {
		Random random = new Random();
		String newSet = set;
		for (int i = 6; i < str2.length(); i++) {
			newSet = newSet.substring(0, str2.charAt(i)-1-'0') + random.nextInt(1,11) + newSet.substring(str2.charAt(i)-'0', newSet.length());
		}
		return newSet;
	}

	private static String generaSet() {
		
		Random random = new Random();
		String str = new String();
		for (int i = 0; i < 5; i++) {
			str = str + random.nextInt(1,11);
		}
		return str;
	}

}
