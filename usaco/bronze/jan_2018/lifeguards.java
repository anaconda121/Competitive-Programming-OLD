import java.io.*;
import java.util.*;

public class lifeguards {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("lifeguards.in"));
        PrintWriter out = new PrintWriter(new File("lifeguards.out"));
        //input
        int lifeGuards = Integer.parseInt(in.nextLine());
        int[] start = new int[lifeGuards];
        int[] end = new int[lifeGuards];
        for (int i = 0; i < lifeGuards; i++) {
            start[i] = in.nextInt(); end[i] = in.nextInt();
            if (i < lifeGuards - 1) {
                in.nextLine();
            }
        }
        //sort and find corresponding times
        int[] sortedStart = new int[lifeGuards];
        int[] sortedEnd = new int[lifeGuards];
        System.arraycopy(start, 0, sortedStart, 0, lifeGuards);
        Arrays.sort(sortedStart);
        for (int i = 0; i < lifeGuards; i++) {
            for (int j = 0; j < lifeGuards; j++) {
                if (sortedStart[i] == start[j]) sortedEnd[i] = end[j];
            }
        }
        System.out.println(Arrays.toString(sortedStart));
        System.out.println(Arrays.toString(sortedEnd) + "\n");
        //finding times
        int max = 0;
        int time = 0;
        int[] firedStart = new int[lifeGuards-1];
        int[] firedEnd = new int[lifeGuards-1];
        int index = 0;
        for (int i = 0; i < lifeGuards; i++) {
            for (int j = 0; j < lifeGuards; j++) {
                if (j != i) {
                    firedStart[index] = sortedStart[j]; 
                    firedEnd[index] = sortedEnd[j]; index++;
                }
            }
            System.out.println(Arrays.toString(firedStart));
            System.out.println(Arrays.toString(firedEnd));
            int[] times = new int[10];
            index = 0;
            for (int j = 0; j < times.length; j++) {

                if (j >= firedStart[index] && j <= firedEnd[index]) times[j]++;
                if (j > firedEnd[index]) index++;
                if (j > firedEnd[firedEnd.length -1]) break;

            }
            System.out.println(Arrays.toString(times));
            for (int j = 0; j < times.length; j++) {
                if (times[j] != 0) { time++; }
                //times[j] = 0;
            }   
            max = Math.max(max, time);
            time = 0;
            index = 0;
            System.out.print(max + " , " + "\n\n");
        }
        System.out.println(max);
        out.close();
    }
}