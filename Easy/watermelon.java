import java.util.Scanner;
public class watermelon {
  public static void main(String[] args) {
    Scanner sc = new Scanner (System.in);
    System.out.println("enter a number");
    int num = sc.nextInt();
    if (num % 2 == 0) {
        System.out.println("YES");
    } else {
        System.out.println("NO");
    }
    sc.close();
  }
}