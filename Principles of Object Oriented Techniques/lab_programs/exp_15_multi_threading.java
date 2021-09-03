/* Develop a Java application that executes two threads. One thread displays-'Hello' in
every 1000 milliseconds and the other displays-'World' in every 3000 milliseconds.
Create the threads by extending the Thread class. */

class NewThread extends Thread {
	NewThread() {   
		start(); // to run the thread
	}

	public void run() {
		try {
			for(int i = 5; i > 0; i--) {	
				System.out.println("Hello");
				Thread.sleep(1000);
			}
		} catch(InterruptedException e) {
			System.out.println("Child interrupted");
		}
		System.out.println("Exiting child thread");
	}
}


class MultipleThreads {
	public static void main(String args[]) {
		new NewThread();

		try {
			for(int i = 5; i > 0; i--) {
				System.out.println("World" );
				Thread.sleep(3000);
			}
		} catch(InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("Main thread exiting");
	}
}
