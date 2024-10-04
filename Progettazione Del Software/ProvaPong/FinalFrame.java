import javax.swing.JFrame;
import javax.swing.JLabel;

public class FinalFrame extends JFrame{
	FinalFrame(boolean bool) {
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setSize(300, 200);
		
		
		if (bool) {
			this.setTitle("VINCE P1!");
			this.add(new JLabel("VITTORIA DI P1!"));
		}
		else {
			this.setTitle("VINCE P2!");
			this.add(new JLabel("VITTORIA DI P1!"));
		}
		
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
}
