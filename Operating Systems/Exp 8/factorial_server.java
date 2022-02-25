import java.net.*;
import java.io.*;

class Server {  
	public static void main(String args[]) throws Exception {
		ServerSocket ss = new ServerSocket(4000);
		Socket s = ss.accept();

		BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintStream pw = new PrintStream(s.getOutputStream());

		String str = "";
		while(true) {
			str = br.readLine();
			if(str.equals("exit")) break;
			System.out.println("Number received is: " + str);

			int number, fact = 1;
			
			number = Integer.parseInt(str);
			for(int i = 1; i <= number; i++) {
				fact = fact * i;
			}
			pw.println("Factorial of " + str + " is: " + fact);
		}

		br.close();
		pw.close();
		s.close();
		ss.close();
    }
}

