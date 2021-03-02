import java.io.*;
import java.util.*;

public class herding {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("herding.in"));    
        PrintWriter out = new PrintWriter(new File("herding.out"));
        //input
        int[] positions = new int[3];
        for (int i = 0; i < 3; i++) {
            positions[i] = in.nextInt();
        }
        Arrays.sort(positions);
        //finding points that will be used for min and max
        int diff1 = positions[1]-positions[0];
        int diff2 = positions[2]-positions[1];
        int min1 = 0; int min2 = 0; int max1 = 0; int max2 = 0;
        if (Math.max(diff1, diff2) == diff1) {
            max1 = positions[0];
            max2 = positions[1];
            min1 = positions[1];
            min2 = positions[2];
        } else {
            max1 = positions[1];
            max2 = positions[2];
            min1 = positions[0];
            min2 = positions[1];
        }
        int[] minMoves = {min1, 0, min2};
        int[] maxMoves = {max1, 0, max2};
        //System.out.println(Arrays.toString(minMoves));
        //System.out.println(Arrays.toString(maxMoves));
        //doing min moves
        int minCount = 0;
        minMoves[1] = minMoves[2]-1;
        if (minMoves[0] + 1 == minMoves[1] && minMoves[1] + 1 == minMoves[2]) {
            minCount = 1;
        } else {
            minCount = 2;
        }
        //doing max moves
        int maxCount = 1;
        while (maxMoves[0] + 1 != maxMoves[1] || maxMoves[1] + 1 != maxMoves[2]) {
            maxMoves[1] = maxMoves[2]-1;
            maxMoves[2] = maxMoves[1];
            maxMoves[1] = maxMoves[2]-1;
            maxCount++;
            //System.out.println(Arrays.toString(maxMoves));
        }
        out.println(minCount);
        out.println(maxCount);

        out.close();
    }
}