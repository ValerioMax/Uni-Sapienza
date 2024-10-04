import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Server {
	
	public static void main(String[] args) throws UnknownHostException, IOException{
	//public Server() throws IOException {
		
		System.out.println("Qui Server");
		ServerSocket server = new ServerSocket(1110);
		Socket socket = server.accept();
		System.out.println("Connesso");
		
		Scanner read = new Scanner(socket.getInputStream());
		PrintWriter write = new PrintWriter(socket.getOutputStream());
		
		for (int i = 0; i < 10; i++) {
			write.println("OK");
			write.flush();
			
			System.out.println("Client dice: " + read.nextLine());
		}
		
		write.println("STOP");
		write.flush();
		
		server.close();
		System.out.println("Fine collegameto");
	}

}
