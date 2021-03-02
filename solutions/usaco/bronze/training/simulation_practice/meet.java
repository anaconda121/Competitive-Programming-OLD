/* http://darrenyao.com/usacobook/java.pdf page 30 */
import java.io.*;
import java.util.*;

public class meet {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("meet.in"));
        PrintWriter out = new PrintWriter(new File("meet.out"));

        int aliceStartingX = 0;
        int aliceStartingY = 0;
        int bobStartingX = in.nextInt();
        in.nextLine();
        int bobStartingY = in.nextInt();
        in.nextLine();
        int aliceX = in.nextInt();
        in.nextLine();
        int aliceY = in.nextInt();
        in.nextLine();
        int bobX = in.nextInt();
        in.nextLine();
        int bobY = in.nextInt();
        in.nextLine();

        boolean intersect = true; 
        int seconds = 0;
        while (intersect == false) {
            aliceStartingX += aliceX; aliceStartingY += aliceY; 
            bobStartingX -= bobX; bobStartingY -= bobY; 
            seconds++;
            if (aliceStartingX == bobStartingX && aliceStartingY == bobStartingY) {
                //intersects
                out.println(seconds);
                intersect= true;
            }
            if (aliceStartingX > bobStartingX && aliceStartingY > bobStartingY) {
                //never gong to intersect
                out.println(-1);
                break;
            }
        }
        out.close();
    }
}