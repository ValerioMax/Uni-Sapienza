import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JTextArea;

public class MyThread extends Thread{
	
	JTextArea logText;
	JTextArea pdfText; 
	JTextArea mp3Text;
	JTextArea dimension;
	Scanner in;
	
	String s;
	String[] str;
	
	double dim = 0;
	
	boolean b = true;
	
	MyThread(Scanner in, JTextArea logText, JTextArea  pdfText, JTextArea  mp3Text, JTextArea  dimension){
		this.in = in;
		this.logText = logText;
		this.pdfText = pdfText; 
		this.mp3Text = mp3Text;
		this.dimension = dimension;
	}
	
	@Override
	public void run() {
		while (b) {
			if (in.hasNextLine())
				s = in.nextLine();
			if (s.equals("ERROR")) {
				b = false;
				//chiudere socket scanner e printWriter
			}
			else if (s.equals("END") || s.equals("INTERRUPTED")) {
				b = false;
			}
			else {
				System.out.println(s);
				str = s.split(":");
				
				logText.append(str[1] + " " + str[2] + "\n");
				
				dim += Double.parseDouble(str[2].split(" ")[0]);
				dimension.setText(Double.toString(Math.floor(dim*100)/100) + " KB");
				
				if (str[0].equals("MP3")) {
					mp3Text.append(str[1].split("\\.")[0] + "\n");
				}
				else if (str[0].equals("PDF")) {
					pdfText.append(str[1].split("\\.")[0] + "\n");
				}
			}
			
			
		}
	}
}
