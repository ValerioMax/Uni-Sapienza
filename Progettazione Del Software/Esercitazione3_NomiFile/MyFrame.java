import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class MyFrame extends JFrame{
	
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
	
	Action action;
	
	MyFrame(){
		super("Client");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());
		this.setSize(600, 320);
		this.setResizable(false);
			
			JPanel panelN = new JPanel();
			panelN.setLayout(new FlowLayout());
				JLabel label1 = new JLabel("Server Address");
				JLabel label2 = new JLabel("Port");
				address = new JTextArea("localhost");
				port = new JTextArea("4400");
				connect = new JButton("Connect");
				disconnect = new JButton("Disconnect");
			panelN.add(label1);
			panelN.add(address);
			panelN.add(label2);
			panelN.add(port);
			panelN.add(connect);
			panelN.add(disconnect);
				
			JPanel panelC = new JPanel();
			panelC.setLayout(new FlowLayout());
				logText = new JTextArea(10, 15);
				logText.setEditable(false);
				JScrollPane logScroll = new JScrollPane(logText);
				logScroll.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), "Log"));
				pdfText = new JTextArea(10, 10);
				pdfText.setEditable(false);
				JScrollPane pdfScroll = new JScrollPane(pdfText);
				pdfScroll.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), ".pdf"));
				mp3Text = new JTextArea(10, 10);
				mp3Text.setEditable(false);
				JScrollPane mp3Scroll = new JScrollPane(mp3Text);
				mp3Scroll.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), ".mp3"));
			panelC.add(logScroll);
			panelC.add(pdfScroll);
			panelC.add(mp3Scroll);
			
			JPanel panelS = new JPanel();
			panelS.setLayout(new FlowLayout());
				JLabel label3 = new JLabel("Dimensione:");
				dimension = new JTextArea("");
				dimension.setEditable(false);
				start = new JButton("Start");
				stop = new JButton("Stop");
				clear = new JButton("Clear");
			panelS.add(label3);
			panelS.add(dimension);
			panelS.add(start);
			panelS.add(stop);
			panelS.add(clear);
			
		action = new Action(address, port, connect, disconnect, logText, pdfText, mp3Text, dimension, start, stop, clear);
		
		connect.addActionListener(action);
		disconnect.addActionListener(action);
		start.addActionListener(action);
		stop.addActionListener(action);
		clear.addActionListener(action);
		
		connect.setEnabled(true);
		disconnect.setEnabled(false);
		start.setEnabled(false);
		stop.setEnabled(false);
		clear.setEnabled(false);
		
		this.add(panelN, BorderLayout.NORTH);
		this.add(panelC, BorderLayout.CENTER);
		this.add(panelS, BorderLayout.SOUTH);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
