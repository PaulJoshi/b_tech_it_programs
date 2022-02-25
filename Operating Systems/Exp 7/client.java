import java.net.*;
import java.io.*;

public class client
{
	Socket s1;
	public client()
	{
		try
		{
			s1=new Socket("localhost",4000);
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			PrintWriter pw=new PrintWriter(new OutputStreamWriter(s1.getOutputStream()),true);
			String line;
			do
			{
				System.out.println("Enter the character:");
				line=br.readLine();
				pw.println(line);
			} while(!line.equals("exit"));
	
			br.close();
			pw.close();
			s1.close();
		} catch(Exception e) {
			System.out.println("Could not connect");
		}
	}

	public static void main(String args[])
	{
		client c=new client();
	}
}

