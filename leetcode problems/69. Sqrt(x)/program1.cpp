class Solution {
public:
    
    long long int binarySearch(int num){
        
        int start = 0;
        int end = num;
        
        long long int mid = start + (end-start)/2;
        
        long long int ans = -1;
        
        while(start<=end){
            
            long long int square = mid*mid;
            
            if(square == num){
                return mid;
            }
            
            if(square < num){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
            
            mid = start + (end-start)/2;
            
        }
        
        return ans;
        
    }
    
    int mySqrt(int x) {
        
        
        return binarySearch(x);
        
    }
};