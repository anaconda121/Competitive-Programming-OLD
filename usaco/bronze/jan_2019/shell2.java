import java.io.*;
import java.util.*;

public class shell2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("shell.in"));
        PrintWriter out = new PrintWriter(new File("shell.out"));
        //input
        int moves = in.nextInt(); in.nextLine();
        int[][] shells = new int[moves][3];
        for (int i = 0; i < moves; i++) {
            shells[i][0] = in.nextInt();
            shells[i][1] = in.nextInt();
            shells[i][2] = in.nextInt();
            if (i < moves - 1) {
                in.nextLine();
            }
        }
        int startingStone = 1; int rightStone = startingStone; int score = 0; int swap = startingStone; int max = Integer.MIN_VALUE;
        int[] possible = {1,2,3};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < moves; j++) {
                if (swap == shells[j][0]) {
                    //swap == second val
                    swap = shells[j][1];
                    rightStone = swap;
                } else if (swap == shells[j][1]) {
                    //swap == first val
                    swap = shells[j][0];
                    rightStone = swap;
                } else {
                    if (j == 0) {
                        rightStone = startingStone;
                    } else {
                        rightStone = swap;
                    }
                    /*
                    for (int k = 0; k < 3; k++) {
                        if (possible[k] != shells[j][0] && possible[k] != shells[j][1]) {
                            //found value of swap
                            swap = possible[k];
                            rightStone = swap;
                        }
                    }*/
                }
                if (shells[j][2] == rightStone) {
                    score++;
                    System.out.println("score: " + score + " , " + rightStone);
                }
            }
            //checking to see if there is a new max score
            if (score > max && score > 0) {
                max = score;
            }
            startingStone++;
            score = 0;
        }
        System.out.println(max);
        out.close();
    }
}