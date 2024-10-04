import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JTextArea;

public class Action implements ActionListener{
	
	JTextArea address;
	JTextArea port;
	JButton connect;
	JButton disconnect;
	JTextArea logText;
	JTextArea pdfText;
	JTextArea mp3Text;
	JTextArea dimension;
	JButton start;
	JButton stop;
	JButton clear;
	
	Socket socket;
	Scanner in;
	PrintWriter out;
	
	MyThread t1;
	
	Action(JTextArea address, JTextArea port, JButton connect, JButton disconnect, JTextArea logText, JTextArea pdfText, JTextArea mp3Text, JTextArea dimension, JButton start, JButton stop, JButton clear){
		this.address = address;
		this.port = port;
		this.connect = connect;
		this.disconnect = disconnect;
		this.logText = logText;
		this.pdfText = pdfText;
		this.mp3Text = mp3Text;
		this.dimension = dimension;
		this.start = start;
		this.stop = stop;
		this.clear = clear;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if (e.getSource() == connect) {
				socket = new Socket(address.getText(), Integer.parseInt(port.getText()));
				System.out.println("Connesso!");
				in = new Scanner(socket.getInputStream());
				out = new PrintWriter(socket.getOutputStream());
				
				connect.setEnabled(false);
				start.setEnabled(true);
				clear.setEnabled(true);
				disconnect.setEnabled(true);
			}
			
			if (e.getSource() == start) {
				out.println("start");
				out.flush();
				
				logText.setText("");
				pdfText.setText("");
				mp3Text.setText("");
				dimension.setText("");
				
				stop.setEnabled(true);
				start.setEnabled(false);
				clear.setEnabled(false);
				disconnect.setEnabled(false);
				
				t1 = new MyThread(in, logText, pdfText, mp3Text, dimension);
				t1.start();
			}
			
			if (e.getSource() == stop) {
				out.println("stop");
				out.flush();
				
				stop.setEnabled(false);
				start.setEnabled(true);
				clear.setEnabled(true);
				disconnect.setEnabled(true);
			}
			
			if (e.getSource() == disconnect) {
				out.println("disconnect");
				out.flush();
				
				socket.close();
				in.close();
				out.close();
				
				System.out.println("Disconnesso");
				
				connect.setEnabled(true);
				stop.setEnabled(false);
				start.setEnabled(false);
				clear.setEnabled(false);
				disconnect.setEnabled(false);
			}
			
			if (e.getSource() == clear) {
				logText.setText(null);
				mp3Text.setText(null);
				pdfText.setText(null);
			}
		}
		catch (NumberFormatException | IOException e1) {
			System.out.println("error");
		}
		
	}

}
