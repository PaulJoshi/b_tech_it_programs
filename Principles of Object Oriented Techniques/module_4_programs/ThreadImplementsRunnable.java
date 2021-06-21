class NewThread implements Runnable {
    Thread t;
    NewThread() {
        t = new Thread(this, "Demo Thread");
        System.out.println("Child Thread" + t);
        t.start();
    }
}

class ThreadImplementsRunnable {
    
}
