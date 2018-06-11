package fetch;

import java.io.*;
import java.net.*;

import fetch.WebResponse.WebResponseBuilder;
import fetch.WebRequest.WebRequestBuilder;

public class Mediator {
  
  public static WebResponse fetch(WebRequest req) {
    
    String chunk;
    StringBuffer body = new StringBuffer();
    WebResponseBuilder res = new WebResponseBuilder();
    
    try {
      
      HttpURLConnection connection
      = (HttpURLConnection) req.getUrl().openConnection();
      
      connection.setRequestMethod(req.getMethod());
      
      BufferedReader data
      = new BufferedReader(new InputStreamReader(connection.getInputStream()));
      
      while ((chunk = data.readLine()) != null) {
        body.append(chunk);
      }
      
      // build response     
      res.status(connection.getResponseCode());
      res.body(body.toString());
      
      connection.disconnect();
      
    } catch (Exception err) {}
    
    return res.build();
    
  }
}




