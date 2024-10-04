import javax.swing.JFrame;

public class MyFrame25 extends JFrame{
	
	MyPanel25 panel;
	
	MyFrame25(){
		
		panel = new MyPanel25();
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.add(panel);
		this.pack();
		this.setLocationRelativeTo(null); //fa apparire il frame al centro dello schermo
		this.setVisible(true);
	}
	
	
}