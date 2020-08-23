import java.util.Scanner;
public class luckynumbers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long number = sc.nextLong();
        String strNumber = (String.valueOf(number));
        int luckycharCount = 0;
        for (int i = 0; i < strNumber.length(); i++) {
            Character num = strNumber.charAt(i);
            if (strNumber.length() == 1) {
                System.out.println("NO");
                break;
            } else if (num.charValue() == '4' || num.charValue() == '7') {
                luckycharCount++;
            } else {
                System.out.println("NO");
                break;
            }
        }
        if (luckycharCount >= 1) {
            if (luckycharCount == 4 || luckycharCount == 7) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
}