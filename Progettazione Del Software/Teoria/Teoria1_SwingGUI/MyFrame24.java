import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JFrame;

public class MyFrame24 extends JFrame{
	
	MyPanel24 panel;
	
	MyFrame24(){
		
		panel = new MyPanel24();
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.add(panel);
		this.pack();
		this.setLocationRelativeTo(null); //fa apparire il frame al centro dello schermo
		this.setVisible(true);
	}
	
	
}