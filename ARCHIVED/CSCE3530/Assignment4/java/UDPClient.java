/* 
	Name:			Axel Yates
	Assignment:		Assignment #4 - Client
	Compilation: 	javac UDPClient.java
   	Execution: 		java Client <port_number> [eg. port_number = 5000, where port_number is the UDP server port number]
*/

import java.io.*;
import java.net.*;
import java.util.*;

class UDPClient{
	public static void main(String args[]) throws Exception{
      	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int sportno = Integer.parseInt(args[0]); /* UDP server port number */
		int transID = 0;
      	DatagramSocket clientSocket = new DatagramSocket(); 
		InetAddress IPAddress = InetAddress.getByName("cse01.cse.unt.edu"); /* UDP server's IP address */
		byte[] sendData = new byte[1024];
      	byte[] receiveData = new byte[1024];
		Random rand = new Random();
		int trans_id = rand.nextInt(100) + 1; //generates random number between 1 and 100
		String ip_addr;

		/* Sending transaction ID address to the UDP server */
      	String clientMsg = Integer.toString(trans_id);
      	sendData = clientMsg.getBytes(); //stores clients message in sendable format into sendData
      	DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, sportno); //creates sendable packet
      	clientSocket.send(sendPacket); //sends the packet to the server

		/* Sending message to the UDP server */
      	clientMsg = ("yiaddr: 0.0.0.0 | Transaction ID "+trans_id);
      	sendData = clientMsg.getBytes(); //stores clients message in sendable format into sendData
      	sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, sportno); //creates sendable packet
      	clientSocket.send(sendPacket); //sends the packet to the server

		/* Receiving IP address from the UDP server */
      	DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
      	clientSocket.receive(receivePacket);
      	String serverMsg = new String(receivePacket.getData());
		System.out.println(serverMsg+" | Transaction ID "+trans_id+" | Lifetime 3600 seconds");
		ip_addr = serverMsg;
		trans_id++;//increment transaction ID by one

		/* Receiving reply from the UDP server /
      	receivePacket = new DatagramPacket(receiveData, receiveData.length);
      	clientSocket.receive(receivePacket);
      	serverMsg = new String(receivePacket.getData());
      	System.out.println(serverMsg);
		*/

		/* Sending 1/2 message to the UDP server */
      	clientMsg = (("yiaddr: "+ (ip_addr) +" and transaction ID is: "+ (trans_id)));
      	sendData = clientMsg.getBytes(); //stores clients message in sendable format into sendData
      	sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, sportno); //creates sendable packet
      	clientSocket.send(sendPacket); //sends the packet to the client
		
		/* Sending 2/2 message to the UDP server */
		clientMsg = " and the transaction ID is: "+trans_id;
      	sendData = clientMsg.getBytes(); //stores clients message in sendable format into sendData
      	sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, sportno); //creates sendable packet
      	clientSocket.send(sendPacket); //sends the packet to the client

		System.out.println(ip_addr+" | Transaction ID "+trans_id+" | Lifetime 3600 seconds");




      	clientSocket.close();

   	}
}
