package fetch;

import java.io.*;
import java.net.*;
import java.util.*;

import fetch.WebResponse;
import fetch.WebRequest;
import logger.*;

public class Cache {
  
	private static final int CACHE_SIZE = 5;
  	private static final String CACHE_PATH = "cache/";

  	private static String[] cacheList = new String[CACHE_SIZE];

	//This will generate a valid filename from a web request.
  	public static String generateFilenameFromReq(WebRequest req) {
    	return req.getUrlAsString().split("://")[1].replace('/', '_') + ".html";
  	}

  	//This generates a valid cache filepath for a specified filename
  	public static String generateCacheFilepath(String filename) {
    	return CACHE_PATH + filename;
  	}

	//This will check if the requested webpage is on the cache list
  	public static Boolean isWebpageInCacheList(WebRequest req) {
    	String filename = generateFilenameFromReq(req);
    	for (String webpage : cacheList)
      		if (webpage != null)
        		if (webpage.equals(filename))
          			return true;
    	return false;
  	}

	//This will return the body of the cached webpage.
  	public static String getCachedWebpage(WebRequest req)
  	throws FileNotFoundException, IOException {

    	String filename = generateFilenameFromReq(req);
    	String path = generateCacheFilepath(filename);

    	InputStream inputStream = new FileInputStream(path);
    	BufferedReader buffer = new BufferedReader(new InputStreamReader(inputStream));

    	String line = buffer.readLine();
    	StringBuilder builder = new StringBuilder();

		while (line != null) {
			builder.append(line).append("\n");
      		line = buffer.readLine();
    	}

    	String webpage = builder.toString();

		return webpage;
  }

	//This will push a web request to the cache list
  	public static void pushToCacheList(WebRequest req) {
    Logger.debug(new StringBuilder("Updating the memory cache list..."));
    String[] newCacheList = new String[CACHE_SIZE];
    newCacheList[0] = generateFilenameFromReq(req);
    for(int i = 0; i < CACHE_SIZE - 1; i++)
      newCacheList[i+1] = cacheList[i];
    cacheList = newCacheList;
  }

	//This will scan the specified path for .html files and remove the ones that are not on the cache list. 

  public static void cleanCache() {

    Logger.debug(new StringBuilder("Cleaning the cache folder..."));

    File folder = new File(CACHE_PATH);
    for (File file : folder.listFiles()) {
      Boolean found = false;
      String fileName = file.getName();
      if (fileName.contains(".html")) {
        for (String cachedName : cacheList) {
          if (cachedName != null)
            if (cachedName.contains(fileName)) found = true;
        }
        if (!found) file.delete();
      }
    }
  }

   //This creates or overrides the list.txt file, that contains a list of all cached websites

  public static void upsertCacheListFile() throws IOException, Exception {

    BufferedWriter writer = null;

    try {

      Logger.debug(new StringBuilder("Upserting the webpage to the list.txt..."));

      StringBuilder builder = new StringBuilder();
      for (String webpage : cacheList) {
        builder.append(webpage);
        builder.append('\n');
      }
      
      File list = new File(generateCacheFilepath("list.txt"));

      if (list.exists()) list.delete();
      list.createNewFile();

      writer = new BufferedWriter(new FileWriter(list));
      writer.write(builder.toString());

    } finally {

      if (writer != null) writer.close(); 

    }

  }

	//This saves the webpage onto the root of the project
  	public static void saveWebpage(WebRequest req, WebResponse res)
  	throws IOException, Exception {

    BufferedWriter writer = null;

    try {

      Logger.debug(new StringBuilder("Saving the webpage..."));

      String filename = generateFilenameFromReq(req);
      String path = generateCacheFilepath(filename);

      File webpage = new File(path);

      if (!webpage.exists()) webpage.createNewFile();

      writer = new BufferedWriter(new FileWriter(webpage));
      writer.write(res.getBody());

    } finally {

      if (writer != null) writer.close(); 

    }
  }
}
