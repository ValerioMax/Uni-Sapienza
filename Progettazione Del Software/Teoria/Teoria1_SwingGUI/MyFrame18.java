import java.awt.*;
import java.awt.event.*;
import java.io.File;

import javax.swing.*;

public class MyFrame18 extends JFrame implements ActionListener{

	JButton button;
	
	MyFrame18(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		
		button = new JButton("Select File");
		button.addActionListener(this);
		
		this.add(button);
		this.pack();
		this.setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			
			JFileChooser fileChooser = new JFileChooser();
			
			fileChooser.setCurrentDirectory(new File("C:\\Users\\ValerioMassimo\\Desktop")); //imposta la directory da cui parte il fileChooser appena si apre (NOTA: "." è la current directory)
			
			//int response = fileChooser.showOpenDialog(null); //seleziona i file da aprire, ritorna 0 se poi fai "Open", 1 se clicchi sulla x oppure su "Cancel"
			int response = fileChooser.showSaveDialog(null); //seleziona i file da salvare
			
			if (response == JFileChooser.APPROVE_OPTION) { //come dire response == 0
				File file = new File(fileChooser.getSelectedFile().getAbsolutePath());
				System.out.println(file);
			}
			
		}
		
	}

}
