
public class Main {

	public static void main(String[] args) throws InterruptedException { //InterruptedException ci sta perchè ho messo join
		
		/*
		Multithreaing è il processo di eseguire più thread simultaneamente
		Esso aiuta a massimizzare l'utilizzo della CPU (per avere una maggiore efficienza del computer)
		I thread sono indipendenti: NON influiscono sull'esecuzione di altri thread.
			->un' exception in un thread non interrompe gli altri
				->Questo è utile per multiple clients, multiplayer games, mutually indipendent tasks
				
		[I thread sono come sotto-programmi che runnano contemporaneamente e indipendentemenete!]
		
		[In realtà non runnano proprio contemporaneamnte ma sempre sequenzialmente solo che si alternano continuamente
		 dando l'idea che runnino in contemporanea (credo (?)).
		 ->esiste anche un modo per far runnare due cose contemporaneamnete ("parallel processing") ma è funziona al livello
		   di hardware (la CPU è divisa in più core (sotto-CPU)) (credo(?))]
		*/
		
		//DOMANDA: Non ho capito come funziona la priorità
		//NOTA: se io setto un thread come Daemon type => se il main thread e tutti gli altri user thread finiscono prima di questo thread il programma si chiuderà prima che questo thread si concluda
		
		//-------------------------------------------------------------------------------------------------------------------
		//MODO 1 di creare un thread
		MyThread thread1 = new MyThread();
		
		//MODO 2 di creare un thread:	creo una classe che implementa l'interfaccia Runnable e poi passo l'oggetto di tipo questa classe a un oggeto di tipo Thread
										//questo mi permette di avere ereditarietà di un'altra classe che non è Thread runnable
		MyRunnable runnable = new MyRunnable();
		Thread thread2 = new Thread(runnable);
		
		//thread1.setDaemon(true);
		//thread2.setDaemon(true);
		
		thread1.start();
		
		
		//thread1.join(); //questo metodo fa si che main thread aspetti che thread1 finisca per continuare con il resto del programma (thread2.start() incluso)
							//se non gli passo nulla aspetta che thread1 finisca del tutto altrimenti aspetta la quantità in ms che gli passo
		
		thread2.start();
		
		//System.out.println(1/0); //se metto l'operazione che mi manda in exception nel main sarà il thread del main a bloccarsi, ma thread1 e thread2 continueranno a runnare
		
		
	}

}
