class Solution {
    
    public int getMaxWealth(int arr[])
    {
        return Arrays.stream(arr).sum();
    }
    
    
    public int maximumWealth(int[][] accounts) {
        
        int maxWealth = getMaxWealth(accounts[0]);
        
        for(int i = 1; i< accounts.length; i++)
        {
            if( getMaxWealth(accounts[i]) > maxWealth ){
                maxWealth = getMaxWealth(accounts[i]);
            }
        }
        
        return maxWealth;
        
    }
}