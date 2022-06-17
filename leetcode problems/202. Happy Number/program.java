class Solution {
    
    private int getSum(int n){
        
        int sum = 0;
        
        while(n!=0)
        {
            int remain = n%10;
            sum += (remain * remain);
            n/=10;
        }
        
        return sum;
        
    }
    
    
    private boolean solve(int n){
        
        int result = getSum(n);
        
        while(true){
            
            System.out.println(result);
            
            if(result == 1 || result == 7 ){
                return true;
            }
            if(result < 10){
                break;
            }
            
            result = getSum(result);
            
            
            
        }
        
        return false;
        
    }
    
    public boolean isHappy(int n) {
        
        return solve(n);
        
    }
}