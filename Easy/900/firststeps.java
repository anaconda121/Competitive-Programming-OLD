import java.util.Scanner;
public class firststeps {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int days = sc.nextInt();
        int[] money = new int[days];
        for (int i = 0; i < money.length; i++) {
            money[i] = sc.nextInt();
        }
        subsegmentNumbers(money);
    }
    public static void subsegmentNumbers(int[] numbers) {
        int counter = 0;
        int largest = Integer.MIN_VALUE;
        for (int i = 0; i < numbers.length; i++) {
            if (i < numbers.length - 1 && numbers[i] <= numbers[i+1]) {
                counter++;
            } else {
                System.out.println("resetting");
                counter = 0;
            }
            if (largest < numbers[i]) {
                largest = i;
            }
        }
        if (largest == numbers.length - 1){
            counter++;
        }
        System.out.println(counter);
    }
}