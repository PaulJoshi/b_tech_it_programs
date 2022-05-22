import java.net.*;
import java.io.*;

class areaserver {  
	public static void main(String args[]) throws Exception {
		ServerSocket ss = new ServerSocket(4000);
		Socket s = ss.accept();

		BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintStream pw = new PrintStream(s.getOutputStream());

		String str = "";
		while(true) {
			str = br.readLine();
			if(str.equals("exit")) break;
			int r = Integer.parseInt(str);
			double area = 3.14 * r * r;
			String x = Double.toString(area);
			pw.println(x);
		}

		br.close();
		pw.close();
   		s.close();
   		ss.close();
    }
}
