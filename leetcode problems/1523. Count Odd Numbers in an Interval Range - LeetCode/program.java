class Solution {
    public int countOdds(int low, int high) {
        
       
        int mid = (high - low)/2;
        
        if(low%2 != 0 || high%2 != 0){
            return mid+1;
        }
        
        return mid;
        
        
    }
}