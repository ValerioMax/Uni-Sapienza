import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class MyFrame3 extends JFrame implements ActionListener{

	JButton button;  //li dichiaro come variabili globali perché nel metodo actionPerformed() vado a usare textField che non avrei potuto usare se l'avessi dichiarata nel costruttore
	JTextField textField;
	
	MyFrame3(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		
		button = new JButton("Submit");
		button.addActionListener(this);
		
		textField = new JTextField();
		textField.setPreferredSize(new Dimension(250,40));
		textField.setFont(new Font("Times New Roman", Font.PLAIN, 20));
		textField.setForeground(Color.green);
		textField.setBackground(Color.black);
		textField.setCaretColor(new Color(150, 20, 250));  //il colore della barra di posizione
		textField.setText("insert username here"); //la scritta che c'è di base
		//textField.setEditable(false);  //fa/nonFa editare il testo
		
		this.add(button);
		this.add(textField);
		this.pack();
		this.setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			System.out.println("Hai submittato la frase: " + textField.getText());
		}
		
	}

}
