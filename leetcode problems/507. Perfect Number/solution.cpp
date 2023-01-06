class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        int count = 1;

        if(num == 1 || num == 0)
            return false;

        for(int i=2; i<num; i++)
        {
            if(num%i == 0){
                count += i;
            }
        }

        return count == num;

    }
};