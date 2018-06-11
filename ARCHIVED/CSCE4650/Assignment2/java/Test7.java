// Test7.java

import java.util.*;

// This class performs matrix multiplication.

class Test7 {

  public static int initializeMatrix (int matrix [][], int n1, int n2) {
    int i; int j;
    i = 0;
    while (i < n1) {
      j = 0;
      while (j < n2) {
        matrix [i][j] = (n1 - i) * (n2 - j);
        j = j + 1;
      }
      i = i + 1;
    }
    return 1;
  }

  public static int printMatrix (int matrix [][], int n1, int n2) {
    int i; int j;
    i = 0;
    while (i < n1) {
      j = 0;
      while (j < n2) {
        System . out . println (matrix [i][j]);
        j = j + 1;
      }
      i = i + 1;
    }
    return 1;
  }

  public static int multiplyMatrix (int a [][], int b [][], int c [][], 
      int n1, int n2, int n3) {
    int i; int j; int k;
    i = 0;
    while (i < n1) {
      j = 0;
      while (j < n3) {
        k = 0;
        c [i][j] = 0;
        while (k < n2) {
          c [i][j] = c [i][j] + a [i][k] * b [k][j];
          k = k + 1;
        }
        j = j + 1;
      }
      i = i + 1;
    }
    return 1;
  }

  public static void main (String args []) {
    int matrixA [][] = new int [4][3]; 
    int matrixB [][] = new int [3][2]; 
    int matrixC [][] = new int [4][2]; 
    int i; 
    i = initializeMatrix (matrixA, 4, 3);
    System . out . println (10431043);
    i = printMatrix (matrixA, 4, 3);
    i = initializeMatrix (matrixB, 3, 2);
    System . out . println (11321132);
    i = printMatrix (matrixB, 3, 2);
    i = multiplyMatrix (matrixA, matrixB, matrixC, 4, 3, 2);
    System . out . println (12421242);
    i = printMatrix (matrixC, 4, 2);
    // example from http://en.wikipedia.org/wiki/Matrix_multiplication
    matrixA [0][0] = 14; matrixA [0][1] =  9; matrixA [0][2] =  3;
    matrixA [1][0] =  2; matrixA [1][1] = 11; matrixA [1][2] = 15;
    matrixA [2][0] =  0; matrixA [2][1] = 12; matrixA [2][2] = 17;
    matrixA [3][0] =  5; matrixA [3][1] =  2; matrixA [3][2] =  3;
    matrixB [0][0] = 12; matrixB [0][1] = 25; 
    matrixB [1][0] =  9; matrixB [1][1] = 10;
    matrixB [2][0] =  8; matrixB [2][1] =  5;
    i = multiplyMatrix (matrixA, matrixB, matrixC, 4, 3, 2);
    System . out . println (12421242);
    i = printMatrix (matrixC, 4, 2);
  }

}
