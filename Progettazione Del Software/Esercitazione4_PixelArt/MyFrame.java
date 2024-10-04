import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class MyFrame extends JFrame implements ActionListener{

	JTextArea text1;
	JTextArea text2;
	JTextArea text3;
	JTextArea text4;
	JButton connect;
	JButton disconnect;
	JButton get;
	JButton reset;
	ArrayList<JButton> list = new ArrayList<JButton>();
	
	Socket socket;
	Scanner in;
	PrintWriter out;
	
	MyFrame(){
		super("PixelArt");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());
		
			JPanel panelN = new JPanel();
				panelN.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 20));
				JLabel label1 = new JLabel("Server Address");
				JLabel label2 = new JLabel("Port");
				text1 = new JTextArea("localhost");
				text2 = new JTextArea("4400");
				connect = new JButton("connect");
				connect.addActionListener(this);
				connect.setEnabled(true);
				disconnect = new JButton("disconnect");
				disconnect.addActionListener(this);
				disconnect.setEnabled(false);
			panelN.add(label1);
			panelN.add(text1);
			panelN.add(label2);
			panelN.add(text2);
			panelN.add(connect);
			panelN.add(disconnect);
			
			JPanel panelM = new JPanel();
			panelM.setLayout(new FlowLayout());
				JPanel panelM1 = new JPanel();
				panelM1.setLayout(new GridLayout(5, 5, 1, 1));
					for (int i = 0; i < 25; i++) {
						JButton b = new JButton();
						b.setPreferredSize(new Dimension(50, 50));
						b.setEnabled(false);
						b.setBackground(Color.WHITE);
						list.add( b);
						panelM1.add(b);
					}
				
				JPanel panelM2 = new JPanel();
					text3 = new JTextArea(10, 10);
					text3.setEditable(false);
					JScrollPane scroll = new JScrollPane(text3);
					scroll.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), "Log"));
				panelM2.add(scroll);
			panelM.add(panelM1);
			panelM.add(panelM2);
			
			JPanel panelS = new JPanel();
				panelN.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 20));
				JLabel label = new JLabel("Numero");
				text4 = new JTextArea("Inserisci numero");
				get = new JButton("get");
				get.addActionListener(this);
				get.setEnabled(false);
				reset = new JButton("reset");
				reset.addActionListener(this);
				reset.setEnabled(false);
			panelS.add(label);
			panelS.add(text4);
			panelS.add(get);
			panelS.add(reset);
		
		this.add(panelN, BorderLayout.NORTH);
		this.add(panelM, BorderLayout.CENTER);
		this.add(panelS, BorderLayout.SOUTH);
		
		this.setResizable(false);
		this.setLocationRelativeTo(null);
		this.pack();
		this.setVisible(true);
	}
	
	
	public void resetGriglia() {
		for (int i = 0; i < 25; i++) {
			list.get(i).setBackground(Color.white);
		}
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			
			if (e.getSource() == connect) {
				socket = new Socket(text1.getText(), Integer.parseInt(text2.getText()));
				System.out.println("Connesso!");
				in = new Scanner(socket.getInputStream());
				out = new PrintWriter(socket.getOutputStream());

				connect.setEnabled(false);
				disconnect.setEnabled(true);
				get.setEnabled(true);
				reset.setEnabled(true);
			}
			
			if (e.getSource() == disconnect) {
				out.write("DISCONNECT");
				out.flush();
				
				socket.close();
				in.close();
				out.close();
				
				connect.setEnabled(true);
				disconnect.setEnabled(false);
				get.setEnabled(false);
				reset.setEnabled(false);
			}
			
			if (e.getSource() == get) {
				MyThread t1 = new MyThread(in, out, text3, text4, get, disconnect, list, this);
				t1.start();			
			}
			
			if (e.getSource() == reset) {
				resetGriglia();
				text3.setText(null);
				text4.setText("Inserisci numero");
			}
		
		}
		catch (IOException e1) {
			System.out.println("Errore");
		}
		
	}
}


