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
			System.out.println("String received is: " + str);

			int i = 0, j = str.length() - 1;
			boolean pal = true;

			while (i < j) {
				if (str.charAt(i) != str.charAt(j))
					pal = false;
				i++;
				j--;
			}
 
			if(pal == false)
				pw.println(str + " is not a palindrome");
			else pw.println(str + " is a palindrome");
		}

		br.close();
		pw.close();
		s.close();
		ss.close();
    }
}

