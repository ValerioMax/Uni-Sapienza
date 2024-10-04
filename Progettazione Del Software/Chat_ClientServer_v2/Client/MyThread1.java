import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JTextArea;

public class MyThread1 extends Thread{
	
	Scanner in;
	JTextArea chat;
	JButton disconnect;
	
	String str = "";
	boolean b = true;
	
	MyThread1(Scanner in, JTextArea chat, JButton disconnect){
		this.in = in;
		this.chat = chat;
		this.disconnect = disconnect;
	}
	
	@Override
	public void run() {
		
		//out.println("connected");
		//out.flush();
		
		while (b) {
			if (disconnect.isEnabled() && in.hasNextLine()) {
				str = in.nextLine();
				System.out.println(str);
			
				chat.append("\n" + str);
			}
			else {
				b = false;
			}
				
			
		}
	}
}
