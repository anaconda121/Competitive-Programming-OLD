import java.io.*;
import java.util.*;

public class triangles2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("triangles.in"));
        PrintWriter out = new PrintWriter(new File("triangles.out"));
        //input
        int points = Integer.parseInt(in.nextLine());
        int[][] coords = new int[points][2];
        for (int i = 0; i < points; i++) {
            for (int j = 0; j < 2; j++) {
                coords[i][j] = in.nextInt();
            }
            if (i < points - 1) {
                in.nextLine();
            }
        }
        int max = 0;
        for (int i = 0; i < points; i++) {
            for (int j = i + 1; j < points; j++) {
                for (int k = j+1; k < points; k++) {
                    int x1 = coords[i][0]; int y1 = coords[i][1];
                    int x2 = coords[j][0]; int y2 = coords[j][1];
                    int x3 = coords[k][0]; int y3 = coords[k][1];
                    if ((x1 == x3 || x2 == x3 || x1 == x2) && (y1 == y3 || y2 == y3 || y1 == y2)) {
                        int b = Math.max(Math.max(Math.abs(x1 - x3), Math.abs(x1 - x2)), Math.abs(x2 - x3));
                        int h = Math.max(Math.max(Math.abs(y1 - y3), Math.abs(y1 - y2)), Math.abs(y2 - y3));
                        max = Math.max(max, b*h);
                    }
                }
            }
        }
        out.println(max);
        out.close();
    }
}