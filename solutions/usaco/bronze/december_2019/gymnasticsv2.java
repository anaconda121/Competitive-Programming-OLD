import java.io.*;
import java.util.*;

public class gymnasticsv2 {
    public static int N = 20;
    public static int K = 10;

    public static void main(String[] args) throws IOException {
        //read and write files
        Scanner in = new Scanner(new File("gymnastics.in"));
        PrintWriter out = new PrintWriter(new File("gymnastics.out"));

        //input
        int row = in.nextInt();
        int cols = in.nextInt();
        in.nextLine();

        int[][] ranks = new int[row][cols];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {    
                ranks[i][j] = in.nextInt();
            }
        }
        System.out.println(Arrays.deepToString(ranks));

        //getting number of consistent pairs in total
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                boolean pair = false;
                if (j < cols - 1) {
                    pair = Nbetter(ranks[i][j], ranks[i][j+1], ranks, row, cols);
                    if (pair == true) {
                        count++;
                    }
                }
            }
        }
        System.out.println(count);
        out.println(count);
    }

    public static boolean better(int a, int b, int session, int[][] data, int cols){
        int apos = 0;
        int bpos = 0;
        for (int i=0; i<cols; i++) {
            if (data[session][i] == a) apos = i;
            if (data[session][i] == b) bpos = i;
        }
        return apos > bpos;
    }
    
    public static boolean Nbetter(int a, int b, int[][]data, int rows, int cols) {
        int total = 0;
        boolean consistentPair = false;
        for (int session=0; session<rows; session++) {
            if (better(a,b,session,data,cols)) {
                total++;
            }
        }
        if (total == rows) {
            consistentPair = true;
        }
        return consistentPair;
    }
}