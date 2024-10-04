
public class Main {

	public static void main(String[] args) throws InterruptedException {
		/*
		Un Thread è un filo di esecuzione in un programma (è come una CPU virtuale che ha il suo set di istruzioni)
		
		La JVM (JavaVirtualMachine) permette ad un'applicazione di avere più thread che runnano contemporaneamente
		Ogni thread può eseguire una parte del codice in parallelo con il thread principale
		Ogni thread ha una priorità:
			I thread con priorità più alta sono eseguiti preferenzialmente (nel senso che vengono eseguite prima le operazioni del thread con priorità alta?) rispetto a quelli con priorità più bassa
		
		La JVM continua a eseguire thread finchè non si verifica una delle due:
			1. The exit method of class Runtime has been called
			2. All user threads have died
		
		Quando la JVM parte ci sta un thread che chiama il metodo main
		->questo thred si chiama "main"
		
		Ci sono:
			1. Daemon threads che sono thread con priorità bassa che runnano nel background per fare task come garbage collection
			2. User threads
		La JVM termites itself quando tutti gli user thread (non daemon) finiscono la loro esecuzione
		
		
		RIASSUNTO:
		Ogni thread è un set di istruzioni.
		E' possibile runnare più thread contemporaneamente (es.: istruzioni di thread1 eseguite in maniera simultanea e alle istruzioni di thread2 (NON tutte le istruzioni di thread1 e una volta finito tutto quelle di thread2))
		A ogni thread si dà un valore di priorità in modo che vengano comunque eseguiti contemporaneamente ma preferenziando quelli con priorità più alta (credo(?))
		Se c'è una RuntTimeExeption su un thread questo si fermerà ma gli altri continueranno a runnare
		
		*/
		
		
		
		
		
		
		//-------------------------------------------------------------------------------------------------------------------
		/*
		System.out.println(Thread.activeCount()); //è il numero di thread che stanno runnando in questo momento
		Thread.currentThread().setName("il mio thread"); //rinomina il thread corrente
		System.out.println(Thread.currentThread().getName()); //è il nome del(dei) thred che stanno runnando
		
		
		Thread.currentThread().setPriority(10); //cambia la priorità da 1 a 10 (maggiore è la priorità maggiore è il numero) (5 è il default)
		System.out.println(Thread.currentThread().getPriority());
		
		System.out.println(Thread.currentThread().isAlive()); //controlla se è vivo
		*/		
		
		//si può fare un thread sleep che è come se il programma sia messo in pausa
		
		/*
		for (int i = 3; i > 0; i--) {
			System.out.println(i);
			Thread.sleep(1000);
		}
		
		System.out.println("Done!");
		*/
		
		
		
		
		
		//-------------------------------------------------------------------------------------------------------------------
		//creiamo un nuovo thread
		
		MyThread thread2 = new MyThread(); //creiamo un secondo thread che runna oltre al main thread che c'è sempre di base
		thread2.setDaemon(true);
		System.out.println(thread2.isDaemon());
		thread2.start(); //starta il thread una volta che l'ho creato -> fa partire di conseguenza la funzione run dell classe MyThread
		
		System.out.println(thread2.isAlive());
		thread2.setName("2nd thread");
		System.out.println(thread2.getName());
		//thread2.setPriority(1);
		System.out.println(thread2.getPriority());
		
		System.out.println(Thread.activeCount()); //perchè restituisce 1 anche se ho startato thread2?
		
		
		
		//-------------------------------------------------------------------------------------------------------------------
		//Differenza fra start() e run()
		
		
		MyThread thread3 = new MyThread();
		MyThread thread4 = new MyThread();
		
		//Questo...						[In questo modo si fanno partire i due thread che runneranno contemporanemante]
		thread3.start();
		thread4.start();
		//...è diverso da questo		[In quest'altro modo si fa runnare il primo e una volta che ha finito si farà runnare il secondo]
		thread3.run();
		thread4.run();
		
		
		
		//-------------------------------------------------------------------------------------------------------------------
		//Osservazione	
		
		
		//O faccio cosi: una riga ma MyThread è sottoclasse di Thread e non può esserlo anche di altro
		MyThread myThread = new MyThread();
		
		//Oppure faccio cosi: più righe ma cosi ho il vantaggio di poter fare extends la classe che voglio
		MyThing thing = new MyThing();
		Thread thingThread = new Thread(thing);
	}

}
