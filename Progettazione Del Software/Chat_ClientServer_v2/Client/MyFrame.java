import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;

public class MyFrame extends JFrame{
	
	JTextArea username;
	JTextArea address;
	JTextArea port;
	JButton connect;
	JButton disconnect;
	
	JTextArea chat;
	
	JTextArea message;
	JButton send;
	
	Action action;
	
	MyFrame(int i, Color color){		
		super("Client" + i);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());
		this.setSize(600, 450);
		this.setResizable(false);
			
			JPanel panelN = new JPanel();
			panelN.setLayout(new FlowLayout());
			panelN.setBackground(color);
				JLabel label0 = new JLabel("Username");
				JLabel label1 = new JLabel("Server Address");
				JLabel label2 = new JLabel("Port");
				username = new JTextArea("Unnamed");
				address = new JTextArea("localhost");
				port = new JTextArea("1110");
				connect = new JButton("Connect");
				disconnect = new JButton("Disconnect");
			
			panelN.add(label0);
			panelN.add(username);
			panelN.add(label1);
			panelN.add(address);
			panelN.add(label2);
			panelN.add(port);
			panelN.add(connect);
			panelN.add(disconnect);
				
			JPanel panelC = new JPanel();
			panelC.setLayout(new FlowLayout());
			panelC.setBackground(color);
			
				chat = new JTextArea("", 20,30);
				chat.setEditable(false);
				JScrollPane chatScroll = new JScrollPane(chat);
			panelC.add(chatScroll);
			
			JPanel panelS = new JPanel();
			panelS.setLayout(new FlowLayout());
			panelS.setBackground(color);
				JLabel label3 = new JLabel("Messaggio");
				message = new JTextArea("Inerisci messaggio", 2, 25);
				send = new JButton("Send");
			panelS.add(label3);
			panelS.add(message);
			panelS.add(send);
			
		action = new Action(username, address, port, connect, disconnect, chat, message, send);
		
		connect.addActionListener(action);
		disconnect.addActionListener(action);
		send.addActionListener(action);
		
		connect.setEnabled(true);
		disconnect.setEnabled(false);
		send.setEnabled(false);
		
		this.add(panelN, BorderLayout.NORTH);
		this.add(panelC, BorderLayout.CENTER);
		this.add(panelS, BorderLayout.SOUTH);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
