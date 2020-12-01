import java.util.Scanner;
public class longwords {
    /* https://codeforces.com/problemset/problem/71/A?csrf_token=db3255759a73b9f4a236c1ae8221c048 */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int words = sc.nextInt();
        String[] letters = new String[words + 1];
        for (int i = 0; i < words + 1; i++) {
            String word = sc.nextLine();
            String condense = "";
            if (word.length() > 10)	{
                condense += word.charAt(0);
                int count = word.length() - 2;
                condense += count;
                condense += word.charAt(word.length() - 1);
                letters[i] = condense;
            } else {
                letters[i] = word;
            }
        }
        for (int i = 0; i < letters.length; i++) {
            System.out.println(letters[i]);
        }
    }
}