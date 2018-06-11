// Test6.java

import java.util.*;

class Test6 {

  static Scanner in = new Scanner (System . in);

  public static void main (String args []) {
    int q; int r; int x; int y;
    x = in . nextInt ();
    y = in . nextInt ();
    q = 0;
    r = x;
    while (r >= y) {
      q = q + 1;
      r = r - y;
    }
    System . out . println (q);
    System . out . println (r);
  }

}
