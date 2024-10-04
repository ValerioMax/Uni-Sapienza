
public class MyThread extends Thread { //o faccio extends Thread oppure faccio implements Runnable solo che poi quando andrò a creare l'oggetto lo dovrò passare come parametro ad un nuovo oggetto di tipo Thread: faccio MyThing thing = new MyThing() (con MyThing che implementa Runnable) e poi Thread myThread = new Thread(thing)
	
	@Override //stiamo facendo l'override (cos'è?) quindi lo dobbiamo mettere
	public void run() {
		if (this.isDaemon()) {
			System.out.println("This thread is Daemon type and it is running");
		}
		else {
			System.out.println("This thread is User type and it is running");
		}
		
	}
}
