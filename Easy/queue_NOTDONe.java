import java.util.Scanner;
import java.util.Arrays;
public class queue_NOTDONe {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numChildren = sc.nextInt();
        int seconds = sc.nextInt();
        String boyGirlArrangement = sc.nextLine();
        String[] arrayBoyGirl = new String[]{boyGirlArrangement};
        String[] editedArrangement = new String[boyGirlArrangement.length()];
        String arrangement = "";
        System.out.println(boyGirlArrangement);

        for (int i = 0; i < arrayBoyGirl.length - 2; i++) {
            arrayBoyGirl[i] = arrayBoyGirl[i + 1];
        }
        System.out.println(Arrays.toString(arrayBoyGirl));
        for (int i = 0; i < seconds; i++) {
            for (int j = 0; j < numChildren; j++) {
                if ((i > 0 )) {
                    String first = arrayBoyGirl[j - 1];
                    String second = arrayBoyGirl[j];
                    if ((first.equals("B")) && second.equals("G")) {
                        editedArrangement[i] = (String.valueOf(second));
                        editedArrangement[i + 1] = (String.valueOf(first));
                    }
                }
            }
        }
        for (int i = 0; i < editedArrangement.length; i++) {
            arrangement.concat(editedArrangement[i]);
        }
        System.out.println(arrangement);
        sc.close();
    } 
}