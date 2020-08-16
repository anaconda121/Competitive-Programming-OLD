import java.util.Scanner;
public class domino {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int rows = sc.nextInt();
        int cols = sc.nextInt();
        int totalArea = rows * cols;
        int squares = (int) (totalArea / 2);
        System.out.println(squares);
        sc.close();
    }
}