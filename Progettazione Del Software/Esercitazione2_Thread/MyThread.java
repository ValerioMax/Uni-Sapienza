
public class MyThread extends Thread{
	
	@Override
	public void run(){
		
		try {
			Thread.sleep(10000);
		} catch (InterruptedException e1) {
			e1.printStackTrace();
		}
	}
}
