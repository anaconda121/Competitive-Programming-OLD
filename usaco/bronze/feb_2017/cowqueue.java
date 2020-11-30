import java.io.*;
import java.util.*;

public class cowqueue {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("cowqueue.in"));
        PrintWriter out = new PrintWriter(new File("cowqueue.out"));
        //input
        int cows = in.nextInt(); in.nextLine();
        int[] times = new int[cows];
        int[] questions = new int[cows];
        for (int i = 0; i < cows; i++) {
            times[i] = in.nextInt();
            questions[i] = in.nextInt();
            if (i < cows - 1) {
                in.nextLine();
            }
        }
        //ordering in chronological order
        int[] sortedTimes = new int[cows];
        int[] sortedQuestions = new int[cows];
        System.arraycopy(times, 0, sortedTimes, 0, cows);
        Arrays.sort(sortedTimes);
        int index = 0;
        int currTime = 0;
        for (int i = 0; i < cows; i++) {
            int time = sortedTimes[i];
            for (int j = 0; j < cows; j++) {
                if (times[j] == time) {
                    sortedQuestions[index] = questions[j];
                    index++; break;
                }
            }
        }
        //adding time
        int prevCurrTime = 0;
        for (int i = 0; i < cows; i++) {
            if (i < cows  && cows > 1) {
                //currTime = sortedTimes[i] + sortedQuestions[i];  
                if (currTime < sortedTimes[i]) {
                    currTime = sortedTimes[i] + sortedQuestions[i];
                } else {
                    currTime = currTime + sortedQuestions[i]; //times overlap, need to wait until prev questioning is done
                }
            } else {
                currTime = sortedTimes[i] + sortedQuestions[i];  
            }
            prevCurrTime = currTime;
            //System.out.println("i: " + i + " " + currTime);
        }
        //System.out.println(Arrays.toString(sortedTimes));
        //System.out.println(Arrays.toString(sortedQuestions));
        out.print(currTime);
        out.close();
    }
}