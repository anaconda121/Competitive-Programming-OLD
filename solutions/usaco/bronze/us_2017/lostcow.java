import java.io.*;
import java.util.*;

public class lostcow {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("lostcow.in"));    
        PrintWriter out = new PrintWriter(new File("lostcow.out"));

        int start = in.nextInt();
        int bessie = in.nextInt();

        boolean increase = false;
        if (start > bessie) {
            increase = false;
        } else {
            increase = true;
        }

        boolean found = false;
        int distance = 1;
        int totalDistance = 0;
        int counter = 1;
        int previous = start;
        int current = 0;

        while (found == false) {
            if (counter % 2 == 0) {
                //fJ position decrease
                current = Math.abs(start - distance);
                totalDistance += Math.abs(previous - current);
            } else {
                //fJ position increase
                current = Math.abs(previous + distance);
                totalDistance += Math.abs(previous - current);
            }
            if (increase == true) {
                if (current > bessie) {
                    totalDistance -= current - bessie;
                    found = true;
                } else if (current == bessie) {
                    found = true;
                } 
            } else if (increase == false) {
                if (current < bessie) {
                    totalDistance -= bessie - current;
                    found = true;
                } else if (current == bessie) {
                    found = true;
                } 
            }
            
            //System.out.println("current: " + current + " totalDistance: " + totalDistance);
            //System.out.println("previous: " + previous + " current: "+ current);
            distance *= 2;
            previous = current;
            counter++;
        }
        out.println(totalDistance);
        out.close();
    }
}
