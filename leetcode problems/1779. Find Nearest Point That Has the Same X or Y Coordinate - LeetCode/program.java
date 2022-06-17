class Solution {
    
    public boolean findSmallest(int a, int b){

        return a>b ? true : false;
            
    }
    
    
    public int nearestValidPoint(int x, int y, int[][] points) {
        
        int smallest = 100000007;
        int smallestIndex = -1;
        
        
        for(int i = 0; i<points.length; i++){
            
            if( x == points[i][0] || y == points[i][1] ){
                
                if(findSmallest(smallest, Math.abs(x - points[i][0]) + Math.abs(y - points[i][1])) == true ){
                    
                    smallest = Math.abs(x - points[i][0]) + Math.abs(y - points[i][1]);
                    smallestIndex = i;
                    
                }
                
            }
            
        }
        
        
        
        return smallestIndex;
        
        
    }
}