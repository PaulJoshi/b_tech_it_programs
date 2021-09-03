class NewThread implements Runnable {
	String name;    //name of the thread
	Thread t;

	NewThread(String theadname) {
		name = theadname;
		t = new Thread(this, name);
		System.out.println("New thread  " + t);
		t.start();
	}

	public void run() {
		try {
			for(int i = 5; i > 0; i--) {
				System.out.println(name + " : " + i);
			    Thread.sleep(1000);
            }
		} catch(InterruptedException e) {
			System.out.println(name + " interruped");
		}
		System.out.println(name + " is exiting");
	}
}

class CreateMultipleThread{
	public static void main(String args[]) {
		NewThread n1 = new NewThread("One");
		NewThread n2 = new NewThread("Two");
		NewThread n3 = new NewThread("Three");

		try{
			System.out.println("Main thread");
			Thread.sleep(10000);
		} catch(InterruptedException e) {
			System.out.println("Main thread interruped");
		}
		System.out.println("Main thread exiting");
	}
}