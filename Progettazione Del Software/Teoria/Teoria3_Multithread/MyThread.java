
public class MyThread extends Thread{
	
	@Override
	public void run() {
		
		for (int i = 10; i > 0; i--) {
			System.out.println("Thread #1: " + i);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			//System.out.println(1/0); //aggiungo quest'operazione che mi genera un'aritmetic exception che mi blocca il programma (non ho messo, intenzionalmente, l'operazione nel catch quindi me la prova ad eseguire andando in errore)
		}
		System.out.println("Thread #1 finished!");
	}
}
