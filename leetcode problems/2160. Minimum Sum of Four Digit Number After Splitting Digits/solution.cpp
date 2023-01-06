class Solution {
public:
    int minimumSum(int num) {
        
        vector<int> arr(4);

        int i=0;
        while(num != 0)
        {
            arr[i] = num%10;
            num /= 10;
            i++;
        }

        sort(arr.begin(), arr.end());

        for(int i1 : arr)
        {
            cout << i1 << " ";
        }

        
        int num1 = arr[0]*10 + arr[1]*10;
        // num1 = num1*10 + ;
        // cout << " num1 = " << num1 << endl;

        int num2 = arr[2]+arr[3];

        return num1 + num2;

    }
};