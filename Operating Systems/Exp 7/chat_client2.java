import java.net.*;
import java.io.*;

class ChatClient {
	public static void main(String args[]) throws Exception {
		Socket s = new Socket("localhost", 4000);

		DataInputStream din = new DataInputStream(s.getInputStream());
		DataOutputStream dout = new DataOutputStream(s.getOutputStream());
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str1 = "", str2 = "";

		while(!str1.equals("exit")) {
			str1 = br.readLine();
			dout.writeUTF(str1);
			dout.flush();
			while(!str1.equals("/")) {
				str2 = din.readUTF();
				System.out.println("Server: " + str2);
			}
		}

		dout.close();
		s.close();
	}
}
