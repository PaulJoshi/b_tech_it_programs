import java.io.*;
import java.net.*;

class EchoServer {
    public static void main(String args[]) throws Exception {
        String echoin;
        ServerSocket svrsoc;
        Socket soc;
        BufferedReader br;
        try {
            svrsoc = new ServerSocket(2000);
            soc = svrsoc.accept();
            br = new BufferedReader (new InputStreamReader(soc.getInputStream()));
            PrintStream ps = new PrintStream(soc.getOutputStream());
            System.out.println("Connected for echo:");
            while((echoin=br.readLine()) != null) {
                if(echoin.equals("exit")) {
                    System.out.println("Client disconnected");
                    br.close();
                    break;
                }
                else
                	System.out.println("Received String: " + echoin);
                    ps.println(echoin);
            }
        } catch(UnknownHostException e) {
            System.out.println(e.toString());
        } catch(IOException ioe) {
            System.out.println(ioe);
        }
    }    
}

