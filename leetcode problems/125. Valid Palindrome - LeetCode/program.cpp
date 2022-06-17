#include<bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.length()-1;
        
        transform(s.begin(),s.end(),s.begin(), ::toupper);
        
        while(start<=end){
            
            if(!isalpha(s[start])){
                if(!isdigit(s[start])){
                    start++;
                    continue;
                }  
            }
            
            if(!isalpha(s[end])){
                if(!isdigit(s[end])){
                    end--;
                    continue;
                }  
            }
            
            if( s[start] != s[end] ){
                return 0;
            }
            
            start++;
            end--;
            
            
            
        }
        
        return 1;
        
    }
};