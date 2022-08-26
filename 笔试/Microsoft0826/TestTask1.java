// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    // public int solution(int[][] A) {
    //     // write your code in [LANGVER]
    // }
    public int solution(int[][] A) {
        int[] row = new int[A.length];
        int[] column = new int[A[0].length];
        int equiRow = 0;
        int equiColumn = 0;

        int position = 0;
        int num = 0;
        for (int i = 0; i < row.length; i++) {
            for (int j = 0; j < column.length; j++) {
                num += A[i][j];
            }
            row[position++] = num;
            num = 0;
        }
        position = 0;
        for (int i = 0; i < column.length; i++) {
            for (int j = 0; j < row.length; j++) {
                num += A[j][i];
            }
            column[position++] = num;
            num = 0;
        }       
        
        for (int i = 0; i < row.length; i++) {
            int leftsum = 0; 
            int rightsum = 0;
            
            for (int j = 0; j < i; j++) { 
                leftsum += row[j];
            }
            
            for (int k = i + 1; k < row.length; k++) { 
                rightsum += row[k];
            }
            
            
            if (leftsum == rightsum) {
                equiRow++;              
            }
        }
        
        
        for (int i = 0; i < column.length; i++) {
            int leftsum = 0; 
            int rightsum = 0; 
            
            for (int j = 0; j < i; j++) { 
                leftsum += column[j];
            }
            
            for (int k = i + 1; k < column.length; k++) { 
                rightsum += column[k];
            }
            
            
            if (leftsum == rightsum) {
                equiColumn++;               
            }
        }
        return equiRow * equiColumn;
    }
}

