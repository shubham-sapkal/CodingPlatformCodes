class Solution {
private:
    int pivotElement(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        
        int mid = start + (end-start)/2;
        
        while(start<end)
        {
            if(arr[mid] >= arr[0] )
            {
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = start+(end-start)/2;
        }
        
        return start;
    }
    
    int binarySearch(vector<int> arr, int s, int e, int target){
     
        int start = s;
        int end = e;
        int mid = start + (end-start)/2;
        
        while(start<=end)
        {
            if(arr[mid] == target ){
                return mid;
            }
            if(arr[mid] < target ){
                start = mid + 1;
            }
            if(arr[mid] > target ){
                end = mid - 1;
            }
            
            mid = start + (end - start)/2;
        }
        
        return -1;
        
    }
public:
    int search(vector<int>& nums, int target) {
        
        
        int pivot = pivotElement(nums);
        
        if(nums[pivot] <= target && target <= nums[nums.size() - 1] )
        {
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
        else{
            return binarySearch(nums, 0, pivot-1, target);
        }
        
        return -1;
        
        
    }
};