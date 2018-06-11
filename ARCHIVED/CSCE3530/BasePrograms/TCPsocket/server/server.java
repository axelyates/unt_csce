/* Compilation: javac Server.java
   Execution  : java Server
*/

import java.io.*;
import java.net.*;
 
public class Server
{
	private static Socket socket;
 
    	public static void main(String[] args)
    	{
        	try
        	{
			//Connecting with the client
            		int port = 6000;
            		ServerSocket serverSocket = new ServerSocket(port);
            		System.out.println("Server Started and listening to the port 6000");

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int length;
 			
            		//Server is running always. This is done using this while(true) loop
            		while(true)
            		{
				//Connecting to the client
				socket = serverSocket.accept();

				DataInputStream in = new DataInputStream(socket.getInputStream());
				DataOutputStream out = new DataOutputStream(socket.getOutputStream());

				//Reading the message from the client
				length = in.readInt();
				byte[] rmessage = new byte[256];
				in.readFully(rmessage, 0, length);
				String recvMessage = new String(rmessage);
		    		System.out.println("Message received from the client: " + recvMessage);
 
				//Sending the response back to the client
				System.out.print("Enter server's message: ");
				String sendMessage = br.readLine();
				byte[] smessage = new byte[256];
				smessage = sendMessage.getBytes();
				out.writeInt(smessage.length);
				out.write(smessage);
				out.flush();			
			    	System.out.println("Message sent to the client: " + sendMessage);

				//Closing the connection
       				socket.close();
            		}
        	}
        	catch (Exception e)
        	{
            		System.out.println("Server socket error!");
        	}
    	}
}