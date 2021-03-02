import java.util.*;

public class question2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        int[] petals = new int[n];
        for (int i = 0; i < n; i++) {
            petals[i] = in.nextInt();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                float avg = calcAvg(i,j,petals);
                for (int k = i; k <= j; k++) {
                    float petal = (float)petals[k];
                    if (petal == avg) {
                        ans++;
                        break;
                    }
                }
            }
        }
        System.out.println(ans + n);
        in.close();
    }
    
    public static float calcAvg(int i, int j, int[] petals) {
        float avg = 0;
        int count = 0;
        for (int k = i; k <= j; k++) {
            avg += petals[k];
            count++;
        }
        avg /= count;
        return avg;
    }
}