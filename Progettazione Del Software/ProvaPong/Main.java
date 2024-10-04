import javax.swing.JFrame;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setResizable(false);
		frame.setTitle("PONG");
		
		GamePanel gamePanel = new GamePanel();
		
		frame.add(gamePanel);
		frame.pack();
		
		frame.setLocationRelativeTo(null);
		frame.setVisible(true);
		
		gamePanel.startGameThread(); //metodo definito in GamePanel
		
		frame.dispose();
		//come faccio a chiudere questo frame dal GamePanel
		//mia idea: si setta gameThread.join() in startGameThread() in questo modo solo quando il gameThread morirà (terminerà) il main thread procederà a eseguire le operazioni successive a .startGameThread(): frame.dispose()
		//[quando si vuole far finire il gioco si imposta gameThread = null => il ciclo infinito si interrompe => gameThread muore => finisce l'azione di .join() => main thread fa frame.dispose()]
		
	}

}
