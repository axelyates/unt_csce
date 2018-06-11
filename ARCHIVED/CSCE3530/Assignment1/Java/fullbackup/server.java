/* Compilation: javac Server.java
   Execution  : java Server
*/

import java.io.*;
import java.net.*;
 
public class server
{
	private static Socket socket;
 
    	public static void main(String[] args)
    	{
        	try
        	{
			//Connecting with the client
                        int counter = 0;
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

                                //you now have clients message as "recvMessage"
                                for(int i = 0; i < recvMessage.length(); i++){
                                    if((recvMessage.charAt(i) == 'a') || (recvMessage.charAt(i) == 'e') || (recvMessage.charAt(i) == 'i') ||(recvMessage.charAt(i) == 'o') || (recvMessage.charAt(i) == 'u') ||
                                    (recvMessage.charAt(i) == 'A') || (recvMessage.charAt(i) == 'E') || (recvMessage.charAt(i) == 'I') ||(recvMessage.charAt(i) == 'O') || (recvMessage.charAt(i) == 'U')){
                                        System.out.println("The String contains " + recvMessage.charAt(i));
                                        counter++;
                                    }
                                }

 
				//Sending the response back to the client
				System.out.print("Enter server's message: ");
				String sendMessage = br.readLine();
				byte[] smessage = new byte[256];
				smessage = sendMessage.getBytes();
				out.writeInt(smessage.length);
                                out.writeInt(counter);
				out.write(smessage);
				out.flush();			
			    	System.out.println("Message sent to the client: " + sendMessage);
                                System.out.println("The clients message had: " + counter + " vowels.");
                                counter = 0;

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
