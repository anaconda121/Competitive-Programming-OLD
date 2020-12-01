import java.io.*;
import java.util.*;

public class cbarn {
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
        int smallest = 900000;
        int doorCount = 1;
        int distance = 0;
        for (int j = 0; j< rooms; j++) {
            int currentRoom = capacities[j];
            doorCount = rooms-1;
            int counter = 0;
            for (int i = 0; i < rooms; i++) { 
                //currentRoom != capacities[0]
                if (currentRoom == capacities[0]) {
                    //have to only check forward
                    if (i < rooms - 1 && i > 0) {
                        distance += capacities[i] * doorCount;
                    } else if (i == rooms - 1) {
                        distance += capacities[i] * doorCount;
                    }
                } else {
                    if (i == rooms - 1) {
                        //have to check front and back
                        for (int x = j; x < rooms; x++) {
                            //front check
                            distance += capacities[x] * doorCount;
                        }
                        for (int z = 0; z < j; z++) {
                            //back check
                            distance += capacities[z] * doorCount;
                        }
                    } 
                }
                doorCount--;
            }
            System.out.println(distance);
            //if (i == rooms - 1) {
                if (distance < smallest && distance > 0) {
                    smallest = distance;
                }
                distance = 0;
            //}
        }
        System.out.println(smallest);

        out.close();
    }
}