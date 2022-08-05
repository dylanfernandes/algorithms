import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    public static List<Integer> breakingRecords(List<Integer> scores) {
        List<Integer> minMax = new ArrayList<Integer>(Arrays.asList(0,0));
        
        if(scores.size() > 0) {
            int min = scores.get(0);
            int max = scores.get(0);
            
            for(int game = 1; game < scores.size(); game++) {
                int currentScore = scores.get(game);
            
                if(currentScore < min) {
                    min = currentScore;
                    minMax.set(1, minMax.get(1)+1);
                } else if(currentScore > max) {
                    max = currentScore;
                    minMax.set(0, minMax.get(0)+1);
                }  
            }
        }
        return minMax;
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> scores = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.breakingRecords(scores);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining(" "))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
