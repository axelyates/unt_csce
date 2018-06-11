
//Please refer to README.md to learn how to compile this code.

import java.io.*;
import java.net.*;
import fetch.*;
import logger.*;

public class Server{

	public static final int OK = 200;
  	public static final int DEFAULT_PORT = 4200;
  	public static final int MESSAGE_SIZE = 256;
  	public static final int PAYLOAD_SIZE = 3000000;

  	private static Socket socket;
  
  	public static void main(String[] args) {

    try{

      // Connecting with the client
      int port = DEFAULT_PORT;

		if (args.length >= 1)
			if (args[0] != null) port = Integer.parseInt(args[0]);
        
      	ServerSocket serverSocket = new ServerSocket(port);

      	Logger.info(new StringBuilder("Proxy server is running on port " + port + "..."));
      
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int length;
      
		// Server is running always. This is done using this while(true) loop
		while(true){
        	// connect to the client
        	Logger.info(new StringBuilder("------- connected to client -------"));
			socket = serverSocket.accept();
        
			DataInputStream in = new DataInputStream(socket.getInputStream());
			DataOutputStream out = new DataOutputStream(socket.getOutputStream());
        
			// read message from client
			length = in.readInt();
			byte[] rmessage = new byte[MESSAGE_SIZE];
			in.readFully(rmessage, 0, length);
        	String recvMessage = new String(rmessage);

        	Logger.debug(new StringBuilder("Building web request..."));
        	WebRequest req = new WebRequest.WebRequestBuilder(recvMessage.trim())
          	.method("GET")
          	.build();

        	// check if the webpage is cached
        	String webpage = "Unknown proxy error";
        	Logger.info(new StringBuilder("Checking if " + req.getUrlAsString() + " is cached..."));
			if (Cache.isWebpageInCacheList(req)) {
				Logger.info(new StringBuilder("Webpage is cached..."));
				webpage = Cache.getCachedWebpage(req);
        	} 
			else {
				Logger.info(new StringBuilder("Webpage is not cached, fetching webpage..."));
          		WebResponse res = Mediator.fetch(req);
          	if (res.getStatus() != OK) {
            	// forward http response to the client
            	Logger.error(new StringBuilder("HTTP Status Code: " + res.getStatus()));
            	webpage = "HTTPS Status is not OK. Unable to fulfill request.";
          	} 
			else {
            	Logger.success(new StringBuilder("HTTP Status Code: " + res.getStatus()));
            	// cache the webpage
            	Logger.info(new StringBuilder("Caching the webpage..."));
            	Cache.pushToCacheList(req);
            	Cache.cleanCache();
            	Cache.upsertCacheListFile();
            	Cache.saveWebpage(req, res);
				webpage = res.getBody();
			}  
        	}
        	Logger.info(new StringBuilder("Preparing payload..."));
        	byte[] payload = new byte[PAYLOAD_SIZE];
        	payload = webpage.getBytes();
        
			out.writeInt(payload.length);
			out.write(payload);
        	out.flush();
        	Logger.info(new StringBuilder("Sent payload to client..."));
        
        	// close the connection
        	socket.close();
      } //end of while loop
    } catch (Exception e){

      StringBuilder errorMessage = new StringBuilder();
      StringWriter errors = new StringWriter();
      e.printStackTrace(new PrintWriter(errors));
      errorMessage.append("Exception was caught...\n");
      errorMessage.append(errors.toString());
      Logger.error(errorMessage);

    } 
		finally{
      
    	}
	}
}
