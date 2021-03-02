import java.util.Scanner;
public class comparing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String first = sc.nextLine();
        String second = sc.nextLine();
        //System.out.println(first.compareTo(second));
        if (first.equals(second)) {
            System.out.println("0");
        } else if (second.compareTo(first) < 0) {
            System.out.println("1");
        } else if (first.compareTo(second) < 0){
            System.out.println("-1");
        }
        sc.close();
    }
}