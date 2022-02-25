import java.io.*;
import java.net.*;

class EchoClient {
	public static void main(String args[]) throws Exception {
	    String sockin;
	    try {
	        Socket csock = new Socket(InetAddress.getLocalHost(),2000);
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        BufferedReader br_sock = new BufferedReader(new InputStreamReader(csock.getInputStream()));
	        PrintStream ps = new PrintStream(csock.getOutputStream());
	        System.out.println("Type 'exit' to terminate");
	        while((sockin = br.readLine()) != null) {
	            ps.println(sockin);
	            if(sockin.equals("exit"))
	                break;
	            else 
	                System.out.println("Echo: " + br_sock.readLine());            
			}
	    } catch(UnknownHostException e) {
			System.out.println(e.toString());    
		} catch(IOException ioe) {
			System.out.println(ioe);
		}
	}
}

