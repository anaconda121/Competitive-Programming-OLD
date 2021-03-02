import java.io.*;
import java.util.*;

public class revegetate {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("revegetate.in"));
        PrintWriter out = new PrintWriter(new File("revegetate.out"));
        //input
        int N = in.nextInt();
        int M = in.nextInt();
        int[][] pref = new int[M][2];
        for (int i = 0; i < M; i++) {
            pref[i][0] = in.nextInt();
            pref[i][1] = in.nextInt();
        }
        //creating possiblities matrix
        int[][] possible = new int[N][4];
        int start = 1;
        int[] types = {1,2,3,4};
        for (int i = 0; i < M; i++) {
            int first = pref[i][0];
            int second = pref[i][1];
            if (i == 0) {
                possible[first-1][0] = start;
                possible[second-1][0] = start+1;
            } else {
                if (possible[first-1][0] != 0) {
                    //already mentioned, need to put multiple
                    int counter = 0;
                    for (int j = 0; j < types.length; j++) {
                        if (types[j] != possible[first-1][0]) {
                            possible[second-1][counter] = types[j];
                            counter++;
                        }
                    }
                } else if (possible[second-1][0] != 0) {
                    int counter = 0;
                    for (int j = 0; j < types.length; j++) {
                        if (types[j] != possible[second-1][0]) {
                            possible[first-1][counter] = types[j];
                            counter++;
                        }
                    }
                } else if (possible[first-1][0] == 0) {
                    //unclaimed
                    possible[first-1][0] = start;
                } else if (possible[second-1][0] == 0) {
                    possible[second-1][0] = start;
                }
            }
        }
        System.out.println(Arrays.deepToString(possible));
        out.close();
    }
}
