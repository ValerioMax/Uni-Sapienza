import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class MyFrame extends JFrame implements ActionListener{
	
	JLabel lab1;
	JLabel lab2;
	JTextArea address;
	JTextArea port;
	JButton connect;
	JButton disconnect;
	
	//JButton b;
	TicketCell ticket;
	//ArrayList<JButton> list = new ArrayList<JButton>();
	ArrayList<TicketCell> list = new ArrayList<TicketCell>();
	
	JTextArea log;
	JScrollPane scroll;

	JButton start;
	JButton stop;
	
	Socket socket;
	Scanner in;
	PrintWriter out;
	
	MyThread t1;
	
	MyFrame(){
		super("nome cognome matricola");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		//this.setSize(1200,450);
		this.setLayout(new BorderLayout());
			
			JPanel panelN = new JPanel();
			panelN.setLayout(new FlowLayout());
				lab1 = new JLabel("Server Address");
				lab2 = new JLabel("Port");
				address = new JTextArea("localhost");
				port = new JTextArea("4400");
				
				connect = new JButton("Connect");
				connect.addActionListener(this);
				connect.setEnabled(true);
				disconnect = new JButton("Disconnect");
				disconnect.addActionListener(this);
				disconnect.setEnabled(false);
			panelN.add(lab1);
			panelN.add(address);
			panelN.add(lab2);
			panelN.add(port);
			panelN.add(connect);
			panelN.add(disconnect);
			
			JPanel panelC = new JPanel();
			panelC.setLayout(new FlowLayout());
				JPanel panelC1 = new JPanel();
				panelC1.setLayout(new GridLayout(3,5,1,1));
					for (int i = 0; i < 15; i++) {
						ticket = new TicketCell();
						list.add(ticket);
						panelC1.add(ticket);
					}
				log = new JTextArea(20,15);
				log.setEditable(false);
				scroll = new JScrollPane(log);
				scroll.setBorder(BorderFactory.createTitledBorder("Log"));
			//panelC.add(panelC1);
			panelC.add(scroll);
				
			JPanel panelS = new JPanel();
			panelS.setLayout(new FlowLayout());
				start = new JButton("Start");
				start.addActionListener(this);
				start.setEnabled(false);
				
				stop = new JButton("Stop");
				stop.addActionListener(this);
				stop.setEnabled(false);
			panelS.add(start);
			panelS.add(stop);
			
		this.add(panelN, BorderLayout.NORTH);
		this.add(panelC, BorderLayout.EAST);
		this.add(panelC1, BorderLayout.CENTER);
		this.add(panelS, BorderLayout.SOUTH);
		this.pack();
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if (e.getSource() == connect) {
				socket = new Socket(address.getText(), Integer.parseInt(port.getText()));
				in = new Scanner(socket.getInputStream());
				out = new PrintWriter(socket.getOutputStream());
				
				System.out.println("Connesso!");
				
				connect.setEnabled(false);
				disconnect.setEnabled(true);
				start.setEnabled(true);
			}
			
			if (e.getSource() == start) {
				out.println("start");
				out.flush();
				
				stop.setEnabled(true);
				disconnect.setEnabled(false);
				start.setEnabled(false);
				
				//creo un ArrayList di Integer da 1 a 90 senza ripetizioni
				Random random = new Random();
				int x;
				ArrayList<Integer> usati = new ArrayList<Integer>();
				for (int i = 0; i < 15; i++) {
					x = random.nextInt(1, 91);
					while (usati.contains(x)) {
						x = random.nextInt(1, 91);
					}
					usati.add(x);
				}
				
				//faccio in modo che la cartella venga riempita in ordine crescente dall'alto al basso scorrendo sulle colonne verso dx
				usati.sort(null);
				
				int[][] mat = new int[3][5];
				int k = 0;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 3; j++) {
						mat[j][i] = usati.get(k);
						k++;
					}
				}
				k = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 5; j++) {
						list.get(k).setSelected(false); //pulisco la cartella del turno precedente
						list.get(k).setValue(mat[i][j]);
						k++;
					}
				}
				
				t1 = new MyThread(in, list, usati, log, start, disconnect);
				t1.start();
			}
			
			if (e.getSource() == stop) {
				out.println("stop");
				out.flush();
			}
			
			if (e.getSource() == disconnect) {
				out.println("disconnect");
				out.flush();
				
				System.out.println("Disconnesso");
				
				socket.close();
				in.close();
				out.close();
				
				connect.setEnabled(true);
				disconnect.setEnabled(false);
				start.setEnabled(false);
				stop.setEnabled(false);
			}
				
				
				
		} catch (NumberFormatException | IOException e1 ) {
			System.out.println("error");
		}
		
	}
}
