class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        map<int, int> count;

        for(vector<int> i : items1)
        {
            count[i[0]] = count[i[0]] + i[1];
            // count[items1[i][0]] = items1[i][1];
        }

        for(vector<int> i : items2)
        {
            count[i[0]] = count[i[0]] + i[1];
            // count[items1[i][0]] = items1[i][1];
        }

        vector<vector<int>> ans;

        for(auto i : count){

            vector<int> temp; //= {i.first, i.second};

            temp.push_back(i.first);
            temp.push_back(i.second);   

            ans.push_back(temp);

        }

        return ans;

    }
};