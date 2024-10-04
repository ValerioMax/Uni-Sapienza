import java.awt.*;
import javax.swing.*;

public class ProgressBarDemo {

	JFrame frame = new JFrame();
	JProgressBar bar = new JProgressBar(0, 150);
	
	ProgressBarDemo(){
		
		bar.setValue(0);
		bar.setBounds(0, 0, 420, 50);
		bar.setStringPainted(true);
		bar.setFont(new Font("MV Boli", Font.BOLD, 25));
		bar.setForeground(Color.red);
		bar.setBackground(Color.BLACK);
		
		frame.add(bar);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(420, 420);
		frame.setLayout(null); //in certe situazioni è utile in altre è utile mettere null e fare tutto da soli
		frame.setVisible(true);
		
		fill2();
	}
	
	public void fill1() { //creato da noi
		int counter = 0;
		while (counter <= 150) {
			bar.setValue(counter);
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			counter += 1;
		}
		bar.setString("Done!");
	}
	
	public void fill2() { //creato da noi
		int counter = 150;
		while (counter > 0) {
			bar.setValue(counter);
			try {
				Thread.sleep(50);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			counter -= 1;
		}
		bar.setString("DEAD!");
	}
}
