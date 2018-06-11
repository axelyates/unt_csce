// Test5.java

import java.util.*;

// This program tests class definitions. 

class List {

  int length;
  int max;
  int list [] = new int [100];

  public int initialize (int n) {
    int flag;
    int i;
    max = 100;
    if (n <= 0 || n > max)
      flag = 0;
    else 
      flag = n;
    return flag;
  }

  public int length () { return this . length; }

  public boolean nil () { 
    boolean nul;
    if (length > 0)
      nul = false; 
    else
      nul = true;
    return nul;
  }

  public List cons (int a) {
    int i;
    List cons_list;
    cons_list = new List ();
    cons_list . length = cons_list . initialize (this . length + 1);
    if (cons_list . length == 0)
      cons_list = this;
    else {
      cons_list . list [0] = a;
      i = 0;
      while (i < this . length) {
	cons_list . list [i + 1] = this . list [i];
	i = i + 1;
      }
    }
    return cons_list;
  }

  public int head () { 
    int head;
    if (length == 0) 
      head = 0;
    else
      head = list [0];
    return head;
  }

  public List tail () {
    int i;
    List tail_list;
    tail_list = new List ();
    i = tail_list . initialize (this . length - 1);
    while (i > 0) {
      tail_list = tail_list . cons (this . list [i]);
      i = i - 1;
    }
    return tail_list;
  }

  public boolean equals (List list2) {
    boolean equals;
    int i;
    if (this . length != list2 . length)
      equals = false;
    else {
      equals = true;
      i = 0;
      while (i < length && this . list [i] == list2 . list [i])
	i = i + 1;
      if (i < length) equals = false;
    }
    return equals;
  }

  public int print () {
    int i;
    System . out . println (88888);
    i = 0;
    while (i < length) {
      System . out . println (list [i]);
      i = i + 1;
    }
    System . out . println (88888);
    return length;
  }

}
      
class Test5 {

  public static void main (String args []) {
    int i; 
    List l1; List l2;
    List my_list;
    my_list = new List ();
    System . out . println (my_list . nil ());
    i = my_list . initialize (20);
    i = 10;
    while (i > 0) {
      my_list = my_list . cons (i);
      i = i - 1;
    }
    i = my_list . print ();
    if (my_list . nil ())
      System . out . println (1);
    else
      System . out . println (0);
    System . out . println (my_list . length ());
    System . out . println (my_list . head ());
    i = my_list . tail () . print ();
    l1 = my_list . cons (0);    
    l2 = my_list . cons (0);
    if (l1 . equals (l2))
      System . out . println (1);
    else 
      System . out . println (0);
    if (my_list . equals (l1)) 
      System . out . println (1);
    else 
      System . out . println (0);
  }

}
