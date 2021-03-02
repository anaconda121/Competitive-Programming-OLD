import java.io.*;
import java.util.*;

public class triangles {
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
        //System.out.println(Arrays.deepToString(coords));
        int[][] xaxis = new int[points][2];
        int[][] yaxis = new int[points][2];
        int xindex = 0;
        int yindex = 0;
        for (int i = 0; i < points; i++) {
            int currX = coords[i][0];
            int currY = coords[i][1];
            for (int j = i+1; j < points; j++) {
                int currX2 = coords[j][0];
                int currY2 = coords[j][1];
                if (currX2-currX==0) {
                    //points are parallel to y-axis
                    System.out.println("adding");
                    yaxis[yindex][0] = currX; yaxis[yindex][1] = currY;
                    yindex++;
                    yaxis[yindex][0] = currX2; yaxis[yindex][1] = currY2;
                } else {
                    double slope = calcSlope(currX, currY, currX2, currY2);
                    //points are parallel to x-axis
                    if (slope == 0.0) {
                        xaxis[xindex][0] = currX; xaxis[xindex][1] = currY;
                        xindex++;
                        xaxis[xindex][0] = currX2; xaxis[xindex][1] = currY2;
                    }
                }
            }
        }
        System.out.println(Arrays.deepToString(xaxis));
        System.out.println(Arrays.deepToString(yaxis));
        out.close();
    }

    public static double calcSlope(int x1, int y1, int x2, int y2) {
        //line parallel to x-axis have slope of 0
        //lines parallel to y-axis have x2-x1=0
        return (y2-y1) / (x2 - x1);
    }
}