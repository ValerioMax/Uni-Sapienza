import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;

public class MyFrame4 extends JFrame implements ActionListener{
	
	JButton button;
	JCheckBox checkBox;
	ImageIcon iconBig1;
	ImageIcon icon1;
	ImageIcon iconBig2;
	ImageIcon icon2;
	
	MyFrame4(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		
		iconBig1 = new ImageIcon("kurisu.png");
		icon1 = new ImageIcon(iconBig1.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT));
		iconBig2 = new ImageIcon("kurisu3.png");
		icon2 = new ImageIcon(iconBig2.getImage().getScaledInstance(100, 100, Image.SCALE_DEFAULT));
		
		button = new JButton();
		button.setText("submit");
		button.addActionListener(this);
		
		checkBox = new JCheckBox();
		checkBox.setText("I'm not a robot");
		checkBox.setFocusable(false); //elimina/mette il riquadro brutto attorno al testo
		checkBox.setFont(new Font("Consolas", Font.PLAIN, 25));
		checkBox.setIcon(icon1);
		checkBox.setSelectedIcon(icon2); //(Non l'ha presa)
		
		this.add(button);
		this.add(checkBox);
		this.pack();
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			System.out.println(checkBox.isSelected());
		}
		
	}

}
