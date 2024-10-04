import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args) {
		//DOMANDE:
		//-Come faccio ad aprire più frame contemporaneamente?
		//-Non ho capito nulla della 22
		//-Non ho capito come funzionano i vari layout in particolare come centrare un label di dimensione mxn in un frame
		//
		//NOTE:
		//-Se setto la visibilità a true del frame prima di fare add(component) non mi visualizza la componente finche non ridimensiono la finestra
		//-Per interrompere un programma andare sul quadratino rosso in basso a destra
		//
		//
		//COSA HO SALTATO(da "Java GUI: Full Course" su YT):
		//8.JLayeredPane, 23.KeyBindings 
		//
		//---------------------------------------------------------------------------------------------------------
		//1.JFrame è una GUI window (una finestra)
		
		/*
		MyFrame myFrame = new MyFrame();
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//2.JLabel è una GUI display area che contiene una stringa di testo, immagine o entrambe
		
		/*
		MyLabel myLabel = new MyLabel();
		myFrame.add(myLabel);
		myFrame.pack();  //espande il label su tutto il frame (credo (?))  (o fare frame.pack() oppure label.setBounds(.,.,.,.)) (da fare dopo aver fatto frame.add(label))
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//3.JPanel è una GUI component che funziona come contenitore per altre componenti: è un riquadro dove puoi mettere dei label nella posizione che vuoi
		
		/*
		ImageIcon iconBig = new ImageIcon("kurisu.png");
		ImageIcon icon = new ImageIcon(iconBig.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT));		
		
		JLabel label = new JLabel();
		label.setText("CIAO!!!!");
		label.setIcon(icon);
		label.setVerticalAlignment(JLabel.BOTTOM);
		label.setHorizontalAlignment(JLabel.RIGHT);
		
		
		JPanel panel1 = new JPanel();
		panel1.setBackground(Color.red);
		panel1.setBounds(0, 0, 250, 250);
		
		JPanel panel2 = new JPanel();
		panel2.setBackground(Color.blue);
		panel2.setBounds(250, 0, 250, 250);
		
		JPanel panel3 = new JPanel();
		panel3.setBackground(Color.green);
		panel3.setBounds(0, 250, 500, 250);
		panel3.setLayout(new BorderLayout());
		
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(null);
		frame.setSize(750,750);
		frame.setVisible(true);
		
		panel1.add(label);
		panel3.add(label);
		
		frame.add(panel1);
		frame.add(panel2);
		frame.add(panel3);
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//4.JButton è un bottone che fa un'azione quando lo clicchi
		
		
		//---------------------------------------------------------------------------------------------------------
		//Layout Manager definisce il layout naturale delle componenti in un contenitore
		//
		//5.BorderLayout serve per piazzare le componenti in 5 aree: NORTH, SOUTH, WEST, EAST, CENTER		
		
		/*
		JFrame frame = new JFrame();
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 500);
		frame.setLayout(new BorderLayout());
		frame.setVisible(true);
		
		JPanel panel1 = new JPanel();
		JPanel panel2 = new JPanel();
		JPanel panel3 = new JPanel();
		JPanel panel4 = new JPanel();
		JPanel panel5 = new JPanel();
		JPanel panel6 = new JPanel();
		
		panel1.setBackground(Color.red);
		panel2.setBackground(Color.green);
		panel3.setBackground(Color.yellow);
		panel4.setBackground(Color.magenta);
		panel5.setBackground(Color.blue);
		panel6.setBackground(Color.gray);
		
		panel5.setLayout(new BorderLayout());
		
		panel1.setPreferredSize(new Dimension(100, 100));
		panel2.setPreferredSize(new Dimension(100, 100));
		panel3.setPreferredSize(new Dimension(100, 100));
		panel4.setPreferredSize(new Dimension(100, 100));
		panel5.setPreferredSize(new Dimension(100, 100));
		panel6.setPreferredSize(new Dimension(50,50));
		
		panel5.add(panel6, BorderLayout.NORTH);
		
		frame.add(panel1, BorderLayout.NORTH);
		frame.add(panel2, BorderLayout.WEST);
		frame.add(panel3, BorderLayout.EAST);
		frame.add(panel4, BorderLayout.SOUTH);
		frame.add(panel5, BorderLayout.CENTER);
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//6.FlowLayout piazza le componenti in riga, se non c'è spazio va a capo
		
		/*
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500,500);
		frame.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 10)); //LEADING, CENTER, TRAILING
		
		JPanel panel = new JPanel();
		panel.setPreferredSize(new Dimension(250, 250));
		panel.setBackground(Color.lightGray);
		panel.setLayout(new FlowLayout());
		
		panel.add(new JButton("1"));
		panel.add(new JButton("2"));
		panel.add(new JButton("3"));
		panel.add(new JButton("4"));
		panel.add(new JButton("5"));
		panel.add(new JButton("6"));
		panel.add(new JButton("7"));
		panel.add(new JButton("8"));
		panel.add(new JButton("9"));
		
		frame.add(panel);
		frame.setVisible(true);
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//7.GridLayout piazza le componenti in una grid di celle, ogni componente prende tutto lo spazio possibile della sua cellae tutte le celle hanno equal size
		
		/*
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500,500);
		frame.setLayout(new GridLayout(3, 3, 10, 10)); //#righe, #colonne, margine orizzontale, margine verticale
		
		frame.add(new JButton("1"));
		frame.add(new JButton("2"));
		frame.add(new JButton("3"));
		frame.add(new JButton("4"));
		frame.add(new JButton("5"));
		frame.add(new JButton("6"));
		frame.add(new JButton("7"));
		frame.add(new JButton("8"));
		frame.add(new JButton("9"));
		
		frame.setVisible(true);
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//[LauchPage.java, NewWindow.java]
		//9.open a window with Swing
		
		/*
		LaunchPage launchPage = new LaunchPage();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//10.JOptionPane is a pop up standard dialogue box che compare e informa lo user di qualcosa
		
		/*
		//JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.PLAIN_MESSAGE);
		//JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.INFORMATION_MESSAGE);
		//JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.QUESTION_MESSAGE);
		//JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.WARNING_MESSAGE);
		//JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.ERROR_MESSAGE);
		
		//while (true) {
		//	JOptionPane.showMessageDialog(null, "HELLO YOUR COMPUTER HAS VIRUS!", "VAIRUS!", JOptionPane.WARNING_MESSAGE);
		//}
		
		//int answer = JOptionPane.showConfirmDialog(null, "hi", "title", JOptionPane.YES_NO_CANCEL_OPTION);
		//String name = JOptionPane.showInputDialog("what is your name?");
		
		//System.out.println(answer);
		//System.out.println(name);
		
		String[] responses = {"Ciao", "ciao", "", "vaffanculo"};
		ImageIcon iconBig = new ImageIcon("kurisu.png");
		ImageIcon icon = new ImageIcon(iconBig.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT));
		JOptionPane.showOptionDialog(null, "Ciao Liv", "message",
				JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.INFORMATION_MESSAGE, icon, responses, 0);
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame3.java]
		//11.JtextField is a GUI textbox component che si usa to set, get or get text
		
		/*
		MyFrame3 frame = new MyFrame3();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame4.java]
		//12.JCheckBox è una GUI component (Label, Panel, ...) che può essere selezionata o deselezionata
		
		/*
		new MyFrame4();
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame5.java]
		//13.JRadioButton è uno o più bottoni. Possono essere messi in un gruppo dove solo uno per gruppo può essere selezionato
		
		/*
		new MyFrame5();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame6.java]
		//14.JComboBox è una componente che combina un bottone e una drop-down list
		
		/*
		new MyFrame6();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[SliderDemo.java]
		//15.JSlider è una GUI component che fa selezionare allo user un valore attraverso uno slider
		
		/*
		SliderDemo sliderDemo = new SliderDemo();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[ProgressBarDemo.java]
		//16.JProgressBar
		
		/*
		ProgressBarDemo demo = new ProgressBarDemo();
		*/
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame17.java]
		//17.JMenuBar
		
		/*
		new MyFrame17();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame18.java]
		//18.JFileChooser is a GUI mechanism che lascia lo user scegliere un file (un po' come il programma "Esplora File")
		
		/*
		new MyFrame18();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame19.java]
		//19.JColorChooser è un GUI mechanism che fa scegliere allo user un colore
		
		/*
		new MyFrame19();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame20.java]
		//20.KeyListener
		
		/*
		new MyFrame20();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame21.java]
		//21.MouseLister
		
		/*
		new MyFrame21();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame22.java, DragPanel.java]
		//22.drag & drop
		
		/*
		MyFrame22 myFrame = new MyFrame22();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame24.java, MyPanel24.java]
		//24.2D Graphics
		
		/*
		new MyFrame24();
		*/
		
		
		//---------------------------------------------------------------------------------------------------------
		//[MyFrame25.java, MyPanel25.java]
		//25.2D Animations
		
		
		new MyFrame25();
		
		
		//new MyFrame2();
	}




}