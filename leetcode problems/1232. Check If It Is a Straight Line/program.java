class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        
        
        float commonSlope = 0;
        int commonDen = coordinates[0][1];

        for (int i = 0; i < coordinates.length - 1; i++) {
            
            // Point 1
            int oX = coordinates[i][0];
            int oY = coordinates[i][1];

            // Point 2
            int tX = coordinates[i + 1][0];
            int tY = coordinates[i + 1][1];

            // Slope
            int num = tX - oX;
            int den = tY - oY;

            // if denominator is 0
            if (den == 0) {

                // and not a common denominator
                if (tY != commonDen)
                    return false;
            
            } else {
    
                float slope = (float) num / (float) den;
                
                // set common slope
                if(i == 0)
                    commonSlope = slope;

                // check if slope is similar
                if (slope != commonSlope) 
                    return false;

            }
        }
		
        return true;
        
        
    }
}