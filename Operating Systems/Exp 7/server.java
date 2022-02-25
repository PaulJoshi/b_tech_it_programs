import java.net.*;
import java.io.*;

public class server
{
	public server()
	{
		try {
			ServerSocket se=new ServerSocket(4000);
			Socket s=se.accept();
			String a;
			BufferedReader br=new BufferedReader(new
			InputStreamReader(s.getInputStream()));
			a=br.readLine();
			while(!a.equals("exitl"))
			{
				System.out.println("Message received:");
				System.out.println(a);
				a=br.readLine();
			}
			br.close();
			se.close();
		} catch(Exception e) { }
	}

	public static void main(String args[])
	{
		server st=new server();
	}
}

