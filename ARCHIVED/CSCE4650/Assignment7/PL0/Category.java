// Category.java

// Category is a class to represent the categories of identifiers in a PL/0
// program.

public class Category {

  public static final int CONSTANT  = 0;
  public static final int VARIABLE  = 1;
  public static final int PROCEDURE = 2;

  public static String toString (int category) {
    switch (category) {
      case CONSTANT  : return "constant ";
      case VARIABLE  : return "variable ";
      case PROCEDURE : return "procedure";
      default        : return null;
    }
  }

}
