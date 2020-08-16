import java.util.Scanner;
public class team {
    public static void main(String[] args ) {
        Scanner sc = new Scanner(System.in);
        //System.out.println("enter the number of problems: ");
        int probCount = sc.nextInt();
        int[] petya = new int[probCount];
        int[] vasya = new int[probCount];
        int[] tonya = new int[probCount];
        int sureCount = 0;
        int answer = 0;
    
        for (int i = 0; i < probCount; i++) {
            sureCount = 0;
            //System.out.println("enter who is sure, separate by spaces");
            petya[i] = sc.nextInt();
            if (petya[i] == 1) {
                sureCount++;
            }
            vasya[i] = sc.nextInt();
            if (vasya[i] == 1) {
                sureCount++;
            }
            tonya[i] = sc.nextInt();
            if (tonya[i] == 1) {
                sureCount++;
            }
            if (sureCount >= 2) {
                answer++;
            }
        }
        System.out.println(answer);
        sc.close();
    }
}