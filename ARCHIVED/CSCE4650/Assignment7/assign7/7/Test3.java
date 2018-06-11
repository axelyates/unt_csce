// Test3.java

import java.util.*;

// This program tests recursive functions.

class Test3 {

  public static int facto (int x) {
    int s;
    if (x == 1)
      s = 1;
    else
      s = x * facto (x - 1);
    return s;
  }

  static Scanner in = new Scanner (System . in);

  public static void main (String args []) {
    int i; int fac;
    {
      i = in . nextInt ();
      fac = facto (i);
    }
    System . out . println (fac);
  }
}

