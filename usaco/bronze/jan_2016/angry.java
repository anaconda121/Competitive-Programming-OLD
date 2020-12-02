import java.io.*;
import java.util.*;

public class angry {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("angry.in"));    
        PrintWriter out = new PrintWriter(new File("angry.out"));
        //input
        int bales = in.nextInt(); in.nextLine();
        int[] positions = new int[bales];
        for (int i = 0; i < bales; i++) {
            positions[i] = Integer.parseInt(in.nextLine());
        }
        Arrays.sort(positions);
        //finding possible indexes bales that have highest likelihood for success
        int[] indexes = new int[positions.length];
        int index = 0;
        for (int i = 0; i < positions.length; i++) {
            if (i > 0 && i < positions.length - 1) {
                if (positions[i-1] + 1 == positions[i] && positions[i+1] - 1 == positions[i]) {
                    indexes[index] = i; index++;
                }
            }
        }
        //testing explosion sequence
        System.out.println(Arrays.toString(indexes));
        int[] positionsCopy= new int[bales];
        System.arraycopy(positions, 0, positionsCopy, 0, bales);
        int range = 1;
        for (int i = 0; i < indexes.length; i++){
            if (indexes[i] == 0) break;
            if (indexes[i] > 0) {
                explosion(positionsCopy[indexes[i]], indexes[i], positionsCopy, range);
                System.out.println(Arrays.toString(positionsCopy));
            }
        }
        out.close();
    }

    public static void explosion(int val, int index, int[] arr, int range) {
        boolean back = true; //calc back side explosion first
        //for (int i = 0; i < arr.length; i++) {
        if (back == true) {
            if (index == 0) {
                //reached front of array, back side explosion maxed out
                back = false;
                range = 1;
            }
            else if (val - range == arr[index-1]) {
                System.out.println("entered");
                index -= 1;
                int currVal = arr[index];
                arr[index] = 0;
                explosion(currVal, index, arr, range++);
            }
        }
        if (back == false) {
            if (index == arr.length - 1) {
                //front side done, explosion should be wrapped up
                back = true;
            }
            if (val + range == arr[index+1]) {
                index += 1;
                int currVal = arr[index];
                arr[index] = 0;
                explosion(currVal, index, arr, range++);
            }
        }    
        System.out.println("final arr: " + Arrays.toString(arr));
            
        //}
    }
}