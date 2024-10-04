import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MyFrame2 extends JFrame implements ActionListener{
	
	JButton button;
	JLabel label;
	
	MyFrame2(){
		
		ImageIcon icona = new ImageIcon("kurisu.png");
		ImageIcon icon = new ImageIcon(icona.getImage().getScaledInstance(75, 75, Image.SCALE_DEFAULT));
		
		label = new JLabel();
		label.setBounds(150, 250, 150, 150);
		label.setIcon(icon);
		label.setVisible(false);
		
		button = new JButton();
		button.setBounds(200, 100, 200, 100);
		button.addActionListener(this); //aggiungere un ActionListenere relativo al frame "this" al bottone. Questo ActionLinstener poi fa ricorso al metodo actionPerformed() (credo (?))
		button.setText("Cliccami!");
		button.setFocusable(false);
		button.setIcon(icon);
		button.setFont(new Font("Comic Sans", Font.BOLD, 20));
		button.setForeground(new Color(150,50,250));
		button.setBackground(Color.LIGHT_GRAY);
		button.setBorder(BorderFactory.createEtchedBorder());
		//button.setEnabled(false);  //disabilita il bottone, NOTA: se lo uso nella funzione actionPerformed(e) posso ad esempio fare un contatore che disabilita il bottone dopo k clicks
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(null);
		this.setSize(500,500);
		this.setVisible(true);
		
		this.add(button);
		this.add(label);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			System.out.println("Ciao!");
			label.setVisible(true);
		}
	}

}
