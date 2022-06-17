class Solution {
    public double average(int[] salary) {
        
        
        
        Arrays.sort(salary);
        
        // int first = salary[0];
        // int last = salary[salary.length - 1];
        
        // float avg = (first+last)/2;
        
        int total=0;
        int count=0;
        
        for(int i=1; i<salary.length-1; i++){
            // System.out.println("adding salary : "+ salary[i]);
            total = total+salary[i];
            count++;
        }
        
//         System.out.println("avg = "+ total);
//         System.out.println("count = "+ count);
        
//         double avg = (double) total/count;
        
        return (double) total/count;
        
        
    }
}