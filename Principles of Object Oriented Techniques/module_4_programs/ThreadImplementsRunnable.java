class NewThread implements Runnable {
	Thread t;
	NewThread() {
		t = new Thread(this, "Demo thread");
		System.out.println("Child thread" + t);
		t.start();
	}
    
	public void run() {
		try{
		for(int i = 5; i > 0; i--) {
			System.out.println("Child thread " + i);
			Thread.sleep(500);
		}}catch(InterruptedException e){
			System.out.println("Child interrupted ");
		}
		System.out.println("EXiting child thread");
	}
}

class ThreadImplementsRunnable {
	public static void main(String args[]) {
		new NewThread();
		try{
			for(int i = 5; i > 0; i--) {
				System.out.println("Main thread " + i);
			    Thread.sleep(1000);
            }
		} catch(InterruptedException e) {
			System.out.println("Main thread interrupted");
		}System.out.println("Main thread exiting");
	}
}