class Solution {
    
private:
    bool solve(int num, int start, int end){
        
        if(start>end){
            return false;
        }
        
        long long int mid = start+(end-start)/2;
        
        if( mid*mid == num){
            return true;
        }
        else if(mid*mid < num )  {
            return solve(num, mid+1, end);
        }
        else{
            return solve(num, start, mid-1);
        }
        
        
    }
    
public:
    bool isPerfectSquare(int num) {
        
        return solve(num, 0, num);
        
    }
};