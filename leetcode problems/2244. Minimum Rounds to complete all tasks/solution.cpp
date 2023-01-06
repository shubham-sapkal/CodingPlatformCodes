class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        // store frequency of each tasks
        unordered_map<int, int> freq;
        for(int i=0; i<tasks.size(); i++)
        {
            freq[tasks[i]]++;
        }

        int noround = 0;

        for(auto x : freq)
        {
            int frequency = x.second;

            // if freq is 1 return -1 not possible
            if(frequency == 1)
            {
                return -1;
            }

            // if freq is is divided by 3 
            else if(frequency%3 == 0)
            {
                noround += frequency/3;
            }

            // if rem == 2 or rem == 1
            else if(frequency%3 == 1 || frequency%3 == 2)
            {
                noround += frequency/3+1;
            }
        }

        return noround;

    }
};