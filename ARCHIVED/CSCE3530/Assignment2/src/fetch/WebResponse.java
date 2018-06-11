package fetch;

import java.io.*;
import java.net.*;

public class WebResponse {
  
  private int status;
  private String body;
  
  private WebResponse(WebResponseBuilder builder) {
    this.status = builder.status;
    this.body = builder.body;
  }
  
  public int getStatus() {
    return this.status;
  }
  
  public String getBody() {
    return this.body;
  }

  public static class WebResponseBuilder {
    private int status;
    private String body;
    
    public WebResponseBuilder() {}
    
    public WebResponseBuilder status(int status) {
      this.status = status;
      return this;
    }
    
    public WebResponseBuilder body(String body) {
      this.body = body;
      return this;
    }
    
    public WebResponse build() {
      return new WebResponse(this);
    }

  }
}