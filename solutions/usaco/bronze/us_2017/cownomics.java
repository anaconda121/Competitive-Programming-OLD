import java.io.*;
import java.util.*;

public class cownomics {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("cownomics.in"));
        PrintWriter out = new PrintWriter(new File("cownomics.out"));
        //input
        int data = in.nextInt(); int chars = in.nextInt(); in.nextLine();
        char[][] spotty = new char[data][chars]; char[][] plain = new char[data][chars];
        for (int i = 0; i < data; i++) spotty[i] = in.nextLine().toCharArray();
        for (int i = 0; i < data; i++) plain[i] = in.nextLine().toCharArray();
        //finding unique chars used per col
        int count = 0;
        for (int i = 0; i < chars; i++) {
            char[] arr = new char[data];
            char[] arr2 = new char[data];
            for (int j = 0; j < data; j++) {
                arr[j] = spotty[j][i];
                arr2[j] = plain[j][i];
            }
            //checking if column arrays have any similarities
            boolean sim = similar(arr, arr2);
            if (sim == false) {
                count++;
            }

        }
        out.println(count);

        out.close();
    }

    public static boolean similar(char[] arr, char[] arr2) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr2.length; j++) {
                if (arr[i] == arr2[j]) {
                    return true;
                }
            }
        }
        return false;
    }
}