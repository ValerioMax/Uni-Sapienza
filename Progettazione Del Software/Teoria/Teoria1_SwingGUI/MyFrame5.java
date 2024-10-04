import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JRadioButton;

public class MyFrame5 extends JFrame implements ActionListener{

	JRadioButton button1;
	JRadioButton button2;
	JRadioButton button3;
	ImageIcon iconBig;
	ImageIcon icon;
	
	MyFrame5(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		
		iconBig = new ImageIcon("kurisu.png");
		icon = new ImageIcon(iconBig.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT));
		
		button1 = new JRadioButton("pizza");
		button2 = new JRadioButton("hamburger");
		button3 = new JRadioButton("kurisu");
		
		ButtonGroup group = new ButtonGroup();
		group.add(button1);
		group.add(button2);
		group.add(button3);
		
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		
		button3.setIcon(icon);
		
		this.add(button1);
		this.add(button2);
		this.add(button3);
		this.pack();
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button1) {
			System.out.println("hai ordianto la pizza!");
		}
		else if (e.getSource() == button2) {
			System.out.println("hai ordianto un hamburger!");
		}
		else if (e.getSource() == button3) {
			System.out.println("hai ordianto una Kurisu Makise! <3");
		}
		
	}
}
