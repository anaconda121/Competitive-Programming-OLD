/*
ID: tanisht1
LANG: JAVA
PROG: milk2
*/

import java.io.*;
import java.util.*;

public class milk2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("milk2.in"));    
        PrintWriter out = new PrintWriter(new File("milk2.out"));

        int farmers = in.nextInt();
        in.nextLine();
        int[] startingTimes = new int[farmers];
        int[] endingTimes = new int[farmers];

        for (int i = 0; i < farmers; i++) {
            startingTimes[i] = in.nextInt();
            //in.nextLine();
            endingTimes[i] = in.nextInt();
            if (!(i == farmers - 1)) {
                in.nextLine();
            }
        }

        int largestContinousMilkingTime = 0;
        int milkingTime = 0;
        int largestIdleTime = 0;
        int idleTime = 0;
        for (int i = 0; i < farmers; i++) {
            if (farmers == 1) {
                largestIdleTime = 0;
                largestContinousMilkingTime = endingTimes[i] - startingTimes[i];
            }
            if (i < farmers - 1 && farmers > 1) {
                if (startingTimes[i+1] < endingTimes[i] && startingTimes[i+1] > startingTimes[i]) {
                    milkingTime += endingTimes[i+1] - startingTimes[i];
                    //System.out.println("found milking time: " + milkingTime + " , i: " + i);
                } else if (startingTimes[i+1] < endingTimes[i] && startingTimes[i+1] < startingTimes[i]) {
                    milkingTime += endingTimes[i+1] - startingTimes[i+1];
                    //System.out.println("found milking time: " + milkingTime + " , i: " + i);
                } else {
                    //milkingTime += endingTimes[i] - startingTimes[i];
                    if (milkingTime > largestContinousMilkingTime) {
                        //System.out.println("storing milking time: " + milkingTime + " , i: " + i);
                        largestContinousMilkingTime = milkingTime;
                        milkingTime = 0;
                    }
                    if (startingTimes[i+1] - endingTimes[i] > 1) {
                        idleTime += startingTimes[i+1] - endingTimes[i];
                        //System.out.println("found idle time: " + idleTime + " , i: " + i);
                    }
                }
                if (idleTime > largestIdleTime) {
                    //System.out.println("storing idle time: " + idleTime);
                    largestIdleTime = idleTime;
                    idleTime = 0;
                }
                if (milkingTime > largestContinousMilkingTime) {
                    //System.out.println("storing milking time: " + milkingTime + " , i: " + i);
                    largestContinousMilkingTime = milkingTime;
                    milkingTime = 0;
                }
                //System.out.println("i: " + i + " " + milkingTime);
                //System.out.println("i: " + i + " " + idleTime);
            }
            
        }
        out.println(largestContinousMilkingTime + " " + largestIdleTime);
        //System.out.println(largestIdleTime);

        out.close();
    }
}