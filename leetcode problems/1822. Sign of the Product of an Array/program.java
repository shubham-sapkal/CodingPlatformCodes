class Solution {
    
    public int signFunc(long num){
        
        if(num == 0){
            return 0;
        }
        else if(num > 0){
            return 1;
        }
        else if(num < 0){
            return -1;    
        }
        
        return 0;
    }
    
    public int arraySign(int[] nums) {
        
        long product = nums[0];
        
        
        for(int i = 1; i<nums.length; i++){
            product = product * signFunc(nums[i]);
            // System.out.println("Product = "+ product);
        }
        
        return signFunc(product);
        
    }
}