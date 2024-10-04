import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class MyFrame extends JFrame {

	MyFrame() {
		//this.setTitle("TITOLO!!!");  //setta il titolo del frame
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);			//exit application quando clicco sul pulsante x
		//this.setDefaultCloseOperation(Jthis.HIDE_ON_CLOSE);			//nasconde la finestra ma non chiude l'applicazione
		//this.setDefaultCloseOperation(Jthis.DO_NOTHING_ON_CLOSE);	//do nothing
		//this.setResizable(false);  //non fa fare il resize
		this.setLayout(null);
		this.setSize(500,500);  //setta la dimensione su x e y
		//this.setLayout(null);  //?
		this.setVisible(true); //rende il frame visibile
		
		ImageIcon image = new ImageIcon("kurisu.png"); //crea una ImageIcon
		this.setIconImage(image.getImage()); //cambia l'immagine del frame
		//this.getContentPane().setBackground(new Color(250,250,250)); //background color
	}
	
}
