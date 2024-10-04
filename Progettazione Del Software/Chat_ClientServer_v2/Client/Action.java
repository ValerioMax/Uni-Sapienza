import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class Action implements ActionListener{
	
	JTextArea username;
	JTextArea address;
	JTextArea port;
	
	JButton connect;
	JButton disconnect;
	
	JTextArea chat;
	JTextArea message;
	
	JButton send;
	
	Socket socket;
	Scanner in;
	PrintWriter out;
	
	MyThread1 t1;
	
	Action(JTextArea username, JTextArea address, JTextArea port, JButton connect, JButton disconnect, JTextArea chat, JTextArea message, JButton send){
		this.username = username;
		this.address = address;
		this.port = port;
		this.connect = connect;
		this.disconnect = disconnect;
		this.chat = chat;
		this.message = message;
		this.send = send;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if (e.getSource() == connect) {
				socket = new Socket(address.getText(), Integer.parseInt(port.getText()));
				System.out.println("Connesso!");
				in = new Scanner(socket.getInputStream());
				out = new PrintWriter(socket.getOutputStream());
				
				out.println(username.getText());
				out.flush();
							
				chat.setText("-------------------------------CHAT AVVIATA-------------------------------");
				out.println("connected");
				out.flush();

				connect.setEnabled(false);
				disconnect.setEnabled(true);
				send.setEnabled(true);
				
				t1 = new MyThread1(in, chat, disconnect);
				t1.start();
			}
			
			if (e.getSource() == disconnect) {
				t1.interrupt();
				
				out.println("disconnected");
				out.flush();
				
				socket.close();
				in.close();
				out.close();
				
				System.out.println("Disconnesso");
				
				connect.setEnabled(true);
				disconnect.setEnabled(false);
				send.setEnabled(false);
			}
			
			if (e.getSource() == send) {
				out.println(message.getText());
				out.flush();
				chat.append("\n" + "Tu: " + message.getText());
			}
			
		}
		catch (NumberFormatException | IOException e1) {
			System.out.println("error");
		}
		
	}

}
