public class Solution {
    public int MostWordsFound(string[] sentences) {
        int maxSize = 0;
        for(int i = 0; i < sentences.Length;i++) {
            string current = sentences[i];
            int currentSize = current.Split().Length;
            if(currentSize > maxSize)
                maxSize = currentSize;
        }
        
        return maxSize;
    }
}