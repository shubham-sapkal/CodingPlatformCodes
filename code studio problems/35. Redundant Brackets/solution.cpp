#include<stack>

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    
    for(int i=0; i<s.length(); i++)
    {
        char ch=s[i];
        
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            // it is opening bracket
            st.push(ch);
        }
        else{
            // it is closing bracket or lower letter 
            if(ch == ')')
            {
                bool isRedundant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/')
                    {
                        +-------
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                {
                    return true;
                }
                
                st.pop();
            }
            
        }
    }
    
    return false;
}
