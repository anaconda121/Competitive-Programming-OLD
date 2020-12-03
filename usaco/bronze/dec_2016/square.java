import java.io.*;
import java.util.*;

public class square {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("square.in"));
        PrintWriter out = new PrintWriter(new File("square.out"));
        //input
        int x1 = in.nextInt(); int y1 = in.nextInt(); int x2 = in.nextInt(); int y2 = in.nextInt();
        int x3 = in.nextInt(); int y3 = in.nextInt(); int x4 = in.nextInt(); int y4 = in.nextInt();
        int[] coords = {x1,x2,x3,x4};
        int[] ycoords = {y1,y2,y3,y4};
        Arrays.sort(coords);
        Arrays.sort(ycoords);
        int xside = Math.abs(coords[3] - coords[0]);
        int yside = Math.abs(ycoords[3] - ycoords[0]);
        int side = Math.max(xside, yside);
        out.println(side*side);
        out.close();
    }
}