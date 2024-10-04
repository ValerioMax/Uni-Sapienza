import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Server {
	//Funziona con solo due Client
	
	
	public static void main(String[] args) throws UnknownHostException, IOException {
		
		System.out.println("Qui Server");
		ServerSocket server = new ServerSocket(1110);
		
		Socket socket1 = server.accept();
		System.out.println("Connesso a Client1");
		Scanner in1 = new Scanner(socket1.getInputStream());
		PrintWriter out1 = new PrintWriter(socket1.getOutputStream());
		
		Socket socket2 = server.accept();
		System.out.println("Connesso a Client2");
		Scanner in2 = new Scanner(socket2.getInputStream());
		PrintWriter out2 = new PrintWriter(socket2.getOutputStream());
		
		TRiceveManda t1 = new TRiceveManda(in1, out2, 1);
		t1.start();
		TRiceveManda t2 = new TRiceveManda(in2, out1, 2);
		t2.start();		
	}

}
