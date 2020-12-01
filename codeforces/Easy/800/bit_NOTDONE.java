import java.util.Scanner;
public class bit_NOTDONE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numStatements = sc.nextInt();
        System.out.println(numStatements);
        String[] statements = new String[numStatements];
        int x = 0;

        for (int i = 0; i < numStatements; i++) {        

            statements[i] = sc.nextLine();
            System.out.println(statements[i] 
            + "huh");
            if (statements[i].equals("++X")) {
                x += 1;
            } else if (statements[i].equals("--X")) {
                x -= 1;
            }
            i++;
        }

        System.out.println(x);
        sc.close();
    }
}