class Solution {
    
    public int getInt(char s){
    
        int number = 0;    
        
        if(s == 'M' || s == 'm'){
            return 1000;
        }
        else if(s == 'D' || s == 'd'){
            return 500;
        }
        else if(s == 'C' || s == 'c'){
            return 100;
        }
        else if(s== 'L' || s == 'l'){
            return 50;
        }
        else if(s == 'X' || s == 'x'){
            return 10;
        }
        else if(s == 'V' || s == 'v'){
            return 5;
        }
        else if(s == 'I' || s == 'i'){
            return 1;
        }
        
        return number;
        
        
    }
    
    public int romanToInt(String s) {
        
        int number = 0, flag = 0, i=0;
        
        //number = getInt(s.charAt(0));
        
        for(i = 0; i<s.length()-1;i++){
            
            //System.out.println("i = "+i);
            
            if( getInt(s.charAt(i)) < getInt(s.charAt(i+1)) ){
                number = number + getInt(s.charAt(i+1)) - getInt(s.charAt(i));
                i = i+1;
                if(i==s.length()-1){
                    flag = 1;
                }
            }        
            else {
                number = number + getInt(s.charAt(i));
                 if(i==s.length()-1){
                    flag = 1;
                }
            }
            
        }
        
        
       
       if(flag==0){
            number = number + getInt(s.charAt(s.length()-1));
       }
        
        
        return number;
        
    }
}