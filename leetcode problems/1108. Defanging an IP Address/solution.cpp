class Solution {
    public String defangIPaddr(String address) {
        
        // String[] splited = address.split('.');

        // String ans = "";

        // System.out.println(splited[0]);

        // for(int i=0; i<splited.length; i++)
        // {
        //     ans = ans + splited[i] + "[.]";
        // }

        // // ans = ans + splited[3];

        return address.replace(".", "[.]");

    }
}