import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JRadioButton;

//NOTA: Non posso fare una lista di dati primitivi => se li voglio usare devo usare le wrapper classes (es: int -> Integer)
public class MyFrame6 extends JFrame implements ActionListener{

	JComboBox comboBox;
	
	MyFrame6(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		
		//NOTA: Non posso fare una lista di dati primitivi => se li voglio usare devo usare le wrapper classes (es: int -> Integer)
		String[] animals = {"dog", "cat", "kurisu"};
		comboBox = new JComboBox(animals);
		comboBox.addActionListener(this);
		
		//comboBox.setEditable(true); //fa editare il contenuto della box e se non è nella lista lo prende come se fosse all'indice -1
		//System.out.println(comboBox.getItemCount()); //printa il numero di elementi nella lista
		//comboBox.addItem("horse"); //aggiunge alla fine
		comboBox.insertItemAt("pig", 0); //aggiunge all'indice specificato
		comboBox.setSelectedIndex(0); //fa partire la Box dall indice specificato
		//comboBox.removeItem("cat");
		//comboBox.removeItemAt(1);
		//comboBox.removeAllItems();
		
		this.add(comboBox);
		this.pack();
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		if (e.getSource() == comboBox) {
			System.out.println(comboBox.getSelectedItem());
			System.out.println(comboBox.getSelectedIndex());
		}
	}
}
