public class Solution {
    public boolean isAnagram(String s, String t) {
        String newS = generateSortedString(s);
        
        String newT = generateSortedString(t);
        
        if(newT.equals(newS))
            return true;
        else
            return false;
        
    }
    
    String generateSortedString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}