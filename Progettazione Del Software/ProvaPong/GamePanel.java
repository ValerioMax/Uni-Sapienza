import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;

public class GamePanel extends JPanel implements Runnable{
	
	//dimensione gamePanel (e anche frame facendo pack)
	int panelX = 1280;
	int panelY = 720;
	
	int FPS = 60;
	
	KeyHandler keyH = new KeyHandler();
	Thread gameThread;
	
	//ball default specifics
	int ballX = 100;
	int ballY = 100;
	int ballXSpeed = 15;
	int ballYSpeed = 7;
	int ballSize = 30;
	
	//bar1 default specifics
	int bar1X = 80;
	int bar1Y = 30;
	int bar1YSpeed = 7;
	int bar1XSize = 20;
	int bar1YSize = 200;
	int punti1 = 0;
	
	//bar2 default specifics
	int bar2X = panelX - 80;
	int bar2Y = 30;
	int bar2YSpeed = 7;
	int bar2XSize = 20;
	int bar2YSize = 200;
	int punti2;
	
	JLabel labelN;
	JLabel label1;
	JLabel label2;
	
	int boost = 0;
	
	GamePanel(){
		this.setPreferredSize(new Dimension(panelX, panelY));
		this.setBackground(Color.black);
		this.setDoubleBuffered(true); //cosa fa?
		this.addKeyListener(keyH);
		this.setFocusable(true);
		this.setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBounds(panelX/2 - 100, 50, 200, 50);
		panel.setBackground(Color.LIGHT_GRAY);
		panel.setLayout(new GridLayout(2,1));
			labelN = new JLabel("PUNTEGGIO:");
			labelN.setHorizontalAlignment(JLabel.CENTER);
			labelN.setFont(new Font("Bank Gothic", Font.BOLD, 30));
			labelN.setForeground(Color.black);
			//labelN.setPreferredSize(new Dimension(panelX/2 - 100, 20));
			JPanel panel1 = new JPanel();
			panel1.setLayout(new GridLayout(1,2));
				label1 = new JLabel();
				label1.setText("P1: " + punti1);
				label1.setHorizontalAlignment(JLabel.CENTER);
				label1.setFont(new Font("Bank Gothic", Font.BOLD, 30));
				label1.setForeground(Color.red);
				label2 = new JLabel();
				label2.setText("P2: " + punti2);
				label2.setHorizontalAlignment(JLabel.CENTER);
				label2.setFont(new Font("Bank Gothic", Font.BOLD, 30));
				label2.setForeground(Color.blue);
			panel1.add(label1);
			panel1.add(label2);
		panel.add(labelN);
		panel.add(panel1);
			
		this.add(panel);
		
		Thread gameThread;
		
	}

	public void startGameThread() throws InterruptedException {
		gameThread = new Thread(this);
		gameThread.start();
		gameThread.join();
	}
	
	@Override
	public void run() {
		
		double drawInterval = 1000000000/FPS; //0.01666 secondi
		double nextDrawTime = System.nanoTime() + drawInterval;
		
		int drawCount = 0;
		long delta = 0;
		
		while (gameThread != null) { //Tutto il gioco gira sul fatto che ho creato un thread (gameThread) che chiama il metodo run che permette di entrare nel ciclo infinito e nel meccanismo di update()/refresh() ogni 0.0166 secondi
									 //il thread fa ricorso a questo metodo run() qui nella classe GamePanel perchè ho passato this a Thread (gameThread = new Thread(this);) e inoltre sto facendo l'Override di run()
									 //gameThread != null è semplicemente un modo per avere un ciclo infinito: gameThread non sarà mai = null (neanche quando finisce le sue operazioni) a meno che non sono io a impostarlo
			update();
			repaint();
			
			try {
				double remainingTime = nextDrawTime - System.nanoTime();
				remainingTime /= 1000000;
				
				if (remainingTime < 0) {
					remainingTime = 0;
				}
				
				Thread.sleep((long) remainingTime);
				
				nextDrawTime += drawInterval;
				
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			delta += drawInterval;
			drawCount++;
			
			if (delta >= 1000000000) {
				//System.out.println("FPS: " + drawCount);
				drawCount = 0;
				delta = 0;
			}
			
			
		}
		
	}
	
	public void update() {
		if (punti1 == 10 || punti2 == 10) {
			gameThread = null;
		}
		if (punti1 == 10) {
			//new FinalFrame(true);
		}
		else if (punti2 == 10) {
			//new FinalFrame(false);
		}
		
		if (keyH.cheat) {
			
		}
		
		if (punti1 == 5)
			bar1YSpeed = 5;
		if (punti1 == 8)
			bar2YSpeed = 3;
		if (punti2 == 5)
			bar1YSpeed = 5;
		if (punti2 == 8)
			bar2YSpeed = 3;
		
		if (bar1Y > 0 && keyH.up1Pressed == true)
			bar1Y -= bar1YSpeed;
		if (bar1Y + bar1YSize < panelY && keyH.down1Pressed == true)
			bar1Y += bar1YSpeed;
		if (bar2Y >= 0 && keyH.up2Pressed == true)
			bar2Y -= bar2YSpeed;
		if (bar2Y + bar2YSize < panelY && keyH.down2Pressed == true)
			bar2Y += bar2YSpeed;
		
		if (ballX >= panelX - ballSize) {
			ballXSpeed *= -1;
			punti1++;
			label1.setText("P1: " + punti1);
		}
		else if (ballX <= 0) {
			ballXSpeed *= -1;
			punti2++;
			label2.setText("P2: " + punti2);
		}
		else if (ballY >= panelY - ballSize || ballY <= 0) {
			ballYSpeed *= -1;
		}
		
		ballX += ballXSpeed;
		ballY += ballYSpeed;
		
		if (keyH.cheat && (ballX - bar1XSize < bar1X || (ballX + ballSize > bar2X && ballY + ballSize > bar2Y && ballY < bar2Y + bar2YSize/2)))
			ballXSpeed *= -1;

			
		
		else if ((ballX - bar1XSize < bar1X && ballY + ballSize > bar1Y && ballY < bar1Y + bar1YSize)
				|| (ballX + ballSize > bar2X && ballY + ballSize > bar2Y && ballY < bar2Y + bar2YSize)) {
			ballXSpeed *= -1;
		}
		
		
		
		
		
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		Graphics2D g2 = (Graphics2D) g;
		
		
		if (keyH.cheat) {
			g2.setColor(Color.red);
			g2.fillRect(bar1X, 0, bar1XSize, panelY);
			g2.setColor(Color.yellow);
			g2.fillRect(ballX, ballY, ballSize, ballSize);
			g2.setColor(Color.blue);
			g2.fillRect(bar2X, bar2Y, bar2XSize, bar2YSize/2);
			
		}
		else {
			g2.setColor(Color.yellow);
			g2.fillRect(ballX, ballY, ballSize, ballSize);
			g2.setColor(Color.red);
			g2.fillRect(bar1X, bar1Y, bar1XSize, bar1YSize);
			g2.setColor(Color.blue);
			g2.fillRect(bar2X, bar2Y, bar2XSize, bar2YSize);
			
		}
		
		
		
		
	
		//g2.dispose(); //come funziona?, se lo metto non mi fa vedere gli altri panel.
	}
	
}
