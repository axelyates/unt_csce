//Please refer to README.md to learn how to compile this code.

import java.io.*;
import java.net.*;
import logger.*;

public class Client{
	private static Socket socket;
	public static void main(String args[]){
    try{
		// Connecting with the server
		
		String host = "localhost"; //default IP address
		int port = 4200; //default port
		if (args.length >= 1)
        if (args[0] != null) host = args[0]; //check argument for user-specified host address
      	if (args.length >= 2)
        if (args[1] != null) port = Integer.parseInt(args[1]);  //check argument for user-specified port number
		Logger.info(new StringBuilder("Connecting to " + host + ":"+ port + " ..."));
		InetAddress address = InetAddress.getByName(host);

		boolean active = true;

		while(active){
			System.out.print("Enter a valid URL: ");
        	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        	String message = reader.readLine();
        
        	//establish connection with the socket
        	socket = new Socket(address, port);
        	DataInputStream in = new DataInputStream(socket.getInputStream());
        	DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        
        	//Sending the message to the server
        	Logger.info(new StringBuilder("Sending request to " + host + ":"+ port + " ..."));
        	byte[] messageBuffer = new byte[256];
        	messageBuffer = message.getBytes();
        	out.writeInt(messageBuffer.length);
        	out.write(messageBuffer);
        	out.flush();
        
        	//Receiving the message from the server
        	int length = in.readInt();
        	byte[] rawResponse = new byte[3000000];
        	in.readFully(rawResponse, 0, length);
        	String response = new String(rawResponse);

        	StringBuilder output = new StringBuilder();
        	output.append("Recieved response from " + host + ":"+ port + " ...\n");
        	output.append(response);
        	Logger.success(output);
      	}
		//Closing the connection
		socket.close();
		Logger.info(new StringBuilder("Connection to " + host + ":"+ port + " has been closed."));
    }
    catch (Exception e){
		Logger.error(new StringBuilder(e.toString()));
    }
  }
}
