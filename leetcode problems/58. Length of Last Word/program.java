class Solution {
    public int lengthOfLastWord(String s) {
        
        String[] newStringArray = s.split(" ");
        
        return newStringArray[newStringArray.length-1].length();
        
    }
}