import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.io.*;

public class EchoClient {

	public static void main(String[] args) {
		
		//NOTA: switchare da un terminale all'altro con Display Selected Console (in basso a destra in Eclipse) invece di riRunnare Client
		try
		{
			String ip = "192.168.1.23"; //IP del portatile di Gaia, funziona!
			System.out.println("Client started");
			Socket soc = new Socket(ip, 9801); //parametro1 = IP_addres del server ("localhost" si usa quando client e server sono locali ovvero si trovano sulla stessa macchina)
														//									 "localhost" = 127.0.0.1 che è l'IP_address della macchina locale
														//parametro2 = portNumber dell'application
														//Dovrebbe creare il Client Socket che tenta di collegarsi alla macchina di IP: "localhost" e PortNumber: 9806 (credo(?))
			
			
			//Leggiamo dei dati da tastiera e mandiamoli al Server:
			BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in)); //InputStreamReader legge i dati dallo stream in input 
																							 //che è preso da System.in che a sua volta permette di leggere dati da tastiera
																							 //tutto ciò è immagazzinato in un Buffer (credo(?))
			System.out.println("Enter a string");
			String str = userInput.readLine(); //fa scrivere la stringa allo user (sicuro?) forse legge la stringa che System.in fa scrivere
			PrintWriter out = new PrintWriter(soc.getOutputStream(), true); //crea un oggetto PrintWriter "out" che manda in output dal Client Socket "soc" uno stream (?)
																			//true sta per autoflash: indica che non appena di fa println() si mandano i dati in output (?)
			out.println(str); //println è un metodo della classe PrintWriter che manda i dati
			
			
			
			BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream())); //leggiamo ora dall'input arrivato al Client socket dal Server
			System.out.println(in.readLine()); //printiamo il contenuto dei dati in input
			
			soc.close();
		}
		catch (UnknownHostException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		} 

	}

}
