import java.io.*;
import java.util.*;

public class speeding {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("speeding.in"));
        PrintWriter out = new PrintWriter(new File("speeding.out"));
        //input
        int segments = in.nextInt(); int bessiePath = in.nextInt(); in.nextLine();
        int[] roadTimes = new int[segments]; int[] bessieTimes = new int[bessiePath]; int time = 0;
        int[] roadMph = new int[segments]; int[] bessieMph = new int[bessiePath];
        for (int i = 0; i < segments; i++) {
            time += in.nextInt();
            roadTimes[i] = time; roadMph[i] = in.nextInt(); in.nextLine();
        }
        time = 0;
        for (int i = 0; i < bessiePath; i++) {
            time += in.nextInt();
            bessieTimes[i] = time; bessieMph[i] = in.nextInt(); 
            if (i < bessiePath - 1 ){
                in.nextLine();
            }
        }
        //System.out.println(Arrays.toString(roadMph));
        //System.out.println(Arrays.toString(bessieMph));
        //calc time
        int max = Integer.MIN_VALUE;
        int diff = 0;
        for (int i = 0; i < segments +1; i++) {
            for (int j = 0; j < 101; j++) {
                int rIndex = calcIndexRoad(roadTimes, j); int bIndex = calcIndexBessie(bessieTimes, j);
                //System.out.println("time j : " + j + " , " + rIndex + " , " + bIndex);
                if (j <= roadTimes[rIndex] && j <= bessieTimes[bIndex]) {
                    //calc respective mphs
                    diff = calcMphDiff(j, roadMph[rIndex], bessieMph[bIndex]);
                    //System.out.println("time : " + j + " , " + roadTimes[rIndex] + " , " + bessieTimes[bIndex] + " , " + diff);
                    
                }
                
                if (diff > max) {
                    //System.out.println("storing " + diff);
                    max = diff;
                }
                diff = 0;
            }
        }
        if (max < 0 ) {
            out.println(0);
        } else {
            out.println(max);
        }
        out.close();
    }

    public static int calcMphDiff(int time, int roadMph, int bessieMph) {
        return bessieMph - roadMph;
    }

    public static int calcIndexRoad(int[] roads, int time) {
        if (time <= roads[0]) {
            return 0;
        }
        for (int i = 0; i < roads.length; i++) { 
            if (i < roads.length - 1) {
                if (roads[i] < time && time <= roads[i+1]) {
                    return i + 1;
                }
            }
        }
        return -1;
    }

    public static int calcIndexBessie(int[] bessie, int time) {
        if (time <= bessie[0]) {
            return 0;
        }
        for (int i = 0; i < bessie.length; i++) {
            if (i < bessie.length - 1) {
                if (bessie[i] < time && time <= bessie[i+1]) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
}