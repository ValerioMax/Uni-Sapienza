import javax.swing.JFrame;

public class MyFrame22 extends JFrame{
	
	DragPanel dragPanel = new DragPanel();
	
	MyFrame22(){
		this.add(dragPanel);
		this.setTitle("Drag & Drop demo");
		this.setSize(600, 600);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
}
