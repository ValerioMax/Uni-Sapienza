import java.awt.Color;
import java.awt.Image;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MyFrame21 extends JFrame implements MouseListener{

	JLabel label;
	ImageIcon icon1;
	ImageIcon icon2;
	
	MyFrame21(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(500, 500);
		this.setLayout(null);
		
		icon1 = new ImageIcon(new ImageIcon("kurisu.png").getImage().getScaledInstance(170, 170, Image.SCALE_DEFAULT));
		icon2 = new ImageIcon(new ImageIcon("kurisu2.png").getImage().getScaledInstance(170, 170, Image.SCALE_DEFAULT));
		
		label = new JLabel();
		label.setBounds(0, 0, 170, 170);
		label.setIcon(icon1);
		//label.setBackground(Color.red);
		//label.setOpaque(true);
		label.addMouseListener(this); //come al solito gli posso passare solo this perché MyFrame21 implementa MouseListener
		
		this.add(label);
		this.setVisible(true);
	}

	@Override
	public void mouseClicked(MouseEvent e) { //Invocato quando un mouse button cliccato (pressed and released) + * = (sulla componente o frame al quale è applicato l'action listener)
		
		System.out.println("You clicked the mouse");		
	}

	@Override
	public void mousePressed(MouseEvent e) { //Invocato quando un mouse button pressed su una componente + *
		
		System.out.println("You pressed the mouse");
		label.setBackground(Color.yellow);
	}

	@Override
	public void mouseReleased(MouseEvent e) { //Invocato quando mouse button released su una componente + *
		
		System.out.println("You released the mouse");
		label.setBackground(Color.green);
	}

	@Override
	public void mouseEntered(MouseEvent e) { //Invocato quando il cursore entra (passa sopra) su una componente + *
		
		System.out.println("You entered the component");
		label.setBackground(Color.blue);
		label.setIcon(icon2);
		
	}

	@Override
	public void mouseExited(MouseEvent e) { //Invocato quando il cursore esce (va fuori dopo che ci è passata sopra) da una componente + *
		
		System.out.println("You exited the component");
		label.setBackground(Color.red);
		label.setIcon(icon1);
	}
}
