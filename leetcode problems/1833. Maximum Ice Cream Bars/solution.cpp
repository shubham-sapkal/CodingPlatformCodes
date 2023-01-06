class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int count = 0;

        sort(costs.begin(), costs.end());

        for(int i=0; i<costs.size(); i++)
        {
            cout << "test = " << coins - costs[i] << endl;
            if( coins - costs[i] < 0)
            {
                break;
            }
            else{
                count++;
                coins = coins-costs[i];
            }
        }

        return count;

    }
};