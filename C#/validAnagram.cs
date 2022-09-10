public class Solution {
    public bool IsAnagram(string s, string t) {
        return orderString(s).Equals(orderString(t));
        
    }
    
    public string orderString(string str) {
        char[] characters = str.ToArray();
        Array.Sort(characters);
        return new string(characters);
    }
}