/* 
	Name: 			Axel Yates
	Assignment: 	Assignment #4 - Server
	Compilation: 	javac UDPServer.java
	Execution: 		java Server <port_number>
*/

/*


reminder:
remove IP addresses from .txt file!!!!!


*/








import java.io.*;
import java.net.*;
import java.util.*;

class UDPServer{
	public static void main(String args[]) throws Exception{
		int sportno = Integer.parseInt(args[0]); /*UDP server port number */
        DatagramSocket serverSocket = new DatagramSocket(sportno);
        byte[] receiveData = new byte[1024];
        byte[] sendData = new byte[1024];
		int num_sent = 0;
		String trans_id;
		java.util.ArrayList<String> list = new java.util.ArrayList<String>();
		String serverMsg;

		try {
			FileInputStream fstream = new FileInputStream("IPaddress.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;

			while ((strLine = br.readLine()) != null) {
				list.add(strLine);
			}
			in.close();
		}
		catch(Exception e) {      
			System.err.println("Error: " + e.getMessage());
		}
        while(true){
			/* Waiting for client's message --transaction ID-- */
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            String clientMsg= new String(receivePacket.getData()); //gets clients message
			trans_id = clientMsg;

			/* Waiting for client's message --first message-- */
            receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);
            clientMsg= new String(receivePacket.getData()); //gets clients message
            System.out.println(clientMsg);

			/* Getting the IP address and port number of client */
            InetAddress IPAddress = receivePacket.getAddress(); /*UDP client IP address */
            int cportno = receivePacket.getPort(); /*UDP client port number */

			/* Sending a message to the client */
			if(num_sent > -1 && num_sent < 10){

				//sending IP address to the client
				serverMsg = (list.get(num_sent));
				sendData = serverMsg.getBytes();
				DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, cportno);
            	serverSocket.send(sendPacket);
				num_sent++;
				

				File inputFile = new File("IPaddress.txt");
				File tempFile = new File("myTempFile.txt");
				BufferedReader reader = new BufferedReader(new FileReader(inputFile));
				BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));
				String lineToRemove = serverMsg;
				String currentLine;
				while((currentLine = reader.readLine()) != null) {
    				// trim newline when comparing with lineToRemove
    				String trimmedLine = currentLine.trim();
    				if(trimmedLine.equals(lineToRemove)) continue;
    				writer.write(currentLine + System.getProperty("line.separator"));
				}
				writer.close(); 
				reader.close(); 
				boolean successful = tempFile.renameTo(inputFile);

				//receiving info from client 1/2
            	receivePacket = new DatagramPacket(receiveData, receiveData.length);
            	serverSocket.receive(receivePacket);
            	String clientMsg1= new String(receivePacket.getData());
				
				//receiving info from client 2/2
            	receivePacket = new DatagramPacket(receiveData, receiveData.length);
            	serverSocket.receive(receivePacket);
            	String clientMsg2= new String(receivePacket.getData());
				
				//printing out 2/2 message
				System.out.println(clientMsg1 + clientMsg2 + " Lifetime 3600 seconds");
            }
			else if(num_sent >= 10){
				serverMsg = "Sorry all out of IP addresses";
				sendData = serverMsg.getBytes();
				DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, cportno);
            	serverSocket.send(sendPacket);
				serverSocket.close();
			}




        }
   	}
}
