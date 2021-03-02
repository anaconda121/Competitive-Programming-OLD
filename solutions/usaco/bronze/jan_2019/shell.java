import java.io.*;
import java.util.*;

public class shell {
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
        //getting max correct answers
        int stone = 0;
        int currStone = 0;
        int maxScore = Integer.MIN_VALUE;
        int score = 0;
        int[] possible = {1,2,3};
        int[] found = {1,2,3};
        boolean first = false; boolean second = false;
        for (int j = 0; j < 3; j++) {
            stone++; 
            score = 0;
            for (int i = 0; i < moves; i++) {
                int swap = 0;
                if (stone == shells[i][0]) {
                    swap = shells[i][1]; //swap is second val
                    second = true;
                } else if (stone == shells[i][1]) {
                    swap = shells[i][0]; //swap is first val
                    first = true;
                } else {
                    System.out.println("\nentering: " + stone);
                    //stone does not swap places
                    for (int k = 0; k < possible.length; k++) {
                        if (possible[k] == shells[i][0] || possible[k] == shells[i][1]) {
                            System.out.println("stone: "  + stone + " , " + possible[k]);
                            found[k] = 0;
                        }
                    }
                    System.out.println(Arrays.toString(found));
                    for (int k = 0; k < possible.length; k++) {
                        if (found[k] != 0) {
                            swap = k + 1;
                            System.out.println("stone: " + stone + " , swap: " + swap);
                            break;
                        }
                    }
                }
                currStone = swap;
                if (shells[i][2] == currStone) {
                    score++;
                    System.out.println("stone: " + currStone + " , " + score);
                }
            }
            System.out.println("stone: " + stone + " , " + score);
            if (score > maxScore) {
                maxScore = score;
            }
        }
        out.println(maxScore);
        
        out.close();
    }
}