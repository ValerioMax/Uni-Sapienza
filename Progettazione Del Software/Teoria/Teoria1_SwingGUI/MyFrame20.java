import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MyFrame20 extends JFrame implements KeyListener{

	JLabel label;
	ImageIcon iconBig;
	ImageIcon icon;
	
	MyFrame20(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(500, 500);
		this.setLayout(null);
		
		this.addKeyListener(this);
		
		iconBig = new ImageIcon("kurisu.png");
		icon = new ImageIcon(iconBig.getImage().getScaledInstance(170, 170, Image.SCALE_DEFAULT));
		
		label = new JLabel();
		label.setBounds(0, 0, 170, 170);
		label.setIcon(icon);
		//label.setBackground(Color.red);
		//label.setOpaque(true);
		
		//this.getContentPane().setBackground(new Color(150, 20, 255));
		this.add(label);
		this.setVisible(true);
	}
	
	//Posso usare uno di questi tre metodi oppure più in combinazione. Ad es. per le freccette direzionali usero keyPressed perché non esiste il keyChar di queste, mentre per wasd posso usare keyTyped
	@Override
	public void keyTyped(KeyEvent e) { //Invocato quando un char viene scritto. Usa un KeyChar (è il char stesso) e da un char in output
		
		switch (e.getKeyChar()) {
			case 'a': label.setLocation(label.getX() - 10, label.getY());
				break;
			case 'w': label.setLocation(label.getX(), label.getY() - 10);
				break;
			case 's': label.setLocation(label.getX(), label.getY() + 10);
				break;
			case 'd': label.setLocation(label.getX() + 10, label.getY());
				break;
		}
	}

	@Override
	public void keyPressed(KeyEvent e) { //Invocato quando il tasto fisico è cliccato. Usa un KeyCode (è un codice (tipo il codice ASCII) relativo al tasto (NON AL CHAR, infatti KeyCode di "a" e "A" è lo stesso)) e da un int in output
		switch (e.getKeyCode()) {
			case 37: label.setLocation(label.getX() - 10, label.getY());
				break;
			case 38: label.setLocation(label.getX(), label.getY() - 10);
				break;
			case 40: label.setLocation(label.getX(), label.getY() + 10);
				break;
			case 39: label.setLocation(label.getX() + 10, label.getY());
				break;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) { //Invocato quando il tasto è rilasciato.
		System.out.println("You released key char: " + e.getKeyChar());
		System.out.println("You released key code: " + e.getKeyCode());
		
	}

}
