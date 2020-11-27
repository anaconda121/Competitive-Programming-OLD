/*
ID: tanisht1
LANG: JAVA
TASK: gymnastics
*/

import java.io.*;
import java.util.*;

public class gymnastics {
    public static void main(String[] args) throws IOException {
        //read and write files
        Scanner in = new Scanner(new File("gymnastics.in"));
        PrintWriter out = new PrintWriter(new File("gymnastics.out"));

        //input
        int row = in.nextInt();
        int cols = in.nextInt();
        int[][] ranks = new int[row][cols];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {    
                ranks[i][j] = in.nextInt();
            }
        }

        //calculate all the possible consistent pairs for the first row
        int [] firstRow = new int[cols];
        for (int i = 0; i < cols; i++) {
            firstRow[i] = ranks[0][i];
        }
        int count = calcPossibleConsistentPairs(cols);
        int[][] consistentPairs = new int[count][2];
        consistentPairs = pairs(0, cols, count, firstRow);

        out.println(Arrays.deepToString(ranks));
        out.println(Arrays.deepToString(consistentPairs));

        out.close();
    }
    //cC = 0, 
    public static int[][] pairs(int currentCow, int cows, int count, int[]row) {
        int[][] consistentPairs = new int[count][2];
        int currentCount = 0;
        for (int i = currentCow; i < cows; i++) {
            for (int j = currentCow; j < cows; j++) {
                int index = currentCow + 1;
                for (int k = 0; k < 2; k++) {
                    consistentPairs[currentCount][k] = row[currentCow];
                    consistentPairs[currentCount][k] = row[index];
                    index++;
                    break;
                }
            }

            //cows--;
            currentCow++;
            pairs(currentCow, cows, count, row);   
        }
        return consistentPairs;
    }

    public static int calcPossibleConsistentPairs(int cows) {
        int consistentPairCount = 0;
        while (cows > 0) {
            consistentPairCount += cows - 1;
            cows--;
        }
        return consistentPairCount;
    }
} 