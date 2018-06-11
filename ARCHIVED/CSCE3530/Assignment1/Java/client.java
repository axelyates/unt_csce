/* 
    Compilation: javac Client.java
    Execution  : java Client

    *NOTE* due to the nature of the program, the server can handle multiple clients,
    however, both clients need to enter a message before the server will respond

    *NOTE 2* to exit this program you need to specifically type the word "bye"
    without the quotation marks
*/

import java.io.*;   //necessary imports
import java.net.*;

public class client
{
    private static Socket socket;
 
    public static void main(String args[]){
        try{
	    //Connecting with the server
	    //String host = "localhost"; //Both in the same machine [IP address 127.0.0.1]
	    String host = "129.120.151.94"; //IP address of server - specifically CSE01
            int port = 6000;    //declaring port number, this can be modified as needed
            int counter = 0;    //initiating a counter to keep track of vowels
            InetAddress address = InetAddress.getByName(host);
            boolean end = false;    //creating a boolean to know when to close connection to server

            while(end != true){     //while loop that keeps going until user types in "bye" making end turn true
                socket = new Socket(address, port); //creates a new socket

		DataInputStream in = new DataInputStream(socket.getInputStream());
		DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int length;

		//Sending the message to the server
		System.out.print("Enter client's message: ");
		String sendMessage = br.readLine(); //takes in clients message
		byte[] smessage = new byte[256];
		smessage = sendMessage.getBytes();
                if(sendMessage.equals("bye")){      //checks to see if clients message is "bye" to end connection
                    end = true;
                }
		out.writeInt(smessage.length);
		out.write(smessage);
		out.flush();			
 
            	//Receiving the message from the server
		counter = in.readInt();             //sets counter equal to number of vowels from server
                if(!sendMessage.equals("bye")){     //only prints number of vowels if user didn't type "bye"
                    System.out.println("The number of vowels present is = " + counter);
                }
            }//end while loop

	    //Closing the connection
	    socket.close();
        }
        catch (Exception e){
            System.out.println("Client socket error!");
        }
    }
}
