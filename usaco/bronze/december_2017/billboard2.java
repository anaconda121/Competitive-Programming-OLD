import java.io.*;
import java.util.*;

public class billboard2 {    
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("billboard.in"));
        PrintWriter out = new PrintWriter(new File("billboard.out"));
        //input
        int bX1 = in.nextInt(); int bY1 = in.nextInt(); // billboard 1
        int bX2 = in.nextInt(); int bY2 = in.nextInt(); // billboard 1
        in.nextLine();
        int b2X1 = in.nextInt(); int b2Y1 = in.nextInt(); // billboard 2
        int b2X2 = in.nextInt(); int b2Y2 = in.nextInt(); // billboard 2
        in.nextLine();
        int tX1 = in.nextInt(); int tY1 = in.nextInt(); // truck
        int tX2 = in.nextInt(); int tY2 = in.nextInt(); // truck

        //calc overlap btwn. 1 and 3
        int xOverlap = (Math.min(bX2, tX2) - Math.max(bX1, tX1));
        int yOverlap = (Math.min(bY2, tY2) - Math.max(bY1, tY1));
        int currOverlap = 0;
        if (xOverlap <= 0 || yOverlap <= 0) {
            //no overlap
            currOverlap += 0;
        } else {
            currOverlap += xOverlap * yOverlap;
        }
        //System.out.println(currOverlap);

        //calc overlap btwn. 2 and 3
        xOverlap = (Math.min(b2X2, tX2) - Math.max(b2X1, tX1));
        yOverlap = (Math.min(b2Y2, tY2) - Math.max(b2Y1, tY1));
        if (xOverlap <= 0 || yOverlap <= 0) {
            //no overlap
            currOverlap += 0;
        } else {
            currOverlap += xOverlap * yOverlap;
        }
        //System.out.println(currOverlap);
        
        //areas 
        int billboard1 = calcArea(bX1, bX2, bY1, bY2);
        int billboard2 = calcArea(b2X1, b2X2, b2Y1, b2Y2);

        int visible = billboard1 + billboard2 - (currOverlap);
        out.println(visible);
        out.close();

    }

    public static int calcArea(int x1, int x2, int y1, int y2) {
        return (Math.abs(x2-x1) * Math.abs(y2-y1));
    }
}