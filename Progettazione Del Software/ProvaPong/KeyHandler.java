import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyHandler implements KeyListener{

	public boolean up1Pressed, down1Pressed, up2Pressed, down2Pressed;
	public boolean cheat = false;
	
	@Override
	public void keyTyped(KeyEvent e) {
	}

	@Override
	public void keyPressed(KeyEvent e) {
		int code = e.getKeyCode();
		
		if (code == KeyEvent.VK_W) {
			up1Pressed = true;
		}
		if (code == KeyEvent.VK_S) {
			down1Pressed = true;
		}
		if (code == KeyEvent.VK_P) {
			up2Pressed = true;
		}
		if (code == KeyEvent.VK_L) {
			down2Pressed = true;
		}
		
		//cheat per P1
		if (cheat == false && code == KeyEvent.VK_1) {
			cheat = true;
		}
		else if (cheat == true && code == KeyEvent.VK_1) {
			cheat = false;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		
		int code = e.getKeyCode();
		
		if (code == KeyEvent.VK_W) {
			up1Pressed = false;
		}
		if (code == KeyEvent.VK_S) {
			down1Pressed = false;
		}
		if (code == KeyEvent.VK_P) {
			up2Pressed = false;
		}
		if (code == KeyEvent.VK_L) {
			down2Pressed = false;
		}
		
	}

}
