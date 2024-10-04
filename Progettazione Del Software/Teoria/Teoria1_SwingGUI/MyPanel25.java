import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyPanel25 extends JPanel implements ActionListener{
	
	final int PANEL_WIDTH = 1200;
	final int PANEL_HEIGHT = 800;
	
	Image image;
	Timer timer;
	int xVelocity = 2;
	int yVelocity = 3;
	int x = 0;
	int y = 0;
	
	MyPanel25(){
		this.setPreferredSize(new Dimension(PANEL_WIDTH, PANEL_HEIGHT));
		this.setBackground(Color.black);
		image = new ImageIcon(new ImageIcon("kurisu.png").getImage().getScaledInstance(300, 300, Image.SCALE_DEFAULT)).getImage();
		timer = new Timer(1000, this); //every 10 ms it performs an action invoking actionPerformed() method (oppure fa tutti i metodi che ci sono? perché fa anche paint())(?)
		timer.start(); //fa startare il timer
	}
	
	public void paint(Graphics g) {
		
		super.paint(g); //fa il paint del background (?)		
		Graphics2D g2D = (Graphics2D) g;
		
		g2D.drawImage(image, x, y, null);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		
		if (x >= PANEL_WIDTH - image.getWidth(null)) {
			xVelocity *= -1;
			this.setBackground(new Color(200, 20, 250));
		}
		if (x < 0) {
			xVelocity *= -1;
			this.setBackground(new Color(200, 10, 10));
		}
		
		x = x + xVelocity;
		
		if (y >= PANEL_HEIGHT - image.getHeight(null)) {
			yVelocity *= -1;
			this.setBackground(Color.blue);
		}
		if (y < 0) {
			yVelocity *= -1;
			this.setBackground(Color.green);
		}
		
		y = y + yVelocity;
		
		repaint(); //devo usare repaint perché una volta chiamato paint non posso richiamare paint (?)
	}
}
