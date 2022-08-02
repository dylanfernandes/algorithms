class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        TreeMap<Character, Integer> letters = populateOccurences(magazine);
        
        return validateMessage(letters, ransomNote);
    }
    
    public TreeMap<Character, Integer> populateOccurences(String magazine) {
        TreeMap<Character, Integer> letters = new TreeMap<Character, Integer>();
        
        for(int i = 0; i < magazine.length(); i++) {
            char current = magazine.charAt(i);
            if(letters.containsKey(current)) {
                int numOccurence = letters.get(current);
                letters.put(current, numOccurence+1);
            } else {
                letters.put(current, 1);
            }
        }
        
        return letters;
    }
    
    public boolean validateMessage(TreeMap<Character, Integer> letters, String ransomNote) {
        for(int i = 0; i < ransomNote.length(); i++) {
            char current = ransomNote.charAt(i);
            if(letters.containsKey(current)) {
                int numOccurence = letters.get(current);
                if(numOccurence > 0)
                    letters.put(current, numOccurence-1);
                else
                    return false;
            } else
                return false;
        }
        return true;
    }
}