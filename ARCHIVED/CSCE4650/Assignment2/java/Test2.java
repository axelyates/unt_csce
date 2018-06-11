// Test2.java

// This program tests non-local referencing.

import java.util.*;

class Test2 {

  static int h;  // non-local variable

  public static int area (int x, int y) {
    int z;
    z = 2 * (x * y + (x * h) + y * h);
    return z;
  }

  static Scanner in = new Scanner (System . in);

  public static void main (String args []) {
    int a; int b; int s;
    {
      a = in . nextInt ();
      b = in . nextInt ();
      h = in . nextInt ();
      s = area (a, b);
    }
    System . out . println (s);
  }

}
