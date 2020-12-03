import java.io.*;
import java.util.*;

public class lifeguards2 {
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
        //System.out.println(Arrays.toString(start));
        //System.out.println(Arrays.toString(end));
        int max = 0;
        int count = 0;
        int[] times = new int[1000];
        for (int i = 0; i < lifeGuards; i++) {
            for (int j = 0; j < lifeGuards; j++) {
                if (j != i) {
                    for (int k = start[j]; k < end[j]; k++) {
                        times[k]++;
                    }
                }
            }
            for (int j = 0; j < 1000; j++) {
                if (times[j] > 0) {
                    count++;
                }
            }
            max = Math.max(max, count);
            count = 0;
            Arrays.fill(times, 0);
        }
        out.println(max);
        out.close();
    }
}