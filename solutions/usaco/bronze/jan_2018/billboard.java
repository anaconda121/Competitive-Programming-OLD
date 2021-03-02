import java.io.*;
import java.util.*;

public class billboard {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("billboard.in"));
        PrintWriter out = new PrintWriter(new File("billboard.out"));
        //input
        int[] grass = new int[4];
        int[] lawnmower = new int[4];
        for (int i = 0; i < 4; i++) grass[i] = in.nextInt();
        in.nextLine();
        for (int i = 0; i < 4; i++) lawnmower[i] = in.nextInt();
        //calculating overlap
        int xOverlap = Math.min(grass[2], lawnmower[2]) - Math.max(grass[0], lawnmower[0]);
        int yOverlap = Math.min(grass[3], lawnmower[3]) - Math.max(grass[1], lawnmower[1]);
        int currOverlap = 0;
        if (xOverlap <= 0 || yOverlap <= 0) {
            //no overlap
            currOverlap += 0;
        } else {
            currOverlap += xOverlap * yOverlap;
        }
        //finding out if overlap covering whole part of billboard
        int minCover = 0;
        int totalArea= Math.abs(grass[2] - grass[0]) * Math.abs(grass[1] - grass[3]);
        //Math.max(grass[3], lawnmower[3]) == grass[3] && Math.max(grass[2], lawnmower[2]) == grass[2]
        if (Math.abs(grass[3]) > Math.abs(lawnmower[3]) && Math.abs(grass[2]) > Math.abs(lawnmower[2]) || Math.abs(grass[0]) > Math.abs(lawnmower[0])&& Math.abs(grass[1]) > Math.abs(lawnmower[1])) {
            //cover whole billboard
            minCover = totalArea;
        } else {
            minCover = totalArea - currOverlap;
        }
        out.println(minCover);
        out.close();
    }
}