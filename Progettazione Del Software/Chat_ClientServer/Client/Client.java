import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client {
	
	public static void main(String[] args) throws UnknownHostException, IOException{
	//public Client() throws UnknownHostException, IOException {
		
		System.out.println("Qui Client");
		Socket socket = new Socket("localhost", 1110);
		System.out.println("Connesso");
		
		PrintWriter write = new PrintWriter(socket.getOutputStream());
		Scanner read = new Scanner(socket.getInputStream());
		
		Scanner scanner = new Scanner(System.in);
		String str;
		
		String s = read.nextLine();
		System.out.println("Server dice: " + s);
		
	
		while (s.equals("OK")) {
			System.out.println("Cosa scrivi a Server?");
			str = scanner.nextLine();
			
			write.println(str);
			write.flush();
			
			s = read.nextLine();
			System.out.println("Server dice: " + s);
		}
		
		socket.close();
		System.out.println("Fine collegameto");
	}

}
