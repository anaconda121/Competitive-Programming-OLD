import java.io.*;
import java.util.*;

public class hoofball {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("hoofball.in"));    
        PrintWriter out = new PrintWriter(new File("hoofball.out"));
        //input
        int N = in.nextInt();
        int[] positions = new int[N];
        for (int i = 0; i < N; i++) {
            positions[i] = in.nextInt();
        }
        Arrays.sort(positions);
        boolean[] touched = new boolean[N];
        int ball = 1;
        int currIndex = 0;
        boolean newBall = false;
        int next = 0;
        for (int i = 0; i < N; i++) {
            if (i > 0 && i < N-1) {
                touched[i] = true;
                int backDist = Math.abs(positions[i]-positions[i-1]);
                int frontDist = Math.abs(positions[i]-positions[i+1]);
                System.out.println(i + " , " + backDist + " , " + frontDist);
                if (backDist == frontDist) {
                    next = positions[i-1];
                } else {
                    next = Math.min(backDist, frontDist);
                    if (next == backDist) {
                        next = positions[i-1];
                    } else {
                        next = positions[i+1];
                    }
                }
                if (next == positions[i+1]) {
                    if (touched[i+1] == true) {
                        ball++;
                    }
                } else if (next == positions[i-1]) {
                    if (touched[i-1] == true) {
                        ball++;
                    }
                }
                if (next == positions[i+1]) {
                    touched[i+1] = true;
                } else {
                    if (i > 0) {
                        touched[i-1] = true;
                    }
                }
                
            } else if (i == 0) {
                touched[i+1] = true;
            }
            System.out.println(Arrays.toString(touched) + "\n");
        }
        int count = N;
        for (int i = 0; i < N; i++) {
            if (touched[i] == true) {
                count--;
            }
        }
        System.out.println(ball);
        out.println(count);
        out.close();
    }
}