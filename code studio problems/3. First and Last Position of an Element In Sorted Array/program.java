import java.util.*;
import javafx.util.Pair;

public class Solution {
    
    static int firstOccurance(ArrayList<Integer> arr, int size, int key){

        int start = 0;
        int end = size - 1;

        int mid = start + (end-start)/2;

        int answer = -1;

        while(start<=end){

            if(arr.get(mid) == key ){
                answer = mid;
                end = mid - 1;
            }

            if(arr.get(mid) > key ){
                end = mid - 1;
            }

            if(arr.get(mid) < key ){
                start = mid + 1;
            }

            mid = start + (end-start)/2;

        }

        return answer;


	}


	static int lastOccurance(ArrayList<Integer> arr, int size, int key){

        int start = 0;
        int end = size - 1;

        int mid = start + (end-start)/2;

        int answer = -1;

        while(start<=end){

            if(arr.get(mid) == key ){
                answer = mid;
                start = mid + 1;
            }

            if(arr.get(mid) > key ){
                end = mid - 1;
            }

            if(arr.get(mid) < key ){
                start = mid + 1;
            }

            mid = start + (end-start)/2;

        }

        return answer;

	}

    public static Pair<Integer, Integer> firstAndLastPosition(ArrayList<Integer> arr, int n, int k) {
        
         Pair<Integer, Integer> p = new Pair<Integer, Integer>(
         		firstOccurance(arr, n, k),
            	lastOccurance(arr, n, k)
         );
        
        return p;
        
    }

};
