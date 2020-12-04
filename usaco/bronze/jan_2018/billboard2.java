import java.io.*;
import java.util.*;
/* https://www.youtube.com/watch?v=gTyvtMZ8kGk&ab_channel=AndyrooDoesCoding*/
public class billboard2 {
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
        //if 1 corner of grass billboard is covered, tarp = whole area
        //if 2 corners are covered, tarp = whole area - overlap
        //if 3 / 4 corners are covered, tarp = 0
        //if 0 corners are covered, tarp = whole area
        int covered = covers(grass[0], grass[2], grass[1], grass[1], grass[2], grass[0], grass[3], grass[3], lawnmower[0], lawnmower[2], lawnmower[1], lawnmower[1], lawnmower[2], lawnmower[0], lawnmower[3], lawnmower[3]);
        //System.out.println("output: " + covered);

        if (covered == 1 || covered== 0) minCover = totalArea;
        if (covered == 2) minCover = totalArea - currOverlap;
        if (covered >= 2) minCover = 0;
        //System.out.println(covered);
        out.println(minCover);
        out.close();
    }

    public static int covers(int x1, int x2, int y1, int y2, int x3, int x4, int y3, int y4, int x5, int x6, int y5, int y6, int x7, int x8, int y7, int y8) {
        //x1-x2-x3-x4 and y1-y2-y3-y4 are grass billboard
        int covered = 0;
        if (Math.abs(x1) < Math.abs(x5) && Math.abs(y1) < Math.abs(y5)) { covered++;}
        if (Math.abs(x2) < Math.abs(x6) && Math.abs(y2) < Math.abs(y6)) { covered++;}
        if (Math.abs(x3) < Math.abs(x7) && Math.abs(y3) < Math.abs(y7)) { covered++;}
        if (Math.abs(x4) < Math.abs(x8) && Math.abs(y4) < Math.abs(y8)) { covered++;}
        //System.out.println(x4 + " , " + y4);
        //System.out.println(x8 + " , " + y8);
        return covered;
    }
}