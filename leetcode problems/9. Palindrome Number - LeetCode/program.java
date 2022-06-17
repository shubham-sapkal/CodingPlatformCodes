class Solution {
    public boolean isPalindrome(int x) {
        
        if( x<0){
            return false;
        }
        else if(x==0){
            return true;
        }
        
        int temp = x;
        int remainder;
        int rev = 0;
        
        while(temp!=0){
            remainder = temp%10;
            rev = (rev*10)+remainder;
            //System.out.println("Rev = "+rev);
            temp /= 10;
        }
        
        
        
        if(x == rev){
            return true;
        }
        
        
        return false;
        
    }
}