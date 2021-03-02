import java.io.*;
import java.util.*;
import java.awt.Rectangle;
/* https://www.youtube.com/watch?v=gTyvtMZ8kGk&ab_channel=AndyrooDoesCoding*/
public class billboard3 {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("billboard.in"));
        PrintWriter out = new PrintWriter(new File("billboard.out"));
        //input
        int[] grass = new int[4];
        int[] lawnmower = new int[4];
        for (int i = 0; i < 4; i++) grass[i] = in.nextInt();
        in.nextLine();
        for (int i = 0; i < 4; i++) lawnmower[i] = in.nextInt();
        //calc area
        Rectangle grassBoard = new Rectangle(grass[0], grass[2], Math.abs(grass[2]-grass[0]), Math.abs(grass[3]-grass[1]));
        Rectangle lawnBoard = new Rectangle(lawnmower[0], lawnmower[2], Math.abs(lawnmower[2]-lawnmower[0]), Math.abs(lawnmower[3]-lawnmower[1]));
        int grassArea = Math.abs(grass[2] - grass[0]) * Math.abs(grass[1] - grass[3]);
        //calc overlap
        int xOverlap = Math.min(grass[2], lawnmower[2]) - Math.max(grass[0], lawnmower[0]);
        int yOverlap = Math.min(grass[3], lawnmower[3]) - Math.max(grass[1], lawnmower[1]);
        int currOverlap = 0;
        if (xOverlap <= 0 || yOverlap <= 0) currOverlap += 0;
        else currOverlap += xOverlap * yOverlap;
        //calc how many corners
        int corners = 0;
        if (lawnBoard.contains(grass[0], grass[1])) corners++;
        if (lawnBoard.contains(grass[2], grass[3])) corners++;
        if (lawnBoard.contains(grass[2], grass[1])) corners++;
        if (lawnBoard.contains(grass[0], grass[3])) corners++;
        System.out.println(corners);
        System.out.println(grass[0] + " , " + grass[1]);
        System.out.println(lawnBoard.contains(grass[0], grass[1]));
        System.out.println(lawnBoard.contains(grass[0], grass[3]));
        int minArea = 0;
        if (lawnBoard.contains(grassBoard)) {
            minArea = 0;
        }else {
            if (corners < 2) minArea = grassArea;
            else if(corners == 2) minArea = grassArea - currOverlap;
            else if (corners >= 2) minArea = 0;
        }

        out.println(minArea);
        out.close();
    }
}