// Test1.java

import java.util.*;

class Test1 {

  public static void main (String args []) {
    int my_list [] = new int [100]; 
    int my_list_tl [] = new int [100];
    int r; int h; int i;
    {
      r = 2;
      while (r < 5) {  
        my_list [r - 2] = r;
        r = r + 1;
      }  
      h = my_list [0];
      i = r;
      while (i > 0) {
	my_list_tl [i - 1] = my_list [i];
	i = i - 1;
      }
    }
    System . out . println (h); 
    System . out . println (my_list_tl [0]);
  }
}
