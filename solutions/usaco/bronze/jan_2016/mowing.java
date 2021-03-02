import java.io.*;
import java.util.*;

public class mowing {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("mowing.in"));    
        PrintWriter out = new PrintWriter(new File("mowing.out"));
        //input
        int lines = in.nextInt(); in.nextLine();
        char[] directions = new char[lines];
        int[] movements = new int[lines];
        for (int i = 0; i < lines; i++) {
            directions[i] = in.next().charAt(0); 
            movements[i] = in.nextInt(); 
            if (i < lines - 1) {
                in.nextLine();
            }
        }
        //constants
        int[][] path2 = new int[2005][2005];
        int fJX = 1000; int fJY = 1000;
        path2[fJX][fJY] = 1; //fJ starting
        int[] repeats = new int[1000];
        int index = 0;
        int counter = 1;

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < movements[i]; j++) {
                int intersect = 0;
                if (directions[i] == 'N') {
                    //north
                    fJY += 1;
                    intersect = intersects(path2, fJX, fJY);
                    if (intersect != -1) {
                        //fJ reached cell again
                        repeats[index] = (counter + 1) - intersect;
                        index++;
                    }
                    path2[fJX][fJY] = counter + 1;
                } else if (directions[i] == 'E') {
                    //east
                    fJX += 1;
                    intersect = intersects(path2, fJX, fJY);
                    if (intersect != -1) {
                        //fJ reached cell again
                        repeats[index] = (counter + 1) - intersect;
                        index++;
                    }
                    path2[fJX][fJY] = counter + 1;
                } else if (directions[i] == 'S') {
                    //south
                    fJY -= 1;
                    intersect = intersects(path2, fJX, fJY);
                    if (intersect != -1) {
                        //fJ reached cell again
                        repeats[index] = (counter + 1) - intersect;
                        index++;
                    }
                    path2[fJX][fJY] = counter + 1;
                } else if (directions[i] == 'W') {
                    //west
                    fJX -= 1;
                    intersect = intersects(path2, fJX, fJY);
                    if (intersect != -1) {
                        //fJ reached cell again
                        repeats[index] = (counter + 1) - intersect;
                        index++;
                    }
                    path2[fJX][fJY] = counter + 1;
                }
                counter++;
                //System.out.println(directions[i] + " , " + "counter: "  + counter + " , fJX: " + fJX + " , fJY: " + fJX + " , intersect: " + intersect);

            }
        }
        //System.out.println(Arrays.toString(repeats));
        int smallest = 500;
        if (index > 0) {
            Arrays.sort(repeats);
            for (int i = 0; i < repeats.length; i++) {
                if (repeats[i] > 0) {
                    out.print(repeats[i]);
                    break;
                }
            }
        } else {
            out.print(-1);
        }

        out.close();
        //System.out.println(Arrays.deepToString(path2));

    }
    
    public static int intersects(int[][] lawn, int fJX, int fJY) {
        if (lawn[fJX][fJY] != 0) {
            return lawn[fJX][fJY];
        }
        return -1;
    }
}