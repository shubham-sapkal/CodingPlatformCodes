//code here.
    bool flag = true;
    int count=0;
    
   
    int i=0;
    while (i < s.length()) 
    { 
        
        if((s[i] == '\\' && s[i+1] == 'n') || (s[i] == '\\' && s[i+1] == 't')) 
        {
            flag = true; 
            i++;
        } 
        else if(s[i] == ' ' ){
            flag = true;
        }
        else if (flag == true) 
        { 
            count++;
            flag = false; 
        } 
  

        i++; 
    } 
    
    return count;