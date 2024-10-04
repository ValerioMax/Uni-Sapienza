import java.io.PrintWriter;
import java.util.Scanner;

public class TRiceveManda extends Thread{

	Scanner in;
	PrintWriter out;
	int i;
	
	String str = "Connesso";
	
	TRiceveManda(Scanner in, PrintWriter out, int i){
		this.in = in;
		this.out = out;
		this.i = i;
	}
	
	@Override
	public void run(){
		while (!str.equals("STOP")) {
			str = in.nextLine();
			
			out.println("Client" + i + " : " + str);
			out.flush();
			
				
		}
	}
}
