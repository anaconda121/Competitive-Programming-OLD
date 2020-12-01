import java.io.*;
import java.util.*;

public class cbarnv2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("cbarn.in"));    
        PrintWriter out = new PrintWriter(new File("cbarn.out"));
        //input
        int rooms = in.nextInt(); in.nextLine();
        int[] capacities = new int[rooms];
        for (int i = 0; i < rooms; i++) {
            capacities[i] = Integer.parseInt(in.nextLine());
        } 
        //start checking all possible rooms
        int smallest = Integer.MAX_VALUE;
        int doorCount = 0;
        int distance = 0;
        for (int i = 0; i < rooms; i++) {
            //iterating over possible entry-points
            int entry = capacities[i];
            distance = 0;
            for (int j = 0; j < rooms; j++) {
                //calculating distances
                if (i == 0) {
                    //entry-point is first element in array, no need to wrap
                    distance += capacities[j] * doorCount; 
                } else {
                    //need to wrap around array
                    if (j == rooms - 1) {
                        int dC = 0;
                        //going forward
                        for (int k = i; k < rooms; k++) {
                            distance += capacities[k] * dC; 
                            dC++;
                        }
                        //going backwards
                        for (int k = 0; k < i; k++) {
                            distance += capacities[k] * dC; 
                            dC++;
                        }
                    }
                }
                doorCount++;
            }
            //System.out.println(distance);
            if (distance < smallest && distance > 0) {
                smallest = distance;
            }
        }
        out.println(smallest);
        out.close();
    }
}