import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JTextArea;

public class MyThread extends Thread{
	
	Scanner in;
	ArrayList<TicketCell> list;
	ArrayList<Integer> usati;
	JTextArea log;
	JButton start;
	JButton disconnect;
	
	Integer n = 0;
	String str;
	
	MyThread(Scanner in, ArrayList<TicketCell> list, ArrayList<Integer> usati, JTextArea log, JButton start, JButton disconnect){
		this.in = in;
		this.list = list;
		this.log = log;
		this.usati = usati;
		this.start = start;
		this.disconnect = disconnect;
	}
	
	@Override
	public void run() {
		
		while (true) {
			
			if (in.hasNextInt()) {
				n = in.nextInt();
				log.append("Estratto: " + n + "\n");
				if (usati.contains(n)) {
					for (int i = 0; i < 15; i++) {
						if (list.get(i).getValue() == n) {
							list.get(i).setSelected(true);	
						}
					}
				}
				System.out.println(n);
			}
			else if (in.hasNextLine()) {
				str = in.nextLine();
				System.out.println(str);
				if (str.equals("+")) {
					start.setEnabled(true);
					disconnect.setEnabled(true);
					log.append("Fine partita\n");
					break;
				}
			}
		}
		System.out.println("Fine ciclo");
	}
	
}
