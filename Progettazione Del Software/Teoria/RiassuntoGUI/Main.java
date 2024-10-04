import java.awt.*;
import java.awt.event.*;
import java.io.File;

import javax.swing.*;
import javax.swing.border.Border;

public class Main {

	public void componenti() {
		//JFrame, JLabel, JPanel, JButton, JOptionPane, JTextField, JCheckBox, JRadioButton, JComboBox, JSlider, JProgressBar, JMenuBar, JFileChooser, JColorChooser
		
		//METODI UTILI:
		//JFrame:
		this.setTitle("TITOLO!!!");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //EXIT_ON_CLOSE, HIDE_ON_CLOSE, DO_NOTHING_ON_CLOSE
		.this.setLayout(null); //null
							   //"new BorderLayout()". Piazza le componenti in 5 aree: NORTH, SOUTH, WEST, EAST, CENTER,
							   //"new FlowLayout(FlowLayout.CENTER, 20, 10)" LEADING, CENTER, TRAILING. Piazza le componenti in riga, se non c'è spazio va a capo
							   //"new GridLayout(3, 3, 10, 10)" #righe, #colonne, margine orizzontale, margine verticale. Piazza le componenti in una grid di celle, ogni componente prende tutto lo spazio possibile della sua cellae tutte le celle hanno equal size
		this.setSize(500,500);
		this.setResizable(false);
		this.setVisible(true);
		this.setIconImage(image.getImage());
		myFrame.pack();  //espande il label su tutto il frame (credo (?))  (o fare frame.pack() oppure label.setBounds(.,.,.,.)) (da fare dopo aver fatto frame.add(label))
		
		
		//JLabel
		.this.setText("Ciao come va?");  //setta il text del label
		this.setIcon(image);
		this.setHorizontalTextPosition(JLabel.CENTER);  //CENTER, LEFT, RIGHT dell'imageIcon
		.this.setVerticalTextPosition(JLabel.TOP);  //TOP, CENTER, BOTTOM dell'imageIcon
		.this.setForeground(new Color(120,50,200));  //cambia colore del testo
		.this.setFont(new Font("MV Boli", Font.ITALIC, 50)); //cambia font e dimensione
		this.setIconTextGap(10);
		.this.setBackground(Color.black);
		this.setOpaque(true);
		.Border border = BorderFactory.createLineBorder(Color.red, 3);
		.this.setBorder(border);
		this.setVerticalAlignment(JLabel.CENTER);  //setta la posizione dell'icon+text dentro al label
		this.setHorizontalAlignment(JLabel.CENTER); //uguale
		.this.setBounds(100, 100, 400, 400);  //setta le coord. dove mettere il label e le dimensioni del label
		
		
		//JPanel
		.panel1.setBackground(Color.red);
		.panel1.setBounds(0, 0, 250, 250);
		.panel3.setLayout(new BorderLayout());
		panel1.setPreferredSize(new Dimension(100, 100));
		
		
		//JButton
		.button.setBounds(200, 100, 200, 100);
		button.addActionListener(this); //aggiungere un ActionListenere relativo al frame "this" al bottone. Questo ActionLinstener poi fa ricorso al metodo actionPerformed() (credo (?))
		.button.setText("Cliccami!");
		button.setFocusable(false);
		.button.setIcon(icon);
		.button.setFont(new Font("Comic Sans", Font.BOLD, 20));
		.button.setForeground(new Color(150,50,250));
		.button.setBackground(Color.LIGHT_GRAY);
		.button.setBorder(BorderFactory.createEtchedBorder());
		button.setEnabled(false);  //abilita/disabilita il bottone, NOTA: se lo uso nella funzione actionPerformed(e) posso ad esempio fare un contatore che disabilita il bottone dopo k clicks
		@Override
		public void actionPerformed(ActionEvent e) {
			if (e.getSource() == button) {
				System.out.println("Hai submittato la frase: " + textField.getText());
			}
		}
		
		
		//JOptionPane (non va creato come gli altri basta usare il metodo direttamente)
		JOptionPane.showMessageDialog(null, "Stai attento", "ATTENZIONE!", JOptionPane.PLAIN_MESSAGE); //PLAIN_MESSAGE, INFORMATION_MESSAGE, QUESTION_MESSAGE, WARNING_MESSAGE, ERROR_MESSAGE
		int answer = JOptionPane.showConfirmDialog(null, "hi", "title", JOptionPane.YES_NO_CANCEL_OPTION);
		String name = JOptionPane.showInputDialog("what is your name?");
		String[] responses = {"Ciao", "ciao", "", "vaffanculo"};
		JOptionPane.showOptionDialog(null, "Ciao Liv", "message",
				JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.INFORMATION_MESSAGE, icon, responses, 0);
		
		
		//JTextField
		.textField.setPreferredSize(new Dimension(250,40));
		.textField.setFont(new Font("Times New Roman", Font.PLAIN, 20));
		.textField.setForeground(Color.green);
		.textField.setBackground(Color.black);
		textField.setCaretColor(new Color(150, 20, 250));  //il colore della barra di posizione
		textField.setText("insert username here"); //la scritta che c'è di base
		textField.setEditable(false);  //fa/nonFa editare il testo
		
		
		//JCheckBox
		checkBox = new JCheckBox();
		checkBox.setText("I'm not a robot");
		checkBox.setFocusable(false); //elimina/mette il riquadro brutto attorno al testo
		checkBox.setFont(new Font("Consolas", Font.PLAIN, 25));
		checkBox.setIcon(icon1);
		checkBox.setSelectedIcon(icon2);
		boolean bool = checkBox.isSelected();
		
		
		//JRadioButton
		ButtonGroup group = new ButtonGroup();
		group.add(radioButton1);
		radioButton1.addActionListener(this);
		
		
		//JComboBox
		String[] animals = {"dog", "cat", "kurisu"};
		comboBox = new JComboBox(animals);
		comboBox.addActionListener(this);
		comboBox.setEditable(true); //fa editare il contenuto della box e se non è nella lista lo prende come se fosse all'indice -1
		System.out.println(comboBox.getItemCount()); //printa il numero di elementi nella lista
		comboBox.addItem("horse"); //aggiunge alla fine
		comboBox.insertItemAt("pig", 0); //aggiunge all'indice specificato
		comboBox.setSelectedIndex(0); //fa partire la Box dall indice specificato
		comboBox.removeItem("cat");
		comboBox.removeItemAt(1);
		comboBox.removeAllItems();

		
		
		
		
		
		
		
		
		
		
		*.add(°);
		ImageIcon image = new ImageIcon("kurisu.png");
	}
}
