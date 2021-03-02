import java.io.*;
import java.util.*;

public class lostcowv3 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("lostcow.in"));    
        PrintWriter out = new PrintWriter(new File("lostcow.out"));
        long x, y = 0;
        long by = 1;
        long dir = 1;
        x = in.nextInt();
        y= in.nextInt();
        long ans = 0;
        while(true) {
            // dir == 1 means Farmer John is moving to the right, and
            // dir == -1 means he is moving to the left.
            if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) {
                // We found Bessie!
                out.println("multiplier: " + Math.abs(y-x));
                ans += Math.abs(y-x);
                out.print(ans);
                break;
            } else {
                // Didn't find Bessie! Add to our running total the cost of
                // moving 'by' units away from the start and back again.
                // Then multiply our next move's length by 2 and switch direction.
                ans += by*2;
                out.println("ans: " + ans);
                by *= 2; // *2 moves fJ back to his starting position
                dir *= -1;
            }
        }
        out.close();
    }
}
