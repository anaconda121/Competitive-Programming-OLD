import java.io.*;
import java.util.*;

public class lostcowv2 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("lostcow.in"));    
        PrintWriter out = new PrintWriter(new File("lostcow.out"));

        int farmerJohn = in.nextInt();
        int bessie = in.nextInt();

        int distance = 1;
        int totalDistance = 0;
        int counter = 1;
        int[] farmerJohnDist = new int[(int) (9 * Math.abs((double) farmerJohn - bessie))];
        farmerJohnDist[0] = farmerJohn;
        int index = 1;
        boolean reached = false;
        while (reached == false) {
            if (counter % 2 == 0) {
                farmerJohnDist[index] = (farmerJohn - distance);
            } else {
                farmerJohnDist[index] = (farmerJohn + distance);
            }
            if (farmerJohnDist[index] >= bessie) {
                //totalDistance += bessie - Math.abs((double) bessie - farmerJohnDist);
                reached = true;
            }
            index++;
            distance *= 2;
            counter++;
        }

        for (int i = 0; i < farmerJohnDist.length; i++) {
            if (i < farmerJohnDist.length - 1) {
                totalDistance += Math.abs(farmerJohnDist[i] - farmerJohnDist[i+1]);
            } else{
                if (farmerJohnDist[i] > bessie) {
                    totalDistance += bessie - Math.abs((double) bessie - farmerJohnDist[i]);
                } else {
                    totalDistance += Math.abs(farmerJohnDist[i] - farmerJohnDist[i-1]);
                }
            }
        }
        out.println(totalDistance);

        out.close();
    }
}