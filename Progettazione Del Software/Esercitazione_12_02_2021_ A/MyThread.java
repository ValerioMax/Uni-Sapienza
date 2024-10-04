import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JProgressBar;
import javax.swing.JRadioButton;

public class MyThread extends Thread{
	
	Scanner in;
	JProgressBar cpuBar;
	JProgressBar memoryBar;
	JProgressBar diskBar;
	JProgressBar networkBar;
	JButton stop;
	JButton start;
	JButton disconnect;
	JRadioButton vm1;
	JRadioButton vm2;
	JRadioButton vm3;
	
	boolean b = true;
	String str;
	String[] vec;
	
	MyThread(Scanner in, JProgressBar cpuBar, JProgressBar memoryBar, JProgressBar diskBar, JProgressBar networkBar, JButton stop, JButton start, JButton disconnect, JRadioButton vm1, JRadioButton vm2, JRadioButton vm3){
		this.in = in;
		this.cpuBar = cpuBar;
		this.memoryBar = memoryBar;
		this.diskBar = diskBar;
		this.networkBar = networkBar;
		this.stop = stop;
		this.start = start;
		this.disconnect = disconnect;
		this.vm1 = vm1;
		this.vm2 = vm2;
		this.vm3 = vm3;
	}
	
	@Override
	public void run() {
		while (true) { //30 sec
			if (in.hasNextLine()) {
				str = in.nextLine();
				System.out.println(str);
				if (str.equals("error")) {
					break;
				}
				if (str.equals("Not Found")) {
					continue;
				}
				if (str.equals("*")) {
					stop.setEnabled(false);
					disconnect.setEnabled(true);
					start.setEnabled(true);
					vm1.setEnabled(true);
					vm2.setEnabled(true);
					vm3.setEnabled(true);
					break;
				}
				else {
					vec = str.split(":");
					cpuBar.setValue(Integer.parseInt(vec[0]));
					memoryBar.setValue(Integer.parseInt(vec[1]));
					diskBar.setValue(Integer.parseInt(vec[2]));
					networkBar.setValue(Integer.parseInt(vec[3]));
				}
					
			}
		}
		System.out.println("fine ciclo");
	}
}
