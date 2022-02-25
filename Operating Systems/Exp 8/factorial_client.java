import java.net.*;
import java.io.*;

class Client {
	public static void main(String args[]) throws Exception {
		Socket s = new Socket("localhost", 4000);

		BufferedReader br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintStream pw = new PrintStream(s.getOutputStream());
		BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

		String str = "", str2 = "";

		while(true) {
			System.out.println("Enter a number: ");
			str = br1.readLine();
			pw.println(str);
			if(str.equals("exit")) break;
    			str2 = br2.readLine();
    			System.out.println(str2);
		}

		br1.close();
		br2.close();
		pw.close();
		s.close();
	}
}

