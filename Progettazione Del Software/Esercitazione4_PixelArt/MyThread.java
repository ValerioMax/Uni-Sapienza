import java.awt.Color;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class MyThread extends Thread{
	
	Scanner in;
	PrintWriter out;
	JTextArea text3;
	JTextArea text4;
	JButton get;
	JButton disconnect;
	ArrayList<JButton> list;
	MyFrame frame;
	
	MyThread(Scanner in, PrintWriter out, JTextArea text3, JTextArea text4, JButton get, JButton disconnect, ArrayList<JButton> list, MyFrame frame){
		this.in = in;
		this.out = out;
		this.text3 = text3;
		this.text4 = text4;
		this.get = get;
		this.disconnect = disconnect;
		this.list = list;
		this.frame = frame;
	}
	
	@Override
	public void run() {
		try {
			if (Integer.parseInt(text4.getText()) >= 0 && Integer.parseInt(text4.getText()) <= 9) {
				out.println("GET:" + text4.getText());
				out.flush();
				
				frame.resetGriglia();
				
				get.setEnabled(false);
				disconnect.setEnabled(false);
	
				String str1 = in.nextLine();
				System.out.println(str1);
				
				for (int i = 0; i < 25; i++) {
					if (str1.charAt(i + 2) == '1')
						list.get(i).setBackground(Color.black);
				}
				
				text3.append(str1 + "\n");
				
				String str3 = in.nextLine();
				System.out.println(str3);

				get.setEnabled(true);
				disconnect.setEnabled(true);
			}
			else {
				JOptionPane.showMessageDialog(new JOptionPane(), "Inserisci numero valido");
			}
		}
		catch(NumberFormatException e2) {
			JOptionPane.showMessageDialog(new JOptionPane(), "Inserisci numero");
		}
	}
}
