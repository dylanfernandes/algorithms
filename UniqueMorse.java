class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashMap<String, Integer> hmap = new HashMap<String, Integer>();
        String curr = "";
        String word;
        char ch;
        for(int i = 0;i < words.length;i++) {
            curr = "";
            word = words[i];
            for(int j = 0; j < word.length(); j++) {
                ch = word.charAt(j);
                curr = curr + codes[(int)ch - 97];
            }
            if(!hmap.containsKey(curr))
                hmap.put(curr, 1);
        }
        return hmap.size();
    }
}