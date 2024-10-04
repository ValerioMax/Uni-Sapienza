import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

//Bisogna runnare prima la server application perchè il server dovrà aspettare gli incoming clients

public class EchoServer {

	public static void main(String[] args) {
		
		
		try
		{
			System.out.println("Waiting for clients...");
			ServerSocket ss = new ServerSocket(9801);	//il parametro è il portNumber del server (serve per identificare l'applicazione nella rete (il socket(?))) (gliedo dò io arbitrariamente?)
			  											//mentre IP_Address è usato per identificare la macchina
														//su una macchina ho più applicazioni che identifico con il portNumber
			Socket soc = ss.accept();	//accept() aspetta le client-connections e non appena le riceve ritorna un oggetto di tipo Socket
			System.out.println("Connection established!");
			
			
			//Leggiamo la stringa mandata dal Client
			BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream())); //InputStreamReader legge i dati dallo stream in input 
																								 //che è preso da cio che il Socket "soc" prende in input qui nel server (soc.getInputStream())
																								 //soc.getInputStream() si mette in attesa dello stream che verrà mandato da println() nell'applicazione Client 
																								 //tutto ciò è immagazzinato in un Buffer (credo(?))
			String str = in.readLine(); //legge la stringa immagazzinata in "in" (sicuro?)
			
			
			
			PrintWriter out = new PrintWriter(soc.getOutputStream(), true); //mandiamo la stringa al socket output stream
			out.println("I am Server and i received your message: " + str); //viene mandata la stringa passata al Client
			
			ss.close();
		} 
		catch (IOException e)
		{
			e.printStackTrace();
		} 
		
	}

}
