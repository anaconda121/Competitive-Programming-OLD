import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class notlast {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("notlast.in"));
        PrintWriter out = new PrintWriter(new File("notlast.out"));
        // input
        int N = Integer.parseInt(in.nextLine());
        int[] gallons = new int[N];
        String[] names = new String[N];
        Set<String> cows = new HashSet<String>();
        HashMap<String, Integer> log = new HashMap<String, Integer>();
        String[] cowNames = { "Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta" };
        for (int i = 0; i < N; i++) {
            String curr = in.nextLine();
            String[] split = curr.split(" ");
            names[i] = split[0];
            gallons[i] = Integer.parseInt(split[1]);
            cows.add(names[i]);
            if (log.containsKey(names[i])) {
                log.put(names[i], log.get(names[i]) + gallons[i]);
            } else {
                log.put(names[i], gallons[i]);
            }
        }
        // seeing which cows have no milk produced
        String[] noMilk = new String[102];
        int index = 0;
        if (cows.size() < 7) {
            for (int i = 0; i < cowNames.length; i++) {
                if (cows.contains(cowNames[i]) == false) {
                    noMilk[index] = cowNames[i];
                    index++;
                }
            }
        }
        // adding those cows w/ no milk produced to hashmap
        if (index > 0) {
            for (int i = 0; i == index; i++) {
                log.put(noMilk[i], 0);
            }
        }
        // finding second smallest milkamount produced
        int[] amounts = new int[7];
        List<String> l = new ArrayList<String>(cows);
        for (int i = 0; i < cows.size(); i++) {
            amounts[i] = log.get(l.get(i));
        }
        //System.out.println(Arrays.toString(amounts));
        Arrays.sort(amounts);
        int second = 0;
        for (int i = 1; i < amounts.length; i++) {
            if (amounts[i] > amounts[0]) {
                second = amounts[i];
                break;
            }
        }
        // getting total # of cows who produce second smallest amount
        int count = 0;
        for (int i = 0; i < amounts.length; i++) {
            if (amounts[i] == second)
                count++;
        }
        // getting cow name to output
        String output = "Tie";
        if (second == amounts[0] || count > 1) {
            output = "Tie";
        } else {
            for (Entry<String, Integer> curr : log.entrySet()) {
                if (curr.getValue().equals(second)) {
                    output = curr.getKey();
                }
            }
        }
        out.println(output);
        out.close();
    }
}