import java.io.*;
import java.util.*;

public class measurement {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("measurement.in"));    
        PrintWriter out = new PrintWriter(new File("measurement.out"));
        
        //input
        int totalCows = in.nextInt(); in.nextLine();
        int[] days = new int[totalCows];
        String[] cows = new String[totalCows];
        String[] changes = new String[totalCows];
        for (int i = 0; i < totalCows; i++) {
            days[i] = in.nextInt();
            cows[i] = in.nextLine();
        }
        
        int initalMilk = 7;

        String[] leaders = new String[totalCows];
        int numLeaders = 0;
        int greatestIncrease = 0;
        int timesChanged = 0;
        int currentHashMapSize = 0;
        int index = 0;

        String[] sepValues = new String[3];
        HashMap<String, Integer> cowGallons = new HashMap<String, Integer>();
        int[] sortedDays = new int[days.length];
        System.arraycopy(days, 0, sortedDays, 0, days.length);
        Arrays.sort(sortedDays);
        System.out.println(Arrays.toString(sortedDays));
        //System.out.println(Arrays.toString(days));
        for (int i = 0; i < totalCows; i++) {
            int cowIndex = 0;
            for (int j = 0; j < totalCows; j++) {
                if (sortedDays[i] == days[j]) {
                    //System.out.println("j: " + j);
                    cowIndex = j;
                    break;
                }
            }
            //System.out.println(cowIndex);
            sepValues = cows[cowIndex].split(" ");
            //System.out.println(sepValues[1]);
            String outcome = sepValues[2];
            int change = Integer.valueOf(outcome);
            //System.out.println(change);
            boolean inMap = alreadyIn(cowGallons, sepValues[1]);
            if (inMap) {
                //System.out.println("in map: " + sepValues[1]);
                //System.out.println("previous: " + cowGallons.get(sepValues[1]));
                cowGallons.put(sepValues[1], (change + cowGallons.get(sepValues[1])));
            } else {
                cowGallons.put(sepValues[1], change);
            }

            //System.out.println(cowGallons);
            //different scenarios
            if (cowGallons.size() > currentHashMapSize && bestIncrease(cowGallons) > greatestIncrease) {
                //update is needed
                timesChanged++;
                leaders[index] = getKey(cowGallons, bestIncrease(cowGallons));
                //System.out.println("timesChanged: " + timesChanged);
                //System.out.println(Arrays.toString(leaders));
            } else if (cowGallons.size() == currentHashMapSize && bestIncrease(cowGallons) == greatestIncrease) {
                //tie in leaders, still need to update
                timesChanged++;
                index++;
                leaders[index] = getKey(cowGallons, bestIncrease(cowGallons));
                //System.out.println("timesChanged: " + timesChanged);
                //System.out.println(Arrays.toString(leaders));
            }
            currentHashMapSize = cowGallons.size();
            greatestIncrease = bestIncrease(cowGallons);
            System.out.println(cowGallons);
            //cowGallons.values() += 7;

        }
        out.println(timesChanged);
        //
        out.close();
    }

    public static String getKey(HashMap <String, Integer> map, int value) {
        for (String key : map.keySet()) {
            if (value == map.get(key)) {
                return key;
            }
        }
        return "";
    }

    public static int bestIncrease(HashMap<String, Integer> cowGallons) {
        int best = 0;
        for (int i : cowGallons.values()) {
            if (i > best) {
                best = i;
            }
        }
        return best;
    }

    public static boolean alreadyIn(HashMap<String, Integer> cowGallons, String cow) {
        for (String i : cowGallons.keySet()) {
            if (i.equals(cow)) {
                //System.out.println("match: " + i + " , " + cow);
                return true;
            }
        }
        return false;
    }
}