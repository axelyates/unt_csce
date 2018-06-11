// Test4.java

import java.util.*;

// This program tests arrays passed as parameters.

class Test4 {

  public static int f (int a [], int i) {
    int x;
    x = a [i];
    a [i] = 0;
    i = 622;
    return x;
  }

  public static void main (String args []) {
    int b [] = new int [100];
    int i; int n;
    n = 40;
    i = 0;
    while (i < 100) {
      b [i] = i * i;
      i = i + 1;
    }
    System . out . println (n);
    System . out . println (f (b, n));
    System . out . println (n);		// n should be unchanged
    System . out . println (b [n]);	// b [n] should be 0
  }

}
