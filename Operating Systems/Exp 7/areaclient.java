import java.net.*;
import java.io.*;

class areaclient {
	public static void main(String args[]) throws Exception {
		Socket s = new Socket("localhost", 4000);

		BufferedReader br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintStream pw = new PrintStream(s.getOutputStream());
		BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

		String str = "", str2 = "";

		while(true) {
			System.out.println("Enter the radius of circle: ");
			str = br1.readLine();
			if(str.equals("exit")) break;
			pw.println(str);
    		str2 = br2.readLine();
			System.out.println("Area computed by Server: " + str2);
		}

		br1.close();
		br2.close();
		pw.close();
		s.close();
	}
}
