class Solution {
    
    public int checkGreater(int arr[], int start, int key)
    {
        for(int i = start; i<arr.length; i++){
            
            // System.out.println("check for key greater then "+ arr[i]);
            
            if( arr[i] > key ){
                // System.out.println(arr[i]);
                return arr[i];
            }
            
        }
        
        return -1;
    }
    
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        int answer[] = new int[nums1.length];
        
        for(int i = 0; i < nums1.length; i++){
            
            for(int j=0; j<nums2.length; j++){
                
                // System.out.println("Comparing for "+ nums1[i] + " and " + nums2[j]);
                
                if(nums1[i] == nums2[j] ){
                    
                    answer[i] = checkGreater(nums2, j, nums1[i]);
                    
                }
            }
            
        }
        
        return answer;
    }
}