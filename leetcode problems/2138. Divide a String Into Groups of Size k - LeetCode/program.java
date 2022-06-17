class Solution {
    public static String assignFill(char fill,int k){
        int i=0;
        String result = "";
        while(i!=k){
            result = result+fill;
            i++;
        }
        return result;
    }
    
    
    public String[] divideString(String s, int k, char fill) {
        List<String> partitions = new ArrayList<>();
        
        int count = 0;
        
        String str = "";
        
        for(char ch : s.toCharArray()) {
            
            if(count==0){
                str = Solution.assignFill(fill,k);
            }
            
            str = str.substring(0,count) + ch + str.substring(count+1);
            count++;
            
            if(count>k-1){
                partitions.add(str);
                count=0;
            }
            
        }
        
        if(count!=0){
            partitions.add(str);
        }
        
        return partitions.toArray(new String[partitions.size()]);
    }
}