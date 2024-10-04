import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;

public class MyFrame extends JFrame implements ActionListener{
	
	JLabel label1;
	JLabel label2;
	JTextArea tAddress;
	JTextArea tPort;
	JButton connect;
	JButton disconnect;
	
	JProgressBar cpuBar;
	JProgressBar memoryBar;
	JProgressBar diskBar;
	JProgressBar networkBar;
	
	ButtonGroup group;
	JRadioButton vm1;
	JRadioButton vm2;
	JRadioButton vm3;
	
	JButton start;
	JButton stop;
	
	Socket socket;
	Scanner in;
	PrintWriter out;
	
	MyThread t1;
	
	String s = "";
	
	MyFrame(){
		super("Nome Cognome 12345");
		this.setSize(500,600);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new BorderLayout());
		
			JPanel panelN = new JPanel();
			panelN.setLayout(new FlowLayout());
				label1 = new JLabel("Server Address");
				label2 = new JLabel("Port");
				tAddress = new JTextArea("localhost");
				tPort = new JTextArea("4400");
				
				connect = new JButton("Connect");
				connect.addActionListener(this);
				connect.setEnabled(true);
				
				disconnect = new JButton("Disonnect");
				disconnect.addActionListener(this);
				disconnect.setEnabled(false);
				
			panelN.add(label1);
			panelN.add(tAddress);
			panelN.add(label2);
			panelN.add(tPort);
			panelN.add(connect);
			panelN.add(disconnect);
				
			JPanel panelC = new JPanel();
			panelC.setLayout(new GridLayout(4,2,5,5));
				JLabel lab1 = new JLabel("CPU Usage");
				JLabel lab2 = new JLabel("Memory Usage");
				JLabel lab3 = new JLabel("Disk Usage");
				JLabel lab4 = new JLabel("Network Usage");
				cpuBar = new JProgressBar(0,100);
				cpuBar.setStringPainted(true);
				cpuBar.setValue(0);
				
				memoryBar = new JProgressBar(0,100);
				memoryBar.setStringPainted(true);
				memoryBar.setValue(0);
				
				diskBar = new JProgressBar(0,100);
				diskBar.setStringPainted(true);
				diskBar.setValue(0);
				
				networkBar = new JProgressBar(0,100);
				networkBar.setStringPainted(true);
				networkBar.setValue(0);
			panelC.add(lab1);
			panelC.add(cpuBar);
			panelC.add(lab2);
			panelC.add(memoryBar);
			panelC.add(lab3);
			panelC.add(diskBar);
			panelC.add(lab4);
			panelC.add(networkBar);
				
				
				
			JPanel panelS = new JPanel();
			panelS.setLayout(new FlowLayout());
				group = new ButtonGroup();
				vm1 = new JRadioButton("VM 1");
				vm1.setEnabled(false);
				vm1.addActionListener(this);
				
				vm2 = new JRadioButton("VM 2");
				vm2.setEnabled(false);
				vm2.addActionListener(this);
				
				vm3 = new JRadioButton("VM 3");
				vm3.setEnabled(false);
				vm3.addActionListener(this);
				
				group.add(vm1);
				group.add(vm2);
				group.add(vm3);
				
				start = new JButton("Start");
				start.addActionListener(this);
				start.setEnabled(false);
				
				stop = new JButton("Stop");
				stop.addActionListener(this);
				stop.setEnabled(false);
				
			panelS.add(vm1);
			panelS.add(vm2);
			panelS.add(vm3);
			panelS.add(start);
			panelS.add(stop);
		
		this.add(panelN, BorderLayout.NORTH);
		this.add(panelC, BorderLayout.CENTER);
		this.add(panelS, BorderLayout.SOUTH);
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			if (e.getSource() == connect) {
					socket = new Socket(tAddress.getText(), Integer.parseInt(tPort.getText()));
					in = new Scanner(socket.getInputStream());
					out = new PrintWriter(socket.getOutputStream());
					
					System.out.println("Connesso!");
					
					connect.setEnabled(false);
					disconnect.setEnabled(true);
					start.setEnabled(true);
					vm1.setEnabled(true);
					vm2.setEnabled(true);
					vm3.setEnabled(true);
			}
			
			if (e.getSource() == vm1) {
				s = "1";
				System.out.println("Scelto vm1");
			}
			if (e.getSource() == vm2) {
				s = "2";
				System.out.println("Scelto vm2");
			}
			if (e.getSource() == vm3) {
				s = "3";
				System.out.println("Scelto vm3");
			}
			
			if (e.getSource() == start) {
				stop.setEnabled(true);
				disconnect.setEnabled(false);
				start.setEnabled(false);
				vm1.setEnabled(false);
				vm2.setEnabled(false);
				vm3.setEnabled(false);
				
				t1 = new MyThread(in, cpuBar, memoryBar, diskBar, networkBar, stop, disconnect, start, vm1, vm2, vm3);
				t1.start();
				
				out.println("start:vm" + s);
				out.flush();
			}
			
			if (e.getSource() == stop) {
				out.println("stop");
				out.flush();
			}
			
			if (e.getSource() == disconnect) {
				out.println("disconnect");
				out.flush();
				System.out.println("Fine collegamento");
				
				socket.close();
				in.close();
				out.close();
				
				connect.setEnabled(true);
				stop.setEnabled(false);
				disconnect.setEnabled(false);
				start.setEnabled(false);
				vm1.setEnabled(false);
				vm2.setEnabled(false);
				vm3.setEnabled(false);
			}
			
		} catch (NumberFormatException | IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
	}
}
