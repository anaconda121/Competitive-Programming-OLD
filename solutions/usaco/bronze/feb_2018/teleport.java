import java.io.*;
import java.util.*;

public class teleport {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("teleport.in"));    
        PrintWriter out = new PrintWriter(new File("teleport.out"));
        //input
        int start = in.nextInt();
        int end = in.nextInt();
        int teleporter1 = in.nextInt();
        int teleporter2 = in.nextInt();
        //calculating distance from both teleporter
        int dist1 = 0;
        int dist2 = 0;
        int ans = 0;
        //dist1 - go to t1, teleport to 2, and go to end
        //dist2 - got to t2, teleport to 1, and go to end
        if (start == end) {
            ans = 0;
        } else {
            dist1 = Math.abs(start - teleporter1) + Math.abs(end - teleporter2);
            dist2 = Math.abs(start - teleporter2) + Math.abs(end - teleporter1);
            ans = Math.min(dist1, dist2);
            if (Math.abs(start-end) < ans) {
                ans = Math.abs(start-end);
            }
        }
        out.println(ans);
        out.close();
    }
}