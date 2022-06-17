class Solution {
    
private:
    void solve(vector<int>& digits, int i){
        
        // base case
        if(digits[i] != 9){
            digits[i]+=1;
            return ;
        }
        
        if(i == 0){
            digits.push_back(0);
            digits[i] = 1;
            return;
        }
        
        
        digits[i] = 0;
        solve(digits, i-1); 
        
    }
    
public:
    vector<int> plusOne(vector<int>& digits) {
        
        solve(digits, digits.size()-1);
        
        return digits;

        
    }
};