/* Compilation: javac Client.java
   Execution  : java Client
*/

import java.io.*;
import java.net.*;

public class client
{
	private static Socket socket;
 
    	public static void main(String args[])
    	{
        	try
        	{
			//Connecting with the server
		    	//String host = "localhost"; //Both in the same machine [IP address 127.0.0.1]
			String host = "129.120.151.94"; //IP address of server
            		int port = 6000;
                        int counter = 0;
            		InetAddress address = InetAddress.getByName(host);
                        boolean end = false;

                        while(end != true){
            		socket = new Socket(address, port);

			DataInputStream in = new DataInputStream(socket.getInputStream());
			DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int length;
			
			//Sending the message to the server
			System.out.print("Enter client's message: ");
			String sendMessage = br.readLine();
			byte[] smessage = new byte[256];
			smessage = sendMessage.getBytes();
                        if(sendMessage.equals("bye")){
                            end = true;
                        }
			out.writeInt(smessage.length);
			out.write(smessage);
			out.flush();			
		    	System.out.println("Message sent to the server: " + sendMessage);
 
            		//Receiving the message from the server
			length = in.readInt();
			counter = in.readInt();
                        byte[] rmessage = new byte[256];
			in.readFully(rmessage, 0, length);
                        //in.readInt(counter);
			String recvMessage = new String(rmessage);
			System.out.println("Message received from the server: " + recvMessage);
                        System.out.println("The number of vowels present is = " + counter);

                        }//end while loop
			//Closing the connection
			socket.close();
        	}
        	catch (Exception e)
        	{
            		System.out.println("Client socket error!");
        	}
    	}
}
