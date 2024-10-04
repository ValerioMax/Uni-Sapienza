import java.awt.Color;
import java.awt.Font;
import java.awt.Image;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.border.Border;

public class MyLabel extends JLabel{
	
	MyLabel()	{
		ImageIcon image = new ImageIcon("kurisu.png");
		ImageIcon image1 = new ImageIcon(image.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT)); //fa lo scale dell'immagine
		Border border = BorderFactory.createLineBorder(Color.red, 3);
		
		this.setText("Ciao come va?");  //setta il text del label
		this.setIcon(image1);
		this.setHorizontalTextPosition(JLabel.CENTER);  //setta il testo al CENTER, LEFT, RIGHT dell'imageIcon
		this.setVerticalTextPosition(JLabel.TOP);  //TOP, CENTER, BOTTOM dell'imageIcon
		this.setForeground(new Color(120,50,200));  //cambia colore del testo
		this.setFont(new Font("MV Boli", Font.ITALIC, 50)); //cambia font e dimensione
		this.setIconTextGap(10);
		this.setBackground(Color.black);
		this.setOpaque(true);
		this.setBorder(border);
		this.setVerticalAlignment(JLabel.CENTER);  //setta la posizione dell'icon+text dentro al label
		this.setHorizontalAlignment(JLabel.CENTER); //uguale
		//this.setBounds(100, 100, 400, 400);  //setta le coord. dove mettere il label e le dimensioni del label
	}
}
