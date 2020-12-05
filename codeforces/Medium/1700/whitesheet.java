import java.io.*;
import java.util.*;
public class whitesheet {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //input
        long x1 = in.nextInt(); long y1 = in.nextInt(); long x2 = in.nextInt(); long y2 = in.nextInt(); in.nextLine();
        long x3 = in.nextInt(); long y3 = in.nextInt(); long x4 = in.nextInt(); long y4 = in.nextInt(); in.nextLine();
        long x5 = in.nextInt(); long y5 = in.nextInt(); long x6 = in.nextInt(); long y6 = in.nextInt(); 

        //calculating overlap
        long xOverlap = (Math.min(x4,x2) - Math.max(x1,x3));
        long yOverlap = (Math.min(y4,y2) - Math.max(y1,y3));
        long currOverlap = 0;
        if (xOverlap <= 0 || yOverlap <= 0) {
            //no overlap
            currOverlap += 0;
        } else {
            currOverlap += xOverlap * yOverlap;
        }
        System.out.println("\n" + currOverlap);

        xOverlap = (Math.min(x2,x6) - Math.max(x1,x5));
        yOverlap = (Math.min(y2,y6) - Math.max(y1,y5));
        //System.out.println(xOverlap + ", " + yOverlap);
        if (xOverlap <= 0 || yOverlap <= 0) {
            //no overlap
            currOverlap += 0;
        } else {
            currOverlap += xOverlap * yOverlap;
        }
        System.out.println("\n" + currOverlap);
        long area = Math.abs(Math.abs(x2-x1) * Math.abs(y2-y1));
        System.out.println(area);
        if (currOverlap >= 0 && currOverlap < area) {
            System.out.println("YES");
        } else System.out.println("NO");
    }
}