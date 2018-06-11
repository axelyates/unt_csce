package logger;

import java.io.*;
import java.net.*;
import java.text.*;
import java.util.*;

public class Logger {

  // terminal colors
  private static final String ANSI_RESET = "\u001B[0m";
  private static final String ANSI_BLACK = "\u001B[30m";
  private static final String ANSI_RED = "\u001B[31m";
  private static final String ANSI_GREEN = "\u001B[32m";
  private static final String ANSI_YELLOW = "\u001B[33m";
  private static final String ANSI_BLUE = "\u001B[34m";
  private static final String ANSI_PURPLE = "\u001B[35m";
  private static final String ANSI_CYAN = "\u001B[36m";
  private static final String ANSI_WHITE = "\u001B[37m";

  private static String generateTimestamp() {
    DateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");
    Calendar cal = Calendar.getInstance();
    return dateFormat.format(cal.getTime());
  }

  /**
   * This will log info onto STDOUT
   */
  public static void info(StringBuilder builder) {
    StringBuilder logBuilder = new StringBuilder();
    logBuilder.append(ANSI_CYAN);
    logBuilder.append("INFO [");
    logBuilder.append(generateTimestamp());
    logBuilder.append("]");
    logBuilder.append(ANSI_RESET);
    logBuilder.append("\n");
    logBuilder.append(builder.toString());
    System.out.println(logBuilder.toString());
  }

  /**
   * This will log success info onto STDOUT
   */
  public static void success(StringBuilder builder) {
    StringBuilder logBuilder = new StringBuilder();
    logBuilder.append(ANSI_GREEN);
    logBuilder.append("SUCCESS [");
    logBuilder.append(generateTimestamp());
    logBuilder.append("]");
    logBuilder.append(ANSI_RESET);
    logBuilder.append("\n");
    logBuilder.append(builder.toString());
    System.out.println(logBuilder.toString());
  }

  /**
   * This will log debug statments into STDOUT
   */
  public static void debug(StringBuilder builder) {
    StringBuilder logBuilder = new StringBuilder();
    logBuilder.append(ANSI_YELLOW);
    logBuilder.append("DEBUG [");
    logBuilder.append(generateTimestamp());
    logBuilder.append("]");
    logBuilder.append(ANSI_RESET);
    logBuilder.append("\n");
    logBuilder.append(builder.toString());
    System.out.println(logBuilder.toString());
  }

  /**
   * This will log error statements into STDOUT
   */
  public static void error(StringBuilder builder) {
    StringBuilder logBuilder = new StringBuilder();
    logBuilder.append(ANSI_RED);
    logBuilder.append("ERROR [");
    logBuilder.append(generateTimestamp());
    logBuilder.append("]");
    logBuilder.append("\n");
    logBuilder.append(builder.toString());
    logBuilder.append(ANSI_RESET);
    System.out.println(logBuilder.toString());
  }
}