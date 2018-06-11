package fetch;

import java.io.*;
import java.net.*;

public class WebRequest {
  
  private URL url;
  private String method;
  
  public WebRequest(WebRequestBuilder builder) {
    this.url = builder.url;
    this.method = builder.method;
  }
  
  public URL getUrl() {
    return this.url;
  }
  
  public String getMethod() {
    return this.method;
  }
  
  public String getUrlAsString() {
    return this.url.toString();
  }

  public static class WebRequestBuilder {
    private URL url;
    private String method;
    
    public WebRequestBuilder(String url) throws MalformedURLException {
      if (!url.contains("http")) {
        this.url = new URL("https://" + url);
      } else {
        this.url = new URL(url);
      }
      this.method = "GET";
    }
    
    public WebRequestBuilder method(String method) {
      this.method = method;
      return this;
    }
    
    public WebRequest build() {
      return new WebRequest(this);
    }
     
  }
}