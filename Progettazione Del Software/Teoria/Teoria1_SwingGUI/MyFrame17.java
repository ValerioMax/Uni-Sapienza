import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyFrame17 extends JFrame implements ActionListener{

	JMenuBar menuBar;
	JMenu fileMenu;
	JMenu editMenu;
	JMenu helpMenu;
	JMenuItem loadItem;
	JMenuItem saveItem;
	JMenuItem exitItem;
	ImageIcon iconBig;
	ImageIcon icon;
	
	MyFrame17(){
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(500, 500);
		this.setLayout(new FlowLayout());
		
		iconBig = new ImageIcon("kurisu.png");
		icon = new ImageIcon(iconBig.getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT));
		
		menuBar = new JMenuBar(); //crea una Menu Bar come quelle di Word o Eclipse (es: File, Edit, Source, Refactor, ...)
		
		fileMenu = new JMenu("File");
		editMenu = new JMenu("Edit");
		helpMenu = new JMenu("Help");
		
		loadItem = new JMenuItem("Load");
		saveItem = new JMenuItem("Save");
		exitItem = new JMenuItem("Exit");
		
		loadItem.addActionListener(this);
		saveItem.addActionListener(this);
		exitItem.addActionListener(this);
		
		//Shortcut per raggiungere i vari menu
		fileMenu.setMnemonic(KeyEvent.VK_F); //shortcut: Alt + f   per fare selezionare fileMenu
		editMenu.setMnemonic(KeyEvent.VK_I); //shortcut: Alt + i   per fare selezionare editMenu
		helpMenu.setMnemonic(KeyEvent.VK_H); //shortcut: Alt + h   per fare selezionare helpMenu
		//Shortcut per raggiungere i vari item una volta che ho selezionato fileMenu
		loadItem.setMnemonic(KeyEvent.VK_L); //shortcut: l   per fare selezionare loadItem
		saveItem.setMnemonic(KeyEvent.VK_S); //shortcut: s   per fare selezionare saveItem
		exitItem.setMnemonic(KeyEvent.VK_E); //shortcut: e   per fare selezionare exitItem
		
		loadItem.setIcon(icon);
		
		fileMenu.add(loadItem);
		fileMenu.add(saveItem);
		fileMenu.add(exitItem);
		
		menuBar.add(fileMenu);
		menuBar.add(editMenu);
		menuBar.add(helpMenu);
		
		this.setJMenuBar(menuBar);
		this.setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == loadItem) {
			System.out.println("You Loaded the file");
		}
		if (e.getSource() == saveItem) {
			System.out.println("You Saved the file");
		}
		if (e.getSource() == exitItem) {
			System.exit(0);
		}
		
	}

}
