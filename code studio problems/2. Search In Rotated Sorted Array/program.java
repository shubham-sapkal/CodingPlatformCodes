import java.util.ArrayList;

public class Solution {
   public static int pivotElement(ArrayList<Integer> arr, int n){
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        
        while(start<end){
            if(arr.get(mid) >= arr.get(0)) {
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        return start;
    }
    
    public static int binarySearch(ArrayList<Integer> arr, int s, int e, int k){
        //System.out.println("in Binary Search");
        int start = s;
        int end = e;
        int mid = start+(end-start)/2;
        
        while(start<=end){
            if(arr.get(mid) == k){
                return mid;
            }
            
            if(arr.get(mid) > k){
                end = mid-1;
            }
            else {
                start = mid+1;
            }
            mid = start+(end-start)/2;
        }
        
        return -1;
    }
    
    
    public static int findPosition(ArrayList<Integer> arr, int n, int k) {
    
        int pivot = pivotElement(arr, n);
        
        if(arr.get(pivot)<=k && k<=arr.get(n-1)){
            return binarySearch(arr, pivot, n-1, k);
        }
        else{
            return binarySearch(arr, 0, pivot-1, k);
        }
        
        //return -1;
        
    }

}
