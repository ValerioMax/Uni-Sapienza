import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class MyPanel24 extends JPanel{
	
	Image image;
	
	MyPanel24(){
		
		image = new ImageIcon("kurisu.png").getImage();
		this.setPreferredSize(new Dimension(500, 500));
	}
	
	public void paint(Graphics g) { //il metodo paint serve per paintare il contenuto di un componente (NOTA: ogni metodo/funzione grafico/a contiene la funzione paint(da quello che ho capito) (?))
		
		Graphics2D g2D = (Graphics2D) g;
		
		g2D.setPaint(Color.blue);
		g2D.setStroke(new BasicStroke(5));
		g2D.drawLine(0, 0, 500, 500);
		
		g2D.setPaint(Color.pink);
		g2D.drawRect(0, 0, 100, 100);
		g2D.fillRect(0, 0, 100, 100);
		
		g2D.setPaint(Color.orange);
		g2D.drawOval(0, 0, 100, 100);
	
		g2D.setPaint(Color.BLACK);
		g2D.drawArc(0, 0, 100, 100, 0, 300);
		
		int[] xPoints = {150, 250, 350};
		int[] yPoints = {300, 150, 300};
		//g2D.drawPolygon(xPoints, yPoints, 3);
		g2D.fillPolygon(xPoints, yPoints, 3);
		
		g2D.setFont(new Font("Ink Free", Font.BOLD, 50));
		g2D.drawString("CIAOOOOO come va?", 50, 50);
		
		g2D.drawImage(image, 0, 0, null);
	}
}
