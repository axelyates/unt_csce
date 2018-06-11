/* 
    Compilation: javac Server.java
    Execution  : java Server
    *NOTE* This program doesn't count "y" or "Y" as a vowel :)
*/

import java.io.*;   //necessary imports
import java.net.*;
 
public class server
{
    private static Socket socket;
 
    public static void main(String[] args)
    {
        try{
            //Connecting with the client
            int counter = 0;    //initiating counter to count vowels
            int port = 6000;    //initiating port to 6000, this can be changed as needed
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server Started and listening to the port 6000");

	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int length;
 			
            //Server is running always. This is done using this while(true) loop
            while(true){
	        //Connecting to the client
		socket = serverSocket.accept(); //creates new socket

		DataInputStream in = new DataInputStream(socket.getInputStream());
		DataOutputStream out = new DataOutputStream(socket.getOutputStream());

		//Reading the message from the client
		length = in.readInt();
		byte[] rmessage = new byte[256];
		in.readFully(rmessage, 0, length);
		String recvMessage = new String(rmessage);

                //You now have clients message as "recvMessage"
                for(int i = 0; i < recvMessage.length(); i++){  //for loop to iterate through string and count number of vowels
                    if((recvMessage.charAt(i) == 'a') || (recvMessage.charAt(i) == 'e') || (recvMessage.charAt(i) == 'i') ||(recvMessage.charAt(i) == 'o') || (recvMessage.charAt(i) == 'u') ||
                    (recvMessage.charAt(i) == 'A') || (recvMessage.charAt(i) == 'E') || (recvMessage.charAt(i) == 'I') ||(recvMessage.charAt(i) == 'O') || (recvMessage.charAt(i) == 'U')){
                        counter++;
                    }
                }

                if(recvMessage.equals("bye")){  //closes socket if client sent "bye"
                    socket.close();
                }

		//Sending the response back to the client
                out.writeInt(counter);
		out.flush();			
                counter = 0;

		//Closing the connection
       		socket.close();
            }
        }
        catch (Exception e){
            System.out.println("Server socket error!");
        }
    }
}
