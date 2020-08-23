import java.util.Scanner;
/* take in a string and return the same string with the first char capitialized */
public class capitialization {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.nextLine();
        String output = word.substring(0, 1).toUpperCase() + word.substring(1);
        System.out.println(output);
        sc.close();
    }
}